#include "queen.hpp"

/**
 * Queen's constructors
*/
Queen::Queen(Color, Coordinates& coordinates, PieceType type) {
    this->color = color;
    this->coordinates = coordinates;
    this->type = type;
};

Queen::Queen(Color color, size_t x, size_t y, PieceType type) {
    this->color = color;
    this->coordinates = {
        .x = x,
        .y = y
    };
    this->type = type;
};