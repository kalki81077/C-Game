#pragma once
#include "GAME.h"
#include "START.h"
#include "Ingame.h"
#include "SCORE.h"

class GAME {
public:
	enum STATE_ID {
		Start_ID,
		Ingame_ID,
		Score_ID,
		ID_num,
		Fin_ID
	};

	GAME() {
		States[Start_ID] = new START(this);
		States[Ingame_ID] = new Ingame(this);
		States[Score_ID] = new SCORE(this);
		nowStateId = Start_ID;

	};
	~GAME() {
		
		for (int i = 0; i < ID_num; i++) {
			delete States[i];
		}
	
	};
	void run() ;
	void changeState(STATE_ID stateID);



private:




	class SCENE* States[ID_num];
	STATE_ID nowStateId;
};
