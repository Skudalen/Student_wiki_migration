#include <curses.h>
#include <unistd.h>

int main() {
        initscr();
        echo(); // Nevypisuj vstup na obrazovku
        cbreak(); // Zabudni starý vstup
        nodelay(stdscr,TRUE); // Nečakaj na stlačenie
        keypad(stdscr,TRUE); // Aktivuje šípky
        curs_set(FALSE); // Neviditeľný kurzor

        // LINES COLS
        int y = LINES/2;
        int x = COLS/2;
        while(1){
          mvprintw(y,x," ");
          int k = getch();
          int nx = x;
          int ny = y;
          if (k == KEY_LEFT){
                  nx -= 1;
          }
          else if (k == KEY_RIGHT){
                  nx += 1;
          }
          if (k == KEY_UP){
                  ny -= 1;
          }
          else if (k == KEY_DOWN){
                  ny += 1;
          }
          if (nx >= COLS || ny >= LINES || ny < 0 || nx < 0){
                  break;
          }
          x = nx;
          y = ny;
          mvprintw(y,x,"&");
          refresh();
          usleep(80000);
        }

        mvprintw(LINES/2,COLS/2,"Buuum");
        getch();
        endwin();
        return 0;
}

