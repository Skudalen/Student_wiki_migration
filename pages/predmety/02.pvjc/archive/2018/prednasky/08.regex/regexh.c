// Priklad na regularne vyrazy v jazyku c
//
// pomocou POSIX regex.h 
//
// Funguje na OS Unix
//
// Na vyukove ucely
//
// (c) 2018 Daniel Hladek a Technicka univerzita v Kosiciach
// v 1.0
//
// Program nacita jeden riadok textu a regularny vyraz.
// Potom zobrazi vsetky vyskyty regularneho vyrazu.
//
// Na preklad nie su potrebne ziadne specialne prepinace
//

#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

#define MAXGROUPS 3
#define MAXMATCH 3
#define STRINGSIZE 100 


// Inspiroval som sa tymito naterialmi:
//
// https://gist.github.com/ianmackinnon/3294587
// https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_73/rtref/regcomp.htm
// https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_73/rtref/regexec.htm
// https://www.gnu.org/software/libc/manual/html_node/Regexp-Subexpressions.html
//

int main(){
    // Retazec v ktorom budeme vyhladavat.
    char source[STRINGSIZE];
    // Regularny vyraz, kotry budeme vyhladavat.
    char regex[STRINGSIZE];
    // Na ulozenie informacie o vysledku kompilacie regexu
    int re = 0;
    // Velkost nacitaneho retazca
    int sz = 0;

    // Nacitanie retazca
    printf("Zadajte retazec (1 riadok, max %d znakov)\n",STRINGSIZE);
    fgets(source,STRINGSIZE,stdin);
    sz = strlen(source);
    printf("Nacitany retazec ma %d znakov (vratane konca riadku)\n",sz);

    // Nacitanie regexu
    printf("Zadajte regex (max %d znakov)\n",STRINGSIZE);
    fgets(regex,STRINGSIZE,stdin);
    sz = strlen(regex);
    // Musime odstranit koniec riadka z regexu
    regex[sz-1] = 0;

    // Regex treba pred pouzitim skompilovat
    // Tu sa ulozi skompimilovany regex
    regex_t compiled_regex;
    if (0!=(re = regcomp(&compiled_regex,regex,REG_EXTENDED))){
        char error[STRINGSIZE];
        perror("Error compiling regex:\n");
        regerror(re,&compiled_regex,error,STRINGSIZE);
        perror(error);
        return 1;
    }

    // Tu si ulozim vysledky vyhladavania
    regmatch_t groupArray[MAXGROUPS];

    // Zaciatok retazca budeme postupne posuvat, aby sme nehladali stale na tom istom mieste.
    int searched_chars = 0;

    // V retaazci mozeme najst max. MAXMATCH vyskledkov
    // Kazdy vysledok vyhladavania moze mat jednu alebo viac skupin.
    for (int i = 0; i < MAXMATCH; i++){
        // Vyhladavame v poli so zaciatkom posunutym o searched_chars
        // Posledny znak pola musi byt nula
        // Vysledky vyhladavania sa ulozia do pola struktur groupArray
        re = regexec(&compiled_regex,&source[searched_chars],MAXGROUPS,groupArray,0);
        if  (re != 0){
            break;
        }

        // Zobrazenie vysledku.
        //

        // Tu si ulozime pocet skupin ktore sme nasli vo vysledku
        int matchcounter = 0;
        // Cely Vysledok vyhladavania je prva skupina v groupArray[0]
        // Skupiny (zatvorky v regex) su ulozene v dalsich prvkoch pola groupArray
        // Nevyuzite prvky pola maju nastavene hodnoty na -1
        char buffer[STRINGSIZE];
        for (int j = 0; j < MAXGROUPS && groupArray[j].rm_eo != -1; j++){
            // Kazdy vysledok vyhladavania je vyjadreny indexom zaciatku (rm_so) 
            // a indexom konca vyskytu rm_eo
            //
            // Oba indexy sa pociutaju od zaciatku aktualneho vyhladavania
            //
            // Ak je index -1, potom nie su ziadne dalsie vysledky
            printf("Match at %d %d:>>>",searched_chars + groupArray[j].rm_so,searched_chars + groupArray[j].rm_eo);
            matchcounter += 1;
            // Ak chceme urobit nieco s najdenym podretazcom, je dobre si ho nakopirovat.
            // Zaciatok vysledku zistime podla rm_so
            char* matchstart = &source[groupArray[j].rm_so + searched_chars];
            // Velkost zistime ako rozdiel oboch indexom
            int matchsize = groupArray[j].rm_eo - groupArray[j].rm_so;
            // Overime, ci velkost sedi
            assert(matchsize < STRINGSIZE);
            // Prekopirujeme do buffra
            memcpy(buffer,matchstart,matchsize);
            // Na koniec doplnimu nulu
            buffer[matchsize] = 0;
            printf("%s<<<\n",buffer);
        }
        assert(matchcounter > 0);
        // Ak sme nasli vysledok, posunieme zaciatok dalsieho vyhladavania, aby sme nehladali na tom istom miete.
        searched_chars += groupArray[0].rm_eo;
    }
    // Uvolnenie pamete pre regex
    regfree(&compiled_regex);

    return 0;
}
