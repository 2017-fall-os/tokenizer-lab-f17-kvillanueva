/*
 * main.c
 *
 *  Created on: Aug 30, 2017
 *      Author: kvillanueva
 */
#include <stdio.h>
#include "mytoc.h"
#define MAXLINE 1000
int terminationCheck(char input []);

int main(){
	char userInput [MAXLINE];
	char **tokenArr;

	/*Test Cases*/
	char *testCase1 = "Hello my dog's name is Darwin.\n";
	tokenArr = mytoc(testCase1, ' ');
	free(tokenArr);

	char *testCase2="     Hello   World!    \n";
	tokenArr = mytoc(testCase2, ' ');
	free(tokenArr);

	char *testCase3="\n";
	tokenArr = mytoc(testCase3, ' ');
	free(tokenArr);

	char *testCase4="          \n";
	tokenArr = mytoc(testCase4, ' ');
	free(tokenArr);

	char *testCase5=" HelloWorld\n";
	tokenArr = mytoc(testCase5, ' ');
	free(tokenArr);

	do{
		write(0, "$\n",1);
		read(0, userInput, MAXLINE);
		char *pointerToInput = &userInput;
		if(terminationCheck(userInput) != 0){
			tokenArr = mytoc(pointerToInput, ' ');
			free(tokenArr);
		}
	}while(terminationCheck(userInput) != 0 || userInput[0]=='\n');
	return 0;
}

int terminationCheck(char input []){
	char exit []="exit";
	int sum1=0;
	int sum2=0;
	for(int i =0; i<4 && input[i]!='\n'; i++){
		if(exit[i]!=input[i]){
			return 1;
		}
		else{
			sum1 += exit[i];
			sum2 += input[i];
		}
	}
	if(sum1==sum2){
		return 0;
	}
	else{
		return 1;
	}
}
