/**
 * Generator.cpp
 * Generator Class Unit
 *
 * Created on: Okt 1, 2020
 * Authors: Falko Casimiro Ribeiro, Fabian Mündlein
 */

#include "Generator.h"
#include <random>

#define FIRST_ROW_INDEX_WHITE (7U)
#define ROW_INDEX_PAWN_WHITE (6U)
#define FIRST_ROW_INDEX_BLACK (0U)
#define ROW_INDEX_PAWN_BLACK (1U)

using std::normal_distribution;

Generator::Generator() {}

Generator::~Generator() {}

void Generator::Init()
{
    uint8_t i_u8;
    uint8_t j_u8;

    for (i_u8 = 0U; i_u8 < CHESS_BOARD_GRID_NUMBERS; i_u8++)
    {
        for (j_u8 = 0U; j_u8 < CHESS_BOARD_GRID_NUMBERS; j_u8++)
        {
            if (ROW_INDEX_PAWN_WHITE == i_u8)
            {
                chessBoard_a[i_u8][j_u8] = "P_w";
            }
            else if (ROW_INDEX_PAWN_BLACK == i_u8)
            {
                chessBoard_a[i_u8][j_u8] = "P_b";
            }
            else
            {
                chessBoard_a[i_u8][j_u8] = "___";
            }
        }
    }
}

std::string Generator::GetBoardPosition(const uint8_t index_row, const uint8_t index_column)
{
    std::string position;

    if ((index_row <= (CHESS_BOARD_GRID_NUMBERS - 1U)) && (index_row >= 0U) &&
            (index_column <= (CHESS_BOARD_GRID_NUMBERS - 1U)) && (index_column >= 0U))
    {
        position = chessBoard_a[index_row][index_column];
    }
    else
    {
       position = "___";
    }
    return position;
}

void Generator::DetermineStartingPositionsRandomly()
{
    uint8_t determinedPosition_u8;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

    /* Define position of white bishop on black field */
    std::uniform_int_distribution<> distrib(0, 3);
    determinedPosition_u8 = 2* distrib(gen);
    chessBoard_a[FIRST_ROW_INDEX_WHITE][determinedPosition_u8] = "B_w";
}
