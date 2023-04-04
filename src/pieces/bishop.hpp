#pragma once

#include "./BasePiece.hpp"
#include "../board/board.hpp"

class Bishop : public BasePiece {
    public:
        /**
         * Constructors
        */
        Bishop(Color, Coordinates&, PieceType);
        Bishop(Color, size_t, size_t, PieceType);

        /**
         * Evaluates possible movements for said piece and stores it in the available moves for said team
         * @return void
        */
        void evaluateMovements(Board&);
};