#include "../include/core/Piece.hpp"

/**
 * ? CONSTRUCTORS
*/
/**
 * Constructor
 * @param color The color of the piece
 * @param coord The coordinates of the piece
 * @param type The type of the piece
*/
Piece::Piece(Color color, Coordinates coord, PieceType type) {
    this->color = color;
    this->coordinates = coord;
    this->type = type;
}

/**
 * Constructor
 * @param color The color of the piece
 * @param x The x coordinates of the piece
 * @param y The y coordinates of the piece
 * @param type The type of the piece
*/
Piece::Piece(Color color, size_t x, size_t y, PieceType type) {
    this->color = color;
    this->coordinates = {
        .x = x,
        .y = y
    };
    this->type = type;
}

/**
 * @param origin Origin of the move
 * @param destination Destination of the move
 * @return Move*
*/
Move* Piece::createMove(Coordinates origin, Coordinates destination) {
    Move* move = new Move {
        .originCoordinates = origin,
        .destinationCoordinates = destination
    };
    return move;
}