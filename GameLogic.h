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
        void DetectCollision(DogeMan* man, Obstacles* obstacle);
    protected:
    private:
        Screen* s;
        void Manage_Input_Jumping(DogeMan & player, InputControl &in);
        void Generate_Doge_Coins(Screen *s, DogeCoins &coin, int x, int y);
};

#endif // GAMELOGIC_H
