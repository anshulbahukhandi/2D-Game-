#include"enemy.h"
using namespace std;


enemy::enemy(const parameter* para) : gameobject(para){}

enemy::~enemy() {}

void enemy::draw(SDL_Renderer* renderer)
{
	gameobject::draw(renderer);
}

void enemy::process()
{
	gameobject::process();
	mPosition.setX(mPosition.getX() -1);
}

void enemy::clean()
{
	gameobject::clean();
}