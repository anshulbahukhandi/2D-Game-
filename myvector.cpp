#include"myvector.h"
using namespace std; 

myvector::myvector()
{
	mX=0;
	mY=0;
}

myvector::myvector(const float x , const float y)
{
	mX=x;
	mY=y;

}

myvector::~myvector()
{

}

void myvector::setX(const float x)
{
	mX=x;
}

void myvector::setY(const float y)
{
	mY=y;
}

const float myvector::getX()
{
	return mX; 
}

const float myvector::getY()
{
	return mY;
}

myvector myvector::operator+(const myvector& vec)
{
	myvector temp; 
	temp.mX=mX+vec.mX;
	temp.mY=mY+vec.mY;
	return temp ;
}

myvector myvector::operator*(const float s)
{
	myvector temp; 
	temp.mX=s*mX;
	temp.mY=s*mY;
	return temp ;
}

myvector myvector::operator-(const myvector& vec)
{
	myvector temp; 
	temp.mX=mX-vec.mX;
	temp.mY=mY-vec.mY;
	return temp ;
}


myvector myvector::operator/(const float s )
{
	myvector temp; 
	temp.mX=mX/s;
	temp.mY=mY/s;
	return temp ;
}

void myvector::normalize()
{
	float temp = sqrt(mX*mX + mY*mY);
	mX=mX/temp ; 
	mY=mY/temp;
}



