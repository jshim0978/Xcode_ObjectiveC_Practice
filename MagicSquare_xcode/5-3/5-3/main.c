//
//  main.c
//  5-3
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//

#include <stdio.h>
#include "AppController.h"

int main()
{
    AppController* appController ;
    appController = AppController_new () ; // appController 객체 생성
    AppController_run (appController) ; // app 실행
    AppController_delete (appController) ; // appController 객체 삭제
    
    return 0;
}
