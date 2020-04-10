#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//---------------------
// Malcolm Cusack
// Lab 3, CSCI 112
// 2/13/2020
// --------------------

// declaration of my function, including multiple pointer returns
void statsOfRandom(long int n, long int ul, int* smallest, int* largest, double* average, double* strDev);

int main(void) {

//variables
long int n, ul;
int smallest, largest;
double average, strDev;

//User questions and scanning in of their answers.
printf("Enter the number of numbers you to randomly generate\n");
scanf("%ld", &n);
printf("Enter the upper limit of those numbers (1 - upperlimit)\n");
scanf("%ld", &ul);

//Calling the stats function, using the pointer's addresses.
statsOfRandom(n, ul, &smallest, &largest, &average, &strDev);

//outputting my answers.
printf("Smallest random number:\t\t\t\t\t%d\n", smallest);
printf("Largest random number:\t\t\t\t\t%d\n", largest);
printf("Average of the random numbers:\t\t\t\t%.2lf\n", average);
printf("The Standard Deviation of the random numbers:\t\t%.2lf\n", strDev);

return (0);
}

void statsOfRandom(long int n, long int ul, int* smallest, int* largest, double* average, double* strDev) {

	//creating my array and sumSquared variable.
	long int sumSquared = 0;
	int numArray[n];

	// Setting my rand() generater seed to zero so that I get new resaults everytime I run.
	srand(time(NULL));
  
	// Setting my smallest and largest variable's to later be set.
	*smallest = 100;
        *largest = 0;

        for (int i = 0; i < n; i++) {

       		//generatiing random numbers
		numArray[i] = (rand() % ul) + 1;
		//claculating sum squared
		sumSquared = sumSquared + ( numArray[i] * numArray[i]);
		//calculating average
		*average = *average +  numArray[i];
		
		// finding the smallest and largest numbers in the array of randoms.
                if (*smallest > numArray[i]) {
                        *smallest = numArray[i];
                }
                if (*largest < numArray[i]) {
                        *largest = numArray[i];
                }
	
        }
     	
	//final calculation for average
	*average /= (double) n;
	
	//final calculation fro standard diviation
	*strDev = sqrt(((double) sumSquared / (double) n) - pow(*average, 2));

}
