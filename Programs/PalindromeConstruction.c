#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER m
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* canConstructPalindrome(char* s, int m) {
    // The Function should return either "Yes" or "No" as strings.
   // The Function should return either "Yes" or "No" as strings.
    char *yes = "yes";
    char *no = "no";

    //m is the number of letter required for the palindrome
        //m-1 is the number of duplicates required from the string
    int length = strlen(s);
    int array[length];
    memset(array, 0, length);
    int i;
    int j;
    for(i=0; i<length; i++){
        for(j=0; j<length; j++)
            if(s[i]==s[j]){
                array[i]++;
            }
    }
    int count=0;
    for(i=0; i<length; i++){
        if(array[i]>=2){
            count++;
        }
    }
    if(count<m-1)
        return no;
    else
        return yes;

}

int main()
{

        int m = 3;
        char* myString;
        memset(myString, '\0', strlen(myString));
        gets(myString);
        printf("myString =", myString);
        char* ans = canConstructPalindrome(myString, m);

        printf("%s\n", ans);




    return 0;
}
