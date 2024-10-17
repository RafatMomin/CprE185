// 185 lab6.c
//
// The DS4 Equalizer


// Please implement the functions given by the prototypes below and


// complete the main function to make the program complete.


// You must implement the functions which are prototyped below exactly


//  as they are requested.


#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C) {

	
	scanf("%d,%lf,%lf,%lf,%d,%d,%d,%d",time,g_x,g_y,g_z,Button_T,Button_X,Button_S,Button_C);

	
	if (*Button_S > 0) {
		return 1;  //1=True
	}
	else {
		return 0; //0=False
	}
}

double roll(double x_mag) {

	
	
	if (x_mag <= -1) {
		return asin(-1);
	}
	if (x_mag >= 1) {
		return   asin(1);
	}
	else {
		return asin(x_mag);
	}
}

double pitch(double y_mag) {
	if (y_mag <= -1) {
		return asin(-1);
	}
	if (y_mag >= 1) {
		return asin(1);
	}
	else {
		return asin(y_mag);
	}
}

int scaleRadsForScreen(double rad) {
	return rad * (2 / PI) * 39.0;
}

void print_chars(int num, char use) {

	for (int count = 0; count < num; ++count) {
		printf("%c",use);
	}
	
}

void graph_line(int number) {

	if (number == 0) {
		print_chars(39, ' ');
		print_chars(1, '0');
		print_chars(1, '\n');
	}
	if (number < 0) {
		print_chars(39, ' ');
		print_chars(-1*number,'l');
		print_chars(1, '\n');
	}
	if (number > 0) {
		print_chars(39 - number, ' ');
		print_chars(number,'r');
		print_chars(1, '\n');
	}
}
int main()
{
double x, y, z;
                            
int b_Triangle, b_X, b_Square, b_Circle, Time, MODE;    
double roll_rad, pitch_rad;                
int scaled_value; 
MODE = 1;

do
{
	read_line(&x, &y, &z, &Time, &b_Triangle, &b_Circle, &b_X, &b_Square);
	roll_rad = roll(x);
	pitch_rad = pitch(y);
	if (b_Triangle == 1) {
		MODE = 1;
	}
	if (b_X == 1) {
		MODE = 0;
	}
	if (MODE == 1) {
		scaled_value = scaleRadsForScreen(roll_rad);
	}
	else if (MODE == 0) {
		scaled_value = scaleRadsForScreen(pitch_rad);
	}
	graph_line(scaled_value);
	fflush(stdout);
}
while (b_Square != 1); 

return 0;
}