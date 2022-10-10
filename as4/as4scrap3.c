
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs
typedef struct Users Users;

struct Users {
    char name[21];
    int tokens;
    int bills;
    int units;
};


//functions
void merge(struct Users * userArray, int numCustomers, struct Users * temp);
void printArray(char ans[], int numCustomers);

int main() {

    int numCustomers, i;

    long long int tokens, bills, units;

    printf("num customers: ");
    scanf("%d\n", &numCustomers);



    Users userArray[numCustomers];


    for(i = 0; i < numCustomers; i++) {
        scanf("%s", &userArray[i].name);
        scanf("%lld", &userArray[i].tokens);
        scanf("%lld", &userArray[i].bills);
    }
    scanf("%lld %lld", &tokens, &bills);
    //scanf("%lld", &tokens);
    //scanf("%lld", &bills);



    //printf("%lld\n", userArray[0].tokens);
    //printf("%lld\n", tokens);

    //do token/bill -> units conversion here


    //assign units to each user
    for(i = 0; i < numCustomers; i++) {

        units = (userArray[i].tokens * bills) + (userArray[i].bills * tokens);

        userArray[i].units = units;

    }

    //printf("%lld\n", userArray[0].units);
    printf("Alice Units: %lld \n", userArray[0].units);
    printf("Bob Units: %lld \n", userArray[1].units);
    printf("Carol Units: %lld \n", userArray[2].units);

    Users temp[numCustomers];

    //call merge sort
    merge(userArray, numCustomers, temp);

    printf("IN MAIN:\n");
    for(i = 0; i < numCustomers; i++) {
        printf("%s\n", userArray[i].name);

    }


}

void merge(struct Users * userArray, int numCustomers, struct Users * temp) {

    //printf("entered merge\n");

    int i, mid;
    char ans[numCustomers][21];

    //Users temp;

    //base case
    //print sorted list in here?
    if(numCustomers <= 1) {

        //printf("entered base case\n");

        //printf("ans array: %s\n", ans[0]);

        //printArray(ans, numCustomers);

        return;
    }


    //recursive step
    mid = (numCustomers / 2);
    merge(userArray, mid, temp);
    merge(userArray + mid, numCustomers - mid, temp);
    //this instead?:
    //merge(userArray[mid].units, numCustomers - mid);

    //int * ans = calloc(numCustomers, sizeof(int));
    int fptr = 0;
    int bptr = mid;


    for(i =  0; i < numCustomers; i++) {
        if (fptr != mid && bptr != numCustomers && userArray[fptr].units <= userArray[bptr].units) {
            //printf("entered if1\n");
            temp[i] = userArray[fptr];
            fptr++;
        }
        else if(fptr != mid && bptr != numCustomers && userArray[fptr].units > userArray[bptr].units) {
            //printf("entered if2\n");
            temp[i] = userArray[bptr];
            bptr++;
        }
        else if(fptr == mid) {
            //printf("entered if3\n");
            temp[i] = userArray[bptr];
            bptr++;
        }
        else {
            //printf("entered if4\n");
            temp[i] = userArray[fptr];
            fptr++;
        }
    }

    //memcpy(&userArray, &temp, sizeof(struct) * numCustomers);
    //userArray = temp;


    for(i = 0; i < numCustomers; i++) {
        userArray[i] = temp[i];
    }


    printf("RECURSE:\n");
    for(i = 0; i < 3; i++) {
        printf("%s\n", userArray[i].name);
    }





}

/*
void printArray(char ans[], int numCustomers) {
    int i;

    printf("entered printARray\n");

    for(i = 0; i < numCustomers; i++) {
        printf("%s\n", ans[i]);
    }


}
*/


















