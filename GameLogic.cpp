#include "GameLogic.h"
#include "DogeMan.h"
#include "DogeCoins.h"
#include "Obstacles.h"
#include "InputControl.h"
#include "Screen.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

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
    s = new Screen(80, 20);
    DogeMan player("Kelvin");
    DogeCoins coin;
    InputControl in;
    Obstacles box(5,5);
    int box_x = box.posx;
    int box_y = box.posy;
    int initial_x = box_x;
    int screen_width = s->GetWidth();
    int coin_x = coin.posx;
    int coin_y = coin.posy;
    //SDL INIT FOR INPUT KEYSTATES
    in.initSDL();
    while(true){
        if(box_x <= -5){
            box_x = initial_x;
            box_y = rand()%(18-15+1)+15; //Generates random number between 15-18 (this can be changed for zpuino/arduino random function)

        }

        if(coin_x <= -55){
            coin_x = initial_x;
            coin_y = rand()%(16-11+1)+11;
        }

        box.Move(box_x, box_y);
        coin.Move(coin_x, coin_y);
        s->drawDoge(player);
        Generate_Doge_Coins(s, coin, coin_x, coin_y);
        s->drawObstacle(box);
        s->displayScreen();
        s->delay(20);
        box_x--;
        coin_x--;
        s->Clear();

        Manage_Input_Jumping(player, in);

        system("clear");

    }

    std::cout<<coin.posy;


}

void GameLogic::Generate_Doge_Coins(Screen *s, DogeCoins &coin, int x, int y){
        int coins_count = 5;
        x = x + 50;
        y = y - 7;
        for(int i = 0; i<2; i++){
            s->drawDogeCoin(coin);
            coin.Move(x+i*20, y);
        }
}

void GameLogic::Manage_Input_Jumping(DogeMan &player, InputControl & in){
        if(player.jumping == 1){
            player.posy--;
            if(player.posy == 4){
                player.jumping = 0;
                player.landing = 1;

            }
        }else{
            if(player.landing == 1){
                player.posy++;
                if(player.posy == 13)
                    player.landing = 0;
            }else
                in.DetectInput(player);
        }
}

void GameLogic::DetectCollision(DogeMan* man, Obstacles* obstacle){

}
