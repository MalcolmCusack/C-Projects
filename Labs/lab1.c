#include <stdio.h>

//-----------------------
// Malcolm Cusack
// Lab 1, CSCI 112
// 1/24/2020
//-----------------------

int main(void) {

	// Declairing the variables for this program
	double temp, time, hours, mins;

	// Printing a question then scanning in the answers
	printf("Enter time since power failure in hours and minutes: \n");
	scanf("%lf", &hours);
	scanf("%lf", &mins);

	// Making the time variable by adding hours and converting hours to minuties 
	time = hours + (mins / 60);
	
	// Equation to determine temp in a freezer in celcius after hours since power failure
	temp =((4 * (time * time)) / (time + 2)) - 20;
	
	// Printing out the resualt
	printf("Temperature after power failure for %.2lf hours is %.2lfC\n", time, temp);

return(0);

}
