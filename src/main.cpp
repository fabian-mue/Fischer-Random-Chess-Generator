/**
 * main.cpp
 * Main File
 *
 * Created on: Okt 1, 2020
 * Authors: Falko Casimiro Ribeiro, Fabian Mündlein
 */

#include "Generator.h"
#include "Board.h"
#include <iostream>

static void DefineAbstractChessBoard();

static void DefineAbstractChessBoard()
{
    Generator generator;
    MyBoard myBoard;
    std::string abstractBoard_a[CHESS_BOARD_GRID_NUMBERS * CHESS_BOARD_GRID_NUMBERS];
    uint8_t i_u8;
    uint8_t j_u8;

    generator.InitChessBoard();
    generator.DetermineStartingPositionsRandomly();

    std::cout << "Current Generated Chess Board Setup:" << std::endl;
    for (i_u8 = 0U; i_u8 < CHESS_BOARD_GRID_NUMBERS; i_u8++)
    {
        for (j_u8 = 0U; j_u8 < CHESS_BOARD_GRID_NUMBERS; j_u8++)
        {
            abstractBoard_a[i_u8*CHESS_BOARD_GRID_NUMBERS + j_u8] = generator.GetBoardPosition(i_u8, j_u8);
            std::cout << abstractBoard_a[i_u8*CHESS_BOARD_GRID_NUMBERS + j_u8] << " ";
        }
        std::cout << std::endl;
    }
    myBoard.SetAbstractChessBoard(abstractBoard_a);
}

class FischerChessGeneratorApp : public wxApp
{
    public:
        virtual bool OnInit()
        {
            ::wxInitAllImageHandlers();
            DefineAbstractChessBoard();
            MyBoard* frame = new MyBoard();
            frame->Show();
            return true;
        }
};

wxIMPLEMENT_APP(FischerChessGeneratorApp);
