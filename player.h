#ifndef PLAYER_H_
#define PLAYER_H_

#include"gameobject.h"
#include"parameter.h"
#include"gameobjectfactory.h"


class player : public gameObject
{

public:

player();
~player();
void draw();
void process();
void clean();
void load (parameter* para);
private:


};

class playerCreator :public baseCreator
{
	gameObject* createGameObject() const 
	{
		return new player();
	}
};

#endif