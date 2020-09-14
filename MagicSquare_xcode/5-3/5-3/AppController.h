//
//  AppController.h
//  5-3
//
//  Created by stu2017s20 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s20. All rights reserved.
//

#ifndef AppController_h
#define AppController_h

#include <stdio.h>
#include "MagicSquare.h"


typedef struct {
    MagicSquare* _magicSquare ;
} AppController ;

AppController* AppController_new ();
void AppController_delete (AppController* _this);
void AppController_run(AppController* _this);
void AppController_showBoard (AppController* _this);



#endif /* AppController_h */
