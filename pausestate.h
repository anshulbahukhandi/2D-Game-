#ifndef PAUSE_STATE_H_
#define PAUSE_STATE_H_

#include"state.h"
#include"gameobject.h"
#include<vector>

class pauseState : public state
{

public:
	pauseState(){}
	virtual ~pauseState(){}
	void process();
	void draw();
	bool onenter();
	bool onexit();
	const std::string getStateId() const{ return mId; }
private:
	
	static const std::string mId;
	std::vector<gameObject*> maGameObject;
	static void mMainButtonFunction() ; 
	static void mResumeButtonFunction(); 

};

#endif