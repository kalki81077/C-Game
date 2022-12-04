#include "Ingame.h"
#include "GAME.h"
//#include "PLAYER.h"
#include "PoolAllocator.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <io.h>
#include <Windows.h>
#include <random>
#include <string>







time_t t = time(NULL);
time_t nt;
int st = -1;
std::random_device rnd;

int score = 0;//スコア
struct Object {
	int ob_x;
	int ob_y;
};
const int MAXOB = 7;

PoolAllocator<Object, MAXOB> b;
Object* ob[MAXOB];

int player_x = 22;//プレイヤー座標
int player_y = 5;//プレイヤー座標
int nexpos = 5; //次の位置（前後）
int object_x = 10;
bool ope = false;//ドア開閉
bool crash = false;//衝突判定
int goal_pos = 40;

 void Ingame::update(){
	int i;//キー入力
	if (_kbhit()) {

		i = _getch();
		printf("\x1b[%d;%dH ",player_x,player_y);
		switch (i)
		{
		case'd':
			if (ope || player_y < 35) {
				player_y = player_y + nexpos;
			}
			break;
		case'a':
			if (player_y > 5) player_y = player_y - nexpos;
			break;
		case'q':
			for (int j = 0; j < MAXOB; j++) {
				b.Free(ob[j]);
			}
			getgame()->changeState(GAME::Score_ID);
			break;
		default:
			break;
		}
		if (player_y == goal_pos) {
			score++;
			player_y = 5;

		}
		
	}

}
 //障害物関数
 int obnum = 0;

 void Ingame::object() {
	
	
	 crash = false;
	nt = time(NULL);
	if (st != nt - t) {

		st = static_cast<int>(nt - t);


		if (obnum < MAXOB) {
			ob[obnum] = b.Alloc();
			ob[obnum]->ob_x = object_x;
			ob[obnum]->ob_y = ((static_cast<unsigned int>(rnd()) % 6) + 2) * 5;
			printf("\x1b[%d;%dHO", ob[obnum]->ob_x, ob[obnum]->ob_y);

			if (obnum < MAXOB - 1)obnum++;

		}

		for (int i = 0; i < MAXOB; i++) {

			if (ob[i] != nullptr) {
				printf("\x1b[%d;%dH ", ob[i]->ob_x, ob[i]->ob_y);
				ob[i]->ob_x += 3;
				printf("\x1b[%d;%dHI", ob[i]->ob_x, ob[i]->ob_y);

				if (ob[i]->ob_x >= 25) {
					printf("\x1b[%d;%dH ", ob[i]->ob_x, ob[i]->ob_y);
					b.Free(ob[i]);
					obnum = i;
				}
			}
		}
		if (static_cast<int>(rnd()) % 3 == 0) {
			ope = true;
		}
		else {
			ope = false;
		}
		door();
	}


		
	for (int i = 0; i < MAXOB; i++) {

		if (ob[i] != nullptr) {
			if (player_x == ob[i]->ob_x && player_y == ob[i]->ob_y) {
				crash = true;
			}
		}
	}
	if (crash) {
		
		printf("\x1b[20;65H%d", score);
		getgame()->changeState(GAME::Score_ID);
	}
}

 void Ingame::door() {
	 if (ope) {
		 printf("\x1b[21;37H ");
		 printf("\x1b[22;37H ");
	 }
	 else {
		 printf("\x1b[21;37H#");
		 printf("\x1b[22;37H#");
	 }

 }

void Ingame::draw() {


	printf("\x1b[%d;%dH&", player_x, player_y);
	printf("\x1b[1;1Hqキーで終了");
	
	printf("\x1b[12;4H#vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv#");
	for (int i = 13; i < player_x + 1; i++) {
		printf("\x1b[%d;%dH#",i,4);
		printf("\x1b[%d;%dH#", i, goal_pos);
	}
	printf("\x1b[23;4H#####################################");

	printf("\x1b[20;36H###");
	printf("\x1b[21;36H#");
	printf("\x1b[21;38H#");
	printf("\x1b[22;36H#");
	printf("\x1b[22;38H#");
}
	
void Ingame::nextState() {
	
}