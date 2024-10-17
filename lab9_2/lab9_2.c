// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0  // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s) ;
void draw_character(int x, int y, char use);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	wordCount = readWords(wordlist, argv[1]);
	initscr();
	refresh();

	if (DEBUG) {
		printf("Read %d words from %s \n", wordCount, argv[1]);
		// add code to print the words to the screen here for part 1 
		for (i = 0; i < wordCount; i++) {
		printf("%s\n", wordlist[i]);
	}
	}
	
	// most of your code for part 2 goes here. Don't forget to include the ncurses library 

	int xval = 0;
	int yval = 0;
	//int track = 0;
	
	for (i = 0; i < wordCount; i++) {
		//mvprintw(20, 25, " %s", wordlist[i]);
		mvprintw(yval, xval, " %s", wordlist[i]);
		refresh();
		xval = xval + 15; 
		//track++;
		if (xval >= 75) {
			yval++;
			xval =0;
			//track = 0;
		}
	}

	int rowCount = wordCount / 5;
	if (wordCount % rowCount != 0) rowCount++;

	int time, jDown, jUp, jLeft, jRight, j5, j6, j7, j8;
	int a1, a2, a3, a4, a5, a6, a7, a8;
	int curX = 0, curY = 0;
	int prevX = 0;
	int prevY = 0;
	int moveTime = 0;
	int lengthOflast = 0;
	int lengthOfSentence = 0;
	int capitalizeNext = 0;
	do {
		scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &time, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &jDown, &jUp, &jLeft, &jRight, &j5, &j6, &j7, &j8);
		if (time - moveTime < 300) {
			continue;
		}
		draw_character(prevX, prevY, ' ');
		if (jDown && curY < rowCount - 1) {
			curY++;
		}
		else if (jUp && curY > 0) {
			curY--;
		}
		if (jRight && curX < 60) {
			curX = curX + 15;
		}
		else if (jLeft && curX > 0) {
			curX -= 15;
		}
	} while (1);
	moveTime = time;

	prevX = curX;
	prevY = curY;
	draw_character(curX, curY, '-' );
	if (a2) {
		int indexToUse = curY * 5 + curX / 15;
		lengthOflast = strlen(wordlist[indexToUse]) + 1;
		char toADD[12];
		strcpy(toADD, wordlist[indexToUse]) + 1;
		if (capitalizeNext) {
			toADD[0] -= 0x20;
		}
		mvprintw(rowCount + 2, lengthOfSentence, " %s", toADD);
		lengthOfSentence += lengthOflast;
	}
	else if (a3) {
		int indexToUse = curY * 5 + curX / 15;
		lengthOflast = strlen(wordlist[indexToUse]) + 1;
		char toADD[12];
		strcpy(toADD, wordlist[indexToUse]);
		if (capitalizeNext) {
			toADD[0] -= 0x20;
		}
		mvprintw(rowCount + 2, lengthOfSentence, " %s", toADD);
		lengthOfSentence += lengthOflast;
	}
	else if (a4) {
		if (capitalizeNext) {
			capitalizeNext = 0;
			mvprintw(rowCount + 1, 0, "    ");
		}
		else {
			capitalizeNext = 0;
			mvprintw(rowCount + 1, 0, "CAP");
		}
	}
	else if (a1) {
		int indexToUse = curY * 5 + curX / 15;
		lengthOfSentence -= lengthOflast;
		mvprintw(rowCount + 2, lengthOfSentence, "               ");
		DEBUG;
	}
}
void trimws(char* s) {
	int len = strlen(s);
	int x;
	if (len == 0) return;
	x = len - 1;
	while (isspace(s[x] && (x > -0))) {
		s[x] = '\0';
		x--;
	}
}
int readWords(char* wl[MAXWORDS], char* filename) {
	int numread = 0;
	char line[WORDLEN];
	char* p;
	FILE* fp = fopen(filename, "r");
	while (!feof(fp)) {
		//p = fgets(line, WORDLEN, fp);
		fscanf(fp, "%s", line);
		if (!feof(fp)) {
			trimws(line);
			wl[numread] = (char*)malloc(strlen(line) + 1);
			strcpy(wl[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}
void draw_character(int x, int y, char use) {
	mvaddch(y, x, use);
	refresh();
}