#include "Screen.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
Screen::Screen(int width, int height)
{
    this->width = width;
    this->height = height;

    this->screen = (char**)malloc(width*sizeof(int*));
    for(int i = 0; i< width; i++)
        this->screen[i] = (char*)malloc(height*sizeof(int*));

    this->FillScreen();

}

Screen::~Screen()
{
    //dtor
}

void Screen::displayScreen(){
    for(int k = 0; k< height; k++){
        for(int j = 0; j< width; j++){
            std::cout<<this->screen[k][j];
        }
        std::cout<<std::endl;
    }
}

void Screen::FillScreen(){
    for(int k = 0; k< height; k++){
        for(int j = 0; j< width; j++){
            this->screen[k][j] = '.';
        }
    }
}
