#ifndef MAIN_MENU_STATE_H_
#define MAIN_MENU_STATE_H_

#include"gameobject.h"
#include"menustate.h"

#include<vector>
class mainMenuState : public menuState
{

public:
void process();
void draw();
bool onenter();
bool onexit();
const std::string getStateId() const;
private:

	static const std::string mId;
	std::vector<gameObject*> maGameObject;
	
	static void mPlayFunction();
	static void mExitFunction();
	
	void setCallBacks(const std::vector<callBack>& callback);

}; 
#endif