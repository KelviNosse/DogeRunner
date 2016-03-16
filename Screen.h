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
        void drawObstacle();
        void Clear();
    protected:
    private:
        void FillScreen();
        void drawAtPos(int x, int y, char pixel);
        int width;
        int height;
        char **screen;

};

#endif // SCREEN_H
