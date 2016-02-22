#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include<string>
#include<SDL2/SDL.h>
#include"texturepool.h"
#include"parameter.h"
#include<iostream>
#include"myvector.h"

class gameObject 
{

public:
virtual void draw();									
virtual void process();
virtual void clean();

protected:
	gameObject(parameter* para);
	virtual ~gameObject();
	std:: string mId; 

	myvector* mpPosition; 
	myvector* mpVelocity;
	myvector* mpAcceleration;
	int mWidth; 
	int mHeight ; 

	int mCurrentFrame ; 
	int mCurrentRow;

};

#endif