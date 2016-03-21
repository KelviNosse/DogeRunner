#include "DogeMan.h"
#include <stdio.h>
#include <string.h>
DogeMan::DogeMan(char* name)
{
    this->name = name;
    this->alive = true;
    this->lives = 3;
    this->score = 0;
    this->posx = 10;
    this->posy = 13;
    this->jumping = 0;
    this->landing = 0;
    this->CreateBody();
}

DogeMan::~DogeMan()
{
    //dtor
}

void DogeMan::CreateBody(){
    strcpy(this->body, "..___x");
    strcat(this->body, "/  V`-,x");
    strcat(this->body, "\\__.~~x");
    strcat(this->body, "/-|--/x");
    strcat(this->body, " /--ix");
    strcat(this->body, "/   Lx");
    strcat(this->body, "L");

}

char* DogeMan::GetBody(){
    return this->body;
}

char* DogeMan::GetName(){
    return this->name;
}

int DogeMan::GetScore(){
    return this->score;
}

void DogeMan::SetScore(int value){

    this->score = value;
}

void DogeMan::Move(int x, int y){
    this->posx = x;
    this->posy = y;

}

void DogeMan::jump(){
    posy--;
    jumping = 1;

}
void DogeMan::ResetBody(){
    this->CreateBody();
}
