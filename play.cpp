#include"play.h"
using namespace std; 

const std::string play::mId= "PLAY";

 void play::process()
 {

 }

 void play::render(SDL_Renderer* renderer)
 {

 }


 bool play::enterState(SDL_Renderer* renderer)
 {
 	cout<<"Entering play state\n";
 }

 bool play::exitState()
 {
 	cout<<"Exiting play state\n";
 }


std::string play::getStateId()
{
	return mId;
}
