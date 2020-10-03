/**
 * main.cpp
 * Main File
 *
 * Created on: Okt 1, 2020
 * Authors: Falko Casimiro Ribeiro, Fabian Mündlein
 */

#include "Generator.h"
#include <iostream>

int main()
{
    Generator generator;
    std::string chessBoard_a[CHESS_BOARD_GRID_NUMBERS][CHESS_BOARD_GRID_NUMBERS];
    uint8_t i_u8;
    uint8_t j_u8;

    generator.Init();

    std::cout << "Initial Chess Board Setup:" << std::endl;

    for (i_u8 = 0U; i_u8 < CHESS_BOARD_GRID_NUMBERS; i_u8++)
    {
        for (j_u8 = 0U; j_u8 < CHESS_BOARD_GRID_NUMBERS; j_u8++)
        {
            chessBoard_a[i_u8][j_u8] = generator.GetBoardPosition(i_u8, j_u8);
            std::cout << chessBoard_a[i_u8][j_u8];
        }
         std::cout << std::endl;
    }
    return 0;
}
