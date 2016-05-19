#include"stateparser.h"
#include"texturepool.h"
#include"game.h"
#include"parameter.h"
#include<string>
#include<iostream>

bool stateParser::parseState(const char* stateFile,  std::string stateId, std::vector<gameObject*>* pObjects,  std::vector<std::string>*pTextures )
{
		TiXmlDocument xmlDoc;
		//checking if file loading successfull
		if(!xmlDoc.LoadFile(stateFile))
		{
			std::cout<<xmlDoc.ErrorDesc()<<"\n";
			return false;
		}
		//Get the root element
		TiXmlElement* pRoot=xmlDoc.RootElement(); 
		
		TiXmlElement* pStateRoot=0;
		for( TiXmlElement* p=pRoot->FirstChildElement() ; p!=NULL ; p=p->NextSiblingElement())
		{
			if(p->Value()==stateId)
				pStateRoot=p;
		}
		TiXmlElement* pTextureRoot=0;
		for( TiXmlElement* p =pStateRoot->FirstChildElement() ; p!=NULL ; p=p->NextSiblingElement())
		{
			if(p->Value()==(std::string)"TEXTURES")
				pTextureRoot=p;
		}
		parseTextures(pTextureRoot, pTextures);

		TiXmlElement* pObjectRoot=0;
		for(TiXmlElement* p=pStateRoot->FirstChildElement() ; p!=NULL ; p=p->NextSiblingElement())
		{
			if(p->Value()==(std::string)"OBJECTS")
				pObjectRoot=p;
		}
		parseObjects(pObjectRoot , pObjects);
		return true; 
}

void stateParser::parseTextures(TiXmlElement* pStateRoot,std::vector<std::string>* pTextureIds)
{
	for(TiXmlElement* p=pStateRoot->FirstChildElement() ; p!=NULL ; p=p->NextSiblingElement())
	{
		std::string filenameAttribute=p->Attribute("filename");
		std::string idAttribute=p->Attribute("ID");
		pTextureIds->push_back(idAttribute);
		texturePool::getInstance()->loadImage(filenameAttribute ,idAttribute , game::getInstance()->getRenderer());
	}
}

void stateParser::parseObjects(TiXmlElement* pStateRoot ,std::vector<gameObject*>* pObjects)
{	
	for( TiXmlElement* p=pStateRoot->FirstChildElement() ; p!=NULL ; p=p->NextSiblingElement())
	{
		int x , y , width , height , callback, numframes , animespeed ;
		std::string id ;
		//since xml files are pure text files  , this is how you assign values.
		p->Attribute("x" , &x);
		p->Attribute("y" , &y);
		p->Attribute("width" , &width);
		p->Attribute("height" , &height);
		p->Attribute("numFrames" , &numframes);
		p->Attribute("callbackID" , &callback);
		p->Attribute("animationSpeed" , &animespeed);
		id=p->Attribute("textureID");

		gameObject* pGameObject=gameObjectFactory::getInstance()->create(p->Attribute("type"));
		pGameObject->load(new parameter(id , x, y ,width , height , numframes ,callback, animespeed));

		pObjects->push_back(pGameObject);
		
	}
}

















