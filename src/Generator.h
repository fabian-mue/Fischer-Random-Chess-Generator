/**
 * Generator.h
 * Generator Class Header
 *
 * Created on: Okt 1, 2020
 * Authors: Falko Casimiro Ribeiro, Fabian Mündlein
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <random>
#define CHESS_BOARD_GRID_NUMBERS (8U)
#define FIRST_ROW_INDEX_WHITE (7U)
#define ROW_INDEX_PAWN_WHITE (6U)
#define FIRST_ROW_INDEX_BLACK (0U)
#define ROW_INDEX_PAWN_BLACK (1U)

class Generator
{
    public:
        /* Constructor */
        Generator();

        /*Destructor */
        virtual ~Generator();

        /* Initializes chess board with pawns on their pre-determined positions */
        void InitChessBoard();

        /* Randomly determines the starting positions of all non-pawn chess pieces */
        void DetermineStartingPositionsRandomly();

        /* Get starting position of black pieces by mirroring them */
        void MirrorBlackPieces();

        /* Provided information if input position is free */
        bool IsPositionEmpty(const uint8_t column_u8);

        /* Get chess board position defined by input index of row and column */
        std::string GetBoardPosition(const uint8_t row_u8, const uint8_t column_u8);

        /* Define position of white bishop on white or black field */
        void PlaceBishop(bool whiteField_b);

        /* Define position of white queen */
        void PlaceQueen();

        /* Define position of white knight */
        void PlaceKnight();

        /* Define position of white king */
        void PlaceKing();

         /* Define position of white rook */
        void PlaceRook();

    private:
        std::string chessBoard_a[CHESS_BOARD_GRID_NUMBERS][CHESS_BOARD_GRID_NUMBERS];
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
};

#endif  // GENERATOR_H
