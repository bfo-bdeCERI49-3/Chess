#include "BasePiece.hpp"

Move* BasePiece::createMove(Coordinates origin, Coordinates destination) {
    Move* move = new Move {
        .originCoordinates = origin,
        .destinationCoordinates = destination
    };
    return move;
}