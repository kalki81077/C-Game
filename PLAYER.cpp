#include "PLAYER.h"
#include <iostream>
#include <conio.h>
char human[5][3] = {
    {' ','O',' '},
    {' ','|',' '},
    {'_','_','_'},
    {' ','|',' ' },
    {'|',' ','|'}


};
int x = 20;//プレイヤー座標
int y = 5;//プレイヤー座標
int nexpos = 10; //次の位置（前後）
int max_w = 100;
void PLAYER::init(){}

void PLAYER::update(){
    int i;//キー入力
    if (_kbhit()) {
        
        i = _getch();
        printf("\x1b[2J");
        switch (i)
        {
        case'd':
            if(y<= max_w) y = y + nexpos;
            break;
        case'a':
           if(y> 5) y = y - nexpos;
            break;
        default:
            break;
        }
        if (y == 55) {
            y = 5;

        }
    }
    
}
void PLAYER::draw() {
    
    /*for (int m = 0; m < 5; m++) {
        for (int n = 0; n < 3; n++) {
            
        }
    }*/
    
    printf("\x1b[%d;%dH&", x, y);
}