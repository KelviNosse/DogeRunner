#include "Obstacles.h"

Obstacles::Obstacles(int width, int height)
{
    this->width = width;
    this->height = height;

    this->posx = 50;
    this->posy = 7;

    CreateBox();
}

Obstacles::~Obstacles()
{
    //dtor
}

int Obstacles::GetHeight(){
    return this->height;
}

int Obstacles::GetWidth(){
    return this->width;
}

char* Obstacles::GetBox(){
    return this->box;
}

void Obstacles::Move(int x, int y){
    this->posx = x;
    this->posy = y;
}

void Obstacles::CreateBox(){
    int length = height*width;
    for(int i = 0; i<length; i++){
        box[i] = '*';
    }
}
