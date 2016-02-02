#ifndef MENU_H_
#define MENU_H_

#include"gamestate.h"
#include<string>

class menu : public gamestate
{

public:

virtual void process();
virtual void render();

virtual bool enterState();
virtual bool exitState();

virtual std::string getStateId();


public:
	static const std::string mId;
};

#endif