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
        int width;
        int height;
        char **screen = new char*[width];

};

#endif // SCREEN_H
