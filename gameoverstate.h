#ifndef GAME_OVER_STATE_H_
#define GAME_OVER_STATE_H_

#include"menustate.h"
#include"gameobject.h"
#include<vector>

class gameoverState : public menuState
{
public:
	void process();
	void draw();
	bool onenter();
	bool onexit();
	virtual const std::string getStateId() const { return mId; }
private:
	static const std::string mId; 
	std::vector<gameObject*> maGameObject;
	static void mRestartFunction();
	static void mMainmenuFunction();

	virtual void setCallBacks(const std::vector<callBack>& callbacks);
} ;
#endif