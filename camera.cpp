#include "header.h"

/**
 * This file will take the pictures from the camera and record and 
 * return the valeus to adjust the speed and direction of the robot 
 */
 
int camera_read () {
	take_picture();
	int min = 255;
	int max = 0;
	int pixels[8][40];
	int count = 0;
	int arrayIndex = 0;
	for (int i = 0; i < 320; i++){
		int pixel = get_pixel(120, i, 3);
		pixels[arrayIndex][count] = pixel;
		if (count == 40) {
			count = 0;
			arrayIndex++;
		}
		count++;
	}
	arrayIndex = 0;
	for (int i = 0; i < 320; i++ ) {
		if (pixels[arrayIndex][count] > max) {
			max = pixels[arrayIndex][count];
		}
		if (pixels[arrayIndex][count] < min) {
			min = pixels[arrayIndex][count];
		}
		if (count == 40) {
			count = 0;
			arrayIndex++;
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

	int sum = 0;

	arrayIndex = 0;
	for (int i = 0; i < 320; i++) {
		int weight = pointValues[i];
		int color = pixels[arrayIndex][count];
		if (color > whiteValue) {
			color = 200;
		} 
		if (color < blackValue) {
			color = 100;
		}
		sum += color * weight;
		if (count == 40) {
			count = 0;
			arrayIndex++;
		}
	}

	return sum;
}
