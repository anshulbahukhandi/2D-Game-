#ifndef PLAYER_H_
#define PLAYER_H_



#include"SDL.h"
#include"SDL_image.h"
#include"parameter.h"
#include"gameobject.h"
#include"myvector.cpp"
#include"input.h"
#include<iostream>

class player : public gameobject
{

public:
player(const parameter*);
virtual ~player();
virtual void draw(SDL_Renderer*) ;
virtual void process();
virtual void clean() ;

private:
 

};

#endif