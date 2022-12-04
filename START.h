#pragma once
#include "SCENE.h"
class START :
    public SCENE
{
public:
    START(class GAME* game):SCENE(game){}
    ~START() {
    
    };
    void draw();
    void nextState();
};

