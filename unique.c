/*
 *- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *|				Unique				|
 *|			Author: Kyle Krueger			|
 *|			Course: CS 420 Spring 2023		|
 *|			--------------------------		|
 *|			Input: 		stdin			|
 *|			Output:		stdout			|
 *|			Arguments:	none			|
 *|			Return:		0 on completion		|
 *|			Imports:	stdio.h			|
 *- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 *| DESIGN DECISIONS:						|
 *|		I chose to include punctuation as a character	|
 *|		IE: "this" and "this." will each print 		|
 *|								|
 *|		If not reading from a file, the user can escape	|
 *|		by hitting the EOT button (CTRL + D)		|
 *- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
 
#include <stdio.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_TOKENS 100

//Implementing a function to compare two strings
int compareString(const char *s1, const char *s2);
//Implementing a function to copy one string to another
void copyString(char *out, const char *in);

int main(int argc, char *argv[])
{
	//DECLARATIONS
	char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
	char buffer[MAX_TOKEN_LENGTH];
	int tokenCount = 0;
	int isUnique = 0;
	int i;

	printf("|-UNIQUE Running, If using a keyboard as stdin, please hit CTRL+D to end input-|\n");
	//Populate the tokens
	// 1.Check if the buffer exists in the token array
	// 2.If unique, add to the next available token
	// 3.After populating array, print out all the unique tokens
	while(scanf("%s",buffer) == 1){
		//Step 1
		isUnique = 1;
		for (i = 0; i <tokenCount; i++){
			if (compareString(tokens[i], buffer) == 0){
				isUnique = 0;
				break;
			}
		}
		//Step 2
		if (isUnique == 1){
			copyString(tokens[tokenCount], buffer);
			tokenCount++;
		}

		//Checking for token limit
		if (tokenCount == MAX_TOKENS){
			printf("ERROR: Max Tokens Reached\n");
			return -1;
		}
	}
	//Outputting the tokens, seperated by a space
	for (i = 0; i <tokenCount; i++){
		printf("%s ",tokens[i]);
	}
	return 0;
}

int compareString(const char *s1, const char *s2){
	int matchedChars = 0;
	//While there is a character at the pointer, and while the two character match
	
	while (*s1 && (*s1 == *s2)){
		s1++;
		s2++;
		
	}

	//compare the characters at the end, they should match and return a 0 if the strings are the same. Non 0 if they are different
	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void copyString(char *out, const char *in){
	//Simple while loop to copy the contents of the in array into the out array
	while ((*out++ = *in++));
}
