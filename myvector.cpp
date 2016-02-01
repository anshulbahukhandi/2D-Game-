#include"myvector.h"
using namespace std;


myvector::myvector(float x , float y) : mX(x) , mY(y)
{

}

myvector::~myvector()
{

}

const float myvector::getX()const 
{
	return mX;
}

const float myvector::getY()const 
{
	return mY;
}

void myvector::setX(const float x) 
{
	mX=x;
}

void myvector::setY(const float y) 
{
	mY=y;
}

float myvector::length()
{
	return (sqrt(mX*mX + mY*mY));
}

myvector myvector::operator+(const myvector& v)
{
	myvector temp ; 
	temp.mX= mX+v.mX;
	temp.mY= mY+v.mY;

	return temp; 	
}

myvector myvector::operator-(const myvector& v)
{
	myvector temp ; 
	temp.mX= mX-v.mX;
	temp.mY= mY-v.mY;

	return temp; 	
}

myvector myvector::operator*(const float f)
{
	myvector temp ; 
	temp.mX=f*mX;
	temp.mY=f*mY;
	return (temp);
}

/* Overloaded for easy division of operators*/
myvector myvector::operator/(const float f)
{
	myvector temp ; 
	temp.mX= mX/f;
	temp.mY= mY/f;

	return temp;
}