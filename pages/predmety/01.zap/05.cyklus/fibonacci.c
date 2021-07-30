// (c) 2019 Daniel Hládek pre TUKE
// Fibonacciho postupnosť
#include <karel.h>
#define SPEED 100

// Skrut doprava
void turn_right(){
	set_step_delay(0);
	turn_left();
	turn_left();
	set_step_delay(SPEED);
	turn_left();
}

// Krok dozadu
void step_back(){
	set_step_delay(0);
	turn_left();
	turn_left();
	step();
	turn_left();
	set_step_delay(SPEED);
	turn_left();
}

// Rekurzívne kopírovanie ǒ jedno políčko
void copy_right(){
	// Robot stojí na žetónoch
	// 3>
     // Ukončovacia podmienka
     if (beepers_present()){
	     // Prenesie žetón
	     pick_beeper();
	     step();
	     put_beeper();
	     // Vráti sa
	     step_back();
	     // Rekurzívne volanie
	     // Kopíruje ďalšie žetóny
	     copy_right();
	     // Vráti žetón
	     put_beeper();
     }

}

// Rekurzívne kopírovanie o dva políčka
void copy_two_right(){
	// Robot stojí na žetónoch
	// 3>
     if (beepers_present()){
	     pick_beeper();
	     step();
	     step();
	     put_beeper();
	     step_back();
	     step_back();
	     copy_two_right();
	     put_beeper();
     }
}


int main(){
	// >
	turn_on("fibonacci2.kw");
	step();
	put_beeper();
	while(front_is_clear()){
		step_back();
		copy_two_right();
		step();
		copy_right();
		step();
	}

	turn_off();
	return 0;
}
