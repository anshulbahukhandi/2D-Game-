#include"statemachine.h"
#include<iostream>
void statemachine::changestate(state* newstate)
{
	std::cout<<"entering change state\n";
	if(!maStates.empty())
	{
		if(maStates.back()->getStateId()==newstate->getStateId())
		{
			return;
		}
		if(maStates.back()->onexit())
		{
			//delete maStates.back();
			maStates.pop_back();
		}
	}
	maStates.push_back(newstate);
	maStates.back()->onenter();
		std::cout<<"exiting change state\n";
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

void statemachine::process()
{
	if(!maStates.empty())
		maStates.back()->process();
}

void statemachine::draw()
{
	if(!maStates.empty())
		maStates.back()->draw();
}




