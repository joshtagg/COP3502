//Assignment 2
//Joshua Taggart

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    //userInput stores what the user types into the program
    char userInput[20];
    int i, j, start = 1, end, mid, numAttempts, maxAttempts;
    //finding the max attempts is split into two variables with baseTwo solving the log of the max integer
    int baseTwo;

    //initially scan in the max integer
    scanf("%d", &end);

    //Set the number of attempts taken to zero
    numAttempts = 0;

    //Math for finding the max amount of attempts the program can make
    baseTwo = log2(end);
    maxAttempts = 1 + (2 * (baseTwo+1));

    //remove in final
    printf("Max Guesses: %d\n", maxAttempts);

    //Calculate the initial middle point
    mid = (start+end) / 2;

    //loops until the program runs out of attempts
    while(numAttempts <= maxAttempts) {
        //Begin with the start/min number, then scan user input
        printf("%d\n", start);
        fflush(stdout);
        scanf(" %[^\n]", userInput);
        numAttempts++;

        //If the start/min number receives anything that isn't "Yes" or "No. No change", enter loop
        if(strcmp(userInput, "Yes!!!") != 0 && strcmp(userInput, "No. No change.") != 0) {
            //after code checks that the starting/min number is neither "Yes!!!" or "No. No change."
            //it checks the ending/max number
            printf("%d\n", end);
            fflush(stdout);
            scanf(" %[^\n]", userInput);
            numAttempts++;

            //If the ending/max number receives "No. Warmer.", enter loop
            if(strcmp(userInput, "No. Warmer.") == 0) {
                //the new minimum number becomes what the middle number was
                start = mid;
                //a new middle number is created based off of the new starting number
                //and the end number (unchanged)
                mid = (start+end) / 2;
            }

            //If the ending/max number receives "No. No change.", enter loop
            else if(strcmp(userInput, "No. No change.") == 0) {
                //if the ending number is no change, the middle number must be the answer
                //ask the user if the middle number is the answer
                printf("%d\n", mid);
                fflush(stdout);
                scanf(" %[^\n]", userInput);
                numAttempts++;
                //If the user answers "Yes!!!"
                if(strcmp(userInput, "Yes!!!") == 0) {
                    //the code ends because the answer was found
                    break;
                }
            }

            //If the ending/max number receives "No. Colder.", enter loop
            else if(strcmp(userInput, "No. Colder.") == 0) {
                //the new max number becomes what the middle number was
                end = mid;
                //calculate new middle number based on the new max number
                mid = (start+end) / 2;
            }

            //If the ending/max number receives "Yes!!!", enter loop
            else if(strcmp(userInput, "Yes!!!") == 0) {
                //the code ends because the answer was found
                break;
            }
        }

        //If the starting/min number receives "No. No change.", enter loop
        else if(strcmp(userInput, "No. No change.") == 0) {
            //if the ending number is no change, the middle number must be the answer
            //ask the user if the middle number is the answer
            printf("%d\n", mid);
            fflush(stdout);
            scanf(" %[^\n]", userInput);
            numAttempts++;
            //If the user answers "Yes!!!"
            if(strcmp(userInput, "Yes!!!") == 0) {
                //the code ends because the answer was found
                break;
            }
        }

        //If the starting/min number receives "Yes!!!", enter loop
        else if(strcmp(userInput, "Yes!!!") == 0) {
            //the code ends because the answer was found
            break;
        }

    }

    return 0;
}
