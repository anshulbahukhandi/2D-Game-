#ifndef GET_STATE_H_
#define GET_STATE_H_


#include<string>
#include"gamestate.h"
#include<vector>

class getstate
{

public:	
	void process();
	void render();	
	void addOneDontRemoveOther(gamestate* );
	void addOneRemoveOther(gamestate* );
	void removeOne();
private:
	std::vector<gamestate* > mArrayGameState;

};
#endif 