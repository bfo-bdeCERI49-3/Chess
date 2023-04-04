#pragma once

#include "./BasePiece.hpp"
#include "../board/board.hpp"

class Bishop : public BasePiece {
    public:
        /**
         * Constructors
        */
        Bishop(Color&, Coordinates&);
        Bishop(Color&, unsigned char, unsigned char);

        /**
         * Evaluates possible movements for said piece and stores it in the available moves for said team
         * @return void
        */
        void evaluateMovements(Board&);
};