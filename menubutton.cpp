#include"menubutton.h"
using namespace std; 

 menubutton::menubutton(const parameter* para) : gameobject(para)
 {
	mCurrentFrame=MOUSEOUT;

 }

 menubutton::~menubutton()
 {

 }

void menubutton::draw(SDL_Renderer* renderer)
{
	gameobject::draw(renderer);
}
	
void menubutton::process()
{
	myvector* tempMousePosition=new myvector();
	tempMousePosition=input::getInstance()->getMousePosition();
	if(
	   (tempMousePosition->getX()>mPosition.getX()) &&
	   (tempMousePosition->getX()<mPosition.getX()+mWidth) &&	
	   (tempMousePosition->getY()>mPosition.getY())  &&
	   (tempMousePosition->getY()<mPosition.getY()+mWidth)
	   )
	{
		mCurrentFrame=MOUSEOVER;
		if(input::getInstance()->getMouseButtonState(LEFT))
			mCurrentFrame=MOUSECLICKED;
	}
	else 
		mCurrentFrame=MOUSEOUT;
}

void menubutton::clean()
{
	gameobject::clean();
}
