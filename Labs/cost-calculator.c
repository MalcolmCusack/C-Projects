#include <stdio.h>

//---------------------
// Malcolm Cusack
// Lab 2, CSCI 112
// 2/9/2020
// --------------------

// A program to calculate someones total cost from a music store
// If this person is a teach they get a 10% discount.
// If the teacher's total is $100 or above they receive a 12% discount.

// Decleration of the sales tax function
double salesTax(double tax, double cost);

int main(void) {

	// variables
	double cost = 0, discount = 0, tax = .05, teachersDiscount = .10, total = 0;
	char flag;

	// User questions and inputs
	printf("Enter the cost of your items: \n");
	//scanf("%lf", &cost);

	printf("Are you a music teacher (y or n): \n");
	scanf("%lf %c",&cost, &flag);
	
	// if statements determining if the user is a teach and
	// if the total amount is over $100
	if ((flag == 'y') || (flag == 'Y')) {
		if (cost >= 100) {

			// All print statements for this case as well as
			// mathematical operations determining the total.
			// Each if statement is a little different.

			discount = (cost * (teachersDiscount + .02));
			printf("Total purchases\t\t\t\t$%.2lf\n", cost);
			printf("Teacher's discount (12%%)\t\t$%.2lf\n", discount);
			total = cost - discount;
			printf("Discounted total\t\t\t$%.2lf\n", total);
			printf("Sales tax (5%%)\t\t\t\t$%.2lf\n", salesTax(tax, total));
			total = total + salesTax(tax, total);
			printf("Total\t\t\t\t\t$%.2lf\n", total);
		}
		else {
			discount = (cost * teachersDiscount);
                        printf("Total purchases\t\t\t\t$%.2lf\n", cost);
                        printf("Teacher's discount (10%%)\t\t$%.2lf\n", discount);
                        total = cost - discount;
                        printf("Discounted total\t\t\t$%.2lf\n", total);
                        printf("Sales tax (5%%)\t\t\t\t$%.2lf\n", salesTax(tax, total));
                        total = total + salesTax(tax, total);
                        printf("Total\t\t\t\t\t$%.2lf\n", total);
		};
	
	} else if ((flag == 'n') || (flag == 'N')) {
		printf("Total purchases\t\t\t\t$%.2lf\n", cost);
		printf("Sales tax (5%%)\t\t\t\t$%.2lf\n", salesTax(tax, cost));
		cost = cost + salesTax(tax, cost);
                printf("Total\t\t\t\t\t$%.2lf\n", cost);
	} else {
		printf("Enter (y or n) for your answer\n");
	};

return (0);
}

// Sales Tax function. Determining the tax on an item.
double salesTax(double tax, double cost) {
	double totalTax = 0;

	totalTax = tax * cost;
	return totalTax;
}

