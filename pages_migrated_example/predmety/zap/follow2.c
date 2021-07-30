// (c) 2019 Daniel Hládek pre TUKE
// Algoritmus sledovania steny na ľavej strane
//
#include <karel.h>
#define SPEED 100

// Otočí robota vpravo
void turn_right(){
	set_step_delay(0);
	turn_left();
	turn_left();
	set_step_delay(SPEED);
	turn_left();
}


int main(){
	turn_on("maze2.kw");
	// Pokiaľ nenájdem žetón
	while(!beepers_present()){
		// 
		// Algoritmus sledovania steny
		//
		//  Robot má stenu na ľavej strane
		turn_left();
		while(front_is_clear()){
			// Pokiaľ nenájde stenu
			// Ide dookola rohu
			step();
			// Otočí sa tak aby mal
			// stenu na ľavej strane
			turn_right();
		}
	}
	turn_off();
	return 0;
}
