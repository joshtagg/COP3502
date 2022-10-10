
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node Node;

struct Node {
	char * name;
	Node * next;
};

Node * createNode(char * name);
void destroyNode(Node * garbage);
Node * addToHead(Node * head, char * name);
Node * addToTail(Node * head, char * name);
Node * removeHead(Node * head);
Node * removeTail(Node * head);
void printList(Node * head);
void freeList(Node * head);

int main() {
	Node * head = NULL;
	for (int i = 0; i < 10000; i++) {
		head = addToHead(head, "Alice");
		//printList(head);
		// head = addToTail(head, "Bob");
		//printList(head);
		//head = addToTail(head, "Carol");
		//printList(head);
	}
	
	freeList(head);
	
	return 0;
}


Node * createNode(char * name) {
	Node * ret = calloc(1, sizeof(Node));
	ret->name = strdup(name);
	ret->next = NULL; // redundant because of calloc
	return ret;
}

void destroyNode(Node * garbage) {
	free(garbage->name);
	free(garbage);
}

// Add to the head
// Return the resulting head of the list
Node * addToHead(Node * head, char * name) {
	Node * newHead = createNode(name);
	
	newHead->next = head;
	
	return newHead;
}

// Add to the tail
// Return the resulting head of the list
Node * addToTail(Node * head, char * name) {
	if (head == NULL)
		return createNode(name);
	
	/*
	Node * current = head;
	while (head->next != NULL) { // while not at tail
		current = current->next;
	}
	
	// make the old tail point to the new element
	current->next = createNode(name);
	*/
	head->next = addToTail(head->next, name);
	
	return head;
}

// return the head of the list
Node * removeHead(Node * head) {
	Node * newHead = head->next;
	destroyNode(head);
	return newHead;
}

// remove the tail and return the head of the list
Node * removeTail(Node * head) {
	if (head == NULL) return NULL;
	if (head->next == NULL) {
		destroyNode(head);
		return NULL;
	}
	head->next = removeTail(head->next);
	return head;
}

void printList(Node * head) {
	if (head == NULL) { 
		printf("\n");
		return;
	}
	printf("%s -> ", head->name);
	printList(head->next);
}

void freeList(Node * head) {
	if (head == NULL) {
		return;
	}
	Node * newHead = head->next;
	destroyNode(head);
	freeList(newHead);
}

