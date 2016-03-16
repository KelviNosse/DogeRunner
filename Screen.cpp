#include "Screen.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void Screen::drawObstacle(Obstacles &box){
    char* obstacle;
    obstacle = box.GetBox();
    int width = box.GetWidth();
    int height = box.GetHeight();
    int length = height*width;
    int posx = box.posx;
    int posy = box.posy;
    int counter = 1;
    for(int i = 0; i<length; i++){

        if(counter > width){
            posx = box.posx;
            counter = 1;
            posy++;
        }
        drawAtPos(posx, posy, obstacle[i]);

        posx++;
        counter++;
    }

    displayScreen();
}

void Screen::drawAtPos(int x, int y, char pixel){
    this->screen[y][x] = pixel;

}

void Screen::delay(int ms){
        //This function later can be changed with zpuino/arduino delay included function
        long pause;
        clock_t now, then;

        pause = ms*(CLOCKS_PER_SEC/1000);
        now = then = clock();
        while((now-then) < pause )
            now = clock();

}

void Screen::Clear(){
    FillScreen();
}
