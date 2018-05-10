#include "header.h"

/**
 * This file will take the pictures from the camera and record and 
 * return the valeus to adjust the speed and direction of the robot 
 */
 
int camera_read () {

	// Variable initilization
	int min = 255; //Stores the minimum recorded value from the image
	int max = 0; //Stores the maximum recorded value from the image
	int pixels[8][40]; //Array of the pixels from a line within the image taken.
	int arrayIndex = 0; //Inner array current position
	int count = 0; //Outer array current position
	
	//Take a picture using the raspberry pi camera
	take_picture();
	
	// This Loop will split the image up into the 8 equal sections of 40 pixels each
	for (int i = 0; i < 320; i++){
		int pixel = get_pixel(120, i, 3);
		pixels[arrayIndex][count] = pixel;
		if (count == 40) {
			count = 0; //Reses the inner array counter to 0
			arrayIndex++;
		}
		count++;
	}

	arrayIndex = 0; //Resets the outer array counter to 0
	
	//This loop determines the maximum and minimum values possible from the picture.
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
	int average = (max - min) / 2; //Calculates the mid-point average between the maximum and minimum values.
	int constantDiff = 30; //Constant value to be added on to the average for calculating ranges.

	int whiteValue = average + constantDiff; //White Value minimum value
	int blackValue = average - constantDiff; //Black Value maximum value

	//Checks if the whiteValue is too high to make sure that the white values are reasonable
	if (average + constantDiff >= 235) {
		whiteValue = 235;
	}
	
	int colorValues[8];
	//Sets the section color values
	for (int i = 0; i < 8; i++) {
		bool white = false;
		for (int j = 0; j < 40; j++) {
			if (pixels[i][j] > whiteValue) {
				colorValues[i] = 200;
				white = true;
			}
		}
		if (!white) {
			colorValues[i] = 100;
		}
	}

	//Sets the section weight values
	int pointValues[8];
	for (int i = -4; i < 4; i++) {
		pointValues[i + 4] = i;
	}

	int sum = 0; // Initialize the sum
	for (int i = 0; i < 8; i++) {
		int weight = pointValues[i];
		int color = colorValues[i];
		sum += color * weight;
		if (count == 40) {
			count = 0;
			arrayIndex++;
		}
	}

	return sum;
}
