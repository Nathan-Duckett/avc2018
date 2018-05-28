#include "header.h"
void go_straight(int delay, double PWM) ;
void go_back(int delay, double PWM);
void turn_left_sharp (int delay, double PWM);
void turn_right_sharp (int delay, double PWM);
void turn_left_slope (int delay, double PWM, double turning_distance);
void turn_right_slope (int delay, double PWM, double turning_distance);
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
	
	// time_t timer;
	// float new_time  = difftime(time(&timer), previous_time);
	// float Kp = -0.005;
	// float Kd = -0.05;

	// float derivative = (error_value - previous_error) / new_time;

	// float dv = error_value * Kp + derivative * Kd;

	// float motor_left = 127 + dv;
	// float motor_right = 127 - dv;

	// set_motor(1, motor_left);
	// set_motor(2, motor_right);


	//Call one of the straight, left, or right methods.
	if (error_value == -100000) {

		go_back(3000, 0.6);

	} else if (error_value < -35) {

		turn_left_sharp(5000, 0.35);

	} else if(error_value < -20 && error_value >= -35){

		turn_left_slope(5000, 0.4, 0.1);
	
	} else if (error_value < -13 && error_value >= -20) {

		turn_left_slope(5000, 0.4, 0.05);

	} else if (error_value >= -13 && error_value <= 5) {

		go_straight(5000, 0.6);

	} else if (error_value > 5 && error_value <= 15) {

		turn_right_slope(5000, 0.4, 0.05);

	} else if (error_value > 15 && error_value <= 30) {

		turn_right_slope(5000, 0.4, 0.1);

	} else if(error_value > 30){

		turn_right_sharp(6000, 0.4);
	
	} else if (error_value == 100000) {
		
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

}

void go_back(int delay, double PWM) {

	int seconds = delay_to_seconds(delay);
	int microSeconds = delay_to_microseconds(delay);

	//Set the speed based off a constant factor (0 < PWM < 1)
	double speed = PWM * 255;
	set_motor(1, -speed);
	set_motor(2, -speed);

	sleep1 (seconds, microSeconds);

	set_motor(1, 0);
	set_motor(2, 0);

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


void turn_left_slope (int delay, double PWM, double turning_distance) {

	int seconds = delay_to_seconds(delay);
	int microSeconds = delay_to_microseconds(delay);

	double speed = PWM * 255;
	double difference = turning_distance * 255;
	set_motor(1, speed - difference);
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


void turn_right_slope (int delay, double PWM, double turning_distance) {
  
	int seconds = delay_to_seconds(delay);
	int microSeconds = delay_to_microseconds(delay);
	
	double difference = turning_distance * 255;
	double speed = PWM * 255;
	set_motor(1, speed + difference);
	set_motor(2,  speed - difference);

	sleep1 (seconds, microSeconds);
	
	set_motor(1, 0);
	set_motor(2, 0);
	
	return;

}
