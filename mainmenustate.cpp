
#include"mainmenustate.h"
#include"parameter.h"
#include"game.h"
#include"button.h"
#include<iostream>
#include"stateparser.h"

const std::string mainMenuState::mId="MAINMENU";

void mainMenuState::process()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->process() ; 

}

void mainMenuState::draw()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->draw(); 
}

bool mainMenuState::onenter()
{
	std::cout<<"Entering MAIN MENU state!\n";
	stateParser stateparser;
	stateparser.parseState("states.xml" , mId , &maGameObject , &maTextureId);
	maCallBack.push_back(0);
	maCallBack.push_back(mPlayFunction);
	maCallBack.push_back(mExitFunction);

	setCallBacks(maCallBack);
	return true; 
}

bool mainMenuState::onexit()
{	

	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->clean() ; 
	maGameObject.clear(); 
	return true;
}

const std::string mainMenuState::getStateId() const
{
	return mId;
}

void mainMenuState::mPlayFunction()
{
	game::getInstance()->getStateMachine()->changestate(new playState());
}
void mainMenuState::mExitFunction()
{
	game::getInstance()->switchOff();
}

void mainMenuState::setCallBacks(const std::vector<callBack>& callbacks)
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
	{
		if(dynamic_cast<button*>(maGameObject[i]))
		{
			button* pbutton = dynamic_cast<button*>(maGameObject[i]);
			pbutton->setCallBack(callbacks[pbutton->getCallBack()]);
		}
	}

}
