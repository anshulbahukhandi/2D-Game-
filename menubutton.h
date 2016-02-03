#ifndef MENU_BUTTON_H_
#define MENU_BUTTON_H_


#include"parameter.h"
#include"SDL.h"
#include"gameobject.h"
#include"myvector.h"
#include"input.h"
#include<iostream>

class menubutton : public gameobject
{
public:
	
	menubutton(const parameter* , void (*callback)());
	virtual ~menubutton();
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

	/*Every menu button has a function pointer that it will call once pressed*/
	void (*mCallBack)();
	/*variable to see if button realesed or not*/
	bool  mButtonRealesed;

};

#endif