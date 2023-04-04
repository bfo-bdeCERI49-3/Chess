#include "king.hpp"

/**
 * King's constructors
*/
King::King(Color, Coordinates& coordinates, PieceType type) {
    this->color = color;
    this->coordinates = coordinates;
    this->type = type;
};

King::King(Color color, size_t x, size_t y, PieceType type) {
    this->color = color;
    this->coordinates = {
        .x = x,
        .y = y
    };
    this->type = type;
};