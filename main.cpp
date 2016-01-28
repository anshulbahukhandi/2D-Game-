#include"game.cpp"
#include<iostream>
#include<fstream>
using namespace std; 

int main( int argc  , char* argv[])
{

	const int FPS =60;
	const int timeBetweenFrames=1000/FPS;
	int frameStart , frameTime;

	if( game::getInstance()->init((char*)"Main Window" , 0 , 0 , 640 , 400 ,0))
	{
		while(game::getInstance()->ifRunning())
		{
			frameStart=SDL_GetTicks();
			game::getInstance()->process();
			game::getInstance()->render(0,0,0,255);
			game::getInstance()->handleEvent();

			frameTime=SDL_GetTicks() - frameStart;
			if(frameTime<timeBetweenFrames)
				SDL_Delay(timeBetweenFrames-frameTime);

		}
	}

return 0 ;
}