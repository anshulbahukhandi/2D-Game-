#include"inputhandler.h"
#include"game.h"
#include<SDL2/SDL.h>
using namespace std; 

inputHandler* inputHandler::mpInputHandler=NULL;

inputHandler::inputHandler()
{
	for( int i = 0 ; i<3 ; i++)
	mArrayMouseButton.push_back(false);
}

void  inputHandler::process()
{
	SDL_Event event; 
	if(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
			     game::getInstance()->switchOff(); 
			     break; 
			default: break;
		}
	}
	if(event.type==SDL_MOUSEBUTTONDOWN)
	{
		if(event.button.button==SDL_BUTTON_LEFT)
			mArrayMouseButton[LEFT]=true;
		if(event.button.button==SDL_BUTTON_MIDDLE)
			mArrayMouseButton[MIDDLE]=true;
		if(event.button.button==SDL_BUTTON_RIGHT)
			mArrayMouseButton[RIGHT]=true;
	}

	if(event.type==SDL_MOUSEBUTTONUP)
	{
		if(event.button.button==SDL_BUTTON_LEFT)
			mArrayMouseButton[LEFT]=false;
		if(event.button.button==SDL_BUTTON_MIDDLE)
			mArrayMouseButton[MIDDLE]=false;
		if(event.button.button==SDL_BUTTON_RIGHT)
			mArrayMouseButton[RIGHT]=false;
	}


}

void inputHandler::clean()
{

}

bool inputHandler::getState(const int n )
{
	return mArrayMouseButton[n];
}

