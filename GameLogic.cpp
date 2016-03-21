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
    InputControl in;
    Obstacles box(3,5);
    int box_x = box.posx;
    int box_y = box.posy;
    int initial_x = box_x;
    int screen_width = s->GetWidth();
    int coin_x = coin.posx;
    int coin_y = coin.posy;
    char *man_body = player.GetBody();
    char *coin_body = coin.GetBody();
    coingrab = 0;
    collision = 0;
    game_running = 1;
    //SDL INIT FOR INPUT KEYSTATES
    in.initSDL();
    while(game_running){

        if(box_x <= -5){
            box_x = initial_x;
            box_y = rand()%(18-15+1)+15; //Generates random number between 15-18 (this can be changed for zpuino/arduino random function)

        }

        if(coin_x <= -55){
            coin_x = initial_x;
            coin_y = rand()%(12-8+1)+8; //this too
        }

        box.Move(box_x, box_y);
        coin.Move(coin_x, coin_y);
        s->drawDoge(player);
        Generate_Doge_Coins(s, coin, coin_x, coin_y);
        s->drawObstacle(box);
        std::cout<<"Score: "<<player.GetScore()<<endl;
        s->displayScreen();
        s->delay(20);
        box_x--;
        coin_x--;
        s->Clear();

        Manage_Input_Jumping(player, in);
        DetectCollision(player, box, player.posx, player.posy, box_x, box_y);
        DetectCoinGrab(player, player.posx,player.posy, coin_x, coin_y);
        system("clear");



    }




}

void GameLogic::Generate_Doge_Coins(Screen *s, DogeCoins &coin, int x, int y){
        int coins_count = 5;
        x = x + 50;
        y = y - 3;
        for(int i = 0; i<1; i++){
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

void GameLogic::DetectCoinGrab(DogeMan& player, int man_x, int man_y, int coin_x, int coin_y)
{
    //Aproximated height and width values for dogeman and dogecoins
    //man_height = 7;
    //coin_height = 2;
    //coin_width = 5;
    //man_width = 3;
    if(man_y+7 < coin_y){
       coingrab = 0;
    }else if(man_y > coin_y + 2)
    {
        coingrab = 0;
    }else if (man_x > coin_x + 5){
        coingrab = 0;
    }else if(man_x + 3 < coin_x){
        coingrab = 0;
    }else
        coingrab++;

   if(coingrab == 1){
        GainScore(player);
   }



}

void GameLogic::GainScore(DogeMan &player){

    player.SetScore(player.GetScore()+coin.scorevalue);

}
void GameLogic::DetectCollision(DogeMan& man,Obstacles& box, int man_x, int man_y, int box_x, int box_y){

    if(man_y + 5 < box_y ){

    }else if(man_y > box_y + box.GetHeight()){

    }else if(man_x > box_x + box.GetWidth()){

    }else if(man_x + 6 < box_x){
    }else
        GameOver();

//    std::cout<<"Man Pos X: "<<man_x<<endl;
//    std::cout<<"Man Pos Y: "<<man_y<<endl;
//    std::cout<<"Box Pos X: "<<box_x<<endl;
//    std::cout<<"Box Pos Y: "<<box_y<<endl;

}

void GameLogic::GameOver(){

    game_running = 0;
    RestartGame();
}

void GameLogic::RestartGame(){
    if(game_running == 0){
        char opc;
        do{
        cout<<"Game Over :( \nWant to retry Y/N? :";
        cin>>opc;

        if(opc == 'y' || opc=='Y')
            initGame();
        else if(opc == 'n' || opc == 'N')
            exit(0);
        }while(opc != 'y' || opc != 'Y' || opc != 'n' || opc != 'N');

    }
}
