/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string

*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre:
	post:
*/
int isBalanced(char* s)
{
    printf("The string input: %s\n", s);

    //If string null, it is balanced
    if (s == NULL){
        return 1;
    }

    char next = nextChar(s);
    char top = '\0';

    //declare stack
    DynArr *stack = newDynArr(20);

    //while loop to run through string until nextChar returns '\0'
    while(next!='\0'){
        printf("\nAnalyzing the next character: %c\n", next);

        //Checking for parenthetical opening bracket
        //pushing to stack if encountered
        if (next == '(' || next == '{' || next == '['){
            pushDynArr(stack, next);
            top = topDynArr(stack);
            printf("Setting the top to: %c\n", top);
        }

        //when a closing parenthetical is encountered, check if it matches
        //the top, pop the top if it does.
        if (next == ')' || next == '}' || next == ']'){
            if((next == ')' && top == '(') || (next== '}' && top == '{') || (next==']' && top=='[')){
                if(isEmptyDynArr(stack)){
                   printf("Imbalance detected...\n\n");
                   return 0;
                }
                else{
                    printf("Popping the top: %c\n", top);
                    popDynArr(stack);
                }
                //reassign top if the stack is not empty
                if(!isEmptyDynArr(stack)){
                    top = topDynArr(stack);
                    printf("The top is now: %c\n", top);
                }
            }
            //if the closing parenthetical is found but does not match the top
            //the string is not balanced (return 0)
            else{
                printf("Imbalance detected...\n");
                return 0;
            }
        }

        //call nextChar to move a character down the string for continue analyzing
        //with the while loop
        next = nextChar(s);
    }

    //check to be sure the stack is empty
    //return true if it is
    if(isEmptyDynArr(stack)){
        deleteDynArr(stack);
        stack=0;
        return 1;
    }
    else{
        printf("Imbalance detected...\n");
        return 0;
    }
    //push anytime I encounter (, {, [
    // call TYPE topDynArr(DynArr *v);, whenever you encounter closing closing parenthetical
        //if the return value matches parenthetical (use if statements to check), pop the value

}

int main(int argc, char* argv[]){

	char* s= "{{{[()[{}]]}}}";
	//(2{a+b[c]})
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}
