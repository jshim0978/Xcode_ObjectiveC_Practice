//
//  AppController.c
//  5-3
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//

#include "AppController.h"
#include "Common.h"
#include "MagicSquare.h"
#include "AppIO.h"

AppController* AppController_new ()
{
    AppController* _this = NewObject(AppController) ;
    _this->_magicSquare = MagicSquare_new() ;
    return _this ;
}
void AppController_delete (AppController* _this)
{
    MagicSquare_delete (_this->_magicSquare) ;
    free (_this) ;
}
void AppController_run(AppController* _this)
{
    AppIO_out_msg_startMagicSquare();
    
    _this->_magicSquare->_maxOrder = MAX_ORDER;
    int order = AppIO_in_order();
    while (order != END_OF_RUN) {
        MagicSquare_setOrder(_this->_magicSquare, order);
        
        if(MagicSquare_orderIsValid(_this->_magicSquare))
        {
            MagicSquare_solve(_this->_magicSquare);
            
            AppController_showBoard(_this);
        }
        order = AppIO_in_order();
    }
    AppIO_out_msg_endMagicSquare();
}
void AppController_showBoard (AppController* _this)
{
    int order = MagicSquare_order (_this->_magicSquare) ;
    AppIO_out_boardColumnTitle (order) ;
    for ( int row = 0; row < order; row++ )
    {
        AppIO_out_boardRowTitle (row) ;
        for ( int col = 0; col < order; col++ )
        {
            AppIO_out_cell (MagicSquare_cell(_this->_magicSquare,row, col)) ;
        }
        AppIO_out_newLine ();
    }
}
