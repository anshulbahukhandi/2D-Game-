#include"player.h"
#include"inputhandler.h"
#include"myvector.h"
#include<iostream>
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

	
	myvector* mousePos=inputHandler::getInstance()->getMousePosition();

	if(inputHandler::getInstance()->getState(LEFT))
	{
		mpVelocity->setX((mousePos->getX()-mpPosition->getX())/100);
		mpVelocity->setY((mousePos->getY()-mpPosition->getY())/100);
	}
	else
	mpVelocity->setX(0);
}

void player::clean()
{

}

