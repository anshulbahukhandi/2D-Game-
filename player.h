#ifndef PLAYER_H_
#define PLAYER_H_

#include"gameobject.h"
#include"parameter.h"

class player : public gameObject
{

public:

player(parameter* para);
~player();
void draw();
void process();
void clean();

private:


};

#endif