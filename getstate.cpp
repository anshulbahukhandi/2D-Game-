/*Current state will always be the last element of the vector*/

#include"getstate.h"
using namespace std; 


/* Function to push a state to the vector*/
void getstate::addOneDontRemoveOther(gamestate* pState )
{
	mArrayGameState.push_back(pState);
	pState->enterState();
}

/*Function to change a state */
void getstate::addOneRemoveOther(gamestate* pState)
{
	/*If array is not empty*/ 
	if(!mArrayGameState.empty())
	{
		if(pState->getStateId() == mArrayGameState.back()->getStateId())
			return; 
		/*Exit and delete the last state*/
		if(mArrayGameState.back()->exitState())
		{
			delete mArrayGameState.back();
			mArrayGameState.pop_back();	
		}
	}
		/*Once the last state has been deleted . push the new state*/
		mArrayGameState.push_back(pState);
		mArrayGameState.back()->enterState();
}

/*Function to just remove a state*/
void getstate::removeOne()
{
	if(!mArrayGameState.empty())
	{
		/*Exiting the last state and then deleting it*/
		if(mArrayGameState.back()->exitState())
		{
			delete mArrayGameState.back();
			mArrayGameState.pop_back();
		}
		
	}
	else 
		cout<<"Vector is empty . Nothing to remove.\n";
}

void getstate::process()
{
	if(!mArrayGameState.empty())
	{
		mArrayGameState.back()->process();
	}
	else 
		cout<<"No states in the vector  getstate::process()\n";

}

void getstate::render()
{
	if(!mArrayGameState.empty())
	{
		mArrayGameState.back()->render();
	}
	else 
		cout<<"No states in the vector  getstate::render()\n";
}