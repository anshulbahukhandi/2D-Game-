#include"game.cpp"
#include<iostream>
#include<fstream>
using namespace std; 

int main( int argc  , char* argv[])
{
	/* Always create on heap  , because its dificult for the compiler to know the exact size
	   as its very complicated to be place don stack*/
	
	game* newGame = new game ; 
	
	if( newGame->init((char*)"Main Window" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 640 , 400 , SDL_WINDOW_SHOWN))
	{
		while(newGame->ifRunning())
		newGame->render(0 ,0,0,255);

	}


	return 0 ;
}