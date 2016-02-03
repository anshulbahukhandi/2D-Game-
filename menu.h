#ifndef MENU_H_
#define MENU_H_

#include"gamestate.h"
#include"gameobject.h"
#include"texture.h"
#include<string>
#include<vector>
#include"SDL.h"

class menu : public gamestate
{

public:

virtual void process();
virtual void render(SDL_Renderer*);

virtual bool enterState(SDL_Renderer*);
virtual bool exitState();

virtual std::string getStateId();


private:

	static const std::string mId;
	std::vector<gameobject*> mArrayGameObject;

};

#endif