#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_


#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"texture.h"
#include"parameter.h"
#include"game.h"
#include"vector.h"

class gameobject
{
	
public:
gameobject(const parameter* para) :mPosition(para->getX() , para->getY()) , mVelocity(0,0) , mAcceleration(0,0)
{
 mCurrentFrame=1;
 mCurrentRow=1;
 mWidth=para->getWidth();
 mHeight=para->getHeight();
 mTextureId=para->getId();
}

virtual ~gameobject(){}

virtual void draw(SDL_Renderer* renderer) 
{ 
	textureConfig::getInstance()->drawAnimated(mTextureId , mPosition.getX() , mPosition.getY() , mWidth , mHeight ,
										       mCurrentRow ,mCurrentFrame,renderer);
}

virtual void process() 
{ 
	mCurrentFrame=(int)((SDL_GetTicks()/100)%6);
	mVelocity=mVelocity+mAcceleration;
	mPosition=mPosition+mVelocity;



}

virtual void clean() 
{

}

protected:
vector mPosition;
vector mVelocity;
vector mAcceleration;
int mCurrentFrame;
int mCurrentRow;
int mWidth;
int mHeight;
std::string mTextureId;

};

#endif