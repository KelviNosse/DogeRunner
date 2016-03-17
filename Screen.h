#ifndef SCREEN_H
#define SCREEN_H
#include "DogeMan.h"
#include "Obstacles.h"

class Screen
{
    public:
        Screen(int width, int height);
        virtual ~Screen();

        void displayScreen();
        void drawDoge(DogeMan &doge);
        void drawObstacle(Obstacles &box);
        void Clear();
        int GetWidth();
        int GetHeight();
        //Delay function (later will be replaced)
        void delay(int ms);
    protected:
    private:
        void FillScreen();
        void drawAtPos(int x, int y, char pixel);
        int width;
        int height;
        char **screen;

};

#endif // SCREEN_H
