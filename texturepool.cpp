#include"texturepool.h"
using namespace std; 

texturePool* texturePool::mpTexturePool=NULL;

texturePool::texturePool()
{

}

texturePool::~texturePool()
{

}

bool texturePool::loadImage(std::string filename , const std::string id ,SDL_Renderer* renderer)
{
	SDL_Surface* ptemp = IMG_Load(filename.c_str());
	if(ptemp==NULL)
		return false; 
	

	SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer , ptemp);

	SDL_FreeSurface(ptemp);
	
	if(texture==NULL)
		return false; 
	
	
	mTextureMap[id]=texture;
	return true; 
}

void texturePool::drawStatic(const std::string id , SDL_Renderer* renderer , int x 
	                         , int y , int width ,int height , SDL_RendererFlip flag )
{
	SDL_Rect sourceRectangle , destinationRectangle;
	
	sourceRectangle.w=destinationRectangle.w=width;
	sourceRectangle.h=destinationRectangle.h=height;
	sourceRectangle.x=0;
	sourceRectangle.y=0;
	destinationRectangle.x=x;
	destinationRectangle.y=y;
	SDL_RenderCopyEx(renderer , mTextureMap[id] , &sourceRectangle , &destinationRectangle,0,0,flag);
}

void texturePool::drawAnimated(const std::string id , SDL_Renderer* renderer , int x , int y , int width 
	                           ,int height,int currentrow , int currentframe, SDL_RendererFlip flag)
{
	SDL_Rect sourceRectangle , destinationRectangle;
	
	sourceRectangle.w=destinationRectangle.w=width;
	sourceRectangle.h=destinationRectangle.h=height;
	sourceRectangle.x=(currentframe)*width;
	sourceRectangle.y=(currentrow-1)*height;
	destinationRectangle.x=x;
	destinationRectangle.y=y;
	SDL_RenderCopyEx(renderer , mTextureMap[id] , &sourceRectangle , &destinationRectangle,0,0,flag);
}
