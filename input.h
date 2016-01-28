/* Name : Anshul Bahukhandi
   Date : 1/27/2016

   This class handles the input  from device like 
   Keyboard and mouse.
   JoyStick has not been implemented as we dont need it.

*/

#ifndef INPUT_H_
#define INPUT_H_

#include"SDL.h"
#include<vector>
   

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

void  process(SDL_Event);

void clean();

/*Function to get the state of mouse button*/
bool getMouseButtonState(const int );

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



};

#endif

