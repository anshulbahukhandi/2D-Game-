#ifndef TEXTURE_POOL_H_
#define TEXTURE_POOL_H_

#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<map>
#include<iostream>
class texturePool
{

public:


~texturePool();
static texturePool* getInstance()
{
	if(mpTexturePool==NULL)
		mpTexturePool=new texturePool();
	
	return mpTexturePool;
}
bool loadImage(const std::string  , const std::string , SDL_Renderer* );
void drawStatic(const std::string , SDL_Renderer*, int  , int  , int  ,int  ,SDL_RendererFlip flag =SDL_FLIP_NONE );
void drawAnimated(const std::string , SDL_Renderer*, int  , int, int ,int ,int , int, SDL_RendererFlip flag =SDL_FLIP_NONE );

private:
/*To stop copying , assigning and creation of new texturePool*/
texturePool();
texturePool(const texturePool&);
texturePool& operator=(const texturePool&);

std::map<std::string , SDL_Texture*>  mTextureMap; 
static texturePool* mpTexturePool;

};

#endif