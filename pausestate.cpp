#include"pausestate.h"
#include"button.h"
#include"game.h"
#include"stateparser.h"
const std::string pauseState::mId="PAUSE";

void pauseState::process()
{
	for(int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->process();
}

void pauseState::draw()
{
	for(int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->draw();
}

bool pauseState::onenter()
{
	std::cout<<"Entering PAUSE state!\n";
	stateParser stateparser;
	stateparser.parseState("states.xml" , mId , &maGameObject , &maTextureId);
	maCallBack.push_back(0);
	maCallBack.push_back(mResumeButtonFunction);
	maCallBack.push_back(mMainButtonFunction);

	setCallBacks(maCallBack);

	return true;
}

bool pauseState::onexit()
{
for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->clean() ; 
	maGameObject.clear(); 
	return true;
}

void pauseState::mMainButtonFunction()
{
	game::getInstance()->getStateMachine()->changestate(new mainMenuState());
}

void pauseState::mResumeButtonFunction()
{
	game::getInstance()->getStateMachine()->popstate();
}


void pauseState::setCallBacks(const std::vector<callBack>& callbacks)
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
