#ifndef STATE_PARSER_H_
#define STATE_PARSER_H_

#include"tinyxml.h"
#include<vector>
#include<iostream>
#include"gameobject.h"
#include<string>

class stateParser
{

public:
	bool parseState(const char* ,  std::string , std::vector<gameObject*> * , std::vector<std::string>* );
private:
	void parseObjects(TiXmlElement* ,std::vector<gameObject*>*);
	void parseTextures(TiXmlElement* ,std::vector<std::string>*);
};
#endif