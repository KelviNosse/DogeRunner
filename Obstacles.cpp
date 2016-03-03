#include "Obstacles.h"

Obstacles::Obstacles(int width, int height)
{
    this->width = width;
    this->height = height;
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
