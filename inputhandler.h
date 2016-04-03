#ifndef INPUT_HANDLER_H_
#define INPUT_HANDLER_H_


#include<vector>
#include<iostream>
#include"myvector.h"
#include<SDL2/SDL.h>
#include<cstdint>

enum mouse_buttons {LEFT = 0,MIDDLE = 1,RIGHT = 2};

class inputHandler
{

public:
~inputHandler();
void  process();
void clean();
bool getState(const int );
myvector* getMousePosition();
bool isKeyPressed(SDL_Scancode);

static inputHandler*  getInstance()
{
	if(mpInputHandler==NULL)
		mpInputHandler=new inputHandler();
	return mpInputHandler;
}

private:
inputHandler();
inputHandler(const inputHandler&);
inputHandler operator=(const inputHandler&);

static inputHandler* mpInputHandler;
std::vector<bool> mArrayMouseButton;
myvector* mpMousePosition; 
/*Array to store the key state*/
const Uint8* mpKeysState;
};

#endif