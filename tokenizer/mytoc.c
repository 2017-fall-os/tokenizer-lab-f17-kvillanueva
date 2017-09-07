/*
 * mytoc.c
 *
 *  Created on: Sep 3, 2017
 *      Author: kvillanueva
 */
#include "mytoc.h"
#define MAXLINE 1000
int tokenArrLength(char input []);
int tokenArrLength(char* input);
char ** fillTokenArr(char *input, char *tokenArr, int tArrLength,int tokenLengthsArr []);
char * fillTokens(int tokenSize, char* input);

static int tokenLengthIndex=0;
static int inputIndex=0;

char ** mytoc(char *str, char delim){
	/*Computes token array length and declares token
	  array with appropriate size*/
	int tArrLength = tokenArrLength(str);
	char tokenArr[tArrLength];
	char *pointToTokenArr = &tokenArr;

	/*Computes token lengths*/
	int tokenLengthsArr [tArrLength];
	for(int i =0; i<tArrLength; i++){
		if(i<tArrLength-1){
			tokenLengthsArr[i]=tokenLengths(str);
		}
		if(i==tArrLength-1){
			tokenLengthsArr[i]=1;
		}
	}
	tokenLengthIndex=0;
	//	for(int i =0; i<tArrLength; i++){
	//		printf("%d| %d : %d \n",tArrLength,	i, tokenLengthsArr[i]);
	//	}


	fillTokenArr(str, pointToTokenArr,tArrLength,tokenLengthsArr);

	return 'a';
}

int tokenArrLength(char input []){
	int counter = 0;
	int checkNewWord=0;
	for(int i =0; i<MAXLINE && input[i]!='\n'; i++){
		if(checkNewWord==0 && input[i] != ' '){
			counter++;
			checkNewWord=1;
		}
		else if(checkNewWord==1 && input[i]==' '){
			checkNewWord=0;
		}
	}
	counter++;
	//	printf("%d \n",counter);
	return counter;
}


int tokenLengths(char* input){
	//	printf("%d \n", tArrLength);
	int counter = 0;
	int checkNewWord=0;
	for(; tokenLengthIndex<MAXLINE && input[tokenLengthIndex]!='\n'; tokenLengthIndex++){
		if(checkNewWord==0 && input[tokenLengthIndex] != ' '){
			counter++;
			checkNewWord=1;
			//			printf("1 %d| %d: %s \n",tokenLengthIndex,counter, &input[tokenLengthIndex]);
		}
		else if(checkNewWord==1 && input[tokenLengthIndex] != ' '){
			counter++;
			//			printf("2 %d| %d: %s \n",tokenLengthIndex,counter, &input[tokenLengthIndex]);
		}
		else if(checkNewWord==0 && input[tokenLengthIndex] == ' '){
			//			printf("3 %d| %d: %s \n",tokenLengthIndex,counter, &input[tokenLengthIndex]);
		}
		else if(checkNewWord==0 && input[tokenLengthIndex] == ' '){
			tokenLengthIndex++;
			//			printf("4 %d| %d: %s \n",tokenLengthIndex,counter, &input[tokenLengthIndex]);
		}
		else if(checkNewWord==1 && input[tokenLengthIndex]==' '){
			checkNewWord=0;
			//			printf("5 %d| %d: %s \n",tokenLengthIndex,counter, &input[tokenLengthIndex]);
			tokenLengthIndex++;
			return counter;
		}
		else if(input[tokenLengthIndex+1]=='\n'){
			checkNewWord=0;
			counter++;
			//			printf("6 %d| %d: %s \n",tokenLengthIndex,counter, &input[tokenLengthIndex]);
			tokenLengthIndex++;
			return counter;
		}
		else{
			counter++;
			//			printf("7 %d| %d: %s \n",tokenLengthIndex,counter, &input[tokenLengthIndex]);
			tokenLengthIndex++;
			return counter;
		}
	}
	//	printf("8 %d| %d: %s \n",tokenLengthIndex,counter, &input[tokenLengthIndex]);
	tokenLengthIndex++;
	return counter;
}

char ** fillTokenArr(char *input, char *tokenArr, int tArrLength,int tokenLengthsArr []){
	for(int i =0; i<tArrLength; i++){
		printf("%d : %d \n",i, tokenLengthsArr[i]);
		//		tokenArr[i]=fillTokens(tokenSizes[i], input);
		//		printf(tokenArr[i]);
	}
	inputIndex = 0;
	return 'a';
}

char * fillTokens(int tokenSize, char* input){
	int checkNewWord=0;
	int tokenIndex=0;
	char tokens[tokenSize];
	for(; inputIndex<MAXLINE && input[inputIndex]!='\n'; inputIndex){
		if(tokenIndex == tokenSize-1){
			return *tokens;
		}
		else if(checkNewWord==0 && input[inputIndex] != ' '){
			checkNewWord=1;
			tokens[tokenIndex];
			tokenIndex++;
		}
		else if(checkNewWord==1 && input[inputIndex] != ' '){
			tokens[tokenIndex];
			tokenIndex++;
		}
	}
	return 'a';
}
