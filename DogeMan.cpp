#include "DogeMan.h"

DogeMan::DogeMan(char* name)
{
    this->name = name;
    this->alive = true;
    this->lives = 3;
    this->score = 0;
}

DogeMan::~DogeMan()
{
    //dtor
}

char* DogeMan::GetName(){
    return this->name;
}
