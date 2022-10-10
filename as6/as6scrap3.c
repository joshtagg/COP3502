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

    totalExcitement = 0;

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


    /*
    //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    // set these 3 loops inside of if(root==NULL) after return;
    //before return; do nullCounter++;
    //this might be better method, set skill to parent prematurely
    //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    if(root->victor != NULL && root->r == NULL) {


        //compare root->victor to root->l->victor, whichever is bigger becomes the root->victor
        //calculate difference

    }

    if(root->victor != NULL && root->l == NULL) {

    }

    if(root->l == NULL && root->r == NULL) {
        //find difference between skillArray[nullCounter] and skillArray[nullCounter-1] <-*i think its -1
    }



    //::::::::::::::::::::::::::::::::::::::::::
    // set these 3 loops inside of if(root==NULL) after return; NO
    //run these comparisons for every single table node reached, so do outside of if loop
    //::::::::::::::::::::::::::::::::::::::::::
    //if left is null and right has a victor
    if(root->l == NULL && root->r->victor != NULL) {
        //compare root victor to r victor, set larger number to become root->victor


    }

    if(root->r == NULL && root->l->victor != NULL) {
        //comparing skillArray[nullCounter+2] and root->l->victor
    }

    if(root->l == NULL && root->r == NULL) {

    }
    */

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


    if(root == NULL) {
        //root = createSkillNode(skillArray[nullCounter]);

        nullCounter++;


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

    }

    //if left is null, right is node, recurse
    if(root->l == NULL && root->r != NULL) {

        //some of these might be redundant/unnecessary

        //if right node is storing a victor
        if(root->r->victor != NULL) {
            totalExcitement += abs(skillArray[nullCounter] - root->r->victor);

            if(skillArray[nullCounter] > root->r->victor) {
                root->victor = skillArray[nullCounter];
            }
            else {
                root->victor = root->r->victor;
            }
            nullCounter++;
        }

        else if(root->r->left != NULL) {


        }
        else if(root->r->right != NULL) {

        }

        else {
            root->left == skillArray[nullCounter];
            nullCounter++;
        }

        setVictor(root->r);

    }


    //if right is null, left is node, recurse
    if(root->r == NULL && root->l != NULL) {

    }


    setVictor(root->l);



    setVictor(root->r);


    /*
    if(root->l == NULL && root->r == NULL) {
        //find difference between skillArray[nullCounter] and skillArray[nullCounter-1] <-*i think its -1
    }

    //if parent is storing victor and l is storing victor, r is null
    else if(root->l == NULL) {
        //compare root->victor to root->l->victor, whichever is bigger becomes the root->victor
        //calculate difference

        //if r is null, skillArray[nullCounter-1]

    }

    //if parent is storing victor and r is storing victor, l is null
    else if(root->victor != NULL && root->l == NULL) {

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










