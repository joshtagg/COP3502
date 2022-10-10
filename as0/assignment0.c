//Assignment 0
//Joshua Taggart

#include <stdio.h>
#include <string.h>

#define MAX 100000

int main() {
    char name[MAX], newword[MAX] = {0};
    int length, numnames, i;
    /*
    scanf("%c", &let);
    while (let != '\n') {
        printf("%c", let);
        scanf("%c", &let);
    }
    printf("\n");
    */
    printf("How many names:\n");
    scanf("%d", &numnames);

    //printf("%c", let[0]);

    while ((getchar()) != '\n');

    newword[0] = '\0';
    printf("NEW WORD: %s\n", newword);

    for(i = 0; i < numnames; i++) {
        length = 0;
        //printf("enter for\n");

        fgets(name, 100000, stdin);

        length = strlen(name);
        printf("string length: %d\n", length);
        //printf("first letter: %c", name[0]);

        for(i = 0; i <= length; i++) {
            //printf("enter for\n");
            //printf("first letter: %c", name[0]);

            //strcat(newword, name[0]);
            //newword[0] = name[0]; //MOVE MOVE MOVE MVOE

            //printf("new word: %s\n", newword);
            if(i == 0) {
                //newword[0] = name[0];
                strcat(&newword, &name[0]);
                printf("added letter: %c\n", name[0]);
                printf("NEW WORD: %s\n", newword);
            }
            else if(name[i] == ' ') {
                printf("ENTERED1\n");
                strcat(&newword, &name[i-1]);
                printf("added letter: %c\n", name[i-1]);
                strcat(&newword, &name[i+1]);
                printf("added letter: %c\n", name[i+1]);
            }
            else if(name[i] == '\0') {
                printf("ENTERED2, i = %d\n", i);
                strcat(&newword, &name[i-2]);
                printf("added letter: %c\n", name[i-2]);
            }

        }

    //add a new line for multiple words
    }



    //printf("%s", name);
    //printf("%c", name[0]);
    printf("new word: %s\n", newword);

    /*
    for(i = 0; i < length; i++) {
        if(let[i] == 0) {

        }
    }
    */


    return 0;
}
