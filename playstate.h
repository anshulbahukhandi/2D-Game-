#ifndef PLAY_STATE_H_
#define PLAY_STATE_H_

#include"state.h"
class playState : public state

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