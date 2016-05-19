#ifndef BUTTON_H_
#define BUTTON_H_

#include"parameter.h"
#include"gameobject.h"
#include"gameobjectfactory.h"

class button : public gameObject
{
public:
	button();
	void draw();
	void process();
	void clean();
	void load(parameter*);	
	void setCallBack(void(*callback)()) {mFunction=callback;}
	int getCallBack(){return mCallBackId;}
private:
	void (*mFunction)();
	bool mButtonReleased;
	enum buttonStatus {MOUSE_OUT=0 , MOUSE_OVER=1 , MOUSE_CLICKED=2};

};

class buttonCreator :public baseCreator
{
	gameObject* createGameObject() const 
	{
		return new button();
	}
};
#endif