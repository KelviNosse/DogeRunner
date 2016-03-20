#include "DogeCoins.h"
#include <string.h>
DogeCoins::DogeCoins()
{
    this->scorevalue = 10;
    this->posx = 60;
    this->posy = 10;

    CreateCoin();
}

DogeCoins::~DogeCoins()
{
    //dtor
}

char* DogeCoins::GetBody(){
    return this->body;
}

void DogeCoins::Move(int x, int y){
    this->posx = x;
    this->posy = y;
}
void DogeCoins::CreateCoin(){
    strcpy(this->body, "..$ $x");
    strcat(this->body, "$ D $x");
    strcat(this->body, " $ $ ");
}

void DogeCoins::ResetBody(){
    CreateCoin();
}
