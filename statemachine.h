#ifndef  STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include"state.h"
#include<vector>

class statemachine
{

public:
	void changestate(state* );
	void pushstate( state*  );
	void popstate();
private:

std::vector<state*> maStates;

};

#endif