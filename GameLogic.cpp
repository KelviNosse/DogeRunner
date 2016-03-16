#include "GameLogic.h"
#include "DogeMan.h"
#include "Obstacles.h"
#include "Screen.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
GameLogic::GameLogic()
{
    //ctor
}

GameLogic::~GameLogic()
{
    //dtor
}

void GameLogic::initGame(){
    s = new Screen(80, 10);
    DogeMan player("Kelvin");
    s->drawDoge(player);
}

void GameLogic::DetectCollision(DogeMan* man, Obstacles* obstacle){

}
