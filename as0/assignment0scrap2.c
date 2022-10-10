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
                strncat(newword, &name[j-1], cat);
                printf("2. added letter: %c\n", name[j-1]);
                strncat(newword, &name[j+1], cat);
                printf("3. added letter: %c\n", name[j+1]);
            }
            else if(name[j] == '\0') {
                strncat(newword, &name[j-2], cat);
                printf("4. added letter: %c\n", name[j-2]);
            }

        }
        printf("new word: %s\n", newword);
        newword[0] = '\0';
        name[0]  = '\0';
    }

    return 0;
}


