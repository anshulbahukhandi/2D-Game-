#ifndef MYVECTOR_H_
#define MYVECTOR_H_


#include<cmath>

class myvector
{

public:
myvector() {}
myvector( float  , float );

~myvector();

const float getX()const ;

const float getY()const ;

void setX(const float) ;

void setY(const float) ;

float length();  

/* Overloaded for easy addition of myvectors*/
myvector operator+(const myvector&);

/* Overloaded for easy subtraction of myvectors*/
myvector operator-(const myvector&);

/* Overloaded for easy division of myvectors*/
myvector operator/(const float);

/* Overloaded for scalar mutiplication of myvectors*/
myvector operator*(const float );

/*function to normalize a myvector*/
void normalize()
{
	*this/(this->length());
}

private:

float mX;
float mY;

};
#endif