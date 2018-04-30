#include <stdio.h>
#include <time.h>
#include "E101.h"
void turn_left(int delay);
void goStraight;

int main (){
	init ();
	
	turn_left(1000000);
	sleep1(2, 0);
	turn_left(500000);
	sleep1(2, 0);
	turn_left(4000000);
	
	return  0;
}

void turn_left(int delay) {
	//Motor 1 = left, Motor 2 = right
	
	int seconds = 0;
	int microSeconds = 0;
	int oneSecond = 1000000;
	if (delay >= oneSecond) {
		seconds = delay / oneSecond;
		microSeconds = delay % oneSecond;
	} else {
		seconds = 0;
		microSeconds = delay;
	}
	set_motor(1, -127);
	set_motor(2,  128);
	sleep1 (seconds, microSeconds);
	
	printf("seconds = %d, microseconds = %d\n", seconds, microSeconds);
	
	set_motor(1, 0);
	set_motor(2, 0);
}

void goStraight () {
	set_motor(1, 128);
	set_motor(2,  -127);
	sleep1 (1, 0);
	
	set_motor(1, 0);
	set_motor(2, 0);
}
