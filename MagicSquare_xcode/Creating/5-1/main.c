//
//  main.c
//  5-1
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//

#include <stdio.h>

#include "Common.h"
#include "MagicSquare.h"
#include "AppIO.h"

int main()
{
    MagicSquare* magicSquare;
    
    AppIO_out_msg_startMagicSquare();
    
    magicSquare = MagicSquare_new();
    magicSquare->_maxOrder = MAX_ORDER;
    int order = AppIO_in_order();
    while (order != END_OF_RUN) {
        MagicSquare_setOrder(magicSquare, order);
        
        if(MagicSquare_orderIsValid(magicSquare))
        {
            MagicSquare_solve(magicSquare);
            
            AppIO_out_board(MagicSquare_order(magicSquare), MagicSquare_board(magicSquare));
        }
        order = AppIO_in_order();
    }
    MagicSquare_delete (magicSquare);
    AppIO_out_msg_endMagicSquare();
    return 0;

    
}
