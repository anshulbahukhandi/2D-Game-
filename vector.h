#ifndef VECTOR_H_
#define VECTOR_H_


#include<cmath>
class vector
{

public:
vector() {}
vector( float  , float );

~vector();

const float getX()const ;

const float getY()const ;

void setX(const float) ;

void setY(const float) ;

float length();  

/* Overloaded for easy addition of vectors*/
vector operator+(const vector&);

/* Overloaded for easy subtraction of vectors*/
vector operator-(const vector&);

/* Overloaded for easy division of vectors*/
vector operator/(const float);

/* Overloaded for scalar mutiplication of vectors*/
vector operator*(const float );

/*function to normalize a vector*/
void normalize()
{
	*this/(this->length());
}

private:

float mX;
float mY;

};
#endif