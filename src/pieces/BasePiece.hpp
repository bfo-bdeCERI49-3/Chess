#pragma once

#include <stddef.h>
#include "../board/board.hpp"

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

    private:
        Color color             { White };  // Piece's color
        bool taken              { false };  // True is piece has been taken by enemy
        Coordinates coordinates { 0, 0 };   // Coordinates on the board
        PieceType type;                     // Type of current piece
};