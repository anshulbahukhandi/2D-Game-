#include"gameobject.h"
#include"game.h"
using namespace std; 

gameObject::gameObject(parameter* para)
{
	mpPosition=new myvector( para->getX() , para->getY());
	mpVelocity=new myvector(); //default  velocity is zero
	mpAcceleration=new myvector(); //default acceleration is zero

	mId = para->getId();  
	mWidth = para->getWidth(); 
	mHeight  = para->getHeight();

	mCurrentRow = 1;
	mCurrentFrame  = 1;
}

gameObject::~gameObject()
{

}

void gameObject::draw()
{
	texturePool::getInstance()->drawAnimated(mId , game::getInstance()->getRenderer(), mpPosition->getX()  , mpPosition->getY()  , mWidth  ,mHeight , mCurrentRow , mCurrentFrame);
}

void gameObject::process()
{
	mCurrentFrame=(SDL_GetTicks()/100)%4;
	/* This Game object changes the position based on the velocity and acceleratio
	   There is no need to change the position for the objects individually . Objects can
	   just decide the velocity and acceleration .*/
	  *mpPosition=*mpPosition + *mpVelocity;
	  *mpVelocity=*mpVelocity + *mpAcceleration;
}

void gameObject::clean()
{

}

