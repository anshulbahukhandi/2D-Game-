#include"enemy.h"
#include"game.h"
#include"inputhandler.h"
#include<SDL2/SDL.h>
using namespace std;

enemy::enemy(parameter* para) : gameObject(para)
{
	
}

enemy::~enemy()
{

}

void enemy::draw()
{
	if(mpVelocity->getX()>0)
	texturePool::getInstance()->drawAnimated(mId ,game::getInstance()->getRenderer(), mpPosition->getX() , mpPosition->getY() , mWidth  ,mHeight , mCurrentRow , mCurrentFrame);
	if(mpVelocity->getX()<0)
	texturePool::getInstance()->drawAnimated(mId ,game::getInstance()->getRenderer(), mpPosition->getX() , mpPosition->getY() , mWidth  ,mHeight , mCurrentRow , mCurrentFrame,SDL_FLIP_HORIZONTAL);
}

void enemy::process()
{

	if(mpPosition->getX()==0)
		mpVelocity->setX(1);
	if(mpPosition->getX()==1280)
		mpVelocity->setX(-1);
	mCurrentRow=1;
	gameObject::process();
}

void enemy::clean()
{

}