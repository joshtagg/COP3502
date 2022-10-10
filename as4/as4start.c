
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
void merge(Users * userArray, int numCustomers);
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


    //call merge sort
    merge(userArray, numCustomers);



}

void merge(Users * userArray, int numCustomers) {

    printf("entered merge\n");

    int i, mid;
    char ans[numCustomers][21];

    //base case
    //print sorted list in here?
    if(numCustomers <= 1) {

        printf("entered base case\n");

        printArray(ans, numCustomers);

        return;
    }


    //recursive step
    mid = (numCustomers / 2);
    merge(userArray, mid);
    //merge(userArray + mid, numCustomers - mid);
    //this instead?:
    merge(userArray[mid].units, numCustomers - mid);

    //int * ans = calloc(numCustomers, sizeof(int));
    int fptr = 0;
    int bptr = mid;

    for(i =  0; i < numCustomers; i++) {
        if(fptr != mid && bptr != numCustomers && userArray[fptr].units <= userArray[bptr].units) {
            printf("entered if1\n");
            //ans[i] = userArray[fptr].units;
            strcpy(ans[i], userArray[fptr].name);
            fptr++;
        }
        else if(fptr != mid && bptr != numCustomers && userArray[fptr].units > userArray[bptr].units) {
            printf("entered if2\n");
            strcpy(ans[i], userArray[bptr].name);
            bptr++;
        }
        else if(fptr == mid) {
            printf("entered if3\n");
            strcpy(ans[i], userArray[bptr].name);
            bptr++;
        }
        else {
            printf("entered if4\n");
            strcpy(ans[i], userArray[fptr].name);
            fptr++;
        }

    }


}

void printArray(char ans[], int numCustomers) {
    int i;

    for(i = 0; i < numCustomers; i++) {
        printf("%s\n", ans[i]);
    }


}
















