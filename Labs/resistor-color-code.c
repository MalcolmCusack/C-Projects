#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Function that compares the hard coded colors strings to the users inputed string.
int search(char[][7], int, char[]); 

int main(void) {

	// variables
	double KO = 0;
	char answer = 'y';
	int I1, I2, I3, digits;	
	char band1[7], band2[7], band3[7], sI1[7], sI2[7];
	char colors[10][7] = {"black", "brown", "red", "orange", "yellow", 
		"green", "blue", "violet", "gray", "white"};
	
	printf("Enter the colors of the resistor's three bands, beginning with\n the band nearest the end. Type the colors in lowercase letters\n only, NO CAPS.\n");
	
	// A loop to determine if the user wants to use decode more resistors
	while (answer == 'y' ||  answer == 'Y') {
		
		// scans in a band string then uses the search function. the functions return is stored in I
		printf("Band 1 => ");
		scanf("%s", band1);
		I1 = search(colors,  10, band1);
			
		// If the previous band is not found this will not run, Same with the next if statement
		if (I1 >= 0) {
			printf("Band 2 => ");
			scanf("%s", band2);
			I2 = search(colors, 10, band2);
		}
		
		if (I2 >= 0) {
			printf("Band 3 => ");
			scanf("%s", band3);
			I3 = search(colors, 10, band3);
		
			// converts the I variable to a string
			sprintf(sI1, "%d", I1);
        		sprintf(sI2, "%d", I2);
			
			// concatenates the two strings to form a sigle digit
			strcat(sI1, sI2);
			
			// converts the string digit to a int.
			digits = atoi(sI1);
			
			// calculates the resistence.
			KO = digits * pow( 10.0,(double) I3);

			printf("Resistence Value: %0.1lf kilo-ohms\n", KO);
		}

		printf("Do you want to decode another resistor? (y / n)\n");
		printf(" => ");
		
		// This loop checks if the user has entered a valid input.
		do {
		scanf(" %c", &answer);	
			if (answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N') {
				printf("Bad answer, try again\n");
				printf("Do you want to decode another resistor? \n");
				printf( " => ");
				
			}
		} while (answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N');

	}

	return 0;
}

int search (char colors[][7], int size, char band[]) {

	// compares the band string to array of color strings then returns the index of that color.
	// If the color is invalid retruns -1.
	for (int i=0; i<size; i++) {
		if (strcmp(band, colors[i]) == 0) {
			return i;
		}
	}
	printf("Invalid color: %s\n", band);
	return -1;
}
