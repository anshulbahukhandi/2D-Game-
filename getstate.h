#ifndef GET_STATE_H_
#define GET_STATE_H_


#include<string>
#include"gamestate.h"
#include<vector>
#include"gamestate.h"
#include"SDL.h"
class getstate
{

public:	
	void process();
	void render(SDL_Renderer*);	
	void addOneDontRemoveOther(gamestate* , SDL_Renderer* );
	void addOneRemoveOther(gamestate* , SDL_Renderer* );
	void removeOne();
private:
	std::vector<gamestate* > mArrayGameState;

};
#endif 