//
//  AppIO.c
//  5-3
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//

#include "AppIO.h"

int AppIO_in_order()
{
    int k;
    printf("마방진의 차수를 입력하시오\n");
    scanf("%d", &k);
    return k;
}
void AppIO_out_msg_startMagicSquare()
{
    printf("<<<마방진 풀이를 시작합니다>>>\n") ;
}
void AppIO_out_msg_endMagicSquare()
{
    printf("<마방진 풀이를 종료합니다>\n") ;
}
void AppIO_out_newLine (void) {
    printf ("\n");
}

void AppIO_out_boardColumnTitle (int anOrder)
{
    printf("%7s", " ");
    for (int col = 0; col < anOrder ; col ++) {
        printf("   [%2d]", col);
    }
    printf("\n");
}
void AppIO_out_boardRowTitle (int aRow)
{
    printf("[%2d]   ",aRow);
}
void AppIO_out_cell (int aCell)
{
    printf("%7d", aCell);
}

