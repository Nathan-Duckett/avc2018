#include "header.h"

/**
 * This file will take the pictures from the camera and record and 
 * return the valeus to adjust the speed and direction of the robot 
 */
 
int camera_read () {
	take_picture();
	int min = 256;
	int max = 0;
	int[] pixels = [];
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

	int blackValue = average + constantDiff;
	int whiteValue = average - constantDiff;

	if (average + constantDiff >= 235) {
		blackValue = 235;
	}
	
	

	return 0;
}
