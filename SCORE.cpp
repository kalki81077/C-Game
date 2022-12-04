#include "SCORE.h"
#include "GAME.h"
#include <conio.h>
#include <iostream>
void SCORE::draw() {
	
	printf("\x1b[20;40HGAME OVER");
	printf("‚ ‚È‚½‚ÌƒXƒRƒA‚Í");
	
}
void SCORE::nextState() {
	int i;
	if (_kbhit()) {
		i = _getch();
		switch (i)
		{
		case'q':
			getgame()->changeState(GAME::Start_ID);
			break;
		default:

			break;
		}

	}
}