#include "DogeCoins.h"
#include <string.h>
DogeCoins::DogeCoins()
{
    this->scorevalue = 10;
    this->posx = 79;
    this->posy = 15;

    CreateCoin();
}

DogeCoins::~DogeCoins()
{
    //dtor
}

void DogeCoins::CreateCoin(){
    strcpy(this->body, " $ $");
    strcat(this->body, "$ D $");
    strcat(this->body, " $ $");
}
