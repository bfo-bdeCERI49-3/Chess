#pragma once

#include "./BasePiece.hpp"
#include "../board/board.hpp"

class Queen : public BasePiece {
    public:
        /**
         * Constructors
        */
        Queen(Color, Coordinates&, PieceType);
        Queen(Color, size_t, size_t, PieceType);

        /**
         * Evaluates possible movements for said piece and stores it in the available moves for said team
         * @return void
        */
        void evaluateMovements(Board&);
};