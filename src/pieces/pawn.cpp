#include "pawn.hpp"

/**
 * Pawn's constructors
*/
Pawn::Pawn(Color, Coordinates& coordinates, PieceType type) {
    this->color = color;
    this->coordinates = coordinates;
    this->type = type;
};

Pawn::Pawn(Color color, size_t x, size_t y, PieceType type) {
    this->color = color;
    this->coordinates = {
        .x = x,
        .y = y
    };
    this->type = type;
};

void Pawn::evaluateMovements(Board& board) {
    /**
     * Get current pawn coordinates
    */
    Coordinates originCoordinates = this->getCoordinates();

    /**
     * if pawn is white we handle logic for white pawn
    */
    if(color == White) {
        /**
         * Pawn's first move
        */
        if(this->movementCounter <= 0) {
            /**
             * Add it as a possibility
            */
            board.addMove(this->createMove(originCoordinates,
            {
                .x = this->coordinates.x - 2,
                .y = this->coordinates.y
            }
            ),
            White);
        }

        /**
         * Nothing in front of the pawn and not at the edge
        */
        if(board.get(this->coordinates.x - 1, this->coordinates.y) == nullptr && (this->coordinates.x - 1 >= 0)) {
            /**
             * Add it as a possibility
            */
            board.addMove(this->createMove(originCoordinates,
            {
                .x = this->coordinates.x - 1,
                .y = this->coordinates.y
            }
            ), White);
        }

        /**
         * Check for "En passant"
         * if our white pawn is at X = 3, We check if the pawn is at our left and is an ennemy piece and not on the edge of the board                                               
        */
        if(originCoordinates.y - 1 >= 0) {
            if(this->coordinates.x == 3 && board.get(this->coordinates.x, this->coordinates.y - 1)->getType() == PAWN && (board.get(this->coordinates.x, this->coordinates.y - 1)->getColor() == Black)) {
                /**
                 * We check if it's the pawn's first move
                */
                if(board.get(this->coordinates.x, this->coordinates.y - 1)->getMovementCounter() == 1) {
                    /**
                     * Finally, if nothing behind the enemy pawn
                    */
                    if(board.get(this->coordinates.x - 1, this->coordinates.y - 1) == nullptr) {
                        board.addMove(this->createMove(originCoordinates, {
                            .x = this->coordinates.x - 1,
                            .y = this->coordinates.y - 1
                        }), White);
                    }
                }
            }
        }
        /**
         * Check for "En passant"
         * if our white pawn is at X = 3, We check if the pawn is at our right and is an ennemy piece and not on the edge of the board                                               
        */
        if(originCoordinates.y + 1 <= 7) {
            if(this->coordinates.x == 3 && board.get(this->coordinates.x, this->coordinates.y + 1)->getType() == PAWN && (board.get(this->coordinates.x, this->coordinates.y + 1)->getColor() == Black)) {
                /**
                 * We check if it's the pawn's first move
                */
                if(board.get(this->coordinates.x, this->coordinates.y + 1)->getMovementCounter() == 1) {
                    /**
                     * Finally, if nothing behind the enemy pawn
                    */
                    if(board.get(this->coordinates.x - 1, this->coordinates.y + 1) == nullptr) {
                        board.addMove(this->createMove(originCoordinates, {
                            .x = this->coordinates.x - 1,
                            .y = this->coordinates.y + 1
                        }), White);
                    }
                }
            }
        }
    }

    /**
     * if pawn is black we handle logic for white pawn
    */
    if(color == White) {
        /**
         * Pawn's first move
        */
        if(this->movementCounter <= 0) {
            /**
             * Add it as a possibility
            */
            board.addMove(this->createMove(originCoordinates,
            {
                .x = this->coordinates.x + 2,
                .y = this->coordinates.y
            }
            ),
            Black);
        }

        /**
         * Nothing in front of the pawn and not at the edge
        */
        if(board.get(this->coordinates.x + 1, this->coordinates.y) == nullptr && (this->coordinates.x + 1 <= 7)) {
            /**
             * Add it as a possibility
            */
            board.addMove(this->createMove(originCoordinates,
            {
                .x = this->coordinates.x + 1,
                .y = this->coordinates.y
            }
            ), Black);
        }

        /**
         * Check for "En passant"
         * if our white pawn is at X = 3, We check if the pawn is at our left and is an ennemy piece and not on the edge of the board                                               
        */
        if(originCoordinates.y - 1 >= 0) {
            if(this->coordinates.x == 4 && board.get(this->coordinates.x, this->coordinates.y - 1)->getType() == PAWN && (board.get(this->coordinates.x, this->coordinates.y - 1)->getColor() == White)) {
                /**
                 * We check if it's the pawn's first move
                */
                if(board.get(this->coordinates.x, this->coordinates.y - 1)->getMovementCounter() == 1) {
                    /**
                     * Finally, if nothing behind the enemy pawn
                    */
                    if(board.get(this->coordinates.x - 1, this->coordinates.y - 1) == nullptr) {
                        board.addMove(this->createMove(originCoordinates, {
                            .x = this->coordinates.x - 1,
                            .y = this->coordinates.y - 1
                        }), White);
                    }
                }
            }
        }
        /**
         * Check for "En passant"
         * if our white pawn is at X = 3, We check if the pawn is at our right and is an ennemy piece and not on the edge of the board                                               
        */
        if(originCoordinates.y + 1 <= 7) {
            if(this->coordinates.x == 3 && board.get(this->coordinates.x, this->coordinates.y + 1)->getType() == PAWN && (board.get(this->coordinates.x, this->coordinates.y + 1)->getColor() == Black)) {
                /**
                 * We check if it's the pawn's first move
                */
                if(board.get(this->coordinates.x, this->coordinates.y + 1)->getMovementCounter() == 1) {
                    /**
                     * Finally, if nothing behind the enemy pawn
                    */
                    if(board.get(this->coordinates.x - 1, this->coordinates.y + 1) == nullptr) {
                        board.addMove(this->createMove(originCoordinates, {
                            .x = this->coordinates.x - 1,
                            .y = this->coordinates.y + 1
                        }), White);
                    }
                }
            }
        }
    }
}