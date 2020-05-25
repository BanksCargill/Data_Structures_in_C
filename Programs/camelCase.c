/* Program to Convert user entered string into camelCase
 */

#include <stdio.h>
#include <stdlib.h>



char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
    return ch - 'a' + 'A';
}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/
    return ch - 'A' + 'a';
}

int stringLength(char s[]) {
    /*Return the length of the string*/
    int count = 0;
    while(s[count]!= '\0'){
        count++;
   }
    return count;
}


void camelCase(char* word){
	/*Convert to camelCase*/
    int length = stringLength(word);

    /*converting upper to lower case and non-letters to underscores*/
    for (int i=0; i<length; i++){
        if (word[i]>=65 && word[i] <=90){
            //lower case all uppercase letters
            word[i]=toLowerCase(word[i]);
        }
        if (word[i]>=97 && word[i] <=122){
            //do nothing
        }
        else{
            //convert non-letters to underscores
            word[i]=95;
        }
    }
    //removing non-letters from beginning of string
    while(word[0]<97 || word[0]>122){
        for(int i=0; i<length; i++){
            word[i]=word[i+1];
        }
    }
    //remove non-letters from end of string
    while(word[length]<97 || word[length]>122){
        word[length]='\0';
        length--;
    }
    //reset the value of length
    length = stringLength(word);
    /*remove duplicate underscores, shift string over*/
    for(int i=0; i<length; i++){
        if (word[i]==95 && word[i+1]==95){
            for(int j = i; j<length; j++){
                word[j]=word[j+1];
                i--;
            }
        }
    }
    //uppercase anything after an underscore
    for (int i = 0; i<length; i++){
        if(word[i] == 95){
            word[i+1] = toUpperCase(word[i+1]);
        }
    }
    //close the gaps, aka remove underscores
    for (int i = 0; i<length; i++){
        if(word[i]==95){
            for(int j = i; j<length; j++){
                word[j]=word[j+1];
            }
        }
    }
}

int main(){
    char str1[85];
	/*Read the string from the keyboard*/
    printf("Please enter a string. ");
    printf("It can be no longer \nthan 84 characters and must contain letters\n");
    scanf("%84[^\n]c", str1);

    //checking for validity of input
    int length = stringLength(str1);
    int validInput = 0;
    for (int i=0; i<length; i++){
        if((str1[i]>65 && str1[i]<90)||(str1[i]>97 && str1[i]<122)){
            validInput = 1;
        }
    }
    if(validInput==0){
        printf("invalid string input, exiting program\n\n");
        exit(0);
    }

/*TEST reprint entry and length*/
//printf("The string you entered was: %s\n", str1);

	/*Call camelCase*/
    camelCase(str1);

	/*Print the new string*/
    printf("The string after camelCase call: %s\n", str1);

	return 0;
}
