#include"button.h"
#include"myvector.h"
#include"inputhandler.h"

using namespace std; 

button::button(parameter* para , void(*function)() ) : gameObject(para) , mFunction(function)
{
	mCurrentFrame=MOUSE_OUT;
	mButtonReleased=true;
}

void button::draw()
{
	gameObject::draw();
}

void button::process()
{
	myvector* vec=inputHandler::getInstance()->getMousePosition();
	if(	vec->getX() < (mpPosition->getX() + mWidth) && vec->getX() > mpPosition->getX()
		&& vec->getY() < (mpPosition->getY() + mHeight) && vec->getY() > mpPosition->getY()
	  )
	{
		if(inputHandler::getInstance()->getState(LEFT) && mButtonReleased)
		{
			mCurrentFrame = MOUSE_CLICKED;
			mFunction();
			mButtonReleased=false;

		}
		else if(inputHandler::getInstance()->getState(LEFT))
		{
			mButtonReleased=true;
			mCurrentFrame = MOUSE_OVER;
		}

	}
	else
	{
		mCurrentFrame = MOUSE_OUT;
	}
}

void button::clean()
{
	gameObject::clean();
}
