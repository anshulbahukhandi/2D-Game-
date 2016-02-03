#include"menubutton.h"
using namespace std; 

 menubutton::menubutton(const parameter* para , void(*callback)()) : gameobject(para) , mCallBack(callback)
 {
	mCurrentFrame=MOUSEOUT;
	mButtonRealesed=false;
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
	   (tempMousePosition->getY()<mPosition.getY()+mHeight)
	   )
	{
			if(input::getInstance()->getMouseButtonState(LEFT))
			{
				mButtonRealesed=true;
				mCurrentFrame=MOUSEOVER;
			}
			if(input::getInstance()->getMouseButtonState(LEFT) && mButtonRealesed )
			{
				mCurrentFrame=MOUSECLICKED;
				mCallBack();
				mButtonRealesed=false;
			}
		
	}
	else 
		mCurrentFrame=MOUSEOUT;
}

void menubutton::clean()
{
	gameobject::clean();
}
