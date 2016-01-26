#ifndef PARAMETER_H_
#define PARAMETER_H_


#include<string>
class parameter
{

public:
parameter(int x , int y , int width , int height , std::string id) : mX(x) , mY(y) , mWidth(width) , mHeight(height) , mTextureId(id) {} 
~parameter(){}
int getX()const  { return mX;}
int getY()const  { return mY;}
int getWidth()const  { return mWidth;}
int getHeight()const { return mHeight; }
std::string getId()const { return mTextureId; }

private:

int mX; 
int mY;
int mWidth; 
int mHeight ; 
std::string mTextureId;

};
#endif
