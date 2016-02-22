#ifndef PARAMETER_H_
#define PARAMETER_H_


#include<string>

class parameter
{

public:

parameter(const std::string  , int , int , int , int);
~parameter();
std::string getId();
int getX();
int getY();
int getWidth();
int getHeight();

private:

	std:: string mId; 
	int mX; 
	int mY;

	int mWidth; 
	int mHeight ; 

	int mCurrentFrame ; 
	int mCurrentRow;

};
#endif