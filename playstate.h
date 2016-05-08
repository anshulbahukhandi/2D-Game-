#ifndef PLAY_STATE_H_
#define PLAY_STATE_H_

#include"state.h"
#include"gameobject.h"
#include<vector>

class playState : public state

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
};

#endif