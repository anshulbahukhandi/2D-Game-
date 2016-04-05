#ifndef MENU_STATE_H_
#define MENU_STATE_H_

#include"state.h"
class menuState : public state
{

public:
void process();
void render();
bool onenter();
bool onexit();
const std::string getStateId() const;
private:
	static const std::string mId;

}; 
#endif