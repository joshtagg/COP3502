/*
#include <stdio.h>
int main()
{
  char name[100000];
  printf("Who are you? ");
  fgets(name,100000,stdin);
  printf("Glad to meet you, %s",name);

  printf("%c", name[0]);
  return(0);
}
*/
//Assignment 0
//Joshua Taggart

#include <stdio.h>
#include <string.h>

#define MAX 100000

int main() {
    char name[MAX], newword[MAX] = {0};
    int length, numnames, i, j;
    int cat = 1;
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
    //printf("NEW WORD: %s\n", newword);

    for(i = 0; i < numnames; i++) {
        length = 0;
        //printf("enter for\n");
        //printf("i is equal to %d\n", i);
        //printf("numnames: %d\n", numnames);

        fgets(name, 100000, stdin);
        /*
        //----test
        scanf("%c", &name);
        while(name != '\n') {
            printf("%c", name);
            scanf("%c", &name);
        }


        //----test
        */

        length = strlen(name);
        //printf("string length: %d\n", length);
        //printf("first letter: %c", name[0]);

        for(j = 0; j <= length; j++) {
            //printf("enter for\n");
            //printf("first letter: %c", name[0]);

            //strcat(newword, name[0]);
            //newword[0] = name[0]; //MOVE MOVE MOVE MVOE

            //printf("new word: %s\n", newword);
            if(j == 0) {
                //newword[0] = name[0];
                strncat(newword, &name[0], cat);
                //printf("added letter: %c\n", name[0]);
                //printf("NEW WORD: %s\n", newword);
            }
            else if(name[j] == ' ') {
                //printf("ENTERED1\n");
                strncat(newword, &name[j-1], cat);
                //printf("added letter: %c\n", name[i-1]);
                strncat(newword, &name[j+1], cat);
                //printf("added letter: %c\n", name[i+1]);


            }
            else if(name[j] == '\0') {
                //printf("ENTERED2, i = %d\n", i);
                strncat(newword, &name[j-2], cat);
                //printf("added letter: %c\n", name[i-2]);
            }
            //else if single letter with space on each side


        }

        //add a new line for multiple words

        //print new array then set to empty for next input
        printf("new word: %s\n", newword);
        newword[0] = '\0';
        name[0]  = '\0';
    }

    //printf("i out of loop: %d", i);

    //printf("%s", name);
    //printf("%c", name[0]);
    //printf("new word: %s\n", newword);

    /*
    for(i = 0; i < length; i++) {
        if(let[i] == 0) {

        }
    }
    */


    return 0;
}

