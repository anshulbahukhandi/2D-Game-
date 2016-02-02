#include"menu.h"
using namespace std; 

const std::string menu::mId="MENU";

 void menu::process()
 {

 }

 void menu::render()
 {

 }


 bool menu::enterState()
 {
 	cout<<"Entering MENU state\n";
 }

 bool menu::exitState()
 {
 	cout<<"Exiting MENU state\n";
 }


std::string menu::getStateId()
{
	return mId;
}
