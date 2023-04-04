#pragma once

#include "./BasePiece.hpp"
#include "../board/board.hpp"

class King : public BasePiece {
    public:
        /**
         * Constructors
        */
        King(Color&, Coordinates&);
        King(Color&, unsigned char, unsigned char);

        /**
         * Evaluates possible movements for said piece and stores it in the available moves for said team
         * @return void
        */
        void evaluateMovements(Board&);
};