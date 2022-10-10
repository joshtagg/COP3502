//as 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//recursive function
void rec(int * used, int * order, char ** wordList, int * NewIntList, int numWords, int pos, int count);

int main() {
    int numWords, i;

    scanf("%d", &numWords);

    //wordList is a double pointer array that will store all of the user inputed words
    //allocate space for whole word array
    char **wordList = (char**)calloc(numWords, sizeof(char*));

    //used keeps track of which spots in the array have been assigned a number
    //each spot in the array will either be TRUE or FALSE
    int * used = (int *) calloc(numWords, sizeof(int));
    //order assigns the number to NewIntList
    int * order = (int *) calloc(numWords, sizeof(int));
    //NewIntList is a list of integers, each number corresponds to a word in the word array
    //ex. 0 represents the first word, 1 represents the second word, etc.
    int * NewIntList = (int *) calloc(numWords, sizeof(int));

    //This loop scans each word into the wordList array
    for(i = 0; i < numWords; i++) {
        //allocate space for each word
        wordList[i] = (char*) calloc(21, sizeof(char));

        scanf("%s", wordList[i]);

        //setup the three other arrays
        used[i] = FALSE;
        order[i] = i;
        NewIntList[i] = '\0';

    }

    //recursive function call
    rec(used, order, wordList, NewIntList, numWords, 0, 0);

    return EXIT_SUCCESS;
}

//brute force every possible combination of words until it is correctly ordered
//check if its correctly ordered every time
void rec(int * used, int * order, char ** wordList, int * NewIntList, int numWords, int pos, int count) {

    int i, flag, lastLetter, test, word1, word2;

    //base case
    //the base case runs every time a new permutation is created
    if (numWords == pos) {

        //flag keeps track of the number of pretty combinations
        flag = 0;

        //it is numWords - 1 because the number of comparisons the code makes will always be numWords - 1
        for(i = 0; i < numWords-1; i++) {

            lastLetter = strlen(wordList[NewIntList[i]]) - 1;

            word1 = NewIntList[i];
            word2 = NewIntList[i+1];

            //if the last letter of one word is the same as the first letter of the next word, enter loop
            if(wordList[word1][lastLetter] == wordList[word2][0]) {
                //flag goes +1 for each pretty combination of 2 words found
                flag++;
            }

            //if a pretty word is not found, break loop to find a new permutation of words to check
            else {
                break;
            }

        }

        //if every word in the current permutation creates a full pretty phrase, enter loop
        if(flag == numWords-1) {
            //this loop prints out the full pretty phrase
            for(i = 0; i < numWords; i++) {
                printf("%s ", wordList[NewIntList[i]]);
            }
            printf("\n");

            //FREE ALL MEMORY HERE
            for(i = 0; i < numWords; i++) {
                free(wordList[i]);
            }
            free(used);
            free(order);
            free(NewIntList);
            free(wordList);

            //This will exit the program since the pretty phrase has already been printed.
            //We don't want to keep checking for pretty phrases once one is found
            exit(0);
        }

    }

    //This loop manages forming the permutations which is the brute force aspect of this code
    //This loop also contains the recursive call
    for(i = 0; i < numWords; i++) {

        if(used[i] == FALSE) {
            //sets the current value in the used array to true
            used[i] = TRUE;

            //this sets up the NewIntList which stores a number that corresponds to each word in the wordList array
            //NewIntList stores the combination of numbers that correspond to words
            NewIntList[pos] = order[i];

            //recursive call, sets pos + 1 to enter the next spot in the NewIntList array to set a new number to it
            rec(used, order, wordList, NewIntList, numWords, pos + 1, count);

            //sets the current value in the used array to false
            used[i] = FALSE;
            //resets the NewIntList array
            NewIntList[pos] = '\0';

        }
    }


}


