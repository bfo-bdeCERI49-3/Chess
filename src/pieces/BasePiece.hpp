#pragma once

#include <stddef.h>

enum Color {
    White = 0,
    Black
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

    private:
        Color color             { White };  // Piece's color
        bool taken              { false };  // True is piece has been taken by enemy
        Coordinates coordinates { 0, 0 };   // Coordinates on the board
};