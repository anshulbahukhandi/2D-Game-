#ifndef GAME_OBJECT_FACTORY_H_
#define GAME_OBJECT_FACTORY_H_

#include<string>
#include<map>
#include"gameobject.h"

class baseCreator
{

public:
	virtual gameObject* createGameObject() const =0;
	virtual ~baseCreator(){}
};


class gameObjectFactory

{

public:
	bool registerType(std::string typeId , baseCreator* pCreator);
	gameObject* create(std::string);
	static gameObjectFactory* getInstance()
	{
		if(mGameObjectFactory==NULL)
			mGameObjectFactory=new gameObjectFactory();
		return mGameObjectFactory;
	}
private: 
	gameObjectFactory(){}
	static gameObjectFactory* mGameObjectFactory;
	std::map<std::string , baseCreator*> mCreatorMap ; 

};

#endif