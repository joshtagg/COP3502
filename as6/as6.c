//As6 Joshua Taggart
//THIS PROGRAM IS INCOMPLETE AND DOESNT WORK
// :(



#include <stdio.h>
#include <stdlib.h>

//structs
typedef struct Node Node;

struct Node {
    long long int value;
    long long int victor;
    int left;
    int right;
    Node * l;
    Node * r;
};


//functions
Node * createNode(long long int value);
Node * insert(Node * root, long long int value);
Node * addUser(Node * root, long long int value);
void setVictor(Node * root);
//TEST PURPOSES
void postOrder(Node * root);

//global variables
long long int * skillArray = NULL;
long long int nullCounter;
long long int totalExcitement;

int main() {
    int i;
    long long int numplayers, numTables, firstTable;

    totalExcitement = 0;

    //set root to null by default
    Node * root = NULL;

    scanf("%lld", &numplayers);


    //if there is only one player, return 1
    if(numplayers == 1 || numplayers == 0) {
        totalExcitement = 0;
        printf("%lld", totalExcitement);
        return 0;
    }

    //set number of tables
    numTables = numplayers - 1;


    //create dynamic array for the tables, not counting parent of tree
    long long int * childrenTable;
    childrenTable = calloc(numTables-1, sizeof(long long int));

    //populate table array that stores skills
    for(i = 0; i < numTables-1; i++) {
        scanf("%lld", &childrenTable[i]);
    }
    scanf("%lld", &firstTable);

    //populate global user skill array
    skillArray = calloc(numplayers, sizeof(long long int));
    for(i = 0; i < numplayers; i++) {
        scanf("%lld", &skillArray[i]);
    }


    //create tree
    root = insert(root, firstTable);
    for(i = numTables-2; i >= 0; i--) {
        root = insert(root, childrenTable[i]);

    }


    setVictor(root);

    printf("%lld\n", totalExcitement);

    return 0;
}


Node * createNode(long long int value) {
    //mem allocate node
    Node * ret = calloc(1, sizeof(Node));
    //set value
    ret->value = value;
    //set l and r pointers to null
    ret->r = ret->l = NULL;
    //return the node
    return ret;
}


Node * insert(Node * root, long long int value) {
    //if root is empty, create a new node
    if(root == NULL) {
        return createNode(value);
    }

    //if root is smaller than our target
    if(root->value < value) {
        root->r = insert(root->r, value);
    }
    //if root is not smaller than our target
    else {
        root->l = insert(root->l, value);
    }

    return root;
}



//do comparisons in different function
//set skills to all of the null slots in this function
void setVictor(Node * root) {


    if(root == NULL) {

        return; //go up a level

    }


    //if roots left and right node point to NULL
    if(root->l == NULL && root->r == NULL) {
        totalExcitement += abs(skillArray[nullCounter] - skillArray[nullCounter+1]);

        if(skillArray[nullCounter] > skillArray[nullCounter+1]) {
            root->victor = skillArray[nullCounter];
        }
        else {
            root->victor = skillArray[nullCounter+1];
        }

        nullCounter += 2;
        return;
    }

    //if left is null, right is node, recurse
    else if(root->l == NULL && root->r != NULL) {

        //some of these might be redundant/unnecessary

        //if we are traversing up and hit the root node
        if(root->left != NULL && root->r->victor != NULL) {
            if(root->left > root->r->victor) {
                totalExcitement += abs(root->left - root->r->victor);
                root->victor = root->left;
            }
            else {
                totalExcitement += abs(root->left - root->r->victor);
                root->victor = root->r->victor;
            }

        }

        //if we are traversing down and hit the root node
        if(root->left == NULL && root->r->victor == NULL) {
            root->left = skillArray[nullCounter];
            nullCounter++;
        }

    }

    //if right is null, left is node, recurse
    else if(root->r == NULL && root->l != NULL) {


        if(root->right != NULL && root->l->victor != NULL) {
            if(root->right > root->l->victor) {
                totalExcitement += abs(root->right - root->l->victor);
                root->victor = root->right;
            }
            else {
                totalExcitement += abs(root->right - root->l->victor);
                root->victor = root->l->victor;
            }
        }

        if(root->right == NULL && root->l->victor != NULL) {

            if(skillArray[nullCounter] > root->l->victor) {
                totalExcitement += abs(skillArray[nullCounter] -  root->l->victor);
                root->victor = skillArray[nullCounter];
                nullCounter++;

            }
            else {
                totalExcitement += abs(skillArray[nullCounter] - root->l->victor);
                root->victor = root->l->victor;
            }

        }


    }


    setVictor(root->l);



    setVictor(root->r);



}











