#include<SDL.h> // include SDL
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<time.h>
#include<string>
#include "../TheUncarriables_Project/GameFunctions.h"
#include<SDL_image.h> // Here we can use images in SDL
#include<SDL_ttf.h>
using namespace std;

int main(int argc, char* argv[])
{
	
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	CreateWindow();
	Setting();
	MainLoop();
	TTF_Quit();
	SDL_Quit();

	return 0;
}