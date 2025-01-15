#include <stdio.h>
#include <string.h>

char *reverseString(char myString[128]) {

    static char gnirtSym[128];  // Static to persist after function exits

    int length = strlen(myString);

    for (int i = 0; i < length; i++) {
        gnirtSym[i] = myString[length - i - 1];
    }
    gnirtSym[length] = '\0';  // Null-terminate the reversed string

    return gnirtSym;
}

int main(){

    // My favorite string to test this with :
    // in girum imus nocte et consumimur igni

    char userString[128];

    printf("Enter your string : ");
    if (fgets(userString, sizeof(userString), stdin) != NULL) {
        
        userString[strcspn(userString, "\n")] = '\0';

        char *outputString = reverseString(userString);

        fprintf(stdout,"IN : %s\nOUT : %s\n",userString,outputString);

    } else {
        fprintf(stderr,"Error on user input.\n:");
    }
}