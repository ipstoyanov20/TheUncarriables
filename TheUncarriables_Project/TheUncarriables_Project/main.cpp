#include<SDL.h> // include SDL
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include<SDL_image.h> // Here we can use images in SDL
using namespace std;

SDL_Rect rect;



int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Surface* surface2;
	SDL_Texture* texture2;
	SDL_CreateWindowAndRenderer(700, 500, 0, &window, &renderer);

	bool flag = true;
	SDL_Event e;

	SDL_RenderClear(renderer);

	srand(time(0));
	SDL_Rect rect2;
	rect2.x = 100;

	rect2.y = 500;

	rect2.h = 20;

	rect2.w = 20;


	SDL_Rect rect3;
	rect3.x = 20;

	rect3.y = 500;

	rect3.h = 50;

	rect3.w = 50;

	SDL_Rect rect4;
	rect4.x = 620;

	rect4.y = 500;

	rect4.h = 50;

	rect4.w = 50;

	surface = IMG_Load("bubble.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	surface2 = IMG_Load("bubble2.png");
	texture2 = SDL_CreateTextureFromSurface(renderer, surface2);

	rect.h = 10;
	rect.w = 10;
	rect.y = 50;

	rect.x = 200;
	float help2 = rect.x;
	float help = rect2.y;
	float help3 = rect.x;
	float counter = 0;
	float y = 0;
	float x = 0;
	float helpbubble = rect3.y;
	int xB;
	int xB2;
	float helpBubble2 = rect4.y;

	while (flag)
	{

		SDL_PollEvent(&e);

		if (e.type == SDL_QUIT || rect.x == 0 || rect.x == 700)
		{
			flag = false;
			cout << "Wrong";
		}
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_LEFT:
			{
				help2 -= 0.3;
				rect.x = help2;
				help3 = help2;
				goto there;
				break;
			}
			case SDLK_RIGHT:
			{
				help3 += 0.3;
				rect.x = help3;
				help2 = help3;
				goto there;
				break;
			}
			}
		}







	there:

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderFillRect(renderer, &rect2);


		SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
		SDL_RenderFillRect(renderer, &rect);

		SDL_RenderCopy(renderer, texture, 0, &rect3);


		SDL_RenderCopy(renderer, texture2, 0, &rect4);


		SDL_SetRenderDrawColor(renderer, 51, 153, 255, 255);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);





		help -= 0.1;
		helpbubble -= 0.07;
		helpBubble2 -= 0.05;
		rect3.y = helpbubble;
		rect2.y = help;
		rect4.y = helpBubble2;


		if (rect3.y < -60)
		{
			helpbubble = 500;
			xB = rand() % 10 + 20;
			rect3.x = xB;
		}
		if (rect4.y < -60)
		{
			helpBubble2 = 500;
			xB2 = rand() % 10 + 620;
			rect4.x = xB2;
		}

		if (((round(rect2.y) - round(rect.y) >= -15) && (round(rect2.y) - round(rect.y) <= 15) && (round(rect2.x) - round(rect.x) <= 15) && (round(rect2.x) - round(rect.x) >= -15)) || rect2.y < -30)
		{
			y = rand() % 20 + 500;
			x = rand() % 340 + 50;
			rect2.x = x;
			rect2.y = y;
			help = rect2.y;

		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}