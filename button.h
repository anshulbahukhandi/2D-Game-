#ifndef BUTTON_H_
#define BUTTON_H_

#include"parameter.h"
#include"gameobject.h"

class button : public gameObject
{
public:
	button(parameter*  , void(*function)() );
	virtual void draw();
	virtual void process();
	virtual void clean();
private:
	void (*mFunction)();
	bool mButtonReleased;
enum buttonStatus {MOUSE_OUT=0 , MOUSE_OVER=1 , MOUSE_CLICKED=2};

};
#endif