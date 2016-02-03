/* Name : Anshul Bahukhandi
   Date : 1/27/2016

   This class handles the input  from device like 
   Keyboard and mouse.
   JoyStick has not been implemented as we dont need it.

*/

#ifndef INPUT_H_
#define INPUT_H_

#include"SDL.h"
#include"myvector.h"
#include<vector>
#include<iostream>
   
enum MOUSEBUTTON
{
	LEFT=0 , MIDDLE=1 , RIGHT=2
};


class input
{
public:

~input();

static input* getInstance()
{
	if(mpInput==NULL)
		mpInput=new input; 
	return mpInput;
}

void  process(const SDL_Event);

void clean();

/*Function to get the state of mouse button*/
bool getMouseButtonState(const int );

/*Function to get the position of mouse totrack its motion*/
myvector* getMousePosition()
{
	return mpMousePosition;
}

/*Function to return the state of any key*/

bool getKeyState(SDL_Scancode key);

private:
/*Disallowing constructor , assignment operator and copy constructor*/	

input();

input(const input&);

input operator=(const input&);

/* You should always create pointer rather than object.
   Beacause to create a complete object you must have complete info
   but its not so with pointer*/
static input* mpInput;

/*There is no point in inheriting mouse and keyboard class from this 
  class and pay extra overhead when we can get away easily by composition.
*/
 
 /*Array to record the 3 button events , one from each button*/
 std::vector<bool> mArrayMouseButtonState;

/*Pointer to store the position of the mouse to track its motion*/
 myvector* mpMousePosition;
 
/*Array to record the state of each key on the keyboard*/
const Uint8* mpKeyState = SDL_GetKeyboardState(0);

};

#endif

