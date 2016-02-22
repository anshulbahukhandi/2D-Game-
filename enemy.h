#ifndef ENEMY_H_
#define ENEMY_H_

#include"gameobject.h"
#include"parameter.h"

class enemy : public gameObject
{
public:

enemy(parameter* );
~enemy();
void draw();
void process();
void clean();

protected:

};

#endif