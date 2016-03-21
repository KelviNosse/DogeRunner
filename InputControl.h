#ifndef INPUTCONTROL_H
#define INPUTCONTROL_H
#include "DogeMan.h"
//This class uses SDL2 for input management, temporarily
class InputControl
{
    public:
        InputControl();
        virtual ~InputControl();

        void DetectInput(DogeMan &player);
        bool initSDL(); //Remove this SDL function and add proper controller for zpuino/arduino input control
        int getInput();
    protected:
    private:
        void setInput(int key);
        int key;
};

#endif // INPUTCONTROL_H
