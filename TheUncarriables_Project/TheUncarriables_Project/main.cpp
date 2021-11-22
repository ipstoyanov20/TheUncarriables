#include<SDL.h> // include SDL
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<time.h>
#include<SDL_image.h> // Here we can use images in SDL
using namespace std;

SDL_Rect diver;
SDL_Event SDLevent;
SDL_Renderer* renderer;
SDL_Window* window;
SDL_Surface* surfaceOfBubbleLeft;
SDL_Texture* textureOfBubbleLeft;
SDL_Surface* surfaceOfBubbleRight;
SDL_Texture* textureOfBubbleRight;
SDL_Rect point;
SDL_Rect bubbleLeft;
SDL_Rect bubbleRight;

//Useful variables
float LeftPosOfDiver;
float PosOfPoint;
float RightPosOfDiver;
float counter = 0;
float y = 0;
float x = 0;
float BubbleLeftY;
float BubbleRightY;
bool flag = true;
void CreateWindow()
{
	
	SDL_CreateWindowAndRenderer(700, 500, 0, &window, &renderer);
}
void SetThePoint()
{
	point.x = 100;

	point.y = 500;

	point.h = 20;

	point.w = 20;
}
void SetBubbleLeft()
{

	bubbleLeft.x = 20;

	bubbleLeft.y = 500;

	bubbleLeft.h = 50;

	bubbleLeft.w = 50;
}

void SetBubbleRight()
{

	bubbleRight.x = 620;

	bubbleRight.y = 500;

	bubbleRight.h = 50;

	bubbleRight.w = 50;
}
void SetTextureAndSurfaceOfBubbleleft()
{
	surfaceOfBubbleLeft = IMG_Load("bubble.png");
	textureOfBubbleLeft = SDL_CreateTextureFromSurface(renderer, surfaceOfBubbleLeft);
}
void SetTextureAndSurfaceOfBubbleright()
{
	surfaceOfBubbleRight = IMG_Load("bubble2.png");
	textureOfBubbleRight = SDL_CreateTextureFromSurface(renderer, surfaceOfBubbleRight);
}
void SetDiver()
{
	diver.h = 10;
	diver.w = 10;
	diver.y = 50;

	diver.x = 200;
}
void MainLoop()
{
	LeftPosOfDiver = diver.x;
	PosOfPoint = point.y;
	RightPosOfDiver = diver.x;

	BubbleLeftY = bubbleLeft.y;
	BubbleRightY = bubbleRight.y;
	while (flag)
	{
		
		SDL_PollEvent(&SDLevent);

		if (SDLevent.type == SDL_QUIT || diver.x == 0 || diver.x == 700)
		{
			flag = false;
			cout << "Wrong";

		}
		if (SDLevent.type == SDL_KEYDOWN)
		{
			switch (SDLevent.key.keysym.sym)
			{
			case SDLK_LEFT:
			{
				LeftPosOfDiver -= 0.3;
				diver.x = LeftPosOfDiver;
				RightPosOfDiver = LeftPosOfDiver;
				goto there;
				break;
			}
			case SDLK_RIGHT:
			{
				RightPosOfDiver += 0.3;
				diver.x = RightPosOfDiver;
				LeftPosOfDiver = RightPosOfDiver;
				goto there;
				break;
			}
			}
		}







	there:

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderFillRect(renderer, &point);//set drawing a point


		SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
		SDL_RenderFillRect(renderer, &diver);// set drawing a diver

		SDL_RenderCopy(renderer, textureOfBubbleLeft, 0, &bubbleLeft);
		//Copy textureOfBubbleLeft in bubbleLeft

		SDL_RenderCopy(renderer, textureOfBubbleRight, 0, &bubbleRight);
		//Copy textureOfBubbleRight in bubbleRight

		SDL_SetRenderDrawColor(renderer, 51, 153, 255, 255);
		SDL_RenderPresent(renderer);//present renderer and visualisation of all shapes
		SDL_RenderClear(renderer);//Clear renderer for next position of all shapes





		PosOfPoint -= 0.1;
		BubbleLeftY -= 0.07;
		BubbleRightY -= 0.05;
		bubbleLeft.y = BubbleLeftY;
		point.y = PosOfPoint;
		bubbleRight.y = BubbleRightY;


		if (bubbleLeft.y < -60)
		{
			BubbleLeftY = 500;

		}
		if (bubbleRight.y < -60)
		{
			BubbleRightY = 500;

		}
		//Find collusion and set random position of point
		if (((round(point.y) - round(diver.y) >= -15) && (round(point.y) - round(diver.y) <= 15) && (round(point.x) - round(diver.x) <= 15) && (round(point.x) - round(diver.x) >= -15)) || point.y < -30)
		{
			y = rand() % 20 + 500;
			x = rand() % 340 + 50;
			point.x = x;
			point.y = y;
			PosOfPoint = point.y;

		}
	}
}
void Setting()
{
	SetThePoint();
	SetDiver();
	SetBubbleLeft();
	SetBubbleRight();



	SetTextureAndSurfaceOfBubbleleft();
	SetTextureAndSurfaceOfBubbleright();
}
int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	CreateWindow();
	Setting();
	MainLoop();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}