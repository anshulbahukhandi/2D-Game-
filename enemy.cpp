#include"enemy.h"
using namespace std;


void enemy::load(int x , int y , int width , int height , std::string id)
{
	gameobject::load(x,y,width , height , id);
}

void enemy::draw(SDL_Renderer* renderer)
{
	gameobject::draw(renderer);
}

void enemy::process()
{
	mCurrentFrame=(int)((SDL_GetTicks()/100)%6);
	mX-=1;
}

void enemy::clean()
{
	gameobject::clean();
}