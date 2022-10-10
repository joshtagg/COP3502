


#include <stdio.h>
#include <stdlib.h>




int main() {
    char userInput[20];
    int i, j, start = 1, end, mid, numTries, maxAttempt;

    scanf("%d", &end);

    numTries = 0;

    //test
    maxAttempt = 10;

    /*
    while(start <= end) { //while numtries < maxtries?
        mid = (start + end) / 2;


        //end loop if exceeds number of tries
        //if(numTries >= 1+2*end(log) )


        numTries++;
    }
    */

    while(numTries <= maxAttempt) {
        mid = (start+end) / 2;
        printf("start %d\n", start);
        scanf(" %[^\n]", userInput);

        //if user typed in "no"
        if(strcmp(userInput, "No.") == 0) {
            printf("%d\n", end);
            scanf(" %[^\n]", userInput);
            if(strcmp(userInput, "No. Warmer") == 0) {
                start = mid;
                //max = no change
                mid = (start+end) / 2;

                //loop repeats after new min,max,mid????
            }
            //if mid is the answer
            else if(strcmp(userInput, "No. No change.") == 0) {
                //print middle value
                //will be the correct answer
                printf("%d", mid);
                scanf(" %[^\n]", userInput);
                if(strcmp(userInput, "Yes!!!") == 0) {
                    //end code, answer found
                    printf("yo1\n");
                }


            }
            else if(strcmp(userInput, "No. Colder.") == 0) {
                //min = no change
                end = mid;
                mid = (start+end) / 2;


            }
            //if end is the answer
            else if(strcmp(userInput, "Yes!!!") == 0) {
                //end code, answer found
                printf("yo2\n");
            }
        }

        //for new start
        //else if(strcmp(userInput, "No. Warmer") == 0)


        //if start is the answer
        else if(strcmp(userInput, "Yes!!!") == 0) {
            //end code, answer found
            printf("yo3\n");
        }


    }











    //if i < max number of tries (formula) loop



    return 0;
}



