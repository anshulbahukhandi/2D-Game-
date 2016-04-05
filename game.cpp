#include"game.h"
#include"inputhandler.h"

using namespace std; 

game* game::myGame=NULL;


bool game::init(const string str , const int x , const int y , const int width , const int height , const bool tflag)
{
	int flag; 
	if(tflag==true)
		flag=SDL_WINDOW_FULLSCREEN;
	else 
		flag=SDL_WINDOW_SHOWN;

	if(SDL_Init(SDL_INIT_EVERYTHING) >=0)
	{
		mpWindow=SDL_CreateWindow(str.c_str() , x, y, width , height , flag);
		if(mpWindow!=0)
		{
			mpRenderer=SDL_CreateRenderer(mpWindow , -1 , 0);
			if(mpRenderer==0)
			{
				cout<<"Failed to create renderer\n"; 																										
				return 0 ;
			}
			else 
				mRunning=true;
		}
		else
		{
			cout<<"Window creation failed\n";
			return 0; 
		}
	}
	else 
	{
		cout<<"SDL Failed to initialize!!\n";
		return 0 ;
	}

	//If everything is successfull program execution will come here
	parameter* playerPara;
	parameter* enemyPara;
	if(texturePool::getInstance()->loadImage("images/horse.png" , "horse" , mpRenderer)
		&& texturePool::getInstance()->loadImage("images/cat.bmp" , "cat" , mpRenderer) 
	   )
	{
		 playerPara=new parameter("horse" , 0 , 100 , 320,225);
		 enemyPara=new parameter ("cat" , 500 , 0 , 128,82);	
	}
	else return false; 
	
	gameObject* mPlayer1=new player(playerPara);
	gameObject* mEnemy1=new enemy(enemyPara);

	mGameObjects.push_back(mEnemy1);
	mGameObjects.push_back(mPlayer1);

	mpStateMachine=new statemachine();
	mpStateMachine->pushstate(new menuState());

	return true;
}

void game::render()
{
	SDL_SetRenderDrawColor(mpRenderer ,0,100, 200 , 0);
	SDL_RenderClear(mpRenderer);
	for(int i = 0 ; i<mGameObjects.size();i++)
		mGameObjects[i]->draw();
	SDL_RenderPresent(mpRenderer);
}

void game::handleEvent()
{
	inputHandler::getInstance()->process();
	if(inputHandler::getInstance()->isKeyPressed(SDL_SCANCODE_RETURN))
	{
		mpStateMachine->changestate(new playState());
	}
}

void game::process()
{
	for(int i = 0 ; i<mGameObjects.size();i++)
		mGameObjects[i]->process();
}

void game::clean()
{
	cout<<"Cleaning game variables\n";
	SDL_DestroyWindow(mpWindow);
	SDL_DestroyRenderer(mpRenderer);
	SDL_Quit();
}

bool game::running()
{
	return mRunning;
}




