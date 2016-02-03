/* Name : Anshul Bahukhandi
   Date : 1/20/2016
*/

#ifndef GAME_H_
#define GAME_H_

#include<iostream>
#include<fstream>
#include<vector>
#include"SDL.h"
#include"SDL_image.h"
#include"texture.cpp"
#include"gameobject.h"
#include"player.cpp"
#include"enemy.cpp"
#include"parameter.h"
#include"input.cpp"
#include"getstate.cpp"
#include"gamestate.h"
#include"play.cpp"
#include"menu.cpp"


class game
{
	
public:

~game();
/*function has the responsibility to initialize the window and renderer*/
/* We can also try to do the same stuff inside constructor */
/*Last argument is whether we want full screen or not*/
bool  init( char*, int, int, int, int, bool);

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

/*function to get the only game object pointer allowed*/
static game* getInstance()
{
	if(mpGame==NULL)
		mpGame=new game();
		return mpGame;
}

void quit()
{
	mIfRunning=false;
}

private: 
static game* mpGame;

SDL_Window* mpWindow;
SDL_Renderer * mpRenderer;
bool mIfRunning; 
int mCurrentFrame;

std::vector<gameobject*> mObjectArray;

/*This object is used to change the states of game*/
getstate* mpStateChanger;

/* No creation or copying or assigning of game objects allowed*/
game();
game(const game&);
game& operator=(const  game&);

};

#endif  