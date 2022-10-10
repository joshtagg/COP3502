//Assignment 4
//Joshua Taggart

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs
typedef struct Users Users;

struct Users {
    char name[21];
    long long int tokens;
    long long int bills;
    long long int units;
};


//functions
void merge(struct Users * userArray, int numCustomers, struct Users * temp);

int main() {

    int numCustomers, i;

    long long int tokens, bills, units;

    scanf("%d\n", &numCustomers);

    //create the main struct array
    Users userArray[numCustomers];

    //scan user input of each user
    for(i = 0; i < numCustomers; i++) {
        scanf("%s", &userArray[i].name);
        scanf("%lld", &userArray[i].tokens);
        scanf("%lld", &userArray[i].bills);
    }
    //scan tokens and bills for unit conversion
    scanf("%lld %lld", &tokens, &bills);

    //assign units to each user
    for(i = 0; i < numCustomers; i++) {

        //performs units conversion based on the bills and tokens
        units = (userArray[i].tokens * bills) + (userArray[i].bills * tokens);

        //assigns units to each user
        userArray[i].units = units;
    }

    //temporary Users array for the merge sort
    Users temp[numCustomers];

    //call merge sort
    merge(userArray, numCustomers, temp);

    //prints sorted list of names after merge sort
    for(i = 0; i < numCustomers; i++) {
        printf("%s\n", userArray[i].name);

    }

}

//merge sort function
void merge(struct Users * userArray, int numCustomers, struct Users * temp) {
    int i, mid;
    char ans[numCustomers][21];

    //base case
    if(numCustomers <= 1) {
        return;
    }


    //set the midpoint as half of the number of customers
    mid = (numCustomers / 2);
    //recursive step
    merge(userArray, mid, temp);
    merge(userArray + mid, numCustomers - mid, temp);

    //setting front and back variable for merge sort
    int fptr = 0;
    int bptr = mid;

    //main merge sort loop
    for(i =  0; i < numCustomers; i++) {
        //each if/else if/else is used for sorting the userArray struct array
        //it sorts based off of each user's units
        if (fptr != mid && bptr != numCustomers && userArray[fptr].units >= userArray[bptr].units) {
            //set temp struct to equal userArray at location fptr
            temp[i] = userArray[fptr];
            fptr++;
        }
        else if(fptr != mid && bptr != numCustomers && userArray[fptr].units < userArray[bptr].units) {
            //set temp struct to equal userArray at location bptr
            temp[i] = userArray[bptr];
            bptr++;
        }
        else if(fptr == mid) {
            //set temp struct to equal userArray at location bptr
            temp[i] = userArray[bptr];
            bptr++;
        }
        else {
            //set temp struct to equal userArray at location fptr
            temp[i] = userArray[fptr];
            fptr++;
        }
    }

    //this will update the order of the main struct array
    for(i = 0; i < numCustomers; i++) {
        userArray[i] = temp[i];
    }




}















