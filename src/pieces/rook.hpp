#pragma once

#include "./BasePiece.hpp"
#include "../board/board.hpp"

class Rook : public BasePiece {
    public:
        /**
         * Constructors
        */
        Rook(Color, Coordinates&, PieceType);
        Rook(Color, size_t, size_t, PieceType);

        /**
         * Evaluates possible movements for said piece and stores it in the available moves for said team
         * @return void
        */
        void evaluateMovements(Board&);
};