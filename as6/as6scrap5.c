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

    printf("%lld\n", totalExcitement);
    //printf("final nullCount = %lld\n", nullCounter);

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
        //root = createSkillNode(skillArray[nullCounter]);

        //nullCounter++;


        return; //go up a level



    }


    //call recurse inside of these following loops or call postOrder(root->l); and postOrder(root->); before all??????????
    if(root->l == NULL && root->r == NULL) {
        totalExcitement += abs(skillArray[nullCounter] - skillArray[nullCounter+1]);

        //should be able to just do skillArray[nullCounter++] - skillArray[nullCounter++]
        if(skillArray[nullCounter] > skillArray[nullCounter+1]) {
            root->victor = skillArray[nullCounter];
        }
        else {
            root->victor = skillArray[nullCounter+1];
        }

        nullCounter += 2;
        //printf("first if: nullCount = %lld, current totalExcitement: %lld\n", nullCounter, totalExcitement);

        //move up level?
        return;
    }

    //if left is null, right is node, recurse
    else if(root->l == NULL && root->r != NULL) {

        //some of these might be redundant/unnecessary

        //we are traversing up and hit the root node
        //do we have to make sure root->victor is also null????might be redundant check
        if(root->left != NULL && root->r->victor != NULL) {
            //compare root->left to root->r->victor
            if(root->left > root->r->victor) {
                totalExcitement += abs(root->left - root->r->victor);
                root->victor = root->left;
            }
            else {
                totalExcitement += abs(root->left - root->r->victor);
                root->victor = root->r->victor;
            }

            //TURNED OFF
            //setVictor(root->r);
        }

        //we are traversing down and hit the root node
        if(root->left == NULL && root->r->victor == NULL) {
            root->left = skillArray[nullCounter];
            nullCounter++;
            //printf("second if: nullCount = %lld, current totalExcitement: %lld\n", nullCounter, totalExcitement);
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
        /*
        if(root->right == NULL && root->l->victor == NULL) {

            //wrong
            //do nothing here

            root->right = skillArray[nullCounter];
            nullCounter++;

        }
        */
        if(root->right == NULL && root->l->victor != NULL) {

            if(skillArray[nullCounter] > root->l->victor) {
                totalExcitement += abs(skillArray[nullCounter] -  root->l->victor);
                root->victor = skillArray[nullCounter];
                //might be redundant
                nullCounter++;
                //printf("third if: nullCount = %lld, current totalExcitement: %lld\n", nullCounter, totalExcitement);
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










