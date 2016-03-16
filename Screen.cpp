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

void Screen::drawDoge(DogeMan &doge){
    char *body;
    body = doge.GetBody();
    int length = strlen(body);
    int posy = doge.posy;
    int posx = doge.posx;
    for(int i = 0; i<length; i++){
        if(body[i] == 'x'){
            body[i] = '.';
            posx = doge.posx;
            posy++;
        }

        drawAtPos(posx, posy, body[i]);

        posx++;

    }
    displayScreen();

    doge.ResetBody();
}

void Screen::drawAtPos(int x, int y, char pixel){
    this->screen[y][x] = pixel;

}

void Screen::Clear(){
    FillScreen();
}
