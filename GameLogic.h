#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "DogeMan.h"
#include "Obstacles.h"
#include "Screen.h"
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
};

#endif // GAMELOGIC_H
