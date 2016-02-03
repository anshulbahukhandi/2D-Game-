#include"menu.h"
using namespace std; 

const std::string menu::mId="MENU";

 void menu::process()
 {
 	for( int i=0 ; i<mArrayGameObject.size(); i++)
 	{
 		mArrayGameObject[i]->process();
 	}
 }

 void menu::render(SDL_Renderer* renderer)
 {
	for( int i=0 ; i<mArrayGameObject.size(); i++)
 	{
 		mArrayGameObject[i]->draw(renderer);
 	}
 }


 bool menu::enterState(SDL_Renderer* renderer)
 {
 	if(!textureConfig::getInstance()->load("images/play.png","playbutton",renderer))
 	{
 		return false;
 	}

 	if(!textureConfig::getInstance()->load("images/exit.png","exitbutton",renderer))
 	{
 		return false;
 	}

 	gameobject* playButton=new menubutton(new parameter(100,100,400,100,"playbutton"));
 	gameobject* exitButton=new menubutton(new parameter(100,300,400,100,"exitbutton"));

 	mArrayGameObject.push_back(playButton);
 	mArrayGameObject.push_back(exitButton);

 	cout<<"Enter Menu State!\n";
 	return true; 


 }

 bool menu::exitState()
 {
	for (int i = 0 ; i<mArrayGameObject.size() ; i++)
	{
		mArrayGameObject[i]->clean();
	}

	mArrayGameObject.clear();
	textureConfig::getInstance()->eraseTexture("playbutton");
	textureConfig::getInstance()->eraseTexture("exitbutton");

	cout<<"Exiting Menu state!\n";
	return true; 
 	
 }


std::string menu::getStateId()
{
	return mId;
}
