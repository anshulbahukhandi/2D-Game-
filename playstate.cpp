
#include"playstate.h"
#include<iostream>

const std::string playState::mId="PLAY";

void playState::process()
{

}

void playState::render()
{

}

bool playState::onenter()
{
	std::cout<<"Entering PLAY state!\n";
	return true;
}

bool playState::onexit()
{	
	std::cout<<"Exiting PLAY state!\n";
	return true;
}

const std::string playState::getStateId() const
{
	return mId;
}