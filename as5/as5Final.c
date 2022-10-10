//As5, 3/17/21
//Joshua Taggart

#include <stdio.h>
#include <stdlib.h>


//struct
typedef struct Node Node;

struct Node {
    char * name;
    int * tokens;
    Node * next;
};


//functions
//create node for stack
Node * createNode(char * name, int * tokens);
//add to top of stack
Node * addToHead(Node * head, char * name, int * tokens);
//remove top of stack
Node * removeHead(Node * head);
//functions used to free everything at end of program
void freeList(Node * head);
void destroyNode(Node * node);

int main() {

    int t = 1, i, tokens;
    char name[21];

    //set head of node to null by default
    Node * head = NULL;

    while(t != 0) {

        //t keeps track of the menu options which can either be 0, 1, 2, or 3
        scanf("%d", &t);

        switch(t) {
            //exit program
            case 0:
                //if the user types in 0, the program ends
                freeList(head);
                free(head);
                exit(0);
                break;
            //add player
            case 1:
                //scan for tokens and name if t is equal to 1
                scanf("%d %s", &tokens, name);
                //add new user to top of stack
                head = addToHead(head, name, tokens);
                break;
            //player leaving
            case 2:
                //remove user from top of stack
                //what is now at the top of the stack would be the mvp after a user left
                head = removeHead(head);
                break;
            //print MVP
            case 3:
                //prints out name at the top of the stack which is the mvp
                printf("%s\n", head->name);
                break;
        }
    }

    //freeList(head);

}

Node * createNode(char * name, int * tokens) {
    //allocate space for node
    Node * ret = calloc(1, sizeof(Node));
    //set name in struct node
    ret->name = strdup(name);
    //set tokens number in struct node
    ret->tokens = tokens;
    //set next pointer to null
    ret->next = NULL;
    //return the newly created node
    return ret;
}


Node * addToHead(Node * head, char * name, int * tokens) {
    //create node pointer for new head that will be created
    Node * newHead;

    //if the stack is not empty
    if(head != NULL) {
        //if the number of tokens of the new user is less than the current mvp, duplicate the mvp in the stack
        if(tokens < head->tokens) {
            //duplicate mvp
            newHead = createNode(head->name, head->tokens);
            newHead->next = head;
        }
        else {
            //if the new user has more tokens than last mvp, add them to top of stack
            newHead = createNode(name, tokens);
            newHead->next = head;
        }
    }

    //if stack is empty, add new user to stack
    else {
        newHead = createNode(name, tokens);
        newHead->next = head;
    }


    return newHead;
}

Node * removeHead(Node * head) {
    //if the stack is empty there is nothing to remove, return NULL
    if(head == NULL) {
        return NULL;
    }

    //set second node in stack to be the head
    Node * newHead = head->next;

    //free the original head
    free(head);

    //return the newly set head
    return newHead;
}

void destroyNode(Node * node) {
    free(node->name);
    free(node->tokens);
    free(node);
}

void freeList(Node * head) {
    if(head == NULL) {
        return;
    }

    Node * newHead = head->next;
    destroyNode(head);
    freeList(newHead);

}
