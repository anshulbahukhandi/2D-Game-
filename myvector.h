#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include<cmath>

class myvector
{

public:
	myvector();
	myvector(const float , const float);
	~myvector();
	void setX(const float );
	void setY(const float );
	const float getX();
	const float getY();
	myvector operator+(const myvector&);
	myvector operator*(const float );
	myvector operator-(const myvector&);
	myvector operator/(const float );
	void normalize();

private:
	float mX; 
	float mY; 

};


#endif