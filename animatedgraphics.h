#ifndef ANIMATED_GRAPHICS_H_
#define ANIMATED_GRAPHICS_H_

#include"gameobject.h"
#include"parameter.h"
#include"gameobjectfactory.h"


class animatedGraphics : public gameObject
{

public:
animatedGraphics();
~animatedGraphics();
void draw();									
void process();
void clean();
void load(parameter* para);
private:
};

class animatedGraphicsCreator :public baseCreator
{
	gameObject* createGameObject() const 
	{
		return new animatedGraphics();
	}
};
#endif