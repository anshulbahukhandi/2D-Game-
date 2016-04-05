
#include"menustate.h"
#include<iostream>

const std::string menuState::mId="MENU";

void menuState::process()
{

}

void menuState::render()
{

}

bool menuState::onenter()
{
	std::cout<<"Entering MENU state!\n";
	return true;
}

bool menuState::onexit()
{	
	std::cout<<"Exiting MENU state!\n";
	return true;
}

const std::string menuState::getStateId() const
{
	return mId;
}