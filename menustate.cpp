
#include"menustate.h"
#include"parameter.h"
#include"game.h"
#include"button.h"
#include<iostream>

const std::string menuState::mId="MENU";

void menuState::process()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->process() ; 

}

void menuState::draw()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->draw(); 
}

bool menuState::onenter()
{
	std::cout<<"Entering MENU state!\n";
	//Creating the objects associated with menu state upon entrance
	if(!texturePool::getInstance()->loadImage("images/exit.png" , "exit" , game::getInstance()->getRenderer())
		|| !texturePool::getInstance()->loadImage("images/play.png" , "play" , game::getInstance()->getRenderer()) 
	   )
	{
		return false; 	
	}
	gameObject* playButton=new button(new parameter("play", 220,100 ,200 ,100 ) , mPlayFunction);
	gameObject* exitButton=new button(new parameter("exit",220 ,300 ,200 ,100 ) , mExitFunction);

	maGameObject.push_back(playButton);
	maGameObject.push_back(exitButton);

	return true;
}

bool menuState::onexit()
{	

	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->clean() ; 
	maGameObject.clear(); 
	return true;
}

const std::string menuState::getStateId() const
{
	return mId;
}

void menuState::mPlayFunction()
{
	game::getInstance()->getStateMachine()->changestate(new playState());
}
void menuState::mExitFunction()
{
	game::getInstance()->switchOff();
}


