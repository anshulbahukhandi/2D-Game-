#include"player.h"
using namespace std;



void player::load(int x , int y , int width , int height , std::string id)
{
	gameobject::load(x,y,width , height , id);
}

void player::draw(SDL_Renderer* renderer)
{
	gameobject::draw(renderer);
}

void player::process()
{
	mCurrentFrame=(int)((SDL_GetTicks()/100)%6);
	mX+=1;
}

void player::clean()
{
	gameobject::clean();
}