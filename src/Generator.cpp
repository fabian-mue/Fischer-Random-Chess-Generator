/**
 * Generator.cpp
 * Generator Class Unit
 *
 * Created on: Okt 1, 2020
 * Authors: Falko Casimiro Ribeiro, Fabian Mündlein
 */

#include "Generator.h"

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
            chessBoard_a[i_u8][j_u8] = '0';
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
       position = '0';
    }
    return position;
}
