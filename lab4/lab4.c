/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


double mag(double ax, double ay, double az);
int minutes(int t);
int seconds(int t);
int millis(int t);
int close_to (double tolerance, double point, double value);	                         




int main(void) {
    

	
	int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;


    while (1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );

        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
        printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);

         /*It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program.*/
		 //printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay,az));
		   
return 0;
    }
}




      
    

    

/* Put your functions here */
int close_to (double tolerance, double point, double value){
	if(point - tolerance<value&&point+tolerance>value){
return 1;	
	}
	else{
		return 0;
	}

}