#include"player.h"
using namespace std;



player::player(const parameter* para) :gameobject(para) {}

player::~player() {}

void player::draw(SDL_Renderer* renderer)
{
	gameobject::draw(renderer);
}

void player::process()
{
	
	mAcceleration.setX(0.1);
	gameobject::process();

}

void player::clean()
{
	gameobject::clean();
}