#pragma once
#include "SCENE.h"
class Ingame :
    public SCENE
{
public:
    Ingame(class GAME* game) :SCENE(game) {}
    ~Ingame() {};
    void update();
    void draw();
    void nextState();
    void object();
   void door();
};
