/**
 * Generator.cpp
 * Generator Class Unit
 *
 * Created on: Okt 1, 2020
 * Authors: Falko Casimiro Ribeiro, Fabian Mündlein
 */

#include "Generator.h"
#include <random>

using std::normal_distribution;

Generator::Generator() {}

Generator::~Generator() {}

void Generator::InitChessBoard()
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

std::string Generator::GetBoardPosition(const uint8_t row_u8, const uint8_t column_u8)
{
    std::string position;

    if ((row_u8 <= (CHESS_BOARD_GRID_NUMBERS - 1U)) && (row_u8 >= 0U) &&
            (column_u8 <= (CHESS_BOARD_GRID_NUMBERS - 1U)) && (column_u8 >= 0U))
    {
        position = chessBoard_a[row_u8][column_u8];
    }
    else
    {
       position = "___";
    }
    return position;
}

bool Generator::IsPositionEmpty(const uint8_t column_u8)
{
    bool free_b;

    if ("___" == chessBoard_a[FIRST_ROW_INDEX_WHITE][column_u8])
    {
        chessBoard_a[FIRST_ROW_INDEX_WHITE][column_u8] = "___";
        free_b = true;
    }
    else
    {
        free_b = false;
    }
    return free_b;
}

void Generator::DetermineStartingPositionsRandomly()
{
    PlaceBishop(true);
    PlaceBishop(false);
    PlaceQueen();
    PlaceKnight();
    PlaceKnight();
    PlaceRook();
    PlaceKing();
    PlaceRook();

    MirrorBlackPieces();
}

void Generator::MirrorBlackPieces()
{
    uint8_t i_u8;
    std::string blackPiece;
    std::string whitePiece;

    for (i_u8 = 0U; i_u8 < CHESS_BOARD_GRID_NUMBERS; i_u8++)
    {
        whitePiece = chessBoard_a[FIRST_ROW_INDEX_WHITE][i_u8];
        blackPiece = whitePiece.replace(2, 1, "b");
        chessBoard_a[FIRST_ROW_INDEX_BLACK][i_u8] = blackPiece;
    }
}

void Generator::PlaceBishop(bool whiteField_b)
{
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib4(0, 3);
    uint8_t determinedPosition_u8;

    if (false != whiteField_b)
    {
        determinedPosition_u8 = 2 * distrib4(gen) + 1;
        chessBoard_a[FIRST_ROW_INDEX_WHITE][determinedPosition_u8] = "B_w";
    }
    else
    {
        determinedPosition_u8 = 2 * distrib4(gen);
        chessBoard_a[FIRST_ROW_INDEX_WHITE][determinedPosition_u8] = "B_w";
    }
}

void Generator::PlaceQueen()
{
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib6(0, 5);
    uint8_t determinedPosition_u8 = distrib6(gen);
    bool queenPlaced_b = false;

    while(!queenPlaced_b)
    {
        if (IsPositionEmpty(determinedPosition_u8))
        {
            chessBoard_a[FIRST_ROW_INDEX_WHITE][determinedPosition_u8] = "Q_w";
            queenPlaced_b = true;
        }
        else
        {
            determinedPosition_u8++;
        }
    }
}

void Generator::PlaceKnight()
{
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib8(0, 7);
    uint8_t determinedPosition_u8 = distrib8(gen);
    bool knightPlaced_b = false;

    while(!knightPlaced_b)
    {
        if (IsPositionEmpty(determinedPosition_u8))
        {
            chessBoard_a[FIRST_ROW_INDEX_WHITE][determinedPosition_u8] = "N_w";
            knightPlaced_b = true;
        }
        else
        {
            determinedPosition_u8 = distrib8(gen);
        }
    }
}

void Generator::PlaceKing()
{
    uint8_t i_u8;
    for (i_u8 = 0U; i_u8 < CHESS_BOARD_GRID_NUMBERS; i_u8++)
    {
        if (IsPositionEmpty(i_u8))
        {
            chessBoard_a[FIRST_ROW_INDEX_WHITE][i_u8] = "K_w";
            break;
        }
    }
}

void Generator::PlaceRook()
{
    uint8_t i_u8;
    for (i_u8 = 0U; i_u8 < CHESS_BOARD_GRID_NUMBERS; i_u8++)
    {
        if (IsPositionEmpty(i_u8))
        {
            chessBoard_a[FIRST_ROW_INDEX_WHITE][i_u8] = "R_w";
            break;
        }
    }
}
