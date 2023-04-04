#include "rook.hpp"

/**
 * Rook constructors
*/
Rook::Rook(Color color, size_t x, size_t y, PieceType type) {
    this->color = color;
    this->coordinates = {
        .x = x,
        .y = y
    };
    this->type = type;
};

Rook::Rook(Color color, Coordinates& coordinates, PieceType type) {
    this->color = color;
    this->coordinates = coordinates;
    this->type = type;
};