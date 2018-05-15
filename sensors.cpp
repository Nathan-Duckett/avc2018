#include "header.h"

/** 
 * This file takes the recordings from the IR sensors during the 
 * challenge part of the course. These values are returned and used to
 * adjust the various speeds of the robot.
 */

void motorspeedFor(int forSpeed){
	set_motor(1,forSpeed);
	set_motor(2,forSpeed);
}

void motorspeedLeft(int leftSpeed, int forSpeed){
	set_motor(1,leftSpeed);
	set_motor(2,forSpeed);
}

void motorSpeedRight(int rightSpeed, int forSpeed){
	set_motor(1,forSpeed);
	set_motor(2,rightSpeed);
}

int sensor_reading () {
	init();
	int adc_readingFor;
	int adc_readingLeft;
	int adc_readingRight;

	adc_readingFor = read_analog(0);
	adc_readingLeft = read_analog(1);
	adc_readingRight = read_analog(2);
	if (adc_readingFor>0 && adc_readingFor<256){
		speed = 127;
		motorSpeed(speed);
		sleep1(1,0);
	}
	if (adc_readingFor>255 && adc_readingFor<511){
		speed = 0;
		motorSpeed(speed);
		sleep1(1,0);
	}
	return 0;
}
