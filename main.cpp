#include "header.h"
#include "movement.cpp"
#include "camera.cpp"
#include "sensors.cpp"
#include "network.cpp"

int main (){
	init ();
	
	while(true) {
		int results = camera_read();
		direction_helper();

	}
	
	
	return  0;
}

