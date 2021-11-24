#include<SDL.h> // include SDL
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<time.h>
#include<string>
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
SDL_Surface* surfaceOfDiver;
SDL_Texture* textureOfDiver;
SDL_Surface* surfaceOfPoint;
SDL_Texture* textureOfPoint;
SDL_Rect point;
SDL_Rect bubbleLeft;
SDL_Rect bubbleRight;

//Useful variables
float LeftPosOfDiver;
float PosOfPoint;
float RightPosOfDiver;
float y = 0;
float x = 0;
float BubbleLeftY;
float BubbleRightY;
bool playing = true;
float gameover = 800;


void CreateWindow()
{
	
	SDL_CreateWindowAndRenderer(700, 500, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "TheUncarriables");
}
void SetThePoint()
{
	point.x = 100;

	point.y = 500;

	point.h = 30;

	point.w = 30;
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
void SetTextureAndSurfaceOfPoint()
{
	surfaceOfPoint = IMG_Load("shield.png");
	textureOfPoint = SDL_CreateTextureFromSurface(renderer, surfaceOfPoint);
}
void SetTextureAndSurfaceOfDiver()
{
	surfaceOfDiver = IMG_Load("diver.png");
	textureOfDiver = SDL_CreateTextureFromSurface(renderer, surfaceOfDiver);
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
	diver.h = 50;
	diver.w = 30;
	diver.y = 50;

	diver.x = 200;
}
bool GameOver(float gameover)
{
	if (gameover <= 0)
	{
		playing = false;
		return playing;
	}
}
bool FindCollusion()
{
	if (((round(point.y) - round(diver.y) >= -40) && (round(point.y) - round(diver.y) <= 40) && (round(point.x) - round(diver.x) <= 30) && (round(point.x) - round(diver.x) >= -30)))
	{
		return true;
	}
	
}
void MainLoop()
{
	LeftPosOfDiver = diver.x;
	PosOfPoint = point.y;
	RightPosOfDiver = diver.x;

	BubbleLeftY = bubbleLeft.y;
	BubbleRightY = bubbleRight.y;


	while (playing)
	{
		
		SDL_PollEvent(&SDLevent);
		gameover -= 0.1;
		
		if (SDLevent.type == SDL_QUIT || diver.x == 0 || diver.x == 700)
		{
			
			cout << "Wrong";
			break;
			

		}
		if (SDLevent.type == SDL_KEYDOWN)
		{
			switch (SDLevent.key.keysym.sym)
			{
				case SDLK_LEFT:
				{
					LeftPosOfDiver -= 0.7;
					diver.x = LeftPosOfDiver;
					RightPosOfDiver = LeftPosOfDiver;

					


					goto there;
					break;
				}
				case SDLK_RIGHT:
				{
					RightPosOfDiver += 0.7;
					diver.x = RightPosOfDiver;
					LeftPosOfDiver = RightPosOfDiver;

				
				

					goto there;
					break;
				}
			}
		}



	there:

		SDL_RenderCopy(renderer, textureOfPoint, 0, &point);
		//Copy textureOfPoint in point rectangle
		SDL_RenderCopy(renderer, textureOfDiver, 0, &diver);
		//Copy textureOfDiver in diver rectangle
		SDL_RenderCopy(renderer, textureOfBubbleLeft, 0, &bubbleLeft);
		//Copy textureOfBubbleLeft in bubbleLeft rectangle

		SDL_RenderCopy(renderer, textureOfBubbleRight, 0, &bubbleRight);
		//Copy textureOfBubbleRight in bubbleRight rectangle

		SDL_SetRenderDrawColor(renderer, 51, 153, 255, 255);
		SDL_RenderPresent(renderer);//present renderer and visualisation of all shapes
		SDL_RenderClear(renderer);//Clear renderer for next position of all shapes





		PosOfPoint -= 0.3;
		BubbleLeftY -= 0.2;
		BubbleRightY -= 0.1;
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
		//Find collusion and set random position of the point
		if (FindCollusion() || point.y < -30)
		{
			if (FindCollusion())
			{
				gameover += 150;
			}
			
			y = rand() % 20 + 500;
			x = rand() % 520 + 65;
			point.x = x;
			point.y = y;
			PosOfPoint = point.y;

		}
		// Output the score of life 
		cout << round(gameover) << endl;
		// set Game Over when score is less or equal to 0
		if (GameOver(gameover) != true)
		{
			cout << endl << endl << "GAME OVER!! The water pressure was ENORMOUS!! YOU DIED!!" << endl << endl;
		}
	}
}
void Setting()
{
	SetThePoint();
	SetDiver();
	SetBubbleLeft();
	SetBubbleRight();

	SetTextureAndSurfaceOfPoint();
	SetTextureAndSurfaceOfDiver();
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