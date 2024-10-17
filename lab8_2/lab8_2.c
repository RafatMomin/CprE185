
// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
// Updated for Esplora 2013 TeamRursch185
// Updated for DualShock 4 2016 Rursch


// Headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLS for the screen height and width (set by system)
// MAXIMUMS
#define NUMCOLS 100
#define NUMROWS 72

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '
#define LEFT -1
#define RIGHT 1
#define NONE 0


// 2D character array which the maze is mapped into
char MAZE[NUMROWS][NUMCOLS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty);

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < x_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the roll function written in previous labs.  
float calc_roll(float x_mag);

// Main - Run with './ds4rd.exe -t -g -b' piped into STDIN

int close_to(double tolerance, double point, double value);
	
int main(int argc, char* argv[])
{
	
	if (argc <2) { 
		printf("You forgot the difficulty\n"); 
		return 1;
	}
	int difficulty = atoi(argv[1]); // get difficulty from first command line arg
	// setup screen   
	
	initscr();
	refresh();

	// Generate and draw the maze, with initial avatar

	// Read gyroscope data to get ready for using moving averages.    
	int prev_t = 0;
	int t;
	int move_dir = NONE;
	double gx, gy, gz;
	bool start, loser, motion;
	scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
	int  y = 0;
	int x = 50;
	generate_maze(difficulty);
	draw_maze();
	draw_character(x, y, AVATAR);
	int t2 = 0;
	// Event loop
	do
	{

		// Read data, update average
		scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
		// Is it time to move?  if so, then move avatar
		
		if (t - t2 > 100) {
			t2 = t;
			prev_t = t;	
			if ((calc_roll(gx) < -.65) && (x > 0) && MAZE[x+1][y] != WALL) {
				
				draw_character(x++, y, EMPTY_SPACE);
				draw_character(x, y, AVATAR);

			}
			else if ((calc_roll(gx) > .65) && (x + 1 < NUMCOLS) && MAZE[x - 1][y] != WALL) {
				
				draw_character(x--, y, EMPTY_SPACE);
				draw_character(x, y, AVATAR);

			}
			else if ((MAZE[y + 1][x] != WALL)) {
				y++;
draw_character(x, y, AVATAR);
				draw_character(x, y - 1, EMPTY_SPACE);
				

			}
			//fflush(stdout);
		}

	} while (y < 72); // Change this to end game at right time 
//!loser && y != NUMCOLS - 1
	// Print the win message
	endwin();
	if(loser){
		printf("YOU LOST\n");
	}
	else{
	printf("YOU WIN!\n");
	}
	return 0;
}



// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//
//    >>>>DO NOT CHANGE THIS FUNCTION.<<<<
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}
void generate_maze(int difficulty) {
	
	int i, j, num;
	for (i = 0; i < NUMROWS; i++) {
		for (j = 0; j < NUMCOLS; j++) {
			if (rand() % 100 < difficulty) {
				MAZE[i][j] = WALL;
			}
			else{
				MAZE[i][j] = EMPTY_SPACE;
			}
			

		}
	}
}
void draw_maze(void) {
	int i, z;
	for (i = 0; i < NUMROWS; i++) {
		for (z = 0; z < NUMCOLS; z++) {
			draw_character(i,z,  MAZE[i][z]);
		}
		
	}
}

float calc_roll(float x_mag) {
	
	if (x_mag <= -1) {
		x_mag = -1;
	}
	else if (x_mag >= 1) {
		x_mag = 1;
	}
	
	return x_mag;
}
