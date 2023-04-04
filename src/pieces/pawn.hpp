#pragma once

#include "./BasePiece.hpp"
#include "../board/board.hpp"

class Pawn : public BasePiece {
    public:
        /**
         * Constructors
        */
        Pawn(Color&, Coordinates&, PieceType&);
        Pawn(Color&, unsigned char, unsigned char);

        /**
         * Evaluates possible movements for said piece and stores it in the available moves for said team
         * @return void
        */
        void evaluateMovements(Board&);
};