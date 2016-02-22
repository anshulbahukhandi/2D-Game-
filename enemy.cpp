#include"enemy.h"
#include"game.h"
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
	mpAcceleration->setX(-0.01);
	mCurrentRow=1;
	gameObject::process();
}

void enemy::clean()
{

}