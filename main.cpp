#include"game.cpp"
#include<iostream>
#include<fstream>
using namespace std; 

int main( int argc  , char* argv[])
{
	/* Always create on heap  , because its dificult for the compiler to know the exact size
	   as its very complicated to be place don stack*/
	
	game* newGame = new game ; 
	
	if( newGame->init((char*)"Main Window" , 0 , 0 , 640 , 400 ,0))
	{
		while(newGame->ifRunning())
		{
			newGame->process();
			newGame->render(0,0,0,255);
			newGame->handleEvent();
			SDL_Delay(10);
		}
	}

return 0 ;
}