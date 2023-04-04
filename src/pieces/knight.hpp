#pragma once

#include "./BasePiece.hpp"
#include "../board/board.hpp"

class Knight : public BasePiece {
    public:
        /**
         * Constructors
        */
        Knight(Color&, Coordinates&, PieceType&);
        Knight(Color&, unsigned char, unsigned char);

        /**
         * Evaluates possible movements for said piece and stores it in the available moves for said team
         * @return void
        */
        void evaluateMovements(Board&);
};