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


    //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    // set these 3 loops inside of if(root==NULL) after return;
    //before return; do nullCounter++;
    //this might be better method, set skill to parent prematurely
    //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    if(root->victor != NULL && root->r == NULL) {
        /*
        //go up a level
        int temp = root->victor
        return;
        root->victor = abs(temp - root->victor);
        */

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





    if(root == NULL) {
        //root = createSkillNode(skillArray[nullCounter]);

        nullCounter++;


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

        /*
        //if only left is null
        if(root->l == NULL && root->r != NULL) {
            //|(root->r->victor) + (skillArray[i])| = parent->victor

            if(root->r->victor != NULL) {
                //combine
                root->victor = abs(root->r->victor + skillArray[nullCounter-1]);
            }

            else {
                nullCounter++;
            }


        }


        //if only right is NULL

        //something behaves different because r only being NULL only occurs on far right of tree only
        else if(root->r == NULL && root->l != NULL) {

            if(root->l->victor != NULL) {
                //combine
                root->victor = abs(root->l->victor + skillArray[nullCounter+1]); //+1 ???
                nullCounter++; //do null counter only for r being NULL???
            }

            else {
                //nullCounter++;
                //dont ++ at else because r only being NULL only occurs at furthest right of tree
                //this means that this is the LAST NULL, do doing ++ would be meaningless

                //STOPPED HERE *********************************^^^^^^^^^^^^^
            }


        }

        //if left and right is NULL, we have hit the first table
        else if(root->l == NULL && root->r == NULL) {

            if()

            //return; again???
        }

        */

    }







    setVictor(root->l, totalExcitement);



    setVictor(root->r, totalExcitement);


    if(root->l == NULL && root->r == NULL) {
        //find difference between skillArray[nullCounter] and skillArray[nullCounter-1] <-*i think its -1
    }

    //if parent is storing victor and l is storing victor, r is null
    else if(root->victor != NULL && root->r == NULL) {
        //compare root->victor to root->l->victor, whichever is bigger becomes the root->victor
        //calculate difference

        //if r is null, skillArray[nullCounter-1]

    }

    //if parent is storing victor and r is storing victor, l is null
    else if(root->victor != NULL && root->l == NULL) {

    }




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









