#pragma once
#include "GAME_OBJECT.h"


class PLAYER :
    public GAME_OBJECT
{
public:
    PLAYER(class GAME* game) :GAME_OBJECT(game) {};
    ~PLAYER() {};


    void init();
    void update();
    void draw();
};

