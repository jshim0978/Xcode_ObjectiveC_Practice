//
//  AppIO.h
//  5-3
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include <stdio.h>

void AppIO_out_boardColumnTitle (int anOrder);
void AppIO_out_boardRowTitle (int aRow);
void AppIO_out_cell (int aCell);
void AppIO_out_newLine(void);

void AppIO_out_msg_startMagicSquare();
void AppIO_out_msg_endMagicSquare();
int AppIO_in_order();


#endif /* AppIO_h */
