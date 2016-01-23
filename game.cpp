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
/* We can also try to do the same stuff inside constructor */
bool  game::init( char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
	if( SDL_Init(SDL_INIT_EVERYTHING)>= 0) 
	{
	/*Creating window*/
		int full; 
		if(fullscreen==true)
			full=1;
		else full=0;
		mpWindow=SDL_CreateWindow( title , xpos , ypos , height , width , full);
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

	/*Loading the texture in our texture array*/
	if(!textureConfig::getInstance().load("images/cat.bmp" ,"cat" , mpRenderer))
	{	cout<<"IMAGE LOADING FAILED!\n";
		return false; 
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

	/*Render the texture*/
	textureConfig::getInstance().drawAnimated("cat" ,0 , 0 , 128, 82 ,1, mCurrentFrame,mpRenderer,SDL_FLIP_NONE);

	textureConfig::getInstance().drawStatic("cat" ,200 , 0 , 128, 82 ,mpRenderer,SDL_FLIP_NONE);
	/* Display the renderer*/
	SDL_RenderPresent(mpRenderer);
}

/*function to handle events/ inputs*/
void game::handleEvent()
{
	SDL_Event event; 
	if(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT : 
			mIfRunning=false;
			break;

			default : break;	
		}	
	}
}

/*function to process the inputs and apply the physics*/
void game::process()
{
	mCurrentFrame=(int)((SDL_GetTicks()/100)%6);
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



