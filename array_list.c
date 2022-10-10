
// Program to add numbers to an array list

#include <stdio.h>
#include <stdlib.h> // where malloc, calloc, realloc, and free come from

#define DEFAULT_CAP 10

typedef struct array_list array_list;

struct array_list {
    int * values;
    int size;
    int capacity;
};

// proto types
void initialize(array_list *);
void destroy(array_list);
void expandList(array_list *);
void addToList(array_list *, int);

int main() {
    array_list list;

    // Create some dynamic memory
    initialize(&list);

    // Read until a -1 is given
    int input;
    scanf("%d", &input);
    while (input != -1) {
        addToList(&list, input);
        scanf("%d", &input);
    }

    // Print what is in the array at the end
    for (int i = 0; i < list.size; i++) {
        printf("%d ", list.values[i]);
    }
    printf("\n");

    // Clean up the memory created
    destroy(list);
    return 0;
}

// Double the capacity of the arraylist
void expandList(array_list * list) {

    // Create a new capacity
    int newCap = list->capacity * 2;

    // Reallocate the value array to the new capacity
    list->values = realloc(list->values, newCap * sizeof(int));
    // TODO Check for NULL here (if NULL )

    // Update the list's capacity to the new capacity
    list->capacity = newCap;
    printf("Expanding List!\n");
}


// Add a value to the end of the list's value array
void addToList(array_list * list, int value) 
{
    // Check if the list is full
    if (list->size == list->capacity) expandList(list);

    // Add the value to the end of the list
    list->values[list->size] = value;
    list->size++;
}

void initialize(array_list * list) 
{
    (*list).values = calloc(DEFAULT_CAP, sizeof(int));
    (*list).capacity = DEFAULT_CAP;
    // (*list).size = 0;
    list->size = 0;
}

void destroy(array_list list) {
    free(list.values); // remove the only dynamic memory I created
}

