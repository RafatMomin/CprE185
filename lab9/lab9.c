// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s) ;

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	wordCount = readWords(wordlist, argv[1]);

	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		// add code to print the words to the screen here for part 1 
		}
	for (i = 0; i < wordCount; i++) {
		printf("%s\n", wordlist[i]);
	}
// most of your code for part 2 goes here. Don't forget to include the ncurses library 

    return 0;
	}
int readWords(char* wl[MAXWORDS], char* filename) {
	FILE* wFile = fopen(filename, "r");
	char currWord[WORDLEN];
	int wordCount = 0;
	do {
		fscanf(wFile, "%s", currWord);
		trimws(currWord);

		wl[wordCount] = malloc(strlen(currWord) * sizeof(char) + 1);
		strcpy(wl[wordCount], currWord);
		
		++wordCount;
	} while (!feof(wFile));
	return wordCount;

	//fgets(*wl, MAXWORDS, wFile);
}
void trimws(char* s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (isspace(s[i])) {
			s[i] = '\0';
		}
	}
}
