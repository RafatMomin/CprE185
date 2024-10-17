// 185 Lab 7

#include <stdio.h>
#define MAXPOINTS 10000

// compute the average of the first num_items of buffer

double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array


void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.

void updatebuffer(double buffer[], int length, double new_item);

int main(int argc, char* argv[]) {
	/* DO NOT CHANGE THIS PART OF THE CODE */
	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc > 1) {
		sscanf(argv[1], "%d", &lengthofavg);
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}
	/* PUT YOUR CODE HERE */

	int p = 0;
	int time, Button_T, Button_C, Button_X, Button_S;
	double g_x, g_y, g_z;
	double  max_x, max_y, max_z, min_x, min_y, min_z, avg_x, avg_y, avg_z;
	while (p < lengthofavg) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &time, &g_x, &g_y, &g_z, &Button_T, &Button_C, &Button_X, &Button_S);
		x[p] = g_x;
		y[p] = g_y;
		z[p] = g_z;
		p++;
	}
	while (Button_S != 1) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &time, &g_x, &g_y, &g_z, &Button_T, &Button_C, &Button_X, &Button_S);
		updatebuffer(x, lengthofavg, g_x);
		updatebuffer(y, lengthofavg, g_y);
		updatebuffer(z, lengthofavg, g_z);
			for (p = 0; p < lengthofavg; p++) {

				printf("x = %lf\n", x[p]);
				printf("y = %lf\n", y[p]);
				printf("z = %lf\n", z[p]);
				
				
				
			}


		
		avg_x = avg(x, lengthofavg);
		maxmin(x, lengthofavg, &max_x, &min_x);
		
		avg_y = avg(y, lengthofavg);
		maxmin(y, lengthofavg, &max_y, &min_y);
		
		avg_z = avg(z, lengthofavg);
		maxmin(z, lengthofavg, &max_z, &min_z);
		printf("X max = %lf, X min = %lf, X avg = %lf\n, Y max = %lf, Y min = %lf, Y avg = %lf\n, Z max = %lf, Z min = %lf, Z avg = %lf\n", max_x, min_x, avg_x, max_y, min_y, avg_y, max_z, min_z, avg_z);

		
	}
}
double avg(double buffer[], int num_items) {
	int p = 0;
	double currvalue = 0;
	double sum = 0;
	double average = 0;
	for (p = 0; p < num_items; p++) {
		currvalue = buffer[p];
		sum = sum + currvalue;
	}
	average = sum / num_items;
	return average;
	}
void maxmin(double array[], int num_items, double* max, double* min) {
	int p = 0;
	double pre_max = array[0];
	double pre_min = array[0];
	for (p = 0; p < num_items; p++) {
		if (array[p] > pre_max) {
			pre_max = array[p];
		}
		if (array[p] < pre_min) {
			pre_min = array[p];
		}
	}
	*max = pre_max;
	*min = pre_min;

}
void updatebuffer(double buffer[], int length, double new_item) {
	int p = 0;
	for (p = 1; p < length; ++p) {
		buffer[p - 1] = buffer[p];
		
	}
	buffer[length - 1] = new_item;
}


