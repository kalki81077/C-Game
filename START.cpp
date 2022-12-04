#include "START.h"
#include "GAME.h"
#include <iostream>
#include <conio.h>
void START::draw() {
	printf("\x1b[10;20HHelmet");
	printf("\x1b[11;15HSPACEキーを押してスタート");
	printf("\x1b[12;15HA,Sキーで移動");
	printf("\x1b[13;15Hqキーで終了");
}
void START::nextState() {
	int i;
	if (_kbhit()) {
		i = _getch();
		switch (i)
		{
		case'q':
			getgame()->changeState(GAME::Fin_ID);
			break;
		case' ':
			printf("\x1b[2J");
			getgame()->changeState(GAME::Ingame_ID);
			break;
		default:

			break;
		}
		
	}
	}