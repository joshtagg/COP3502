

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
Node * createNode(char * name, int * tokens);
Node * addToHead(Node * head, char * name, int * tokens);
Node * removeHead(Node * head);
void destroyNode(Node * node);
//void destroyNode(Node * garbage);

//pop (removeFromHead)
//destroystack


int main() {

    int t = 1, i, tokens;
    char name[21];

    Node * head = NULL;

    while(t != 0) {

        scanf("%d", &t);

        scanf("%d %s", &tokens, name);

        //player leaving
        if(t == 2) {
            printf("T is 2\n");
            removeHead(head);
        }

        //print MVP
        if(t == 3) {
            printf("T is 3\n");
            printf("%s", head->name);
        }

        if(t == 1) {
            //scanf("%d", &tokens);
            //scanf("%s", name);

            //scanf("%d %s", &tokens, name);

            printf("%d\n", tokens);
            printf("%s\n", name);

            addToHead(head, name, tokens);

        }


        //printf("%d\n", tokens);
        //printf("%s\n", name);

    }



}

Node * createNode(char * name, int * tokens) {

    Node * ret = calloc(1, sizeof(Node));
    ret->name = strdup(name);
    ret->tokens = tokens;
    ret->next = NULL;
    return ret;
}


Node * addToHead(Node * head, char * name, int * tokens) {

    Node * newHead;

    if(tokens < head->tokens) {
        //duplicate head node
        newHead = createNode(head->name, head->tokens);
    }
    else {
        newHead = createNode(name, tokens);
    }

    /*
    Node * newHead = createNode(name);
    newHead->next = head;
    */

    return newHead;
}




Node * removeHead(Node * head) {
    if(head == NULL) {
        return NULL;
    }
    Node * newHead = head->next;
    destroyNode(head);

    return newHead;
}

void destroyNode(Node * node) {
    free(node);
}











