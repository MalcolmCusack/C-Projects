#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

// This file reads in student data from a file and stores it into an linked list of 
// staruatures called Node_t
void ReadGrades(FILE *inp, Node_t** head) {

	// variables needed
        char data[200];
        const char d[5] = ","; //used for cutting up the string of data in each line of the file
        char* result; //Stores what's in that string

	//Loops through the file
        while(fgets(data, 500, inp) != NULL) {
		
		// creates memory for the student object
		Student_t* stu = malloc(sizeof(Student_t));
		// Stores the different data seperated by a comma into their variables
                result = strtok(data, d); // splcies
                strcpy(stu->last, result); //stores
                result = strtok(NULL, d);
                strcpy(stu->first, result);
                result = strtok(NULL, d);
                sscanf(result, "%lf", &stu->grade); //converts to double
		
		// Function to insert students into the linked list	
		ListInsert(head, stu);

        }
	
        return;
}
