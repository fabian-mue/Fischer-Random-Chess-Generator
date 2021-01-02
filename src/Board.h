/**
 * Board.h
 * Board Header
 *
 * Created on: Dec 29, 2020
 * Authors: Falko Casimiro Ribeiro, Fabian Mündlein
 */

#ifndef BOARD_H
#define BOARD_H

#include <wx/wx.h>
#include "Generator.h"

#define NUMBER_OF_PIECE_MAPPINGS (12U)

struct PieceMapping_t {
  std::string abstractPiece;
  wxBitmap Piece;
} ;

class MyBoard: public wxFrame
{
    public:
        MyBoard();
        void SetAbstractChessBoard(const std::string board[]);

    private:
        void OnPaint(wxPaintEvent& event);
        void InitMappingTable();
        void DrawChessPiece(wxPaintDC dc, const std::string inputPiece, uint8_t index_u8);

        wxPanel* m_board;

        wxBitmap m_blackRook;
        wxBitmap m_blackKnight;
        wxBitmap m_blackBishop;
        wxBitmap m_blackQueen;
        wxBitmap m_blackKing;
        wxBitmap m_blackPawn;

        wxBitmap m_whiteRook;
        wxBitmap m_whiteKnight;
        wxBitmap m_whiteBishop;
        wxBitmap m_whiteQueen;
        wxBitmap m_whiteKing;
        wxBitmap m_whitePawn;

        wxBitmap outputpiece;

        PieceMapping_t mappingTable[NUMBER_OF_PIECE_MAPPINGS];
};

#endif  // BOARD_H
