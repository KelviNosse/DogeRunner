#include "InputControl.h"
#include <termios.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "DogeMan.h"
InputControl::InputControl()
{
}

InputControl::~InputControl()
{
    //dtor
}

void InputControl::setInput(int key){
    this->key = key;
}

int InputControl::getInput(){
    return this->key;
}

bool InputControl::initSDL(){
    bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		SDL_CreateWindow( "Doge Runner Window Controller", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 250, 250, SDL_WINDOW_SHOWN );
	}

	return success;
}
void InputControl::DetectInput(DogeMan &player){
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0)
				{
					//User requests quit
        if( e.type == SDL_QUIT )
        {
            exit(0);
        }
    }

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if(keystates[SDL_SCANCODE_UP]){
        player.jump();

    }

}
