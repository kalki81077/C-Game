#pragma once
#include "GAME_OBJECT.h"
class SCENE :
    public GAME_OBJECT{
public:
    SCENE(class GAME* game):GAME_OBJECT(game){};
    virtual  ~SCENE() {};
    virtual void create();
    virtual void init();
    virtual void proc();
    virtual void update();
    virtual void draw();
    virtual void object();
    virtual void nextState();
};

