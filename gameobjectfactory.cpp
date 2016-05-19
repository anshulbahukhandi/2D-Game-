#include"gameobjectfactory.h"
#include<iostream>


gameObjectFactory* gameObjectFactory::mGameObjectFactory=NULL;

bool gameObjectFactory::registerType(std::string typeId , baseCreator* pCreator)
{
	std::map<std::string , baseCreator*>::iterator it =mCreatorMap.find(typeId);
	if(it!=mCreatorMap.end())
	{
		delete pCreator;
		return false;
	}
	mCreatorMap[typeId]=pCreator;
	return true; 

}

gameObject* gameObjectFactory::create(std::string typeId)
{
	std::map<std::string , baseCreator*>::iterator it=mCreatorMap.find(typeId);
	if(it==mCreatorMap.end())
	{
		std::cout<<"Could not find type : "<<typeId<<"\n";
		return NULL;
	}
	baseCreator* pCreator=(*it).second;
	return pCreator->createGameObject();

}