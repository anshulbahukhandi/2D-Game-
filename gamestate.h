#ifndef GAME_STATE_H_
#define GAME_STATE_H_

#include<string>
#include"SDL.h"
class gamestate
{

public:

virtual void process()=0;
virtual void render(SDL_Renderer*)=0;

virtual bool enterState(SDL_Renderer*)=0;
virtual bool exitState()=0;

virtual std::string getStateId()=0;

};

#endif