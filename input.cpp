#include"input.h"
using namespace std; 

input* input::mpInput=NULL;

input::input()
{
	for (int i= 0 ; i<3 ; i++)
		mArrayMouseButtonState.push_back(false);
}

input::~input()
{

}

void input::process(SDL_Event event)
{
		/*If mouse button is pressed down*/
		if(event.type==SDL_MOUSEBUTTONDOWN)
		{
			if(event.button.button==SDL_BUTTON_LEFT)
				mArrayMouseButtonState[LEFT] =true;
			if(event.button.button==SDL_BUTTON_MIDDLE)
				mArrayMouseButtonState[MIDDLE] =true;
			if(event.button.button==SDL_BUTTON_RIGHT)
				mArrayMouseButtonState[RIGHT] =true;

				
		}
		/*If Mouses button is pressed up or not pressed at all*/
		if(event.type==SDL_MOUSEBUTTONUP)
		{
			if(event.button.button==SDL_BUTTON_LEFT)
				mArrayMouseButtonState[LEFT] =false;
			if(event.button.button==SDL_BUTTON_MIDDLE)
				mArrayMouseButtonState[MIDDLE] =false;
			if(event.button.button==SDL_BUTTON_RIGHT)
				mArrayMouseButtonState[RIGHT] =false;

		}
}

void input::clean()
{

}

bool input::getMouseButtonState(const int  n)
{
	return (mArrayMouseButtonState[n]);
}


