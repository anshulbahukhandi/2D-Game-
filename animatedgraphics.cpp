#include"animatedgraphics.h"

animatedGraphics::animatedGraphics()
{

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
	mCurrentFrame = int(((SDL_GetTicks() / (1000 / mAnimationSpeed)) % mNumFrames));	
}

void animatedGraphics::clean()
{

}

void animatedGraphics::load(parameter* para)
{
	gameObject::load(para);
}
