//Josh t

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAP 10

// Some typedefs to make life easier
typedef struct Piece Piece;
typedef struct List List;
typedef struct Board Board;

// Our structs
struct Piece {
    int rank, file, ind; //ind is for saying _ piece is attacking _ piece
};
struct List { //like a rank or file, think of like rows
    int identifier; //row number, 1, 2, 3, 4
    Piece ** arr;
    int size, cap;
};
struct Board {
    List ** arr; //array of pointers to rank or files
    int size, cap;
};

// Prototypes


//i thought we are only allocating the spots on the board based on user input not the whole board needed
//explain how the list and board structs are supposed to be used, create board size based on furthest point?
//like for board are we basically making a 2d array based on where the pieces are?
Board * createBoard();
List * createRank(int); //create spot for piece to go?
Piece * createPiece(int, int, int); //(file, rank, index) index is which piece? (first, second, etc)
void destroyBoard(Board *, int); //clear memory (destroy means freeing memory)
void destroyRank(List *, int); //clear memory
void destroyPiece(Piece *); //clear memory
void addPieceToRank(List * , Piece *); //edit struct/array
void addRankToBoard(Board *, List *); //edit struct/array, ------adding an extra row if one isnt already made
void expandRank(List *); //allocate memory
void expandBoard(Board *); //allocate memory
List * findRank(Board *, int);


//scanf("%[^\n]s") instead of fscanf to read line?

int main() {

    Board * rows = createBoard();
    Board * cols = createBoard();

    //create ARRAY


    int i, rank, file, index, total_pieces;

    //create memory for 2 boards and ARRAY
    //Board * rankBoard = createBoard //do this twice for both boards?


    //however many callocs or mallocs you have, you need to free that many times

    //user input subtract variable -1
    printf("how many pieces:\n");
    scanf("%d", &total_pieces);

    //ARRAY based on total_pieces
    Piece piece_Array[total_pieces];


    for(i = 1; i <= total_pieces; i++) {
        scanf("%d %d", &file, &rank);

        piece_Array[i-1].file = file;
        piece_Array[i-1].rank = rank;
        piece_Array[i-1].ind = i;

        /*
        //scan rank and file, throw into function
        createPiece(file, rank, i);

        //call findRank here
        //if rank doesn't exist, this will create a rank
        findRank(rows, i);
        findRank(cols, i);

        //call addPiecetoRank here, add piece to ARRAY
        //i am not calling addRanktoBoard anywhere, UH OH
        addPieceToRank(rows->arr, createPiece(file, rank, i)); //call list and piece
        addPieceToRank(cols->arr, createPiece(rank, file, i));

        //add created pieces to ARRAY in loop?
        */

        //create piece pointer here
        Piece * curPiece = createPiece(file, rank, i);

        //findrank
        findRank(rows, i);
        //addpiecetorank
        addPieceToRank(rows->arr, curPiece);
        //findrank
        findRank(cols, i);
        //addpiecetorank
        addPieceToRank(cols->arr, curPiece);

    }

    /*
    // THREAT LOOP
    //create ARRAY to store all pieces for elimination
    //      start with a piece, go to rank of that piece, compare between other pieces of that rank
    //      loop through pieces in rank, loop through pieces in file
    //store temp variable: this piece can attack this piece

    //Logic for elimination:
    //check if in same rank or file and if its the closest piece
    //when in rank 1, compare file 2, 3, 4, etc.


    int minDistance, keep replacing to find the smallest one



    //check by row and then by col
    //find piece that is the min distance from current piece in threat loop


    for(i = 0; i < total_pieces; i++) {

        int minDistance;
        int leftThreat, rightThreat, upThreat, downThreat
        int curLeftThreat, curRightThreat,


        //board->row->identifier for row
        //rows->arr->identifier

        //start with a piece, piece_Array[i]

        //curRow and curCol are lists
        List * curRow = rows->arr[piece_Array[i].file];
        List * curCol = cols->arr[piece_Array[i].rank];



        //find all attackers in row
        //loop through all pieces of current row
        for(j = 0; j < curRow->size; j++) {



            //piece_Array[i] is what we are comparing to every other piece



            //------------------------------------------------------------------------------------


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






        //after both row and col,loops, print number of threats and which pieces threat current piece (id)
        //%d %d, numThreats, threatID
        //loop will continue by going to the next piece in ARRAY

    }



    */






    //call all destroy functions below
    destroyBoard(rows, TRUE);
    destroyBoard(cols, FALSE);
    //clean ARRAY




    //time ./a/out



    return 0;
}

/*
//Repl memory Checker:
//gcc main.c (or file name instead of main)
//valgrind --leak-check=full ./a.out
*/


//loop through ARRAY to free pieces

Board * createBoard() {
    //setting up the cap of board defaultcap

    Board * ret = (Board *) calloc(1, sizeof(Board));
    //Board * ret = calloc(1, sizeof(Board));
    printf("calloc called in createBoard\n");

    //create the array of list pointers
    ret->arr = (List **)calloc(DEFAULT_CAP, sizeof(List *)); //not **
    //ret->arr = calloc(DEFAULT_CAP, sizeof(List *));

    //setup capacity to default
    ret->cap = DEFAULT_CAP;

    //set size to 0 initially?
    ret->size = 0;


    return ret;
}

List * createRank(int identifier) { //int is identifier
    //setting up the cap of rank (row) to defaultcap
    List * ret = (List *) calloc(1, sizeof(List));
    //List * ret = calloc(1, sizeof(List));

    ret->identifier = identifier; //whatever the identifier is when the function is called gets set as the identifier
    ret->size = 0;
    ret->cap = DEFAULT_CAP;
    ret->arr = (Piece **) calloc(DEFAULT_CAP, sizeof(Piece *)); //creates rank, gives it 10 spaces
    //ret->arr = calloc(DEFAULT_CAP, sizeof(Piece *));
    printf("calloc called in createRank\n");


    return ret;
}
//mem allocate
Piece * createPiece(int file, int rank, int index) {
    Piece * ret = (Piece *) calloc(1, sizeof(Piece));
    //Piece * ret = calloc(1, sizeof(Piece));

    printf("calloc called in createPiece\n");

    ret->file = file; //file that is passed in
    ret->ind = index; //index passed in
    ret->rank = rank; //rank passed in

    //call findRank to see if rank exists
    //if rank doesnt exist -> addRankToBoard
    //call addPiecetoRank
    //do i call createRank in addPiecetoRank?????????????????


    //print statements, _ piece was created with _ rank, _ file

    return ret;
}



// IGNORE FOR NOW
void destroyBoard(Board * curBoard, int shouldFree) {
    int i;

    for(i = 0; i < curBoard->size; i++) {
        destroyRank(curBoard->arr[i], shouldFree);

    }

    //Free array of list pointers
    free(curBoard->arr);

    //Free actual array list
    free(curBoard);
    //printf("Board destroyed in destroyBoard\n");
}


// IGNORE FOR NOW
void destroyRank(List * pieceList, int shouldFree) {
    int i;


    //(size of array (list))
    //for loop, i < arr->size
    //    call destroyPiece

    for(i = 0; i < pieceList->size; i++) {
        //List * curList = pieceList->arr[i];
        if (shouldFree == 1) {
            destroyPiece(pieceList->arr[i]);
        }
    }

    //Free the array of piece pointers
    free(pieceList->arr);

    //Free the actual array list
    free(pieceList);

    //printf("Rank destroyed in destroyRank\n");

    //free everything inside the rank (each individual piece), then free the rank itself
}


void destroyPiece(Piece * onePiece) {

    //free(piece); frees each piece for all pieces in the rank
    free(onePiece->file);
    free(onePiece->rank);
    free(onePiece->ind);

    free(onePiece);

    //printf("Piece destroyed in destroyPiece\n");

}

/*
void addPieceToRank(List * curList, Piece * curPiece) { //addFriendtoUser

    printf("addPieceToRank called\n");

    //add pieces to list until it reaches cap
    //then call expandRank to increase cap

    if(curList->size == curList->cap) {
        //if rank cap has been reached
        //expand rank cap
        expandRank(curList);
    }

    curList->arr[curList->size] = createPiece(curPiece->file, curPiece->rank, curPiece->ind);
    curList->size++;

}

void addRankToBoard(Board * curBoard, List * curList) {

    printf("addRankToBoard called\n");

    //add ranks to board until it reaches cap
    //then call expandBoard to increase cap
    if(curBoard->size == curBoard->cap) {
        //expand board cap
        expandBoard(curBoard); //correct syntax?
    }

    //call createRank
    curBoard->arr[curBoard->size] = createRank(curList->identifier); //i think thats called properly
    curBoard->size++;

}
*/
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
    //when list(think of a row) cap is reached, double it

    printf("expandRank called\n");

    int newCap = curList->cap * 2;

    curList->arr = (Piece **) realloc(curList->arr, newCap * sizeof(Piece *)); //piece * right?, correct syntax?
    //curList->arr = realloc(curList->arr, newCap * sizeof(Piece *));
    curList->cap = newCap;

}

void expandBoard(Board * curBoard) {

    printf("expandBoard called\n");

    //when board cap is reached, double it
    int newCap = curBoard->cap * 2;

    curBoard->arr = (List **) realloc(curBoard->arr, newCap * sizeof(List *)); //is list * right?, correct syntax?
    //curBoard->arr = realloc(curBoard->arr, newCap * sizeof(List *));
    curBoard->cap = newCap;


}

//checks to see if rank is already on the board
//board to get board size

List * findRank(Board * board, int checking_identifier) { //board and identifier from list, findUser

    printf("findRank called\n");

    int i, ret;
    //reference findIndex from friendship.c
    //if rank not found, create that new rank
    //int ret;




    //loop for the number of times of the boards size
    for(i = 0; i < board->size; i++) {

        /*
        List * curList = board->arr[i];
        if(identifier == curList->identifier) {
            return i;
        }
        */

        List * curList = board->arr[i];

        if(curList->identifier == checking_identifier) {
            return board->arr[i];
        }

        /*
        //if list(row) already exists
        if(board->arr[i]->identifier == checking_identifier) {
            return board->arr[i];
        }
        */

    }

    //addRankToBoard() <----
    //call createRank instead

    ret = createRank(checking_identifier);

    //return createRank(checking_identifier);

    /*
    addRankToBoard(board, board->arr); //call ret here
    */
    addRankToBoard(board, ret);

    return ret;
}



//LATEST WALL
//i need to finish findRank, addRankToBoard, addPieceToRank
//      understand how all of those functions interact with each other
//understand how to create 2 boards, create ARRAY in main
//      complete main
//finally, work on threat detection in main


//one board identifiers for each list would be the row num/col num
//addRanktoBoard(row), addRanktoBoard(col)


//LATEST TO DO
//Threat loop
//create ARRAY in main








