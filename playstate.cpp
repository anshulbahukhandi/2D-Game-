
#include"playstate.h"
#include<iostream>
#include"parameter.h"
#include"game.h"
#include"player.h"
#include"enemy.h"
#include"inputhandler.h"
#include"pausestate.h"
#include"gameoverstate.h"
#include"stateparser.h"
const std::string playState::mId="PLAY";

void playState::process()
{
	if(inputHandler::getInstance()->isKeyPressed(SDL_SCANCODE_ESCAPE))
	{
		game::getInstance()->getStateMachine()->pushstate(new pauseState());
	}

	 if(checkCollision(maGameObject[0] , maGameObject[1]))
	 	game::getInstance()->getStateMachine()->changestate(new gameoverState());
	
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
	std::cout<<"Entering Play state!\n";
	stateParser* stateparser; 
	stateparser->parseState("states.xml",mId,&maGameObject , &maTextureId);
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

bool playState::checkCollision(gameObject* o1 , gameObject* o2 )
{
	int right1 , right2 , left1 , left2 , top1 , top2 , bottom1 , bottom2 ;
	left1= o1->getPosition()->getX() ; 
	left2= o2->getPosition()->getX() ; 
	top1=o1->getPosition()->getY(); 
	top2=o2->getPosition()->getY();
	int  width1 , width2 , height1 , height2 ; 
	width1=o1->getWidth() ; 
	height1=o1->getHeight() ; 
	width2=o2->getWidth() ; 
	height2=o2->getHeight() ;

	right1=left1+width1; 
	right2=left2+width2;
	bottom1=top1+height1;
	bottom2=top2+height2;

	if(right1<left2 || left1>right2 || bottom1<top2 || top1>bottom2)
		return false ; 
	else return true; 

}
