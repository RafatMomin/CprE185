
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define TRUE 1

/*Hey! This is Brianna Norman (Peer Mentor, I was working with Rafat this afternoon(10/6) and we cannot find the error
* listed by the compiler, and this program compiles in other compilers besides cygwin without error.
*/

double mag(double ax, double ay, double az);
int close_to(double tolerance, double point, double value);
double distance(double time);
const double g = 9.8;

int main(void) {

	int t;
	int count;
    double gx, gy, gz, starting_time, landing_time, temp_t, t_diff, v, x, time;
	char period = '.';
	char ex = '!';

	printf("<Rafat> <Momin>\n");
	printf("<593070532>\n");
	scanf("%d,%lf,%lf,%lf", &t,&gx,&gy,&gz);
    if(t>0){
   printf("Ok, I'm now receiving data.\n\n");
   }
   printf("I'm waiting");

while(close_to(0.25, 1, mag(gx, gy, gz) != 1)){
scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
 if(close_to( 0.25, 1, mag(gx, gy, gz) != 1)){
 if((count % 10) == 0){
 printf("%c", period);
 }
 }

fflush(stdout);
 ++count; 


		if(close_to( 0.50, 1, mag(gx, gy, gz)) != 1) {
			starting_time = t / 1000.0;
			//printf("\n%d\n", t);
			break;
		}
	}

	printf("\nHelp me! I'm falling");

	while(1) {
		scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
		if (close_to(0.1, 1, mag(gx, gy, gz)) == 1) {
			if ((count % 10) == 1) {
				//printf("%c", ex);
			}
		}
		fflush(stdout);
		++count;
		if(mag(gx, gy, gz) > 2) {
			landing_time = t / 1000.0;
			//printf("\n%d\n", t);
			break;
		}

		/*t_diff = (t - temp_t) / 1000.0;

		v = v + g * (1 - mag(gx, gy, gz)) * t_diff;
		x = x + (v) * t_diff;

		temp_t = t;*/
	}

	time = (landing_time - starting_time);
	printf("\nOuch! I fell %.3lf meters in %.3lf seconds.\n", distance(time), time);


	return 0;

}


/* Put your functions here */


double mag(double ax, double ay, double az){
double y = sqrt(ax*ax + ay*ay + az*az);
return y;
}
int close_to(double tolerance, double point, double value){
if(value>0){
if(sqrt((value-point)*(value-point))<(tolerance)){
return 1;
}
else{
return 0;
}
}
else{

if(sqrt((value+point)*(value+point))<(tolerance))
return 2;
}
}
double distance(double time){
	return ( 0.5 * g * (time * time));
}

