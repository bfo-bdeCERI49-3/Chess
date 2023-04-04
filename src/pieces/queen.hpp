#pragma once

#include "./BasePiece.hpp"
#include "../board/board.hpp"

class Queen : public BasePiece {
    public:
        /**
         * Constructors
        */
        Queen(Color&, Coordinates&);
        Queen(Color&, unsigned char, unsigned char);

        /**
         * Evaluates possible movements for said piece and stores it in the available moves for said team
         * @return void
        */
        void evaluateMovements(Board&);
};