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
        void drawDoge();
        void drawObstacle();
    protected:
    private:
        void FillScreen();
        int width;
        int height;
        char **screen;

};

#endif // SCREEN_H
