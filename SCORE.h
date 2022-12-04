#pragma once
#include "SCENE.h"
class SCORE :
    public SCENE
{
public:
    SCORE(class GAME* game) :SCENE(game) {}
    ~SCORE() {};
    void draw();
    void nextState();
};
