/*Assignment 0
Joshua Taggart
1/15/21
*/

#include <stdio.h>
#include <string.h>

#define MAX 100000

int main() {
    //name is what the user inputs, newword is what gets returned
    char name[MAX], newword[MAX] = {0};
    //length holds the strlen of the name, numnames holds the number of names
    int length, numnames, i, j;
    //cat stores 1 to make sure strncat only concatenates one character
    int cat = 1;

    //Input number of names
    //printf("How many names:\n");
    scanf("%d", &numnames);

    //Discards input
    while ((getchar()) != '\n');

    //Initialized newword array to make sure it is empty
    newword[0] = '\0';

    //Loops for however many names are inputed
    for(i = 0; i < numnames; i++) {
        //resets length every time
        length = 0;

        //prompt for user to type in name
        fgets(name, 100000, stdin);

        length = strlen(name);
        //loops through every spot in name array
        for(j = 0; j <= length; j++) {
            //finds very first letter of name
            if(j == 0 && name[j] != ' ') {
                strncat(newword, &name[0], cat);
            }
            //if it finds a space, do nothing (redundant)
            else if(name[j] == ' ') {
                ;
            }
            //handles very last letter of name
            //whether it be an individual letter or end of word
            else if(name[j+2] == '\0') {
                strncat(newword, &name[j], cat);
                break;
            }
            //handles individual letter surrounded by spaces
            else if(name[j+1] == ' ' && name[j-1] == ' ') {
                strncat(newword, &name[j], cat);
            }
            //handles 't' in 'josh tag'
            else if(name[j-1] == ' ' && name[j+1] != ' ') {
                strncat(newword, &name[j], cat);
            }
            //handles 'h' in 'josh tag'
            else if(name[j+1] == ' ' && name[j-1] != ' ') {
                strncat(newword, &name[j], cat);
            }
        }
        //Print statement for output
        printf("%s\n", newword);
        newword[0] = '\0';
        name[0]  = '\0';
    }

    return 0;
}


