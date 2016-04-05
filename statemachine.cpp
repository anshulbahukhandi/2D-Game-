#include"statemachine.h"

void statemachine::changestate(state* newstate)
{
	if(!maStates.empty())
	{
		if(maStates.back()->getStateId()==newstate->getStateId())
		{
			return;
		}
		if(maStates.back()->onexit())
		{
			delete maStates.back();
			maStates.pop_back();
		}
	}
	maStates.push_back(newstate);
	maStates.back()->onenter();
}

void statemachine::pushstate( state* newstate )
{
	maStates.push_back(newstate);
	maStates.back()->onenter();
}

void statemachine::popstate()
{
	if(!maStates.empty())
	{
		if(maStates.back()->onexit())
		{
			delete maStates.back();
			maStates.pop_back();
		}
	}	
}
