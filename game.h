#ifndef GAME_H_
#define GAME_H_

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>
#include<iostream>
#include<vector>
#include"texturepool.h"
#include"gameobject.h"
#include"player.h"
#include"enemy.h"
#include"statemachine.h"
#include"playstate.h"
#include"mainmenustate.h"
class game
{

public:
~game(){}
bool init(const std::string str , const int x , const int y , const int width , const int height , const bool flag);
void render();
void handleEvent();
void process();
void clean();
bool running();
void switchOff()
{
	mRunning=false;
}
SDL_Renderer* getRenderer() const 
{
	return mpRenderer;
}
static game* getInstance()
{
	if(myGame==NULL)
		myGame=new game();
	return myGame;
}
statemachine* getStateMachine() { return mpStateMachine; }

private:

static game* myGame; 
game(){}
game(const game&);
game& operator=(const game&);

SDL_Window* mpWindow; 
bool mRunning;
SDL_Renderer* mpRenderer;
std::vector<gameObject*> mGameObjects;

statemachine* mpStateMachine;

};

#endif