#ifndef ANIMATED_GRAPHICS_H_
#define ANIMATED_GRAPHICS_H_

#include"gameobject.h"
#include"parameter.h"
class animatedGraphics : public gameObject
{

public:
animatedGraphics(parameter* para , int , int);
~animatedGraphics();
void draw();									
void process();
void clean();
private:
	int mAnimationSpeed;
	int mNumberFrames;
};
#endif