#ifndef STATE_H_
#define STATE_H_

#include<string>

class state
{
	
public:
	virtual void process()=0;
	virtual void render()=0;
	virtual bool onenter()=0;
	virtual bool onexit()=0;

	virtual const std::string getStateId() const =0;

};
#endif