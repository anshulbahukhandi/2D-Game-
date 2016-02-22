#include"player.h"
#include"inputhandler.h"
using namespace std; 


player::player(parameter* para) : gameObject(para)
{


}

player::~player()
{

}

void player::draw()
{
	gameObject::draw();
}

void player::process()
{
	gameObject::process();
	mCurrentRow=2;
	if(inputHandler::getInstance()->getState(LEFT))
	mpVelocity->setX(1);
	else
	mpVelocity->setX(0);
	//mpVelocity->setY(-0.8);

}

void player::clean()
{

}

