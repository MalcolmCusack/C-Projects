#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

// This file reads in student data from a file and stores it into an array structure called class
// Returns the size of the array for use in other functions.
int ReadGrades(FILE *inp, Student_t class[]) {

	// variables needed
        char data[200];
        const char d[5] = ","; //used for cutting up the string of data in each line of the file
        char* result; //Stores what's in that string
        int i = 0;

	//Loops through the file
        while(fgets(data, 500, inp) != NULL) {

		// Stores the different data seperated by a comma into their variables
                result = strtok(data, d); // splcies
                strcpy(class[i].last, result); //stores
                result = strtok(NULL, d);
                strcpy(class[i].first, result);
                result = strtok(NULL, d);
                sscanf(result, "%lf", &class[i].grade); //converts to double

                i++;
        }
	
	// returns the size of the array
        return i;

}
