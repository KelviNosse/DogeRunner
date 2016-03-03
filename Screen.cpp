#include "Screen.h"

Screen::Screen(int width, int height)
{
    this->width = width;
    this->height = height;
    for(int i = 0; i < width; i++)
        this->screen[i] = new char[height];
}

Screen::~Screen()
{
    //dtor
}

void Screen::displayScreen(){
    int screen_size = width*height;

    for(int i = 0; i<screen_size ; i++){

    }
}
