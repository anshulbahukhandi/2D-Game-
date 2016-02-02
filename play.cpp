#include"play.h"
using namespace std; 

const std::string play::mId= "PLAY";

 void play::process()
 {

 }

 void play::render()
 {

 }


 bool play::enterState()
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
