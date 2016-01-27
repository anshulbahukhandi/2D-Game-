#include"vector.h"
using namespace std;


vector::vector(float x , float y) : mX(x) , mY(y)
{

}

vector::~vector()
{

}

const float vector::getX()const 
{
	return mX;
}

const float vector::getY()const 
{
	return mY;
}

void vector::setX(const float x) 
{
	mX=x;
}

void vector::setY(const float y) 
{
	mY=y;
}

float vector::length()
{
	return (sqrt(mX*mX + mY*mY));
}

vector vector::operator+(const vector& v)
{
	vector temp ; 
	temp.mX= mX+v.mX;
	temp.mY= mY+v.mY;

	return temp; 	
}

vector vector::operator-(const vector& v)
{
	vector temp ; 
	temp.mX= mX-v.mX;
	temp.mY= mY-v.mY;

	return temp; 	
}

vector vector::operator*(const float f)
{
	vector temp ; 
	temp.mX=f*mX;
	temp.mY=f*mY;
	return (temp);
}

/* Overloaded for easy division of operators*/
vector vector::operator/(const float f)
{
	vector temp ; 
	temp.mX= mX/f;
	temp.mY= mY/f;

	return temp;
}