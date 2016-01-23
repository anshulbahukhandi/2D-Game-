/* Name : Anshul Bahukhandi
   Date : 1/22/2016
*/
 /* We will always copy the complete texture data structure from 
    source rectangle .
    In case we need some portion of a particular image we will not
	create a seperate texture structure for it instead we will 
	load just the required portion using two drawing function.
 */

/* This class is made singleton so that there  is only one texture pool*/

#ifndef TEXTURE_H_
#define TEXTURE_H_
#include<iostream>
#include<fstream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include<map>
class textureConfig
{

public:
~textureConfig(){}

/*Function will load image by making it texture structure*/
bool load ( std::string imagename , std::string id  , SDL_Renderer* renderer);

/*Function to draw the static image*/
bool drawStatic(std::string ,int  , int , int , int , SDL_Renderer* , SDL_RendererFlip  );

/*Function to draw the animated image or spirits*/ 
bool drawAnimated(std::string ,int  , int , int , int ,int , int , SDL_Renderer* , SDL_RendererFlip );

/*Function to access the only object of this class*/
static textureConfig& getInstance()
{
	return mpTexture;
}

private:
static textureConfig mpTexture;
/* All textures will be stored in this map */
std::map<std::string , SDL_Texture*>	mTextureArray;
textureConfig(){}
textureConfig(const textureConfig&);
textureConfig& operator=(const textureConfig&);
};
#endif 