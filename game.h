/* Name : Anshul Bahukhandi
   Date : 1/20/2016
*/

#ifndef GAME_H_
#define GAME_H_

#include"SDL.h"
#include"SDL_image.h"
#include"texture.cpp"
#include<iostream>
#include<fstream>
#include"gameobject.h"
#include"player.cpp"
#include"enemy.cpp"
#include"parameter.h"
#include<vector>
#include"input.cpp"

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

private: 
static game* mpGame;

SDL_Window* mpWindow;
SDL_Renderer * mpRenderer;
bool mIfRunning; 
int mCurrentFrame;

std::vector<gameobject*> mObjectArray;

/* No creation or copying or assigning of game objects allowed*/
game();
game(const game&);
game& operator=(const  game&);

};

#endif  