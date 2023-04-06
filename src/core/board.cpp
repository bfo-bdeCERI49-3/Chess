#include "../include/core/board.hpp"
#include "../include/core/Piece.hpp"
#include "stdlib.h"
#include <cmath>

Board::Board() {

    /**
     * Inits pieces to their respective place
    */

    /**
     * Black
    */
    this->grid[0][0] = new Piece(Black, 0, 0, ROOK);
    this->grid[0][1] = new Piece(Black, 0, 1, KNIGHT);
    this->grid[0][2] = new Piece(Black, 0, 2, BISHOP);
    this->grid[0][3] = new Piece(Black, 0, 3, QUEEN);
    this->grid[0][4] = new Piece(Black, 0, 4, KING);
    this->grid[0][5] = new Piece(Black, 0, 5, BISHOP);
    this->grid[0][6] = new Piece(Black, 0, 6, KNIGHT);
    this->grid[0][7] = new Piece(Black, 0, 7, ROOK);

    for(int i = 0; i < 8; i++)
        this->grid[1][i] = new Piece(Black, 1, i, PAWN);

    /**
     * WHITE
    */
    this->grid[7][0] = new Piece(White, 7, 0, ROOK);
    this->grid[7][1] = new Piece(White, 7, 1, KNIGHT);
    this->grid[7][2] = new Piece(White, 7, 2, BISHOP);
    this->grid[7][3] = new Piece(White, 7, 3, QUEEN);
    this->grid[7][4] = new Piece(White, 7, 4, KING);
    this->grid[7][5] = new Piece(White, 7, 5, BISHOP);
    this->grid[7][6] = new Piece(White, 7, 6, KNIGHT);
    this->grid[7][7] = new Piece(White, 7, 7, ROOK);

    for(int i = 0; i < 8; i++)
        this->grid[1][i] = new Piece(White, 6, i, PAWN);

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
    this->whiteAvailableMoves = List<Move*>();
    this->blackAvailableMoves = List<Move*>();
};

/**
 * Destructor
*/
Board::~Board() {
    delete[] pieces;
    delete[] grid;
};

/**
 * Registers an available move for white player
 * @return void
*/
void Board::addMove(Move* move, Color color) {
    List<Move*> moves = (color == Black) ? this->blackAvailableMoves : moves = this->whiteAvailableMoves;
    moves.add(move);
};