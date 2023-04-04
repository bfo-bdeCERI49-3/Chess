#pragma once

#include "./BasePiece.hpp"
#include "../board/board.hpp"

class Pawn : public BasePiece {
    public:
        /**
         * Constructors
        */
        Pawn(Color, Coordinates&, PieceType);
        Pawn(Color, size_t, size_t, PieceType);

        /**
         * Evaluates possible movements for said piece and stores it in the available moves for said team
         * @return void
        */
        void evaluateMovements(Board&);

        /**
         * Returns how many movements a pawn did do
         * @return unsigned char
        */
       inline unsigned char getMovementCounter() { this->movementCounter; };

    private:
        unsigned char movementCounter { 0 };
};