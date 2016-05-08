
#include"playstate.h"
#include<iostream>
#include"parameter.h"
#include"game.h"
#include"player.h"
#include"enemy.h"

const std::string playState::mId="PLAY";

void playState::process()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->process();
}

void playState::draw()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->draw();
}

bool playState::onenter()
{

	if(!texturePool::getInstance()->loadImage("images/cat.bmp" , "cat" , game::getInstance()->getRenderer())
	   || !texturePool::getInstance()->loadImage("images/horse.png" , "horse" , game::getInstance()->getRenderer())
	   )
	   
	{
		return false; 
	}
	parameter* playerPara=new parameter("horse" , 0 , 200 , 320,225);
	parameter* enemyPara=new parameter ("cat" , 500 , 0 , 128,82);

	gameObject* mPlayer1=new player(playerPara);
	gameObject* mEnemy1=new enemy(enemyPara);


	maGameObject.push_back(mPlayer1);
	maGameObject.push_back(mEnemy1);
	return true;
}

bool playState::onexit()
{	
	for( int i=0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->clean();
	maGameObject.clear();
	std::cout<<"Exiting PLAY state!\n";
	return true;
}

const std::string playState::getStateId() const
{
	return mId;
}