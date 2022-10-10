#include <stdio.h>
#include <stdlib.h>

//structs
typedef struct Node Node;

struct Node {
    long long int value;
    long long int victor;
    Node * l;
    Node * r;
};


//functions
Node * createNode(int value);
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
    long long int numplayers, numTables; //, totalExcitement;

    Node * root = NULL;

    scanf("%lld", &numplayers);
    numTables = numplayers - 1;

    int childrenTable[numTables-1];

    //populate table array
    for(i = 0; i < numTables-1; i++) {
        scanf("%d", childrenTable);
    }
    scanf("&d", firstTable);
    //----------------------------


    //populate global user skill array
    skillArray = calloc(numplayers, sizeof(int));

    for(i = 0; i < numplayers; i++) {
        scanf("%lld", skillArray[i]);
    }
    //----------------------------


    //insert table loop
    root = insert(root, firstTable);
    for(i = numTables-1; i < 0; i--) {
        root = insert(root, childrenTable[i])
    }
    //------------------------------

    /*
    array = calloc(numplayers, sizeof(long long int));

    //loop that scans and adds users to tree
    for(i = 0; i < numplayers; i++) {
        //array[i] = calloc(1, sizeof(int));
        scanf("%lld", array[i]);
    }
    */


    //if numplayers == 1, return 1;


    setVictor(root);





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


//wack
Node * addUser(Node * root, long long int value) {


    /*
    if(root == NULL) {
        return createNode(value);
    }

    if(root != NULL) {
        insert(root->l, value);
    }
    */

    if(root->l != NULL) {
        insert(root->l, value);
    }

    else if(root->r != NULL) {
        insert(root->r, value);
    }

    else if(root->l == NULL) {
        root->l = createNode(value);
        return;
        //break here
    }

    else if(root->r == NULL) {
        root->r = createNode(value);
        return;
        //break here
    }

    //traverse tree in post order until you find null pointer

    //find left null pointer, then check if right is also null
    //if right is also null, calculate first 2 skill differences
    //set victor skill to parent

    //find left null pointer, if right is not null
    //store current skill in left pointer (root->victor = skillArray[nullCounter]; nullCounter++;)

    //you find right null pointer, if left is not null
    //store current skill in right pointer



}

//same as createNode except l and r are not set to NULL
//might be unecessary because in setVictor it would go up after null so it wouldnt see the new nulls being made for the scores*****
Node * createSkillNode(int value) {
    Node * ret = calloc(1, sizeof(Node));
    ret->value = value;
    return ret;
}


//do comparisons in different function
//set skills to all of the null slots in this function

//put this in while loop, while nullCounter < numplayers??????
void setVictor(Node * root) {

    if(root == NULL) {
        //root = createSkillNode(skillArray[nullCounter]);

        //nullCounter++;
        return; //go up a level


        //if only left is NULL
        //if root->r->victor == NULL, keep recursing, do nothing
        /*
        if(root->l == NULL && root->r != NULL) {
            if(root->r->victor == NULL) {
                ;
            }

            else {
                root->victor = abs()
            }

        }
        */
        if(root->l == NULL && root->r->victor != NULL) {
            //|(root->r->victor) + (skillArray[i])| = parent->victor
            root->victor = abs()

            nullCounter++;
        }


        //if only right is NULL
        else if(root->l != NULL && root->r == NULL) {

        }

        //if left and right is NULL, we have hit the first table
        else if(root->l == NULL && root->r == NULL) {

        }



    }


    setVictor(root->l, totalExcitement);



    setVictor(root->r, totalExcitement);


}



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







