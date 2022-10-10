#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {


    char orig[101];
    scanf("%s", orig);

    int num, i, j, lenOfString;

    scanf("%d", &num);

    char forbid[num];
    for(i = 0; i < num; i++) {
        scanf(" ");
        scanf("%c", &forbid[i]);
    }

    lenOfString = strlen(orig);

    for(i = 0; i < lenOfString; i++) {
        int okay = 1;

        for(j = 0; j < num; j++) {
            if(orig[i] == forbid[j]) {
                okay = 0;
            }
        }
        if(okay == 1) {
            printf("%c", orig[i]);
        }
    }
    printf("\n");

    return 0;
}
