#include"parameter.h"
using namespace std; 

parameter::parameter(const std::string id , int x, int y, int width, int height , int frames , int callback , int speed)
{
	mId=id; 
    mX=x; 
    mY=y;

    mWidth=width; 
    mHeight =height;  
    mNumFrames=frames; 
    mCallBackId=callback;
    mAnimationSpeed=speed;
}

parameter::~parameter()
{

}

int parameter::getX()
{
	return mX;
}

int parameter::getY()
{
	return mY;
}

int parameter::getWidth()
{
	return mWidth;
}

int parameter::getHeight()
{
	return mHeight; 
}

std::string parameter::getId()
{
	return mId;
}