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
#define CHESS_BOARD_GRID_NUMBERS (8U)


class Generator
{
    public:
        /* Constructor */
        Generator();

        /*Destructor */
        virtual ~Generator();

        /* Initialize Generator and set up chess board with pawns on
         * their pre-determined positions */
        void Init();

        /* Randomly determines the starting positions of all non-pawn chess pieces */
        void DetermineStartingPositionsRandomly();

        /* Get chess board position defined by input index of row and column */
        std::string GetBoardPosition(const uint8_t index_row, const uint8_t index_column);

    private:
        std::string chessBoard_a[CHESS_BOARD_GRID_NUMBERS][CHESS_BOARD_GRID_NUMBERS];
};

#endif  // GENERATOR_H
