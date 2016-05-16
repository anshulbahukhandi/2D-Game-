#include"gameoverstate.h"
#include"animatedgraphics.h"
#include"game.h"
#include"button.h"

const std::string gameoverState::mId="GAMEOVER";

void gameoverState::process()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->process();
}

void gameoverState::draw()
{
	for( int i = 0 ; i<maGameObject.size() ; i++)
		maGameObject[i]->draw();
}

bool gameoverState::onenter()
{
	std::cout<<"Entering Game Over state!\n";
	//Creating the objects associated with state upon entrance
	if(!texturePool::getInstance()->loadImage("images/restart.png" , "restart" , game::getInstance()->getRenderer())
		|| !texturePool::getInstance()->loadImage("images/gameover.png" , "gameover" , game::getInstance()->getRenderer())
		|| !texturePool::getInstance()->loadImage("images/mainmenu.png" , "mainmenubutton" , game::getInstance()->getRenderer())
	   )
	{
		return false; 	
	}
	gameObject* mainmenuButton=new button(new parameter("mainmenubutton", 500+15/2,250 ,170 ,100) , mMainmenuFunction);
	gameObject* restartButton=new button(new parameter("restart",500 ,400 ,185 ,100 ) , mRestartFunction);
	gameObject* gameoverGraphics=new animatedGraphics(new parameter("gameover",500 ,100 ,215 ,100 ) ,2,2);

	maGameObject.push_back(mainmenuButton);
	maGameObject.push_back(restartButton);
	maGameObject.push_back(gameoverGraphics);

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
	game::getInstance()->getStateMachine()->changestate(new menuState());
}

void gameoverState::mRestartFunction()
{
	game::getInstance()->getStateMachine()->changestate(new playState());
}



