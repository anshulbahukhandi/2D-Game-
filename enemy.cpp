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
	if(input::getInstance()->getMouseButtonState(RIGHT))
		{
			mCurrentFrame=(int)((SDL_GetTicks()/100)%6);
		}

	else if(input::getInstance()->getKeyState(SDL_SCANCODE_RIGHT))
		mVelocity.setX(1);

	else if(input::getInstance()->getKeyState(SDL_SCANCODE_LEFT))
		mVelocity.setX(-1);	
	else
		mVelocity.setX(0);
	gameobject::process();

	
}

void enemy::clean()
{
	gameobject::clean();
}