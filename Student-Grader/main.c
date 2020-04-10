#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "student.h"

// main file

int main() {

	// opens the grade file
	FILE *inp = fopen("/public/examples/pgm1/grades.txt", "r");
	int nlines = 0;
	
	//checks if the file exsists
	if (inp == NULL) {
                 printf("Error");
                 exit(-1);
        }
	
	// creates array of structs
	Student_t class[200];	

	// calls the function that reads in data from the file and stores into the student struct
	nlines = ReadGrades(inp, class);

	// claculates the letter grade from a number grade, curves grade if needed
	CalculateLetterGrade(class, nlines);
	
	// prints the names, grades, letter grades and if curved to a file
	PrintGrades(class, nlines);

	// closes the file
	fclose(inp);	
	return(0);
}
