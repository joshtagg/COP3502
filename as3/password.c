#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHRASE "adeflr"
#define FALSE 0
#define TRUE 1

int count;

// Prototype for our recursive password
void perm(int * used, char * original, char * current, int len, int pos);

int main() {
    int * used; // Which letters have been used
    char * orig; // The original set of letter
    char * cur; // The current arrangement of letters
    int i;

    // Initialize the count to 0
    count = 0;

    // Create memory
    used = (int *) calloc(strlen(PHRASE), sizeof(int));
    orig = (char *) calloc(strlen(PHRASE), sizeof(char));
    cur = (char *) calloc(strlen(PHRASE), sizeof(char));

    // Fill the arrays
    for(i = 0; i < strlen(PHRASE); i++) {
        used[i] = FALSE;
        orig[i] = (PHRASE)[i];
        cur[i] = '\0';
    }

    // Run the recursive method
    perm(used, orig, cur, strlen(PHRASE), 0);

    // Return a success
    return EXIT_SUCCESS;

}

// The recursive method that does the permutation
void perm(int * used, char * original, char * current, int len, int pos) {

    int i;

    // Base case Check if the current position is at the end (len)
    if (len == pos) {
        // Print and update the count
        printf("%d. ", ++count);

        // Print the string
        for (i = 0; i < len; i++) {
            printf("%c", current[i]);
        }
        printf("\n");

        // Don't do the recursion stuff
    }

    // Loop through all possible letters
    for(i = 0; i < len; i++) {
        if(used[i] == FALSE) {
            // Set the value to used
            used[i] = TRUE;

            // Assign the value
            current[pos] = original[i];

            // Recurse
            perm(used, original, current, len, pos + 1);

            // Undo the changes
            used[i] = FALSE;
            current[pos] = '\0';
        }
    }

    // not necessary
    //but if i needed to return something it could be here
    return;
}

//used =    [0, 0, 0, 0, 0, 0]
//orig =    "a, d, e, f, l, r"
//current = [_, _, _, _, _, _]






