#include "header.h"

/**
 * This file will take the values passed through from the main function
 * and move the robot appropriately.
 */

int delay_to_seconds (int delay) {
	int seconds = 0;
	int oneSecond = 1000000;
	if (delay >= oneSecond) {
		seconds = delay / oneSecond;
	}
	return seconds;
}
int delay_to_microseconds (int delay) {
	int microseconds = 0;
	int oneSecond = 1000000;
	if (delay >= oneSecond) {
		microseconds = delay % oneSecond;
	} else {
		microseconds = delay;
	}
	return microseconds;
}

/* Take the incoming data and choose which direction the robot should go */
void direction_helper(int error_value) {
	//Call one of the straight, left, or right methods.
	if (error_value < -700) {
		turn_left_sharp(1000, 0.5);
	} else if (error_value < -200 && error_value > -700) {
		turn_left_slope(1000, 0.5, 0.25);
	} else if (error_value > -200 && error_value < 200) {
		go_straight(10000, 1);
	} else if (error_value > 200 && error_value < 700) {
		turn_right_slope(1000, 0.5, 0.25);
	} else if (error_value > 700) {
		turn_right_sharp(1000, 0.5);
	}
}

void go_straight(int delay, double PWM) {

	int seconds = delay_to_seconds(delay);
	int microSeconds = delay_to_microseconds(delay);

	//Set the speed based off a constant factor (0 < PWM < 1)
	double speed = PWM * 255;
	set_motor(1, speed);
	set_motor(2, speed);

	sleep1 (seconds, microSeconds);

	set_motor(1, 0);
	set_motor(2, 0);

	return;
}

void turn_left_sharp (int delay, double PWM) {
	
	int seconds = delay_to_seconds(delay);
	int microSeconds = delay_to_microseconds(delay);

	double speed = PWM * 255;
	set_motor(1, -speed);
	set_motor(2,  speed);

	sleep1 (seconds, microSeconds);
	
	set_motor(1, 0);
	set_motor(2, 0);

	return;
}

void turn_left_slope (int delay, double PWM, int turning_distance) {
	int seconds = delay_to_seconds(delay);
	int microSeconds = delay_to_microseconds(delay);

	double speed = PWM * 255;
	double difference = turning_distance * 255;
	set_motor(1, speed);
	set_motor(2, speed + difference);

	sleep1 (seconds, microSeconds);
	
	set_motor(1, 0);
	set_motor(2, 0);

	return;
}

void turn_right_sharp (int delay, double PWM) {

	int seconds = delay_to_seconds(delay);
	int microSeconds = delay_to_microseconds(delay);

	double speed = PWM * 255;
	set_motor(1, speed);
	set_motor(2,  -speed);

	sleep1 (seconds, microSeconds);
	
	set_motor(1, 0);
	set_motor(2, 0);
	
	return;
}

void turn_right_slope (int delay, double PWM, int turning_distance) {
	int seconds = delay_to_seconds(delay);
	int microSeconds = delay_to_microseconds(delay);

	double speed = PWM * 255;
	set_motor(1, speed);
	set_motor(2,  speed + turning_distance);

	sleep1 (seconds, microSeconds);
	
	set_motor(1, 0);
	set_motor(2, 0);
	
	return;
}