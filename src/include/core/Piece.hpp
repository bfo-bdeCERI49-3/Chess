#pragma once

#include <stddef.h>
#include "board.hpp"

class Board;

enum Color {
    White = 0,
    Black
};

enum PieceType {
    KING = 0,
    QUEEN,
    ROOK,
    KNIGHT,
    BISHOP,
    PAWN
};

struct Coordinates {
    size_t x;
    size_t y;
};

class Piece {

    public:

        /**
         * CONSTRUCTOR
        */
        Piece(Color, Coordinates, PieceType);
        Piece(Color, size_t, size_t, PieceType);
        
        /**
         * Get color of piece
         * @return Color
        */
        inline Color getColor() { return this->color; };
        
        /**
         * Get coordinates of piece on the board
         * @return Coordinates
        */
        inline Coordinates getCoordinates() { return this->coordinates; };

        /**
         * Returns true if the enemy did take the piece, false if not
         * @return bool
        */
        inline bool isTaken() { return this->taken; };

        /**
         * Returns type of the piece
         * @return PieceType
        */
        inline PieceType getType() { return this->type; };

        /**
         * Evaluates possible movements for said piece and stores it in the available moves for said team
         * @return void
        */
        void evaluateMovements(Board&);

        /**
         * Returns how many movements a pawn did do
         * @return unsigned char
        */
       inline unsigned char getMovementCounter() { this->movementCounter; };

        /**
         * Creates a move for a piece and returns a pointer to said move variable
         * @return Move*
        */
        Move* createMove(Coordinates origin, Coordinates destination);

        /**
         * Returns value of pinned variable
         * @return bool
        */
        inline bool isPinned() { return this->pinned; };
        
    private:
        Color color             { White };  // Piece's color
        bool taken              { false };  // True is piece has been taken by enemy
        Coordinates coordinates { 0, 0 };   // Coordinates on the board
        PieceType type;                     // Type of current piece
        unsigned char movementCounter { 0 };// Movement counter for the piece
        bool pinned { false };              // Piece pinned, cannot move
};