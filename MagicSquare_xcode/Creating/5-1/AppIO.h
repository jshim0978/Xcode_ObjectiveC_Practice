//
//  AppIO.h
//  5-1
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h
#include <stdio.h>
#include "Common.h"
#include "MagicSquare.h"

void AppIO_out_msg_startMagicSquare();
void AppIO_out_msg_endMagicSquare();
int AppIO_in_order();
void AppIO_out_board ( int anOrder, int aBoard[][MAX_ORDER]) ;


#endif /* AppIO_h */
