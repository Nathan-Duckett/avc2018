#include "header.h"

/**
 * This file will take the values passed through from the main function
 * and move the robot appropriately.
 */

/* Take the incoming data and choose which direction the robot should go */
void direction_helper(/*Some variables*/) {
	//Call one of the straight, left, or right methods.
}

void go_straight(int delay) {
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
	set_motor(1, 128);
	set_motor(2,  128);
	sleep1 (seconds, microSeconds);
	printf("seconds = %d, microseconds = %d\n", seconds, microSeconds);
	set_motor(1, 0);
	set_motor(2, 0);

	return;
}

void turn_left(int delay) {
	//Motor 1 = left, Motor 2 = right
	//microseconds to seconds
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
	return;
}

void turn_right (int delay) {
	//Motor 1 = left, Motor 2 = right
	//microseconds to seconds
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
	set_motor(1, 128);
	set_motor(2,  -127);
	sleep1 (seconds, microSeconds);
	
	printf("seconds = %d, microseconds = %d\n", seconds, microSeconds);
	
	set_motor(1, 0);
	set_motor(2, 0);
	return;
}

