//Assignment 2
//Joshua Taggart

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    char userInput[20];
    int i, j, start = 1, end, mid, numAttempts, maxAttempts;
    int baseTwo;

    scanf("%d", &end);

    numAttempts = 0;

    //calculating max num of guesses
    baseTwo = log2(end);
    maxAttempts = 1 + (2 * (baseTwo+1));

    printf("Max Guesses: %d\n", maxAttempts);

    mid = (start+end) / 2;
    while(numAttempts <= maxAttempts) {

        printf("start %d\n", start);
        fflush(stdout);
        scanf(" %[^\n]", userInput);
        numAttempts++;

        if(strcmp(userInput, "No.") == 0) {
            printf("%d\n", end);
            fflush(stdout);
            scanf(" %[^\n]", userInput);
            numAttempts++;
        }


        //for new start
        if(strcmp(userInput, "No. Warmer.") == 0) {


            start = mid;
            mid = (start+end) / 2;




            printf("%d\n", end);
            fflush(stdout);
            scanf(" %[^\n]", userInput);
            numAttempts++;
        }
        else if(strcmp(userInput, "No. No change.") == 0) {


            printf("%d\n", mid);
            fflush(stdout);
            scanf(" %[^\n]", userInput);
            numAttempts++;
            if(strcmp(userInput, "Yes!!!") == 0) {
                //end code, answer found
                break;
            }
        }
        else if(strcmp(userInput, "No. Colder.") == 0) {


            end = mid;
            mid = (start+end) / 2;

            printf("%d\n", end);
            fflush(stdout);
            scanf(" %[^\n]", userInput);
            numAttempts++;


        }


        //if start is the answer
        else if(strcmp(userInput, "Yes!!!") == 0) {


            //end code, answer found
            break;

        }

        //test
        //numAttempts = 50;

        //check num attempts
        if(numAttempts >= maxAttempts) {
            printf("FAIL\n");
            break;
        }

    }




    return 0;
}


//TODO
//create and set maxAttempts properly
//make program break when max attempts reached
//make program break when answer found
//make ++ for numAttempts


