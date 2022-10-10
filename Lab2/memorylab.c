
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct author_t author_t;
typedef struct book_t book_t;

struct author_t {
    char name[20];
    int birthYear;
    int publishings;
};

struct book_t {
    char name[20];
    int year;
    int numAuthors;
    author_t * authors;
};


int main() {
    int numBooks, i, j;

    book_t * bookArr;

    scanf("%d", numBooks);

    bookArr = (book_t *) calloc(numBooks, sizeof(book_t));

    for(i = 0; i < numBooks; i++) {
        scanf("%s", bookArr[i].name);
        scanf("%d", &bookArr[i].year);
        scanf("%d", &bookArr[i].numAuthors);

        bookArr[i].authors = (author_t *) calloc(bookArr[i].numAuthors, sizeof(author_t));

        for(j = 0; j < bookArr[i].numAuthors; j++) {
            scanf("%s", bookArr[i].authors[j].name);
            scanf("%d", &bookArr[i].authors[j].birthYear);
            scanf("%d", &bookArr[i].authors[j].publishings);
        }
    }




    //free
    for(i = 0; i < numBooks; i++) {
        free(bookArr[i].authors);
        bookArr[i].authors = NULL; //pointer still points to some memory location, this frees the pointer by pointing it to null
        //good practice to always set pointer to null when freeing
    }
    free(bookArr);
    bookArr = NULL;

    return 0;
}

//function 2, 3, 5, wrong
//2 and 3 returns are right
