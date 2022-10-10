//Joshua Taggart
//Assignment 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAP 10

//typedefs
typedef struct Piece Piece;
typedef struct List List;
typedef struct Board Board;

//structs
struct Piece {
    int rank, file, ind;
};
struct List {
    int identifier;
    Piece ** arr;
    int size, cap;
};
struct Board {
    List ** arr;
    int size, cap;
};

// Prototypes
Board * createBoard();
List * createRank(int);
Piece * createPiece(int, int, int);
void destroyBoard(Board *, int);
void destroyRank(List *, int);
void destroyPiece(Piece *);
void addPieceToRank(List * , Piece *);
void addRankToBoard(Board *, List *);
void expandRank(List *);
void expandBoard(Board *);
List * findRank(Board *, int);


int main() {
    int i, rank, file, index, total_pieces;

    //Board pointer for rows Board
    Board * rows = createBoard();
    //Board pointer for columns board
    Board * cols = createBoard();

    //scan for amount of pieces user will input
    scanf("%d", &total_pieces);

    //create array for threat finding portion
    //this array will store all of the piece pointers
    Piece piece_Array[total_pieces];


    for(i = 1; i <= total_pieces; i++) {
        scanf("%d %d", &file, &rank);

        // Create array for threat finding portion
        piece_Array[i-1].file = file;
        piece_Array[i-1].rank = rank;
        piece_Array[i-1].ind = i;

        //create piece pointer
        Piece * curPiece = createPiece(file, rank, i);

        //Call findRank for the rows Board
        findRank(rows, i);
        //Call addPieceToRank for the rows board
        addPieceToRank(rows->arr, curPiece);
        //Call findRank for the columns Board
        findRank(cols, i);
        //Call addPieceToRank for the columns board
        addPieceToRank(cols->arr, curPiece);

    }

    //Threat finding loop (incomplete)
    /*
    for(i = 0; i < total_pieces; i++) {

        int minDistance;
        int leftThreat, rightThreat, upThreat, downThreat
        int curLeftThreat, curRightThreat,

        //curRow and curCol are lists
        List * curRow = rows->arr[piece_Array[i].file];
        List * curCol = cols->arr[piece_Array[i].rank];


        //find all attackers in row
        //loop through all pieces of current row
        for(j = 0; j < curRow->size; j++) {


            //if both pieces in the same rank
            if(piece_Array[j].rank == piece_Array[i].rank) {

                //if piece is to the right of piece[i]
                if(piece_Array[j].file > piece_Array[i].file) {

                }
                //if piece is to the left of piece[i]
                if(piece_Array[j].file < piece_Array[i].file) {
                    //note how far away
                    //if closer than minDistance, replace minDistance


                }

            }
            //if both pieces in the same file
            if(piece_Array[j].file == piece_Array[i].file) {


            }


        }

        for(j = 0; j < curCol->size; j++) {



        }




        //after both row and col,loops, print number of threats and which pieces threat current piece (id)
        //%d %d, numThreats, threatID
        //loop will continue by going to the next piece in ARRAY

    }
    */


    //call all destroy functions to clear memory
    //destroyBoard(rows);
    //destroyBoard(cols);
    destroyBoard(rows, 1);
    destroyBoard(cols, 0);

    return 0;
}

Board * createBoard() {
    //allocate memory for size of Board
    //create ret, Board pointer
    Board * ret = (Board *) calloc(1, sizeof(Board));

    //create the array of list pointers
    ret->arr = (List **)calloc(DEFAULT_CAP, sizeof(List *)); //not **

    //setup capacity to default
    ret->cap = DEFAULT_CAP;

    //set size to 0 initially
    ret->size = 0;

    //return the board pointer
    return ret;
}

List * createRank(int identifier) { //int is identifier
    //allocate memory for size of List
    //create ret, List pointer
    List * ret = (List *) calloc(1, sizeof(List));

    //whatever the identifier is when the function is called gets set as the identifier
    ret->identifier = identifier;
    //set the size to 0 initially
    ret->size = 0;
    //set capacity to default
    ret->cap = DEFAULT_CAP;
    //creates rank, gives it 10 spaces
    ret->arr = (Piece **) calloc(DEFAULT_CAP, sizeof(Piece *));

    //return the List pointer
    return ret;
}

Piece * createPiece(int file, int rank, int index) {
    //allocate memory for the size of Piece
    //create ret, Piece pointer
    Piece * ret = (Piece *) calloc(1, sizeof(Piece));

    //file that is passed in
    ret->file = file;
    //index passed in
    ret->ind = index;
    //rank passed in
    ret->rank = rank;

    //return the Piece pointer
    return ret;
}

void destroyBoard(Board * curBoard, int shouldFree) {
    int i;

    //call destroyRank for every rank in the board
    for(i = 0; i < curBoard->size; i++) {
        destroyRank(curBoard->arr[i], shouldFree);
    }

    //Free the array of list pointers
    free(curBoard->arr);

    //Free actual array list
    free(curBoard);
}


//free everything inside the rank (each individual piece), then free the rank itself
void destroyRank(List * pieceList, int shouldFree) {
    int i;

    //Loop through all the pieces in the list and free them
    for(i = 0; i < pieceList->size; i++) {
        if(shouldFree == 1) {
            destroyPiece(pieceList->arr[i]);
        }
    }

    //Free the array of piece pointers
    free(pieceList->arr);

    //Free the actual array list
    free(pieceList);
}

void destroyPiece(Piece * onePiece) {

    //frees each part of the piece struct
    free(onePiece->file);
    free(onePiece->rank);
    free(onePiece->ind);

    //free the piece struct itself
    free(onePiece);
}


void addPieceToRank(List * curList, Piece * curPiece) {

    //If rank cap has been reached
    if(curList->size == curList->cap) {
        //Call the expand rank function to expand the cap
        expandRank(curList);
    }

    //Add the piece to the rank
    curList->arr[curList->size] = curPiece;

    //Each time a piece is added to rank, increase the rank size by +1
    curList->size++;

}

void addRankToBoard(Board * curBoard, List * curList) {

    //If board cap has been reached
    if(curBoard->size == curBoard->cap) {
        //expand board cap
        expandBoard(curBoard);
    }

    //Add the List to the Board
    curBoard->arr[curBoard->size] = curList;

    //Each time a rank is added to the board, increase the board size by +1
    curBoard->size++;
}

void expandRank(List * curList) {

    //when list cap is reached, double its size for more space
    int newCap = curList->cap * 2;

    //realloc the new space created when the cap was doubled
    curList->arr = (Piece **) realloc(curList->arr, newCap * sizeof(Piece *));
    //set the new cap size
    curList->cap = newCap;
}

void expandBoard(Board * curBoard) {

    //when board cap is reached, double its size for more space
    int newCap = curBoard->cap * 2;

    //realloc the new space created when the cap was doubled
    curBoard->arr = (List **) realloc(curBoard->arr, newCap * sizeof(List *));
    //set the new cap size
    curBoard->cap = newCap;
}

//checks to see if rank is already on the board
List * findRank(Board * board, int checking_identifier) { //board and identifier from list, findUser

    int i, ret;


    //loop for the number of times of the boards size
    for(i = 0; i < board->size; i++) {
        //list pointer
        List * curList = board->arr[i];
        //if rank is found, return that spot in the array
        if(curList->identifier == checking_identifier) {
            return board->arr[i];
        }
    }

    //If rank is not found, call the createRank function with the identifier that was passed it
    ret = createRank(checking_identifier);

    //call function to add the rank to the board
    addRankToBoard(board, ret);

    //return what was returned from the createRank function
    return ret;
}

