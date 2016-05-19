#ifndef PARAMETER_H_
#define PARAMETER_H_


#include<string>

class parameter
{

public:

parameter(const std::string  , int , int , int , int, int , int callbackid=0 , int animespeed=0);
~parameter();
std::string getId();
int getX();
int getY();
int getWidth();
int getHeight();
int getFrames() { return mNumFrames;}
int getAnimationSpeed(){return mAnimationSpeed;}
int getCallBackId(){return mCallBackId;}

private:

	std:: string mId; 
	int mX; 
	int mY;

	int mWidth; 
	int mHeight ; 

	int mCurrentFrame ; 
	int mCurrentRow;

	int mNumFrames; 
	int mCallBackId;
	int mAnimationSpeed;

};
#endif