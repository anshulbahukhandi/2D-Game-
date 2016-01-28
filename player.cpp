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
	if(input::getInstance()->getMouseButtonState(LEFT))
		{
			mVelocity.setX(1);
			mCurrentFrame=(int)((SDL_GetTicks()/100)%6);
			cout<<"Inside player::process()\n change velocity\n";
		}
		else
			mVelocity.setX(0);
	gameobject::process();

}

void player::clean()
{
	gameobject::clean();
}