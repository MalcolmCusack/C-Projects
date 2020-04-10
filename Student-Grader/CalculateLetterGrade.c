#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// Calculates the letter grade from the numerial grade. Checks to see if the grade can be curved up if within 0.5

void CalculateLetterGrade(Student_t class[], int size) {
	
    Grade_t grades[11] = { {"A", 93.0}, {"A-", 90.0}, {"B+", 87.0},
                           {"B", 83.0}, {"B-", 80.0}, {"C+", 77.0},
                           {"C", 73.0}, {"C-", 70.0}, {"D+", 67.0},
                           {"D", 63.0}, {"D-", 60.0} };

     for (int i = 0; i < size; ++i) {

        for (int j = 0; j < 11; ++j) {

            // this if is for determining letter grade
            if (class[i].grade >= (grades[j].lower_limit - 0.5)) {

                strcpy(class[i].letter, grades[j].letter);

                // this if is for determining if it hit that letter
                // grade because it was curved (within the .5 of the
                // lower limit
                if (class[i].grade < (grades[j].lower_limit)) {
                    class[i].curved = 'y';
                }
                else {
                    class[i].curved = 'n';
                }
                break;
            }
        }
    }
    return;
}