/*Lab1: Tokenizer
  Name: Kristian Villanueva
  Last Modification: 9/10/17
 */
#include <stdio.h>
#include "mytoc.h"
#define MAXLINE 1000
int terminationCheck(char input []);

int main(){
	/*Initial declaration for userInput and the receiving
	  variable tokenArr from call to mytoc()*/
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

	/*Loop requesting user input and calling mytoc() for
	  corresponding input. Quits when exit is typed.
	 */
	do{
		write(0, "$\n",1);
		read(0, userInput, MAXLINE);
		char *pointerToInput = &userInput;
		/*Checks if exit was typed prior to calling mytoc()*/
		if(terminationCheck(userInput) != 0){
			tokenArr = mytoc(pointerToInput, ' ');
			free(tokenArr);
		}
	}while(terminationCheck(userInput) != 0 || userInput[0]=='\n');
	return 0;
}

/*Checks if exit is typed into terminal*/
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
