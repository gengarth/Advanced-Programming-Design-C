//Program that checks if a given string is a palindrome.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char userNum[50];
    char palNum[50];
    int length = 0;
    int reverser = 0;

    //gets number to check
    printf("Enter number to check: ");
    scanf(" %s", &userNum);

    //gets length of the user's number and
    //sets the reverser to the 2nd last character
    length = strlen(userNum);
    reverser = length - 1;

    //loop to reverse the user's number
    for(int i = 0; i < length; i++){
        palNum[i] = userNum[reverser];
        reverser--;
    }

    if(strcmp(userNum, palNum) == 0){
        printf("%s is a palindrome.\n", userNum);
    }
    else{
        printf("%s is not a palindrome\n", userNum);
    }

    return 0;
}
