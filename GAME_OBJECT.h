#pragma once
#include <iostream>
class GAME_OBJECT
{
private:
	class GAME* Game= 0 ;
public:
	GAME_OBJECT(class GAME* game) {
		Game = game;
	
	};
	virtual ~GAME_OBJECT() {};
	class GAME* getgame() {
		return Game;
	}


	
	
};

