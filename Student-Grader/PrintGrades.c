#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

// Prints First, last, numerical grade, letter grade, and if curved to a file called Student-Grades

void PrintGrades(Student_t class[], int size) {
	
	// Opens file
        FILE *outp = fopen("Student-Grades.txt", "w");
	
	// Checks for existence
        if (outp == NULL) {
                 printf("Error");
                 exit(-1);
        }
	
	// Prints each student
        for(int i=0; i<size; i++) {
                fprintf(outp, "Name: %s %s\tGrade: %.4lf %s\tCurved? %c\n", class[i].first, class[i].last, class[i].grade, class[i].letter, class[i].curved);
        }

	// Closes file
        fclose(outp);
}

