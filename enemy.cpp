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
			mVelocity.setX(1);
			mCurrentFrame=(int)((SDL_GetTicks()/100)%6);
			cout<<"Inside player::process()\n change velocity\n";
		}
		else
			mVelocity.setX(0);
	gameobject::process();

	
}

void enemy::clean()
{
	gameobject::clean();
}