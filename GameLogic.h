#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "DogeMan.h"
#include "Obstacles.h"
#include "Screen.h"
#include "InputControl.h"
class GameLogic
{
    public:
        GameLogic();
        virtual ~GameLogic();

        void initGame();
        void DetectCollision(DogeMan& man,Obstacles& box, int man_x, int man_y, int box_x, int box_y);
        void DetectCoinGrab(DogeMan& player, int man_x, int man_y, int coin_x, int coin_y);
    protected:
    private:
        Screen* s;
        DogeCoins coin;
        InputControl in;
        int coingrab;
        int collision;
        int game_running;
        void Manage_Input_Jumping(DogeMan & player, InputControl &in);
        void Generate_Doge_Coins(Screen *s, DogeCoins &coin, int x, int y);
        void GainScore(DogeMan &player);
        void GameOver();
        void RestartGame();
};

#endif // GAMELOGIC_H
