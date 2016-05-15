#include"pausestate.h"
#include"button.h"
#include"game.h"

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
	//Creating the objects associated with menu state upon entrance
	if(!texturePool::getInstance()->loadImage("images/mainmenu.png" , "mainmenubutton" , game::getInstance()->getRenderer())
		|| !texturePool::getInstance()->loadImage("images/resume.png" , "resumebutton" , game::getInstance()->getRenderer()) 
	   )
	{
		return false; 	
	}
	gameObject* mainMenuButton=new button(new parameter("mainmenubutton", 220,100 ,180 ,100 ) , mMainButtonFunction);
	gameObject* resumeButton=new button(new parameter("resumebutton",220 ,300 ,180 ,100 ) , mResumeButtonFunction);

	maGameObject.push_back(mainMenuButton);
	maGameObject.push_back(resumeButton);

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
	game::getInstance()->getStateMachine()->changestate(new menuState());
}

void pauseState::mResumeButtonFunction()
{
	game::getInstance()->getStateMachine()->popstate();
}



