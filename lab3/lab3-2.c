/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */
int numButtons(int triangle, int circle, int x, int square);

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int triangle, circle, x, square;
       


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
      
        scanf(" %d, %d, %d, %d", &triangle, &circle, &x, &square);
        int result = numButtons(triangle, circle, x, square);
            printf("%d\n", result);
            fflush(stdout);
    }

return 0;
}

/* Put your functions here */

int numButtons(int triangle, int circle, int x, int square) {
   int result = triangle + circle + x + square;
    return result;
}
