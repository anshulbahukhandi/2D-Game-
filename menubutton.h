#ifndef MENU_BUTTON_H_
#define MENU_BUTTON_H_


#include"parameter.h"
#include"SDL.h"
#include"gameobject.h"
#include"myvector.cpp"
#include"input.h"
class menubutton : public gameobject
{
public:
	
	menubutton(const parameter*);
	virtual ~menubuttonn();
	virtual void draw(SDL_Renderer*);
	virtual void process();
	virtual void clean();
private:
	/*Mouse cursor can be over the button or outside the button 
	  or clicked on the button
	*/
	  enum MENUBUTTONSTATE
	  {
	  	MOUSEOUT=0,
	  	MOUSEOVER=1,
	  	MOUSECLICKED=2
	  };

};

#endif