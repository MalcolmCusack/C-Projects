#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//--------------------------
// Malcolm Cusack
// Lab 4, CSCI 112
// 2/28/2020
//--------------------------

// get corners takes a 2D array as parameter populates it with x,y coridents of corners
// in a polygon from a file, then returns the size of the array.
int get_corners( double array[][5]);

// Takes the array of x y cords, and the array size. Then it calculates the area of the polygon.
double polygon_area(double array[][5],  int size);

// Takes the array, size of the array and polygon area as parameters, then outputs all the x y cords
// and area of the ploygon they made up.
void output_corners(double array[][5], int size, double area);

int main(void) {
	
	// variables
	double array[20][5];	
	double area = 0;
	int size = 0;
	
	//determineing size, area and outputs the cords and area of the polygon.
	size = get_corners(array);

	area = polygon_area(array, size);

	output_corners(array, size, area);


	return 0;
}	

int get_corners(double array[][5]) {
	
	// variables
	int i = 0, num_items;
	
	// populates the array from a file, also determines how many rows are in the file, then returns that size.
	do {
		num_items = scanf("%lf %lf", &array[i][0], &array[i][1]);
		++i;
	} while (num_items > 0);

	return i;
}

double polygon_area(double array[][5], int size) {

	// variables
	double area = 0;
	
	// uses a for loop to calculate the sumation of (x2 + x1) * (y2 - y1)
	for (int i=0; i<size; i++) {
		area += ((array[i+1][0] + array[i][0]) * (array[i+1][1] - array[i][1]));

	}
	
	// returns the abs of area divided by 2.
	return area = fabs(area) / 2;

}

void output_corners(double array[][5], int size, double area) {
	
	// outputs all the information found besides how many rows are in the file.
	printf("  x\t y\n");
	printf("  -\t -\n");
	
	for (int i=0; i<size; i++) {
		for (int j=0; j<2; j++) {
			printf("%.2lf\t", array[i][j]);
		}
		printf("\n");
	}
	printf("\narea of this polygon is %.2lf\n", area);
}

