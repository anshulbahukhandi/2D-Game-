/* Name : Anshul Bahukhandi
   Date : 1/20/2016
*/

#ifndef GAME_H_
#define GAME_H_

#include"SDL.h"
#include<iostream>
#include<fstream>
class game
{
	
public:
game();
~game();
/*function has the responsibility to initialize the window and renderer*/
/* We can also try to do the same stuuff inside constructor */
bool  init( char*, int, int, int, int, int);

/*function has the responsibility of creating a renderer and rendering */
void render(int , int , int , int);

/*function to handle events/ inputs*/
void handleEvent();

/*function to process the inputs and apply the physics*/
void process();

/*function to handle the cleanups*/
/* We can also try same stuff inside the destructor*/
void clean();

/*function to know the state of game*/
bool ifRunning ()
{
	return mIfRunning;
}

private: 
SDL_Window* mpWindow;
SDL_Renderer * mpRenderer;
bool mIfRunning;

};

#endif  