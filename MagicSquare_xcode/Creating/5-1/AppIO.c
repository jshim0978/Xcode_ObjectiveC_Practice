//
//  AppIO.c
//  5-1
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//


#include "AppIO.h"
#include "Common.h"
#include "MagicSquare.h"

int AppIO_in_order()
{
    int k;
    printf("마방진의 차수를 입력하시오\n");
    scanf("%d", &k);
    return k;
}
void AppIO_out_board ( int anOrder, int aBoard[][MAX_ORDER])
{
    printf("Magic Square Board: Order %d", anOrder);
    printf("\n");
    printf("%7s", " ");
    for (int  k= 0; k<anOrder; k++)
    {
        printf("   [%2d]",k);
    }
    printf("\n");
    for (int l=0; l<anOrder; l++) {
        printf("\n[%2d]   ",l);
        for (int c=0; c<anOrder; c++) {
            printf("%7d", aBoard[l][c]);
        }
    }
    printf("\n");
}

void AppIO_out_msg_startMagicSquare()
{
    printf("<<<마방진 풀이를 시작합니다>>>\n") ;
}
void AppIO_out_msg_endMagicSquare()
{
    printf("<마방진 풀이를 종료합니다>\n") ;
}
