#include "header.h"

/**
 * This file will take the pictures from the camera and record and 
 * return the valeus to adjust the speed and direction of the robot 
 */
 
int camera_read (int image_row) {

	// Variable initilization
	int min = 255; //Stores the minimum recorded value from the image
	int max = 0; //Stores the maximum recorded value from the image
	int pixels[8][40]; //Array of the pixels from a line within the image taken.
	int arrayIndex = 0; //Inner array current position
	int count = 0; //Outer array current position
	bool black = false;
	
	//Take a picture using the raspberry pi camera
	take_picture();
	
	// This Loop will split the image up into the 8 equal sections of 40 pixels each
	for (int i = 0; i < 320; i++){
		//Get the pixel from the image
		int pixel = get_pixel(image_row, i, 3);
		
		if (pixel < min) {
			min = pixel;
		}
		if (pixel > max) {
			max = pixel;
		}

		pixels[arrayIndex][count] = pixel;
		if (count == 40) {
			count = 0; //Resets the inner array counter to 0
			arrayIndex++;
		}
		count++;
	}

	arrayIndex = 0; //Resets the outer array counter to 0
	int pixelSum = 0;
	//This loop determines the maximum and minimum values possible from the picture.
	for (int i = 0; i < 320; i++ ) {
		pixelSum += pixels[arrayIndex][count];
		if (count == 40) {
			count = 0;
			arrayIndex++;
		}
	}


	int average = pixelSum / 320; //Calculates the mid-point average between the maximum and minimum values.

	int whiteValue = (max - min) / 2; //White Value minimum value
	
	if (whiteValue - average < 15) {
		black = true;
	}
	
	int colorValues[8];
	//Sets the section color values
	for (int i = 0; i < 8; i++) {
		bool white = false;
		for (int j = 0; j < 40; j++) {
			if (pixels[i][j] > whiteValue) {
				colorValues[i] = 1;
				white = true;
			}
		}
		if (!white) {
			colorValues[i] = 0;
		}
	}

	//Sets the section weight values
	int pointValues[8];
	for (int i = -4; i < 5; i++) {
		if (i == 0) { i++; }
		if (i < 0 && i > -5) {
			pointValues[i + 4] = i;
		} else if (i > 0 && i < 5) {
			pointValues[i + 3] = i;
		}
	}

	/*Adds up the sum of the weight * color for each section to get the error value
	  Postive means line is to right of centre
	  Negative means line is to the left of centre
	  Zero means the line is in the centre
	*/
	FILE *file;
	file = fopen("data.txt","w");
	
	if (black) {
		fprintf(file,"Image is all black\n");
		fclose(file);
		return -10000;
	} else {
		int sum = 0; // Initialize the sum
		for (int i = 0; i < 8; i++) {
			int weight = pointValues[i];
			int color = colorValues[i];
			sum += color * weight;
		}
		printf("Error value: %d\n", sum);
		fprintf(file,"Error value: %d\n", sum);
		fclose(file);

		return sum;
	}
}

int camera_read_vertical(int image_column) {
	// Variable initilization
	int min = 255; //Stores the minimum recorded value from the image
	int max = 0; //Stores the maximum recorded value from the image
	int pixels[8][30]; //Array of the pixels from a line within the image taken.
	int arrayIndex = 0; //Inner array current position
	int count = 0; //Outer array current position
	bool black = false;
	
	//Take a picture using the raspberry pi camera
	take_picture();
	
	// This Loop will split the image up into the 8 equal sections of 40 pixels each
	for (int i = 0; i < 240; i++){
		//Get the pixel from the image
		int pixel = get_pixel(i, image_column, 3);
		
		if (pixel < min) {
			min = pixel;
		}
		if (pixel > max) {
			max = pixel;
		}

		pixels[arrayIndex][count] = pixel;
		if (count == 30) {
			count = 0; //Resets the inner array counter to 0
			arrayIndex++;
		}
		count++;
	}

	arrayIndex = 0; //Resets the outer array counter to 0
	int pixelSum = 0;
	//This loop determines the maximum and minimum values possible from the picture.
	for (int i = 0; i < 240; i++ ) {
		pixelSum += pixels[arrayIndex][count];
		if (count == 30) {
			count = 0;
			arrayIndex++;
		}
	}


	int average = pixelSum / 320; //Calculates the mid-point average between the maximum and minimum values.

	int whiteValue = (max - min) / 2; //White Value minimum value
	
	if (whiteValue - average < 15) {
		black = true;
	}
	
	int colorValues[8];
	//Sets the section color values
	for (int i = 0; i < 8; i++) {
		bool white = false;
		for (int j = 0; j < 30; j++) {
			if (pixels[i][j] > whiteValue) {
				colorValues[i] = 1;
				white = true;
			}
		}
		if (!white) {
			colorValues[i] = 0;
		}
	}

	//Sets the section weight values
	int pointValues[8];
	for (int i = -4; i < 5; i++) {
		if (i == 0) { i++; }
		if (i < 0 && i > -5) {
			pointValues[i + 4] = i;
		} else if (i > 0 && i < 5) {
			pointValues[i + 3] = i;
		}
	}

	/*Adds up the sum of the weight * color for each section to get the error value
	  Postive means line is to right of centre
	  Negative means line is to the left of centre
	  Zero means the line is in the centre
	*/
	FILE *file;
	file = fopen("data.txt","w");
	
	if (black) {
		fprintf(file,"Image is all black\n");
		fclose(file);
		return -10000;
	} else {
		int sum = 0; // Initialize the sum
		for (int i = 0; i < 8; i++) {
			int weight = pointValues[i];
			int color = colorValues[i];
			sum += color * weight;
		}
		printf("Error value: %d\n", sum);
		fprintf(file,"Error value: %d\n", sum);
		fclose(file);

		return sum;
	}
}
}
