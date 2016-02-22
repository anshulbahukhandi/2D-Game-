#ifndef INPUT_HANDLER_H_
#define INPUT_HANDLER_H_


#include<vector>
#include<iostream>

enum mouse_buttons {LEFT = 0,MIDDLE = 1,RIGHT = 2};

class inputHandler
{

public:
~inputHandler();
void  process();
void clean();
bool getState(const int );

static inputHandler*  getInstance()
{
	if(mpInputHandler==NULL)
		mpInputHandler=new inputHandler();
	return mpInputHandler;
}

private:
inputHandler();
inputHandler(const inputHandler&);
inputHandler operator=(const inputHandler&);

static inputHandler* mpInputHandler;
std::vector<bool> mArrayMouseButton; 

};

#endif