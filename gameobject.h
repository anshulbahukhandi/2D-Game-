#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_


#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"texture.h"

class gameobject
{
	
public:
void load(int x , int y , int width , int height , std::string id)
{
 mX=x;
 mY=y;
 mCurrentFrame=1;
 mCurrentRow=1;
 mWidth=width;
 mHeight=height;
 mTextureId=id;
}

void draw(SDL_Renderer* renderer) 
{ 
	textureConfig::getInstance()->drawAnimated(mTextureId , mX , mY , mWidth , mHeight ,
										       mCurrentRow ,mCurrentFrame,renderer);
}

void process() 
{ 
	mCurrentFrame=(int)((SDL_GetTicks()/100)%6);
	mX+=1;
}

void clean() 
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