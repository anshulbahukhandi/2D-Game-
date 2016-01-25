#ifndef PLAYER_H_
#define PLAYER_H_


#include"gameobject.h"
#include"SDL.h"
#include"SDL_image.h"


class player : public gameobject
{

public:

void load(int, int , int , int , std::string );
void draw(SDL_Renderer*) ;
void process();
void clean() ;

};

#endif