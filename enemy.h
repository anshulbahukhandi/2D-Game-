#ifndef ENEMY_H_
#define ENEMY_H_

#include"gameobject.h"
#include"parameter.h"
#include"gameobjectfactory.h"

class enemy : public gameObject
{
public:

enemy();
~enemy();
void draw();
void process();
void clean();
void load(parameter*);
protected:

};

class enemyCreator :public baseCreator
{
	gameObject* createGameObject() const 
	{
		return new enemy();
	}
};



#endif