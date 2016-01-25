#ifndef ENEMY_H_
#define ENEMY_H_

class enemy : public gameobject
{

public:
void load(int, int , int , int , std::string );
void draw(SDL_Renderer*) ;
void process();
void clean() ;

};

#endif