#include<SDL.h> // include SDL
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<time.h>
#include<string>
#include "../TheUncarriables_Project/GameFunctions.h"
#include<SDL_image.h> // Here we can use images in SDL
using namespace std;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	CreateWindow();
	Setting();
	MainLoop();

	SDL_Quit();

	return 0;
}