#include "../include/core/Piece.hpp"


/**
 * Generates movements for pawns
 * @param pawn Pointer to the pawn
 * @param board Reference to the board
 * @return void
*/
void generatePawnMovements(Piece* pawn, Board& board) {

    /**
     * ? If pawn is pinned, we shouldn't move at all
    */
    if(pawn->isPinned())
        return;

    /**
     * ? Ennemy color
     * ! Black if current pawn is white
     * ! White if curreny pawn is black
    */
    Color ennemyColor = (pawn->getColor() == White) ? Black : White;

    /**
     * ? Current pawn's coordinates
    */
    Coordinates currentCoordinates = pawn->getCoordinates();

    /**
     * ? Direction
     * ! Positive if black pawn
     * ! Negative if white pawn
    */
    int pawnDirection = (ennemyColor == Black) ? 1 : (-1);

    /**
     * ? If something is in front, we shouldn't move at all
    */
    if(board.get(currentCoordinates.x + pawnDirection, currentCoordinates.y) != nullptr)
        return;

    /**
     * ? If on the edge of the board, we shouldn't move at all
    */
    if(currentCoordinates.x == 0 && currentCoordinates.x == 7)
        return;

    /**
     * ? Default move forwards
    */
    board.addMove(pawn->createMove(
        currentCoordinates,
        {
            .x = currentCoordinates.x + pawnDirection,
            .y = currentCoordinates.y
        }),
        pawn->getColor()
    );

    /**
     * ? 2 Squares on first move if nothing in that place
    */
    if(board.get(currentCoordinates.x + (pawnDirection * 2), currentCoordinates.y) == nullptr) {
        /**
         * ? + 2 move forwards
        */
        board.addMove(pawn->createMove(
            currentCoordinates,
            {
                .x = currentCoordinates.x + (pawnDirection * 2),
                .y = currentCoordinates.y
            }),
            pawn->getColor()
        );
    }


    /**
     *  ? X index for 'En passant'
     *  ! 3 if ennemy is black
     *  ! 4 if ennemy is white
    */ 
    size_t enPassantXIndex = (ennemyColor == Black) ? 3 : 4;

    /**
     * ? Check for 'En Passant'
    */
    if(currentCoordinates.x == enPassantXIndex) {
        /**
         * Not on the left side of the board
        */
        if(currentCoordinates.y > 0) {
            /**
             * Check if there is an ennemy
            */
            Piece* adjacentPiece = board.get(currentCoordinates.x, currentCoordinates.y - 1);
            if((adjacentPiece != nullptr) && (adjacentPiece->getColor() == ennemyColor)) {
                /**
                 * Check if it is the ennemy's first movement
                */
                if(adjacentPiece->getMovementCounter() == 1) {
                    /**
                     * ? Create the move and add it to the move list
                    */
                    board.addMove(pawn->createMove(
                        currentCoordinates,
                        {
                            .x = currentCoordinates.x + pawnDirection,
                            .y = currentCoordinates.y - 1
                        }),
                        pawn->getColor()
                    );
                }
            }
        }
        /**
         * Not on the right side of the board
        */
        if(currentCoordinates.y > 0) {
            /**
             * Check if there is an ennemy
            */
            Piece* adjacentPiece = board.get(currentCoordinates.x, currentCoordinates.y + 1);
            if((adjacentPiece != nullptr) && (adjacentPiece->getColor() == ennemyColor)) {
                /**
                 * Check if it is the ennemy's first movement
                */
                if(adjacentPiece->getMovementCounter() == 1) {
                    /**
                     * ? Create the move and add it to the move list
                    */
                    board.addMove(pawn->createMove(
                        currentCoordinates,
                        {
                            .x = currentCoordinates.x + pawnDirection,
                            .y = currentCoordinates.y + 1
                        }),
                        pawn->getColor()
                    );
                }
            }
        }
    }
}

/**
 * Generates movements for the diagonal moving pieces (Bishops & Queens)
 * @param piece Pointer to the piece
 * @param board Reference to the board
 * @return void
*/
void generateDiagonalMovements(Piece* piece, Board& board) {

}

/**
 * Generates movements for the sliding pieces (Bishops & Queens)
 * @param piece Pointer to the piece
 * @param board Reference to the board
 * @return void
*/
void generateSlidingMovements(Piece* piece, Board& board) {

}

/**
 * Generates movements for the King
 * @param piece Pointer to the piece
 * @param board Reference to the board
 * @return void
*/
void generateKingMovements(Piece* king, Board& board) {

}

/**
 * Generates movements for the knights
 * @param piece Pointer to the piece
 * @param board Reference to the board
 * @return void
*/
void generateKnightMovements(Piece* knight, Board& board) {

}

/**
 * ? CONSTRUCTORS
*/
/**
 * Constructor
 * @param color The color of the piece
 * @param coord The coordinates of the piece
 * @param type The type of the piece
*/
Piece::Piece(Color color, Coordinates coord, PieceType type) {
    this->color = color;
    this->coordinates = coord;
    this->type = type;
}

/**
 * Constructor
 * @param color The color of the piece
 * @param x The x coordinates of the piece
 * @param y The y coordinates of the piece
 * @param type The type of the piece
*/
Piece::Piece(Color color, size_t x, size_t y, PieceType type) {
    this->color = color;
    this->coordinates = {
        .x = x,
        .y = y
    };
    this->type = type;
}

/**
 * @param origin Origin of the move
 * @param destination Destination of the move
 * @return Move*
*/
Move* Piece::createMove(Coordinates origin, Coordinates destination) {
    Move* move = new Move {
        .originCoordinates = origin,
        .destinationCoordinates = destination
    };
    return move;
}

/**
 * Evaluates movements for current piece
 * @param board Reference to the board in order to register the move
*/
void Piece::evaluateMovements(Board& board) {
    /**
     * Evaluate movements for piece
    */
    switch (this->type) {
        case PAWN:
            generatePawnMovements(this, board);
            break;
        case BISHOP:
            generateDiagonalMovements(this, board);
            break;
        case ROOK:
            generateSlidingMovements(this, board);
            break;
        case KNIGHT:
            generateKnightMovements(this, board);
            break;
        case QUEEN:
            generateDiagonalMovements(this, board);
            generateSlidingMovements(this, board);
            break;
        case KING:
            generateKingMovements(this, board);
            break;
        default:
            break;
    }
};