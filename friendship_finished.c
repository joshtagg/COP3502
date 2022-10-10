
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAP 10
#define MAX_LEN 100

// not efficient
// array (n) of arrays (2) of strings (char array)

typedef struct UserList UserList;
typedef struct User User;

struct UserList {
	User ** arr;
	int cap, size;
};
struct User {
	char * name;
	char ** friends;
	int cap, size;
};

UserList * createUserList();
void addFriendToUser(User *, char *);
void addFriendshipFromInput(UserList *);
void printAllFriendships(UserList *);
void destroyAllUsers(UserList *);
User * createUser(char *);
void expandUser(User *);
void expandUserList(UserList *);
void addUserToUserList(UserList *, char *);
int findIndex(UserList *, char *);

// The main method
int main() {
	
	// Build the data structure
	UserList * all_users = createUserList();
	
	// Read in all the friendships
	int num_friendships;
	scanf("%d", &num_friendships);
	for (int i = 0; i < num_friendships; i++) {
		addFriendshipFromInput(all_users);
	}
	
	// Print out frienships
	printAllFriendships(all_users);
	
	// Destroy friendships
	destroyAllUsers(all_users);
	
	// Exit program
	return 0;
}


// Array List 1 Creation
UserList * createUserList() {
	UserList * ret;
	
	// Create the list
	ret = calloc(1, sizeof(UserList));
	
	// Initialize values
	ret->arr = calloc(DEFAULT_CAP, sizeof(User *));
	ret->cap = DEFAULT_CAP;
	ret->size = 0;
	
	return ret;
}

void addFriendshipFromInput(UserList * user_list) {
	char name1[MAX_LEN + 1];
	char name2[MAX_LEN + 1];
	
	// Read in the names
	scanf("%s%s", name1, name2);
	
	// Find the index for both users
	int index1 = findIndex(user_list, name1);
	int index2 = findIndex(user_list, name2);
	
	// Get the user data from the user list
	User * user1 = user_list->arr[index1];
	User * user2 = user_list->arr[index2];
	
	addFriendToUser(user1, name2);
	addFriendToUser(user2, name1);
}

// This is disgusting but it works
void expandUser(User * u) {
	u->friends = realloc(u->friends,
			(u->cap*=2) * sizeof(char *));
}

// Add to array list function
void addFriendToUser(User * u, char * name) {
	if (u->cap == u->size) {
		expandUser(u);
	}
	
	// This is wrong
	// u->friends[u->size] = name;
	u->friends[u->size] = calloc(strlen(name) + 1,
			sizeof(char));
	strcpy(u->friends[u->size], name);
	u->size++;
}

void printAllFriendships(UserList * user_list) {
	for (int i = 0; i < user_list->size; i++) {
		printf("%s is friends with\n", user_list->arr[i]->name);
		for (int j = 0; j < user_list->arr[i]->size;
			j++)
		{
			printf("%s ", user_list->arr[i]->friends[j]);;
		}
		printf("\n\n");
	}
}

void destroyAllUsers(UserList * user_list) {
	// TODO
}


User * createUser(char * name) {
	
	// Make our user data
	User * ret;
	ret = calloc(1, sizeof(User));
	
	// Copy in the name
	ret->name = calloc(strlen(name) + 1, sizeof(char));
	strcpy(ret->name, name);
	
	// create the array values
	ret->friends = calloc(DEFAULT_CAP, sizeof(char *));
	ret->cap = DEFAULT_CAP;
	ret->size = 0;
	
	// Return the finished user
	return ret;
}

void expandUserList(UserList * user_list) {
	int newCap = 2 * user_list->cap;
	user_list->arr = realloc(user_list->arr, 
			newCap * sizeof(User *));
	user_list->cap = newCap;
}

void addUserToUserList(UserList * user_list, char * name) {
	if (user_list->size == user_list->cap) {
		expandUserList(user_list);
	}
	user_list->arr[user_list->size] = 
		createUser(name);
	user_list->size++;
}

int findIndex(UserList * user_list, char * input) {
	for (int i = 0; i < user_list->size; i++) {
		// user_list->arr[i] is a User *
		if (strcmp(input, user_list->arr[i]->name) == 0) {
			return i;
		}
	}
	addUserToUserList(user_list, input);
	return user_list->size - 1;
}

// better idea
// array (size num users) of array (their friends) of strings