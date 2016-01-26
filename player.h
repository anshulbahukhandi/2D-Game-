#ifndef PLAYER_H_
#define PLAYER_H_



#include"SDL.h"
#include"SDL_image.h"
#include"parameter.h"
#include"gameobject.h"

class player : public gameobject
{

public:
player(const parameter*);
virtual ~player();
virtual void draw(SDL_Renderer*) ;
virtual void process();
virtual void clean() ;

};

#endif