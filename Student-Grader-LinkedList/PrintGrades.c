#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

// Prints First, last, numerical grade, letter grade, and if curved to a file called Student-Grades

void PrintGrades(Node_t** head) {
	
	// Opens file
        FILE *outp = fopen("Student-Grades.txt", "w");
	
	// Checks for existence
        if (outp == NULL) {
                 printf("Error");
                 exit(-1);
        }
	
	// Creates a node tracker	
	Node_t* cur = *head;	
	// Prints each student
        while (cur != NULL) {
                fprintf(outp, "Name: %s %s\tGrade: %.4lf %s\tCurved? %c\n", cur->stu->first, cur->stu->last, cur->stu->grade, cur->stu->letter, cur->stu->curved);
		
		// moves to the next node
		cur = cur->next;
        }

	// Closes file
        fclose(outp);
}

