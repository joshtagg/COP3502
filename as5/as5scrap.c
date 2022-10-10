

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
//void removeHead(Node * head);
void destroyNode(Node * node);
void printList(Node * head);
//void destroyNode(Node * garbage);

//pop (removeFromHead)
//destroystack


int main() {

    int t = 1, i, tokens;
    char name[21];

    Node * head = NULL;

    while(t != 0) {
        /*
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
        */

        //printf("pre-scan\n");
        scanf("%d", &t);
        //printf("post-scan\n");

        //printf("T = %d", t);

        switch(t) {
            //exit program
            case 0:
                exit(0);
                break;
            //add player
            case 1:
                //printf("T is 1\n");
                scanf("%d %s", &tokens, name);

                //printf("%d\n", tokens);
                //printf("%s\n", name);

                head = addToHead(head, name, tokens);
                //printf("AFTER\n");
                break;
            //player leaving
            case 2:
                printf("T is 2\n");
                //removeHead(head);

                head = removeHead(head);

                break;
            //print MVP
            case 3:
                //printf("T is 3\n");
                printf("--- %s ---\n", head->name);
                //printList(head);
                break;

        }

    }



}

Node * createNode(char * name, int * tokens) {
    //printf("start of createNode\n");
    Node * ret = calloc(1, sizeof(Node));
    ret->name = strdup(name);
    ret->tokens = tokens;
    ret->next = NULL;
    //printf("end of createNode\n");
    return ret;
}


Node * addToHead(Node * head, char * name, int * tokens) {

    //printf("entered addtohead\n");
    Node * newHead;

    //if head->tokens != NULL
    if(head != NULL) {
        //printf("first if\n");
        if(tokens < head->tokens) {
            //duplicate head node
            //printf("entered if\n");
            newHead = createNode(head->name, head->tokens);
            newHead->next = head;
        }
        else {
            //printf("entered if, else\n");
            newHead = createNode(name, tokens);
            newHead->next = head;
        }
    }
    /*
    if(tokens < head->tokens) {
        //duplicate head node
        printf("entered if\n");
        newHead = createNode(head->name, head->tokens);
        newHead->next = head;
    }
    */
    else {
        //printf("entered else\n");
        newHead = createNode(name, tokens);
        newHead->next = head;
        //printf("end else\n");
    }

    /*
    Node * newHead = createNode(name);
    newHead->next = head;
    */

    //printf("before return");
    return newHead;
    //printf("after return");
}




Node * removeHead(Node * head) {
    if(head == NULL) {
        return NULL;
    }
    Node * newHead = head->next;
    //destroyNode(head);
    free(head);

    return newHead;
}


/*
void removeHead(Node * head) {

    printf("entered removeHead\n");
    Node * newHead = head->next;
    //destroyNode(head);
    free(head);
}
*/


void destroyNode(Node * node) {
    free(node);
}

void printList(Node * head) {
	if (head == NULL) {
		printf("\n");
		return;
	}
	printf("%s -> ", head->name);
	printList(head->next);
}










