#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// Calculates the letter grade from the numerial grade. Checks to see if the grade can be curved up if within 0.5

void CalculateLetterGrade(Node_t** head) {

	// creates an array of stucts containing what numerical grade determines letter grade	
   	Grade_t grades[11] = { {"A", 93.0}, {"A-", 90.0}, {"B+", 87.0},
                           {"B", 83.0}, {"B-", 80.0}, {"C+", 77.0},
                           {"C", 73.0}, {"C-", 70.0}, {"D+", 67.0},
                           {"D", 63.0}, {"D-", 60.0} };

	// creates a current node tracker
	// Then loops through the linked list
    	Node_t* cur = *head;
     	while (cur != NULL) {
	
	// Loops though the array of grades
	for (int j = 0; j < 11; ++j) {

            // this if is for determining letter grade
       		 if (cur->stu->grade >= (grades[j].lower_limit - 0.5)) {

                strcpy(cur->stu->letter, grades[j].letter);

                // this if is for determining if it hit that letter
                // grade because it was curved (within the .5 of the
                // lower limit
                if (cur->stu->grade < (grades[j].lower_limit)) {
                    cur->stu->curved = 'y';
                }
                else {
                    cur->stu->curved = 'n';
                }
                break;
            }
        }
	// moves to the next node
	cur = cur->next;
    }
    return;
}

