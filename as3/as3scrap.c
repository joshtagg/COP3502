//as 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//void recursion function here
//probably not correct
void rec(int * used, int * order, char ** wordList, int * NewIntList, int numWords, int pos, int count);

int main() {

    int numWords, i;
    //20 char max word

    printf("number of words: ");
    scanf("%d", &numWords);

    //allocate space for whole word array
    char **wordList = (char**)calloc(numWords, sizeof(char*));

    int * used = (int *) calloc(numWords, sizeof(int));
    int * order = (int *) calloc(numWords, sizeof(int));
    int * NewIntList = (int *) calloc(numWords, sizeof(int));

    //char * word;

    //make 2d array to store words
    //for loop to scan and assign all of them


    for(i = 0; i < numWords; i++) {

        wordList[i] = (char*) calloc(21, sizeof(char));

    }

    for(i = 0; i < numWords; i++) {
        scanf("%s", wordList[i]);
    }


    for(i = 0; i < numWords; i++) {
        //allocate
        //scanf word






        used[i] = FALSE;
        order[i] = i;
        NewIntList[i] = '\0';

    }


    //printf("%c\n", &wordList[0][3]);
    printf("%s\n", wordList[0]);
    printf("%c\n", wordList[0][3]);
    //printf("%c\n", )

    //printf("%s", &wordList[1]);

    //call recursive function
    rec(used, order, wordList, NewIntList, numWords, 0, 0);


    return EXIT_SUCCESS;
}

//brute force every possible combination of words until it is correctly ordered
//check if its correctly ordered every time
void rec(int * used, int * order, char ** wordList, int * NewIntList, int numWords, int pos, int count) {

    int i, flag, lastLetter, test, word1, word2;

    if (numWords == pos) {

        //printf("entered loop 1\n");

        /*
        printf("%d. ", ++count);

        for(i =0; i < numWords; i++) {
            printf("%d", NewIntList[i]);
        }
        printf("\n");
        */


        flag = 0;


        for(i = 0; i < numWords; i++) {


            printf("entered loop 2\n");



            //test = NewIntList[i];

            lastLetter = strlen(&wordList[NewIntList[i]]) - 1;
            //lastLetter = strlen(&wordList[test]);
            //printf("%d\n", lastLetter);



            //START THROWING & ON ALL CALLS OF wordList


            word1 = NewIntList[i];
            word2 = NewIntList[i+1];

            //strcmp(wordList[NewIntList[i]][lastLetter], wordList[NewIntList[i+1]][0]) == 0

            //if last letter of word same as first letter of next word
            //if(&wordList[NewIntList[i]][lastLetter] == &wordList[NewIntList[i+1]][0])

            //printf("lastLetter: %d\n", lastLetter);
            //printf("word1: %d\n", word1);





            printf("%c\n", wordList[0][strlen(wordList[0])-1]);
            //printf("%c\n", &wordList[0][0]);
            //printf("%c\n", &wordList[0][1]);
            //printf("%c\n", &wordList[0][2]);
            printf("%s\n", &wordList[0]);

            printf("%c\n", &wordList[word1][lastLetter]);
            printf("%c\n", &wordList[word2][0]);





            if(&wordList[word1][lastLetter] == &wordList[word2][0]) {
                printf("entered loop 3\n");
                flag++;

            }

            //else, break loop and make another combination
            else {

                printf("entered loop 4\n");

                break;
                //set i to over 12 to break for loop?
                //i = 100;
            }

        }

        //if the string is correct
        if(flag == numWords) {

            printf("entered loop 5\n");

            //print the array
            for(i = 0; i < numWords; i++) {

                printf("%s ", &wordList[NewIntList[i]]);

            }
            printf("\n");

            return;

        }




        /*
        for(i = 0; i < numWords; i++) {

            //test = NewIntList[i];

            //printf("TEST: %d", test);



            printf("%s ", &wordList[NewIntList[i]]);

        }
        printf("\n");
        */


    }

    for(i = 0; i < numWords; i++) {

        if(used[i] == FALSE) {
            used[i] = TRUE;

            NewIntList[pos] = order[i];

            //printf("recured\n");
            rec(used, order, wordList, NewIntList, numWords, pos + 1, count);

            used[i] = FALSE;
            NewIntList[pos] = '\0';

        }
    }



    //create order of words
    //check that order of words
    //if its not correct, loop again
    //if it is correct, you are done

    //return;

}

//make seperate function receive newly created order of words?
//if the order is correct, return num to break recursion























