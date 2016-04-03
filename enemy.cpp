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
	texturePool::getInstance()->drawAnimated(mId ,game::getInstance()->getRenderer(), mpPosition->getX() , mpPosition->getY() , mWidth  ,mHeight , mCurrentRow , mCurrentFrame,SDL_FLIP_HORIZONTAL);
}

void enemy::process()
{
	if(inputHandler::getInstance()->isKeyPressed(SDL_SCANCODE_LEFT))
		mpVelocity->setX(-1);
	if(inputHandler::getInstance()->isKeyPressed(SDL_SCANCODE_RIGHT))
		mpVelocity->setX(1);
	mCurrentRow=1;
	gameObject::process();
}

void enemy::clean()
{

}