//As5

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


int main() {

    int t = 1, i, tokens;
    char name[21];

    Node * head = NULL;

    while(t != 0) {

        scanf("%d", &t);

        switch(t) {
            //exit program
            case 0:
                exit(0);
                break;
            //add player
            case 1:
                scanf("%d %s", &tokens, name);

                head = addToHead(head, name, tokens);
                break;
            //player leaving
            case 2:
                head = removeHead(head);
                break;
            //print MVP
            case 3:

                printf("--- %s ---\n", head->name);

                break;

        }

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

    if(head != NULL) {

        if(tokens < head->tokens) {
            newHead = createNode(head->name, head->tokens);
            newHead->next = head;
        }
        else {
            newHead = createNode(name, tokens);
            newHead->next = head;
        }
    }

    else {
        newHead = createNode(name, tokens);
        newHead->next = head;
    }


    return newHead;
}

Node * removeHead(Node * head) {
    if(head == NULL) {
        return NULL;
    }
    Node * newHead = head->next;

    free(head);

    return newHead;
}









