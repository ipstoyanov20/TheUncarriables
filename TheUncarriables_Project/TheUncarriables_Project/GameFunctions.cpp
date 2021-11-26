#include<SDL.h> // include SDL
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<time.h>
#include<string>
#include "../TheUncarriables_Project/GameFunctions.h"
#include<SDL_image.h> // Here we can use images in SDL
using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Rect diver;
SDL_Event SDLevent;
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
int countQuestions = 0;
string answer;
int randomquiz = 0;
string arrayOfQuestion[10] = { "In what unit are forces measured?", "When the net force on an object equals 0 Newtons, we know the forces are __?", "Anytime the net force does NOT equal zero, the forces are __", "What is the scientific name for a push or a pull?", "The combination of multiple forces acting on an object is known as", "Which type of force creates contact between two surfaces?", "What operation is used to calculate net forces acting in the SAME direction?", "What operation is used to calculate net forces acting in DIFFERENT directions?", "True or false, in physics we measure speed in m/s", "True or false, Forces cannot act on objects from a distance, only through direct contact." };
void CreateWindow()
{

	SDL_CreateWindowAndRenderer(700, 500, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "TheUncarriables");
	SDL_SetWindowPosition(window, 700, SDL_WINDOWPOS_CENTERED);
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
	if (gameover >= 0)
	{
		playing = true;
		return playing;
	}
}
bool FindCollusion()
{
	if (((round(point.y) - round(diver.y) >= 0) && (round(point.y) - round(diver.y) <= 35) && (round(point.x) - round(diver.x) <= 20) && (round(point.x) - round(diver.x) >= -20)))
	{
		return true;
	}

}
void Quiz()
{
	cout << "Type only with small letters:" << endl;
	cout << arrayOfQuestion[countQuestions] << endl;

	getline(cin, answer);
	switch (countQuestions)
	{
	case 0: {
		if (answer == "newtons")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your to: " << round(gameover) << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'newtons\'" << endl;
			gameover -= 80;
			cout << "You decrease your score to: " << round(gameover) << endl;
		}

		break;
	}
	case 1: {
		if (answer == "balanced")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your to: " << round(gameover) << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'balanced\'" << endl;
			gameover -= 80;
			cout << "You decrease your score to: " << round(gameover) << endl;
		}
		break;
	}
	case 2: {
		if (answer == "unbalanced")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your to:  " << round(gameover) << endl;

		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'unbalanced\'" << endl;
			gameover -= 80;
			cout << "You decrease your score to: " << round(gameover) << endl;
		}
		break;
	}
	case 3: {
		if (answer == "force")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your to: " << round(gameover) << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'force\'" << endl;
			gameover -= 80;
			cout << "You decrease your score to: " << round(gameover) << endl;
		}
		break;
	}
	case 4: {
		if (answer == "net force")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your to: " << round(gameover) << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'net force\'" << endl;
			gameover -= 80;
			cout << "You decrease your score to: " << round(gameover) << endl;
		}
		break;
	}
	case 5: {
		if (answer == "fricton")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your to: " << round(gameover) << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'friction\'" << endl;
			gameover -= 80;
			cout << "You decrease your score to: " << round(gameover) << endl;
		}
		break;
	}
	case 6: {
		if (answer == "+")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your to: " << round(gameover) << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'+\'" << endl;
			gameover -= 80;
			cout << "You decrease your score to: " << round(gameover) << endl;
		}
		break;
	}
	case 7: {
		if (answer == "-")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your to: " << round(gameover) << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'-\'" << endl;
			gameover -= 80;
			cout << "You decrease your score to: " << round(gameover) << endl;
		}
		break;
	}
	case 8: {
		if (answer == "true")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your to: " << round(gameover) << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'true\'" << endl;
			gameover -= 80;
			cout << "You decrease your score to: " << round(gameover) << endl;
		}
		break;
	}
	case 9: {
		if (answer == "false")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your to: " << round(gameover) << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'false\'" << endl;
			gameover -= 80;
			cout << "You decrease your score to: " << round(gameover) << endl;

		}
		break;
	}

	}
	countQuestions++;
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
				randomquiz++;
				if (randomquiz % 5 == 0)
				{
					Quiz();

					cout << "Press \'Alt + Tab\' and WAIT to continue playing" << endl;
					cout << "Ready?" << endl;
					cout << "GOO!";
					SDL_Delay(7000);

				}
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
		if (GameOver(gameover) == true)
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
