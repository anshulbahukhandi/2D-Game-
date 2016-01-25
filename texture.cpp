#include"texture.h"
using namespace std; 

textureConfig* textureConfig::mpTexture=NULL;
/*Function will load image by making it texture structure*/
bool textureConfig::load ( std::string imagename , std::string id  , SDL_Renderer* renderer)
{
	/*Loading the image in the texture data structure*/
	SDL_Surface * pSurface=IMG_Load(imagename.c_str());
	if(pSurface==0)
		return false;
	else
	{
		SDL_Texture* pTexture=SDL_CreateTextureFromSurface(renderer , pSurface);
		SDL_FreeSurface(pSurface);
		if(pTexture==0)
		return false; 
		else
		{/*Add texture to our texture array*/
			mTextureArray[id]=pTexture;
			return true;
		}	
	}
}

/*Function to draw the static image*/
/* First argument is the id of the texture we want to draw*/
bool textureConfig::drawStatic(std::string id, int x , int y , int width , int height ,
							   SDL_Renderer* renderer , SDL_RendererFlip flip=SDL_FLIP_NONE  )
{
	SDL_Rect sourceRectangle; 
	SDL_Rect destinationRectangle; 

	/* Setting the destination rectangle width and height and position*/
	sourceRectangle.x=0;
	sourceRectangle.y=0;
	sourceRectangle.w=destinationRectangle.w=width;
	sourceRectangle.h=destinationRectangle.h=height;
	destinationRectangle.x=x;
	destinationRectangle.y=y;	

	/* Drawing the texture data structure
	   You can imagine rectangles as just frames/boundary  and not image .
	   You places the source rectangle on the image and the portion inside the
	   rectangle is copied inside the destination rectangle placed on the window*/
	SDL_RenderCopyEx( renderer, mTextureArray[id] , &sourceRectangle , &destinationRectangle , 0 ,0 ,flip);
	
}

/*Function to draw the animated image or spirits*/ 
bool textureConfig::drawAnimated(std::string id, int x , int y, int width , int height, int currentRow  
								 , int currentFrame, SDL_Renderer* renderer , SDL_RendererFlip flip=SDL_FLIP_NONE)
{	

/* current frame can be thought of as the column index and current row is row index.
   Imagine the spirit with its frames in 2D array*/

	SDL_Rect sourceRectangle; 
	SDL_Rect destinationRectangle; 

	/* Setting the destination rectangle width and height and position.
	   starting with 0th row and 0th column.
	
	/*current frame is not reduced by one because we will be starting from 
      second frame and first frame will be initialized.
    */

	sourceRectangle.x=currentFrame* width;  
	sourceRectangle.y=(currentRow-1)*height;
	sourceRectangle.w=destinationRectangle.w=width;
	sourceRectangle.h=destinationRectangle.h=height;
	destinationRectangle.x=x;
	destinationRectangle.y=y;	

	/* Drawing the texture data structure
	   You can imagine rectangles as just frames/boundary  and not image .
	   You places the source rectangle on the image and the portion inside the
	   rectangle is copied inside the destination rectangle placed on the window*/
	  /*This function renders to the hidden target.
	  	RenderPresent function in game .cpp in render() brings all this data in the 
	  	hidden place to existence*/
	SDL_RenderCopyEx( renderer, mTextureArray[id] , &sourceRectangle , &destinationRectangle , 0 ,0 ,flip);
}







