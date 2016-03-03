#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "DogeMan.h"
#include "Obstacles.h"

class GameLogic
{
    public:
        GameLogic();
        virtual ~GameLogic();

        void initGame();
        void DetectCollision(DogeMan* man, Obstacles* obstacle);
    protected:
    private:

};

#endif // GAMELOGIC_H
