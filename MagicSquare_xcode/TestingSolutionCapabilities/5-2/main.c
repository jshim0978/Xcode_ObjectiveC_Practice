//
//  main.c
//  5-2
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NewObject(TYPE) (TYPE*) malloc(sizeof(TYPE))

#define MAX_ORDER 99
#define END_OF_RUN -1
#define EMPTY_CELL -1

typedef enum {FALSE, TRUE} Boolean;


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

typedef struct{
    clock_t startCounter;
    clock_t stopCounter;
}Timer;


Timer* Timer_new();
void Timer_delete(Timer* _this);
void Timer_start(Timer* _this);
void Timer_stop(Timer* _this);
long Timer_duration(Timer* _this);


Timer* Timer_new()
{
    Timer* _this = NewObject(Timer);
    return _this;
}
void Timer_delete(Timer* _this)
{
    free(_this);
}
void Timer_start(Timer* _this)
{
    _this->startCounter = clock();
}
void Timer_stop(Timer* _this)
{
    _this->stopCounter = clock();
}
long Timer_duration(Timer* _this)
{
    return (long)(_this->stopCounter- _this->startCounter) * (long)1000000 / (long)CLOCKS_PER_SEC;
}

int main()
{
    MagicSquare* magicSquare;
    int order, count;
    Timer* timer;
    long executionTime;
    
    timer = Timer_new();
    printf("<<<마방진 풀이의 성능 측정을 시작합니다>>>\n");
    
    printf("하나의 차수에 대해 10 회 반복 실행한 시간을 측정합니다.\n");
    for (order = 9; order <= MAX_ORDER; order+= 10) {
        Timer_start(timer);
        for (count = 0; count<10; count++) {
            magicSquare = MagicSquare_new();
            MagicSquare_setOrder(magicSquare, order);
            MagicSquare_solve(magicSquare);
            MagicSquare_delete(magicSquare);
        }
        Timer_stop(timer);
        executionTime = Timer_duration(timer);
        printf(" 차수  : %2d, 시간 : ,%ld (마이크로 초)\n",order , executionTime);
        //𝑇(𝑛) = 0.2 ∙ 𝑛2 = 𝑂(𝑛2) => Numbers
    }
    Timer_delete(timer);
    printf(">>>end<<</n");
    return 0;
    
}

