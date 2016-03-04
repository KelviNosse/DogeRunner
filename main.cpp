#include <iostream>
#include "GameLogic.h"
#include "Screen.h"
using namespace std;

int main()
{
    Screen *s = new Screen(80, 10);
    s->displayScreen();
    return 0;
}
