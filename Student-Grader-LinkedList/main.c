#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "student.h"

// main file

int main() {

	// opens the grade file
	FILE *inp = fopen("/public/examples/pgm1/grades.txt", "r");
	// Creates the head of the linked list
	Node_t* head = NULL;

	//checks if the file exsists
	if (inp == NULL) {
                 printf("Error");
                 exit(-1);
        }
	
	// calls the function that reads in data from the file and stores into the student struct
	ReadGrades(inp, &head);
	
	// Function that sorts the grades using selection sort from highest to lowest	
	SortGrades(&head);

	// claculates the letter grade from a number grade, curves grade if needed
	CalculateLetterGrade(&head);
	
	// prints the names, grades, letter grades and if curved to a file
	PrintGrades(&head);

	// closes the file
	fclose(inp);	
	return(0);
}
