
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define DEFAULT_CAP 10

typedef struct list {
    char ** arr;
    int size, cap;
} list;

void sort(char **, int);
int  binarySearch(list *, char *);
int  linearSearch(list *, char *);
void addWordToList(list *, char *);
list * createList();
void expandList(list *);
void destroyList(list *);

int main(int argc, char ** argv) {
    FILE * dictionary;
    if (argc < 2) {
        printf("Please enter the dictionary in the arguements\n");
        return 0;
    }   
    
    // Open the file name argv[1] with the read flag
    dictionary = fopen(argv[1], "r");

    // Read in the first word
    char buff[MAX_LEN + 1];
    int scanReturn = fscanf(dictionary, "%s", buff);

    // Create the list of word
    list * word_list = createList();

    // Read in all word
    while (scanReturn != EOF) {
        // Add the word into our internal dicionary (array list)
        addWordToList(word_list, buff);

        // Try to read in the next word
        scanReturn = fscanf(dictionary, "%s", buff);
    }

    FILE * binary_file = fopen("bin_file.txt", "w");
    FILE * linear_file = fopen("lin_file.txt", "w");

    sort(word_list->arr, word_list->size);    
    for (int i = 0; i < word_list->size - 1; i++) {
        int cmpRes = strcasecmp(word_list->arr[i], word_list->arr[i + 1]);
        if (cmpRes > 0) {
            printf("out of order dictionary. :(\n");
        }
    }

    int tries = 10000;
    printf("Starting binary search...\n");
    srand(123);
    for (int i = 0; i < tries; i++) {
        for (int j = 0; j < 3; j++) {
            buff[j] = ((rand()%26)+'a');
        }
        buff[3] = '\0';
        fprintf(binary_file, "%d\n", binarySearch(word_list, buff));
    }
    printf("Binary Search Done.\n");
    printf("Starting linear search...\n");
    srand(123);
    for (int i = 0; i < tries; i++) {
        for (int j = 0; j < 3; j++) {
            buff[j] = ((rand()%26)+'a');
        }
        buff[3] = '\0';
        fprintf(linear_file, "%d\n", linearSearch(word_list, buff));
    }
    printf("Linear Search Done.\n");

    destroyList(word_list);
    fclose(dictionary);
    fclose(binary_file);
    fclose(linear_file);

    return 0;
}

// Insertion sort
void sort(char ** array, int size) {
    char * buff;
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j && (strcasecmp(array[j], array[j - 1]) < 0)) {
            buff = array[j];
            array[j] = array[j - 1];
            array[j-1] = buff;
            j--;
        }
    }
}

int binarySearch(list * word_list, char * word) {
    int start = 0; // inclusive
    int end = word_list->size - 1; // inclusive
    
    while (start <= end) {
        // find the mid point
        int mid = (end + start) / 2;
        int cmpRes = strcasecmp(word, word_list->arr[mid]);
        // word - midpoint < 0
        // word < midpoint
        if (cmpRes == 0) {
            return 1; // we found the word!!!
        }
        if (cmpRes < 0) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;
}

int linearSearch(list * word_list, char * word) { 
    for (int i = 0; i < word_list->size; i++)
        if (strcasecmp(word_list->arr[i], word) == 0)
            return 1;
    return 0;
}

void addWordToList(list * word_list, char * word) {
    if (word_list->size == word_list->cap) {
        expandList(word_list);
    }

    // Moving the word into the list
    word_list->arr[word_list->size] = 
            calloc(strlen(word) + 1, sizeof(char));
    strcpy(word_list->arr[word_list->size],
            word);

    // Update the size
    word_list->size++;
}

list * createList() {
    list * ret;

    ret = malloc(sizeof(list));
    ret->size = 0;
    ret->cap = DEFAULT_CAP;
    ret->arr = malloc(DEFAULT_CAP * sizeof(char *));

    return ret;
}

void expandList(list * word_list) {
    int newCap = word_list->cap * 2;
    // BADNESS BELOW
    word_list->arr = realloc(word_list->arr, newCap * sizeof(char*));
    word_list->cap = newCap;
}

void destroyList(list * word_list) {
    for (int i = 0; i < word_list->size; i++)
        free(word_list->arr[i]);
    free(word_list->arr);
    free(word_list);
}


