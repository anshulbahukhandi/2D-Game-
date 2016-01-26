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
	gameobject::process();
	mX+=1;
}

void player::clean()
{
	gameobject::clean();
}