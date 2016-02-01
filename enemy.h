#ifndef ENEMY_H_
#define ENEMY_H_

#include"parameter.h"
#include"myvector.h"

class enemy : public gameobject
{

public:

enemy(const parameter*);
virtual ~enemy();
virtual void draw(SDL_Renderer*) ;
virtual void process();
virtual void clean() ;

};

#endif