#include<iostream>
#include<cstring>
#include"game.h"
#include"SDL2/SDL.h"
using namespace std; 
const static int FPS=60;
const int timePerFrame=1000/60;

int main()
{
	Uint32 startTime , timeTaken;

	if(game::getInstance()->init("MAIN WINDOW" , 100 , 100 ,640,480,false) )
		cout<<"Game initialization successfull!\n";
	else 
		return 0; 

	while(game::getInstance()->running())
	{
		startTime=SDL_GetTicks();
		game::getInstance()->handleEvent();
		game::getInstance()->render();
		game::getInstance()->process();
		timeTaken=SDL_GetTicks() - startTime;
		if(timeTaken<timePerFrame)
		{
			SDL_Delay(timePerFrame - timeTaken);
		} 
	}

	game::getInstance()->clean();
	
	return 0 ; 

}




