#include"gameoverstate.h"
#include"animatedgraphics.h"
#include"game.h"
#include"button.h"
#include"mainmenustate.h"
#include"stateparser.h"
#include<iostream>
const std::string gameoverState::mId="GAMEOVER";

void gameoverState::process()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		{
			maGameObject[i]->process();
		}
}

void gameoverState::draw()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->draw();
}

bool gameoverState::onenter()
{
	std::cout<<"Entering Game Over state!\n";
	stateParser stateparser;
	stateparser.parseState("states.xml" , mId , &maGameObject , &maTextureId);
	maCallBack.push_back(0);
	maCallBack.push_back(mRestartFunction);
	maCallBack.push_back(mMainmenuFunction);

	setCallBacks(maCallBack);
	return true;

}

bool gameoverState::onexit()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->clean() ; 
	maGameObject.clear(); 
	return true;
}

void gameoverState::mMainmenuFunction()
{
	game::getInstance()->getStateMachine()->changestate(new mainMenuState());
}

void gameoverState::mRestartFunction()
{
	game::getInstance()->getStateMachine()->changestate(new playState());
}

void gameoverState::setCallBacks(const std::vector<callBack>& callbacks)
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