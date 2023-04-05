#include "./board.hpp"
#include "../pieces/BasePiece.hpp"
#include "stdlib.h"
#include <cmath>

Board::Board() {

    /**
     * Inits pieces to their respective place
    */

    /**
     * Black
    */
    this->grid[0][0] = new Rook(Black, 0, 0, ROOK);
    this->grid[0][1] = new Knight(Black, 0, 1, KNIGHT);
    this->grid[0][2] = new Bishop(Black, 0, 2, BISHOP);
    this->grid[0][3] = new Queen(Black, 0, 3, QUEEN);
    this->grid[0][4] = new King(Black, 0, 4, KING);
    this->grid[0][5] = new Bishop(Black, 0, 5, BISHOP);
    this->grid[0][6] = new Knight(Black, 0, 6, KNIGHT);
    this->grid[0][7] = new Rook(Black, 0, 7, ROOK);

    for(int i = 0; i < 8; i++)
        this->grid[1][i] = new Pawn(Black, 1, i, PAWN);

    /**
     * WHITE
    */
    this->grid[7][0] = new Rook(White, 7, 0, ROOK);
    this->grid[7][1] = new Knight(White, 7, 1, KNIGHT);
    this->grid[7][2] = new Bishop(White, 7, 2, BISHOP);
    this->grid[7][3] = new Queen(White, 7, 3, QUEEN);
    this->grid[7][4] = new King(White, 7, 4, KING);
    this->grid[7][5] = new Bishop(White, 7, 5, BISHOP);
    this->grid[7][6] = new Knight(White, 7, 6, KNIGHT);
    this->grid[7][7] = new Rook(White, 7, 7, ROOK);

    for(int i = 0; i < 8; i++)
        this->grid[1][i] = new Pawn(White, 6, i, PAWN);

    /**
     * Copy all created pieces into the pieces array
    */
    for(size_t x = 0; x < 8; x++) {
        for(size_t y = 0; y < 8; y++) {
            if(this->grid[x][y] != nullptr)
                this->pieces[y * 8 + x] = this->grid[x][y];
        }
    }

    /**
     * Initializes arrays for moves
    */
    this->whiteAvailableMoves.size = 10;
    this->whiteAvailableMoves.elements = 0;
    this->whiteAvailableMoves.list = new Move[10];

    this->blackAvailableMoves.size = 10;
    this->blackAvailableMoves.elements = 0;
    this->blackAvailableMoves.list = new Move[10];
};

/**
 * Destructor
*/
Board::~Board() {
    delete[] pieces;
    delete[] grid;
    delete[] whiteAvailableMoves.list;
    delete[] blackAvailableMoves.list;
};

/**
 * Registers an available move for white player
 * @return void
*/
void Board::addWhiteMove(Move* move) {

    List<Move*> moves = this->whiteAvailableMoves;

    /**
     * If more elements in the array than the size of the array return error code
     * 1, 2, 126 – 165 and 255 have special meanings therefore we start from 1000
    */
    if(moves.elements > moves.size)
        exit(1000);

    /**
     * Array not full
    */
    if(moves.elements < moves.size)
        moves.list[moves.elements++] = *move;

    /**
     * Array full
    */
    if(moves.elements == moves.size) {
        size_t newSize = moves.size * floor(sqrt(moves.size));

        // We create a new pointer array
        Move* _ = new Move[newSize];

        // We replace the values
        for(size_t x = 0; x < moves.size; x++)
            _[x] = moves.list[x];
        
        // We set the new size
        moves.size = newSize;

        // We delete the old array
        delete[] moves.list;

        // We replace the old array by the new array
        moves.list = _;

        // We set the new value
        moves.list[moves.elements++] = *move;
    }
}