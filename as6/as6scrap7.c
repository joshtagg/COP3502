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
long long int lastSkill;

int main() {
    int i;
    long long int numplayers, numTables, firstTable; //, totalExcitement;

    totalExcitement = 0;

    Node * root = NULL;

    scanf("%lld", &numplayers);

    //printf("numplayers: %lld\n", numplayers);

    if(numplayers == 1) {
        return 1;
    }

    //set number of tables
    numTables = numplayers - 1;

    //table array
    //long long int childrenTable[numTables-1];
    //long long int * childrenTable = NULL;

    long long int * childrenTable;
    childrenTable = calloc(numTables-1, sizeof(long long int));

    //populate table array
    for(i = 0; i < numTables-1; i++) {
        //printf("entered loop\n");
        //childrenTable[i] = calloc(1, sizeof(long long int));
        scanf("%lld", &childrenTable[i]);
    }
    //printf("exit loop\n");
    scanf("%lld", &firstTable);

    /*
    for(i = 0; i < numTables; i++) {
        printf("children table: %lld\n", childrenTable[i]);
    }
    */
    //printf("head table: %d\n", firstTable);
    //printf("first childrentable: %lld\n", childrenTable[0]);
    //----------------------------


    //populate global user skill array
    skillArray = calloc(numplayers, sizeof(long long int));

    for(i = 0; i < numplayers; i++) {
        scanf("%lld", &skillArray[i]);
    }

    lastSkill = skillArray[numplayers-1];
    //----------------------------


    //insert table loop
    root = insert(root, firstTable);
    //printf("inserted head\n");
    for(i = numTables-2; i >= 0; i--) {
        //printf("enter for\n");
        root = insert(root, childrenTable[i]);
        //printf("children table: %lld\n", childrenTable[i]);

        //should print 4, 3, 1
    }
    //------------------------------





    //printf("call setVictor\n");
    setVictor(root);
    //printf("exit setVictor\n");

    printf("FINAL ANSWER %lld\n", totalExcitement);
    printf("final nullCount = %lld\n", nullCounter);

    return 0;
}


Node * createNode(long long int value) {
    Node * ret = calloc(1, sizeof(Node));
    ret->value = value;
    ret->r = ret->l = NULL;
    return ret;
}


Node * insert(Node * root, long long int value) {
    if(root == NULL) {
        return createNode(value);
    }

    if(root->value < value) {
        root->r = insert(root->r, value);
    }
    else {
        root->l = insert(root->l, value);
    }

    return root;
}




    //traverse tree in post order until you find null pointer

    //find left null pointer, then check if right is also null
    //if right is also null, calculate first 2 skill differences
    //set victor skill to parent

    //find left null pointer, if right is not null
    //store current skill in left pointer (root->victor = skillArray[nullCounter]; nullCounter++;)

    //you find right null pointer, if left is not null
    //store current skill in right pointer






//do comparisons in different function
//set skills to all of the null slots in this function

//put this in while loop, while nullCounter < numplayers??????
void setVictor(Node * root) {


    //printf("inside setVictor\n");


    if(root == NULL) {


        return; //go up a level



    }



    //call recurse inside of these following loops or call postOrder(root->l); and postOrder(root->); before all??????????
    if(root->l == NULL && root->r == NULL) {

        root->left = skillArray[nullCounter];
        root->right = skillArray[nullCounter+1];

        nullCounter += 2;

        //move up level?
        return;
    }

    //if left is null, right is node, recurse
    else if(root->l == NULL && root->r != NULL) {

        root->left = skillArray[nullCounter];
        nullCounter++;
    }

    //if right is null, left is node, recurse
    else if(root->r == NULL && root->l != NULL) {


        //equals very last node
        root->right =


    }

    printf("#####node->value: %lld\n", root->value);

    setVictor(root->l);


    printf("####2node->value: %lld\n", root->value);

    /*
    if(root->r == NULL && root->l->victor != NULL) {
        if(skillArray[nullCounter] > root->l->victor) {
            totalExcitement += abs(skillArray[nullCounter] - root->l->victor);
            root->victor = skillArray[nullCounter];
        }
        else {
            totalExcitement += abs(skillArray[nullCounter] - root->l->victor);
            root->victor = root->l->victor;
        }
    }
    */
    setVictor(root->r);

    /*
    if(root->r == NULL && root->l->victor != NULL) {

    }
    */


}


//one function should set the skill to all of the tables
//next function should go through post order normally, checking each table




//instead of making node for skills
//when null is reached, go to parent node to set victor


//FOR TEST PURPOSES
void postOrder(Node * root) {
    if (root == NULL)
        return;

    postOrder(root->l);

    postOrder(root->r);


    printf("%d ", root->value);
}











