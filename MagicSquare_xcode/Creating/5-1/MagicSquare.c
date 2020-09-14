//
//  MagicSquare.c
//  5-1
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//
#include "MagicSquare.h"
#include "Common.h"
#include <stdlib.h>
#define NewObject(TYPE) (TYPE*) malloc(sizeof(TYPE))

Boolean MagicSquare_orderIsValid (MagicSquare *_this)
{
    
    if (_this->_order < 3)
    {
        printf("오류: 차수가 너무 작습니다. 3 보다 크거나 같아야 합니다.\n") ;
        return FALSE ;
    }
    else if (_this->_order > _this->_maxOrder)
    {
        printf("오류: 차수가 너무 큽니다. %d 보다 작아야 합니다.\n", _this->_maxOrder) ;
        return FALSE ;
    }
    else if ( (_this->_order % 2) == 0 )
    {
        printf("오류: 차수가 짝수입니다. 홀수이어야 합니다.\n") ;
        return FALSE ;
    }
    else
    {
        return TRUE ;
    }
}
void MagicSquare_solve(MagicSquare*_this)
{
    CellLocation currentLoc;
    CellLocation nextLoc;
    
    int row;
    int col;
    
    for (row = 0; row< _this->_order; row++)
    {
        for (col =0; col<_this->_order; col++) {
            _this->_board[row][col] = EMPTY_CELL;
        }
    }
    int cellValue =1;
    int lastCellValue = _this->_order*_this->_order;
    
    currentLoc._row = 0;
    currentLoc._col = _this->_order/2;
    _this->_board[currentLoc._row][currentLoc._col] = cellValue;
    
    for (cellValue = 2; cellValue <= lastCellValue; cellValue++) {
        nextLoc._row = currentLoc._row-1;
        if (nextLoc._row<0)
            nextLoc._row = _this->_order -1;
        nextLoc._col = currentLoc._col+1;
        if (nextLoc._col>=_this->_order)
            nextLoc._col =0;
        
        if (_this->_board[nextLoc._row][nextLoc._col]!=EMPTY_CELL)
        {
            nextLoc._row = currentLoc._row+1;
            nextLoc._col = currentLoc._col;
        }
        currentLoc = nextLoc;
        _this->_board[nextLoc._row][nextLoc._col] = cellValue;
    }
}
void MagicSquare_setOrder(MagicSquare *_this, int anOrder){
    _this->_order = anOrder;
}
int MagicSquare_order(MagicSquare*_this)
{
    return _this->_order;
}
int* MagicSquare_board(MagicSquare*_this)
{
    return (int*)_this->_board;
}

MagicSquare* MagicSquare_new()
{
    MagicSquare* _this;
    _this = NewObject(MagicSquare) ; // malloc
    return _this;
}
void MagicSquare_delete(MagicSquare* _this)
{
    free(_this); // free
}

