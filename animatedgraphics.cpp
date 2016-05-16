#include"animatedgraphics.h"

animatedGraphics::animatedGraphics(parameter* para , int speed , int frames) : gameObject(para)
{
	mAnimationSpeed=speed;
	mNumberFrames=frames;
}

animatedGraphics::~animatedGraphics()
{

}

void animatedGraphics::draw()
{
	gameObject::draw();
}	

void animatedGraphics::process()
{
	mCurrentFrame = int(((SDL_GetTicks() / (1000 / mAnimationSpeed)) % mNumberFrames));	
}

void animatedGraphics::clean()
{

}

