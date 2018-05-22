#include "header.h"

/** 
 * This file takes the recordings from the IR sensors during the 
 * challenge part of the course. These values are returned and used to
 * adjust the various speeds of the robot.
 */

void motorSpeed(int leftSpeed, int rightSpeed){
	set_motor(1,leftSpeed);
	set_motor(2,rightSpeed);
}



int sensor_reading () {
	init();
	int adc_readingFor;
	int adc_readingLeft;
	int adc_readingRight;
	int speed = 0;
	
	adc_readingFor = read_analog(0);
	adc_readingLeft = read_analog(1);
	adc_readingRight = read_analog(2);
	int leftDiff = adc_readingLeft - adc_readingRight;
	int rightDiff = acd_readingRight - adc_readingLeft;
	if (adc_readingFor>0 && adc_readingFor<256){
		speed = 127;
		motorSpeed(speed, speed);
		sleep(0,50000);
	}
	if (adc_readingFor>255 && adc_readingFor<512){
		speed = 0;
		motorSpeed(speed, speed);
		sleep(0,50000);
	}
	if (adc_readingLeft > adc_readingRight && leftDiff < 300){
		speed = 127;
		leftSpeed = 160;
		motorSpeed(leftSpeed, speed);
		sleep(0,50000);
	}
	else if (adc_readingLeft > adc_readingRight && leftDiff > 299){
		speed = -127
		leftSpeed = 127
		motorSpeed(leftSpeed, speed)
		sleep(0,50000);
	}
	if (adc_readingLeft < adc_readingRight && rightDiff < 300){
		speed = 127;
		rightSpeed = 160;
		motorSpeed(speed, rightSpeed);
		sleep(0,50000);
	}
	else if (adc_readingLeft < adc_readingRight && rightDiff > 299){
		speed = -127
		RightSpeed = 127
		motorSpeed(speed, rightSpeed)
		sleep(0,50000);
	return 0;
}
