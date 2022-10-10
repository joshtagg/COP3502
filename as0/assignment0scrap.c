//Assignment 0
//Joshua Taggart

#include <stdio.h>
#include <string.h>

#define MAX 100000

int main() {
    char name[MAX], newword[MAX] = {0};
    int length, numnames, i, j;
    int cat = 1;

    printf("How many names:\n");
    scanf("%d", &numnames);

    while ((getchar()) != '\n');

    newword[0] = '\0';

    for(i = 0; i < numnames; i++) {
        length = 0;

        fgets(name, 100000, stdin);

        length = strlen(name);

        for(j = 0; j <= length; j++) {
            if(j == 0) {
                strncat(newword, &name[0], cat);
                printf("1. added letter: %c\n", name[0]);
            }

            else if(name[j] == ' ') {
                ;
            }

            //handles very last letter of name
            //whether it be an individual letter or end of word
            else if(name[j+2] == '\0') {
                strncat(newword, &name[j], cat);
                printf("6. added letter: %c\n", name[j]);
                break;
            }
            //handles individual letter surrounded by spaces
            else if(name[j+1] == ' ' && name[j-1] == ' ') {
                strncat(newword, &name[j], cat);
                printf("7. added letter: %c\n", name[j]);
            }
            /*
            //handles individual letter before end of code
            else if(name[j-1] == ' ' && name[j+1] == '\n') {
                strncat(newword, &name[j], cat);
                printf("8. added letter: %c\n", name[j]);
            }
            */
            //handles 't' in 'josh tag'
            else if(name[j-1] == ' ' && name[j+1] != ' ') {
                strncat(newword, &name[j], cat);
                printf("9. added letter: %c\n", name[j]);

            }
            //handles 'h' in 'josh tag'
            else if(name[j+1] == ' ' && name[j-1] != ' ') {
                strncat(newword, &name[j], cat);
                printf("10. added letter: %c\n", name[j]);
            }


        }
        printf("new word: %s\n", newword);
        newword[0] = '\0';
        name[0]  = '\0';
    }

    return 0;
}


