#include "GAME.h"

bool isFin = true;
void GAME::run() {

	while (isFin) {
		if (nowStateId == Fin_ID) break;
		States[nowStateId]->proc();
	}

}

void GAME::changeState(STATE_ID stateID) {
	nowStateId = stateID;
}