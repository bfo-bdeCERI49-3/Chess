#pragma once

#include <stddef.h>
#include "../board/board.hpp"

#include "king.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "pawn.hpp"
#include "queen.hpp"
#include "rook.hpp"

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

class BasePiece {

    public:
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

    protected:
        /**
         * Creates a move for a piece and returns a pointer to said move variable
         * @return Move*
        */
        Move* createMove(Coordinates origin, Coordinates destination);

        Color color             { White };  // Piece's color
        bool taken              { false };  // True is piece has been taken by enemy
        Coordinates coordinates { 0, 0 };   // Coordinates on the board
        PieceType type;                     // Type of current piece
};