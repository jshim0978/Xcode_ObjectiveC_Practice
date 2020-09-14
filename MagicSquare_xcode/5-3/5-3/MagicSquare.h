//
//  MagicSquare.h
//  5-3
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//

#ifndef MagicSquare_h
#define MagicSquare_h

#include <stdio.h>
#include <stdlib.h>
#include "Common.h"
#define NewObject(TYPE) (TYPE*) malloc(sizeof(TYPE))


typedef struct {
    int _row;
    int _col;
}CellLocation;

typedef struct{
    int _order;
    int _maxOrder;
    int _board[MAX_ORDER][MAX_ORDER];
}MagicSquare;

void MagicSquare_setOrder(MagicSquare *_this, int anOrder);
Boolean MagicSquare_orderIsValid(MagicSquare *_this);
void MagicSquare_solve(MagicSquare *_this);
int MagicSqueare_order(MagicSquare *_this);
int* MagicSquare_board(MagicSquare*_this);
MagicSquare* MagicSquare_new();
void MagicSquare_delete(MagicSquare* _this);
int MagicSquare_cell (MagicSquare* _this, int aRow, int aCol);

#endif /* MagicSquare_h */
