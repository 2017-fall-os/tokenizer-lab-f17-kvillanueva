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


	do{
		write(0, "$\n",1);
		read(0, userInput, MAXLINE);
		//		fgets(userInput,MAXLINE,stdin);
		char *pointerToInput = &userInput;
		if(terminationCheck(userInput) != 0){
			mytoc(pointerToInput, ' ');
		}

	}while(terminationCheck(userInput) != 0);
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
			//			printf("1: %d",sum1);
			//			printf("2: %d",sum2);
		}
	}
	if(sum1==sum2){
		return 0;
	}
	else{
		return 1;
	}
}


