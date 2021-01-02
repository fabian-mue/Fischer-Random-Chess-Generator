/**
 * Board.cpp
 * Board Unit
 *
 * Created on: Dec 30, 2020
 * Authors: Falko Casimiro Ribeiro, Fabian Mündlein
 */

#include "Board.h"

/* Code partly from:
 * https://stackoverflow.com/questions/61803924/sample-code-for-c-wxwidgets-blit-an-image-to-the-canvas */

static std::string abstractBoard[CHESS_BOARD_GRID_NUMBERS * CHESS_BOARD_GRID_NUMBERS];

MyBoard::MyBoard()
        :wxFrame(NULL, wxID_ANY, "Chess", wxDefaultPosition, wxSize(1000, 1000))
{
    m_board = new wxPanel(this, wxID_ANY);
    m_board->Bind(wxEVT_PAINT, &MyBoard::OnPaint, this);

    // Load the image.
    wxImage im("/home/fabian/Fischer-Random-Chess-Generator/chess_pieces.png", wxBITMAP_TYPE_PNG);

    // Extract the images of the pieces from the larger image.
    wxBitmap b(im);
    m_blackKing = b.GetSubBitmap(wxRect(5,113,100,100));
    m_blackQueen = b.GetSubBitmap(wxRect(110,113,100,100));
    m_blackBishop = b.GetSubBitmap(wxRect(215,113,100,100));
    m_blackKnight = b.GetSubBitmap(wxRect(323,113,100,100));
    m_blackRook = b.GetSubBitmap(wxRect(433,113,100,100));
    m_blackPawn = b.GetSubBitmap(wxRect(535,113,100,100));

    m_whiteKing = b.GetSubBitmap(wxRect(5,7,100,100));
    m_whiteQueen = b.GetSubBitmap(wxRect(110,7,100,100));
    m_whiteBishop = b.GetSubBitmap(wxRect(215,7,100,100));
    m_whiteKnight = b.GetSubBitmap(wxRect(323,7,100,100));
    m_whiteRook = b.GetSubBitmap(wxRect(433,7,100,100));
    m_whitePawn = b.GetSubBitmap(wxRect(535,7,100,100));
}

/*
void MyBoard::InitMappingTable()
{
    mappingTable[0] = {"K_b", m_blackKing.GetSubBitmap(wxRect(0, 0, m_blackKing.GetWidth(), m_blackKing.GetHeight()))};
    mappingTable[1] = {"Q_b", m_blackQueen.GetSubBitmap(wxRect(0, 0, m_blackQueen.GetWidth(), m_blackQueen.GetHeight()))};
    mappingTable[2] = {"B_b", m_blackBishop.GetSubBitmap(wxRect(0, 0, m_blackBishop.GetWidth(), m_blackBishop.GetHeight()))};
    mappingTable[3] = {"N_b", m_blackKnight.GetSubBitmap(wxRect(0, 0, m_blackKnight.GetWidth(), m_blackKnight.GetHeight()))};
    mappingTable[4] = {"R_b", m_blackRook.GetSubBitmap(wxRect(0, 0, m_blackRook.GetWidth(), m_blackRook.GetHeight()))};
    mappingTable[5] = {"P_b", m_blackPawn.GetSubBitmap(wxRect(0, 0, m_blackPawn.GetWidth(), m_blackPawn.GetHeight()))};
    mappingTable[6] = {"K_w", m_whiteKing.GetSubBitmap(wxRect(0, 0, m_whiteKing.GetWidth(), m_whiteKing.GetHeight()))};
    mappingTable[7] = {"Q_w", m_whiteQueen.GetSubBitmap(wxRect(0, 0, m_whiteQueen.GetWidth(), m_whiteQueen.GetHeight()))};
    mappingTable[8] = {"B_w", m_whiteBishop.GetSubBitmap(wxRect(0, 0, m_whiteBishop.GetWidth(), m_whiteBishop.GetHeight()))};
    mappingTable[9] = {"N_w", m_whiteKnight.GetSubBitmap(wxRect(0, 0, m_whiteKnight.GetWidth(), m_whiteKnight.GetHeight()))};
    mappingTable[10] = {"R_w", m_whiteRook.GetSubBitmap(wxRect(0, 0, m_whiteRook.GetWidth(), m_whiteRook.GetHeight()))};
    mappingTable[11] = {"P_w", m_whitePawn.GetSubBitmap(wxRect(0, 0, m_whitePawn.GetWidth(), m_whitePawn.GetHeight()))};
}*/

void MyBoard::SetAbstractChessBoard(const std::string board[])
{
    for (uint8_t i_u8 = 0U; i_u8 < CHESS_BOARD_GRID_NUMBERS; i_u8++)
    {
        for (uint8_t j_u8 = 0U; j_u8 < CHESS_BOARD_GRID_NUMBERS; j_u8++)
        {
            abstractBoard[i_u8*CHESS_BOARD_GRID_NUMBERS + j_u8] = board[i_u8*CHESS_BOARD_GRID_NUMBERS + j_u8];
        }
    }
}

void MyBoard::OnPaint(wxPaintEvent&)
{
    wxPaintDC dc(m_board);
    dc.Clear();

    // Draw thie light squares
    dc.SetPen(wxColour(209,139,71));
    dc.SetBrush(wxColour(209,139,71));
    dc.DrawRectangle(0,0,800,800);

    // Draw thie dark squares
    dc.SetPen(wxColour(255,206,158));
    dc.SetBrush(wxColour(255,206,158));
    for ( int i = 0 ; i< 8 ; ++i )
    {
        for ( int j = i%2 ; j< 8 ; j+=2 )
        {
            dc.DrawRectangle(i*100,j*100,100,100);
        }
    }

    std::string inputPiece;
    for (uint8_t i_u8 = 0U; i_u8 < CHESS_BOARD_GRID_NUMBERS; i_u8++)
    {
        for (uint8_t j_u8 = 0U; j_u8 < CHESS_BOARD_GRID_NUMBERS; j_u8++)
        {
            inputPiece = abstractBoard[i_u8*CHESS_BOARD_GRID_NUMBERS + j_u8];

            // Draw the black pieces
            if (FIRST_ROW_INDEX_BLACK == i_u8)
            {
                if (inputPiece == "K_b")
                {
                    dc.DrawBitmap(m_blackKing, j_u8*100, 0, true);
                }
                else if (inputPiece == "Q_b")
                {
                    dc.DrawBitmap(m_blackQueen, j_u8*100, 0, true);
                }
                else if (inputPiece == "B_b")
                {
                    dc.DrawBitmap(m_blackBishop, j_u8*100, 0, true);
                }
                else if (inputPiece == "N_b")
                {
                    dc.DrawBitmap(m_blackKnight, j_u8*100, 0, true);
                }
                else if (inputPiece == "R_b")
                {
                     dc.DrawBitmap(m_blackRook, j_u8*100, 0, true);
                }
                else
                {

                }
            }

            // Draw the black pawns
            else if (ROW_INDEX_PAWN_BLACK == i_u8)
            {
                dc.DrawBitmap(m_blackPawn, j_u8*100, 100, true);
            }

            // Draw the white pieces
            else if (FIRST_ROW_INDEX_WHITE == i_u8)
            {
                if (inputPiece == "K_w")
                {
                    dc.DrawBitmap(m_whiteKing, j_u8*100, 700, true);
                }
                else if (inputPiece == "Q_w")
                {
                    dc.DrawBitmap(m_whiteQueen, j_u8*100, 700, true);
                }
                else if (inputPiece == "B_w")
                {
                    dc.DrawBitmap(m_whiteBishop, j_u8*100, 700, true);
                }
                else if (inputPiece == "N_w")
                {
                    dc.DrawBitmap(m_whiteKnight, j_u8*100, 700, true);
                }
                else if (inputPiece == "R_w")
                {
                    dc.DrawBitmap(m_whiteRook, j_u8*100, 700, true);
                }
                else
                {

                }
            }

            // Draw the white pawns
            else if (ROW_INDEX_PAWN_WHITE == i_u8)
            {
                dc.DrawBitmap(m_whitePawn, j_u8*100, 600, true);
            }

            else
            {

            }
        }
    }
}
