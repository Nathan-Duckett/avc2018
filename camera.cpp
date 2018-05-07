#include "header.h"

/**
 * This file will take the pictures from the camera and record and 
 * return the valeus to adjust the speed and direction of the robot 
 */
 
int camera_read () {
	take_picture();
	int min = 256;
	int max = 0;
	int pixels[320];
	for (int i = 0; i < 320; i++){
		int pixel = get_pixel(i, 120, 3);
		pixels[i] = pixel;
	}

	for (int i = 0; i < 320; i++ ) {
		if (pixels[i] > max) {
			max = pixels[i];
		}
		if (pixels[i] < min) {
			min = pixels[i];
		}
	}
	int average = (max - min) / 2;
	int constantDiff = 30;

	int whiteValue = average + constantDiff;
	int blackValue = average - constantDiff;

	if (average + constantDiff >= 235) {
		whiteValue = 235;
	}
	
	int pointValues[320];

	for (int i = -160; i < 160; i++) {
		pointValues[i + 160] = i;
	}	

	float sum = 0;

	for (int i = 0; i < 320; i++) {
		int weight = pointValues[i];
		int color = pixels[i];
		if (color > whiteValue) {
			color = 200;
		} 
		if (color < blackValue) {
			color = 100;
		}
		sum += color * weight;
	}

	return sum;
}
