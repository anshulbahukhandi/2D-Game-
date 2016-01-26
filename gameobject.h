#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_


#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"texture.h"
#include"parameter.h"
#include"game.h"


class gameobject
{
	
public:
gameobject(const parameter* para)
{
 mX=para->getX();
 mY=para->getY();
 mCurrentFrame=1;
 mCurrentRow=1;
 mWidth=para->getWidth();
 mHeight=para->getHeight();
 mTextureId=para->getId();
}

virtual ~gameobject(){}

virtual void draw(SDL_Renderer* renderer) 
{ 
	textureConfig::getInstance()->drawAnimated(mTextureId , mX , mY , mWidth , mHeight ,
										       mCurrentRow ,mCurrentFrame,renderer);
}

virtual void process() 
{ 
	mCurrentFrame=(int)((SDL_GetTicks()/100)%6);
}

virtual void clean() 
{

}

protected:
int mX;
int mY;
int mCurrentFrame;
int mCurrentRow;
int mWidth;
int mHeight;
std::string mTextureId;

};

#endif