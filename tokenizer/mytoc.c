/*Lab1: Tokenizer
  Name: Kristian Villanueva
  Last Modification: 9/10/17
 */
#include "mytoc.h"
#define MAXLINE 1000
int tokenArrLength(char *input, char delim);
int tokenLengths(char* input, char delim);
void fillTokenArr(char *input, char **tokenArr,int currTokenArrIndex,int tokenLengthsArr, char delim);
void printTokenArr(char **tokenArr,int currTokenArrIndex,int tokenLengthsArr);

/*Global index variable used to traverse the user input
  pointer to count token lengths and to copy tokens*/
static int tokenLengthIndex=0;

char ** mytoc(char *str, char delim){
	/*Computes token array length and declares token
	  array with appropriate size*/
	int tArrLength = tokenArrLength(str, delim);
	char **tokenArr = (char **)calloc(tArrLength, sizeof(char *));

	/*Computes individual token lengths*/
	int tokenLengthsArr [tArrLength];
	for(int i =0; i<tArrLength; i++){
		if(i<tArrLength-1){
			tokenLengthsArr[i]=tokenLengths(str,delim)+1;
		}
		if(i==tArrLength-1){
			tokenLengthsArr[i]=1;
		}
	}
	tokenLengthIndex=0;

	/*Allocates space based on lengths of tokens*/
	for(int i=0; i<tArrLength;i++){
		tokenArr[i] = (char *)malloc(tokenLengthsArr[i]);
	}

	/*Copies tokens into appropriate spot in tokenArr*/
	for(int i=0; i<tArrLength-1;i++){
		fillTokenArr(str, tokenArr,i,tokenLengthsArr[i],delim);
	}
	/*Sets final indices to null character*/
	tokenArr[tArrLength-1][tokenLengthsArr[tArrLength-1]]=(char*)0;
	tokenLengthIndex=0;

	/*Prints out contents of tokenArr*/
	for(int i=0; i<tArrLength;i++){
		printTokenArr(tokenArr,i,tokenLengthsArr[i]);
	}

	return tokenArr;
}

/*Traverses the user input pointer and counts the number of tokens based on
  the delimiter specified(in this case a space)*/
int tokenArrLength(char *input, char delim){
	int counter = 0;
	int checkNewWord=0;
	for(int i =0; i<MAXLINE && input[i]!='\n'; i++){
		if(checkNewWord==0 && input[i] != delim){
			counter++;
			checkNewWord=1;
		}
		else if(checkNewWord==1 && input[i]==delim){
			checkNewWord=0;
		}
	}
	counter++;
	return counter;
}

/*Uses tokenLengthIndex to count individual token lengths*/
int tokenLengths(char* input, char delim){
	int counter = 0;
	int checkNewWord=0;
	for(; tokenLengthIndex<MAXLINE && input[tokenLengthIndex]!='\n'; tokenLengthIndex++){
		if(checkNewWord==0 && input[tokenLengthIndex] != delim){
			counter++;
			checkNewWord=1;
		}
		else if(checkNewWord==1 && input[tokenLengthIndex] != delim){
			counter++;
		}
		else if(checkNewWord==0 && input[tokenLengthIndex] == delim){
		}
		else if(checkNewWord==0 && input[tokenLengthIndex] == delim){
			tokenLengthIndex++;
		}
		else if(checkNewWord==1 && input[tokenLengthIndex]==delim){
			checkNewWord=0;
			tokenLengthIndex++;
			return counter;
		}
		else if(input[tokenLengthIndex+1]=='\n'){
			checkNewWord=0;
			counter++;
			tokenLengthIndex++;
			return counter;
		}
		else{
			counter++;
			tokenLengthIndex++;
			return counter;
		}
	}
	tokenLengthIndex++;
	return counter;
}

/*Uses tokenLengthIndex and token lengths to copy tokens into individual indices*/
void fillTokenArr(char *input, char **tokenArr,int currTokenArrIndex,int tokenLengthsArr, char delim){
	int checkNewWord=0;
	int currentTokenIndex=0;
	for(; tokenLengthIndex<MAXLINE && input[tokenLengthIndex]!='\n' && currentTokenIndex<tokenLengthsArr-1; tokenLengthIndex++){
		if(checkNewWord==0 && input[tokenLengthIndex] != delim){
			tokenArr[currTokenArrIndex][currentTokenIndex]=input[tokenLengthIndex];
			currentTokenIndex++;
			checkNewWord=1;
		}
		else if(checkNewWord==1 && input[tokenLengthIndex] != delim && currentTokenIndex<tokenLengthsArr){
			tokenArr[currTokenArrIndex][currentTokenIndex]=input[tokenLengthIndex];
			currentTokenIndex++;
		}
		else if(checkNewWord==0 && input[tokenLengthIndex] == delim){
		}
		else if(checkNewWord==0 && input[tokenLengthIndex] == delim){
			tokenLengthIndex++;
		}
		else if(checkNewWord==1 && input[tokenLengthIndex]== delim){
			checkNewWord=0;
			tokenLengthIndex++;
			return;
		}
		else if(input[tokenLengthIndex+1]=='\n' && currentTokenIndex<tokenLengthsArr){
			checkNewWord=0;
			tokenArr[currTokenArrIndex][currentTokenIndex]=input[tokenLengthIndex];
			currentTokenIndex++;
			tokenLengthIndex++;
			return;
		}
		else{
			tokenArr[currTokenArrIndex][currentTokenIndex]=input[tokenLengthIndex];
			currentTokenIndex++;
			tokenLengthIndex++;
			return;
		}
	}
	tokenLengthIndex++;
	tokenArr[currTokenArrIndex][tokenLengthsArr-1]='\0';
	return;
}

/*Prints tokenArr before returning tokenArr to main*/
void printTokenArr(char **tokenArr,int currTokenArrIndex,int tokenLengthsArr){
	for(int i=0; i<tokenLengthsArr; i++){
		printf("%c",tokenArr[currTokenArrIndex][i]);
	}
	printf("\n");
}
