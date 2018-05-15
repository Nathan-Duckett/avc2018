#include "header.h"
#include "movement.cpp"
#include "camera.cpp"
#include "sensors.cpp"
#include "network.cpp"

int main (){
	init ();
	int quadrant = 1;
	while(true) {
		switch(quadrant) {
			case 1:
				open_gate();
			case 2:
				int error = camera_read();
				direction_helper(error);
				break;
		}
	}
	
	
	return  0;
}

