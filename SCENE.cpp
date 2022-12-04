#include "SCENE.h"

void SCENE::create() {

}
void SCENE::init() {}
void SCENE::update() {}
void SCENE::proc() {
	update();
	draw();
	nextState();
	object();
}
void SCENE::draw() {}
void SCENE::nextState() {}
void SCENE::object() {}