#pragma once

#include "../pieces/BasePiece.hpp"

enum Color;
enum PieceType;
struct Coordinates;
class BasePiece;

class Move {
    public:
        Coordinates originCoordinates;      // Starting position of the move
        Coordinates destinationCoordinates; // Ending position of the move
};

class Board {
    private:
        /**
         * 2D Grid representing the checker
        */
        BasePiece* grid[8][8] { nullptr };

        /**
         * Grid representing all available moves for White player
        */
        Move* whiteAvailableMoves { nullptr };

        /**
         * Grid representing all available moves for Black player
        */
        Move* blackAvailableMoves { nullptr };

        /**
         * 0 if white player's turn, 1 if black player's turn
        */
        unsigned char playerTurn { 0 };

        /**
         * Pieces on the Checker
        */
        BasePiece* pieces[32] { nullptr };

    public:
        /**
         * CONSTRUCTOR
        */
        Board();

        /**
         * Returns the piece at coordinates (x,y) or nullptr if no piece is present
         * @return BasePiece* or nullptr
        */
        inline BasePiece* get(size_t x, size_t y) { return this->grid[x][y]; };

        /**
         * Get all of White player's available moves
         * @return Move*
        */
        inline Move* getWhiteAvailableMoves() { return this->whiteAvailableMoves; };

        /**
         * Get all of Black player's available moves
         * @return Move*
        */
        inline Move* getBlackAvailableMoves() { return this->blackAvailableMoves; };

        /**
         * Returns which player's turn it is - 1 if black's turn, 0 if white's turn
         * @return unsigned char
        */
        inline unsigned char getTurn() { return this->playerTurn; };

        /**
         * Move piece from one place to another
         * @param Move - Move to make
         * @return
        */
        void movePiece(Move& move);
};