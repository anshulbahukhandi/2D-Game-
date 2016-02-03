#ifndef PLAY_H_
#define PLAY_H_

#include"gamestate.h"
#include<string>

class play : public gamestate
{

public:

virtual void process();
virtual void render(SDL_Renderer*);

virtual bool enterState(SDL_Renderer*);
virtual bool exitState();

virtual std::string getStateId();


public:
	static const std::string mId;
};

#endif