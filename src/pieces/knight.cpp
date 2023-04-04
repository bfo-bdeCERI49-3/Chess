#include "knight.hpp"

/**
 * Knight's constructors
*/
Knight::Knight(Color, Coordinates& coordinates, PieceType type) {
    this->color = color;
    this->coordinates = coordinates;
    this->type = type;
};

Knight::Knight(Color color, size_t x, size_t y, PieceType type) {
    this->color = color;
    this->coordinates = {
        .x = x,
        .y = y
    };
    this->type = type;
};