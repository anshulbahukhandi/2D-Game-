#include"game.h"
using namespace std; 

game::game()
{
	cout<<"Game Object Created.\n";
}

game::~game()
{
	cout<<"Game Object Destroyed.\n";
}

/*function has the responsibility to initialize the window and renderer*/
/* We can also try to do the same stuuff inside constructor */
bool  game::init( char* title, int xpos, int ypos, int height, int width, int flag)
{
	if( SDL_Init(SDL_INIT_EVERYTHING)>= 0) 
	{
	/*Creating window , last flag is window flag*/
		mpWindow=SDL_CreateWindow( title , xpos , ypos , height , width , flag);
		/* If window is created  , create the renderer*/
		if( mpWindow!=0)
		{
			/* Last flag is the renderer flag*/
			mpRenderer=SDL_CreateRenderer(mpWindow , -1 , 0);
			if(mpRenderer==0)
			{
				cout<<"Failed to create the renderer!\n";
				return false;
			}	

		} 
		else 
		{
			cout<<"Failed to create the Window!\n";
			return false ;
		}
	}	
	else 
	{
		cout<<"Failed to initialize SDL!\n";
		return false ;
	}

	mIfRunning=true;
	return true; 
}

/*function has the responsibility of creating a renderer and rendering */
void game::render(int red, int blue , int green , int alpha)
{
	/*Fill the colors in the renderer */
	SDL_SetRenderDrawColor(mpRenderer, red , blue , green , alpha);
	
	/* Clear the colors from the renderer*/
	SDL_RenderClear(mpRenderer);

	/* Display the renderer*/
	SDL_RenderPresent(mpRenderer);
}

/*function to handle events/ inputs*/
void game::handleEvent()
{

}

/*function to process the inputs and apply the physics*/
void game::process()
{

}

/*function to handle the cleanups*/
/* We can also try same stuff inside the destructor*/
void game::clean()
{
	cout<<"Cleaning Game.\n";
	SDL_DestroyWindow(mpWindow);
	SDL_DestroyRenderer(mpRenderer);
	SDL_Quit();
}



