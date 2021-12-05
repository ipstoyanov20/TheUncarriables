#include<SDL.h> // include SDL
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<time.h>
#include<string>
#include "../TheUncarriables_Project/GameFunctions.h"
#include<SDL_image.h> // Here we can use images in SDL
#include<SDL_ttf.h>//Here we can display text in SDL window
using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Rect diver;
SDL_Surface* surfaceOfBombOne;
SDL_Texture* textureOfBombOne;
SDL_Surface* surfaceOfBombTwo;
SDL_Texture* textureOfBombTwo;
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
SDL_Rect scoreRect;
TTF_Font* font = nullptr;
SDL_Rect BombOne;
SDL_Rect BombTwo;
SDL_Color color = { 0,0,0 };
SDL_Surface* scoreSurface = nullptr;
SDL_Texture* scoreTexture = nullptr;
//Useful variables
float LeftPosOfDiver;
float PosOfPoint;
float RightPosOfDiver;
float y = 0;
float DecreasePosOfPoint = 0.25;
float x = 0;
float IncreaseSpeedOfDiver = 0.5;
int counterOfDecrease = 0;
float BubbleLeftY;
float BubbleRightY;
bool playing = true;
float decreaseScore = 0.08;
float gameover = 800;
string answer;
int counterOfArrayForQuestion = 0;
int fillerArrayForQuestion = 0;
int randomquiz = 0;
float PosYOfBombOne;
float PosYOfBombTwo;
bool BoolOne = false;
bool BoolTwo = false;
int randomQuestion = 0;
int ArrayForQuestion[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 ,-1 };

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
void SetscoreRect()
{
	scoreRect.x = 600;
	scoreRect.h = 50;
	scoreRect.w = 60;
	scoreRect.y = 0;
	font = TTF_OpenFont("arial.ttf", 25);

}
void UpdateScore(float gameover)
{
	int firstPartOfFloat = round(gameover);
	string score = to_string(firstPartOfFloat);
	scoreSurface = TTF_RenderText_Solid(font, score.c_str(), color);
	scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
}
void SetBubbleLeft()
{

	bubbleLeft.x = 10;

	bubbleLeft.y = 500;

	bubbleLeft.h = 50;

	bubbleLeft.w = 50;
}

void SetBubbleRight()
{

	bubbleRight.x = 650;

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
bool FindCollisionOfPoint()
{
	if (((round(point.y) - round(diver.y) >= -35) && (round(point.y) - round(diver.y) <= 35) && (round(point.x) - round(diver.x) <= 21) && (round(point.x) - round(diver.x) >= -21)))
	{
		return true;
		if (round(point.y) - round(point.y) == -35 && round(point.x) - round(diver.x) >= -17)
		{
			return true;
		}
	}

}
void Rendering()
{
	//Copy textureOfPoint in point rectangle
	SDL_RenderCopy(renderer, textureOfPoint, 0, &point);
	//Copy textureOfDiver in diver rectangle
	SDL_RenderCopy(renderer, textureOfDiver, 0, &diver);
	//Copy textureOfBubbleLeft in bubbleLeft rectangle
	SDL_RenderCopy(renderer, textureOfBubbleLeft, 0, &bubbleLeft);

	SDL_RenderCopy(renderer, textureOfBombOne, 0, &BombOne);
	SDL_RenderCopy(renderer, textureOfBombTwo, 0, &BombTwo);
	//Copy textureOfBubbleRight in bubbleRight rectangle
	SDL_RenderCopy(renderer, textureOfBubbleRight, 0, &bubbleRight);
	//Copy scoreTexture in scoreRect rectangle
	SDL_RenderCopy(renderer, scoreTexture, 0, &scoreRect);
	//Set Background color to the window
	SDL_SetRenderDrawColor(renderer, 51, 153, 255, 255);
	//present renderer and visualisation of all shapes
	SDL_RenderPresent(renderer);
	//Clear renderer for next position of all shapes
	SDL_RenderClear(renderer);
}
void Random()
{

	randomQuestion = rand() % 10;
	if (ArrayForQuestion[counterOfArrayForQuestion] == randomQuestion || ArrayForQuestion[counterOfArrayForQuestion + 1] == randomQuestion || ArrayForQuestion[counterOfArrayForQuestion + 2] == randomQuestion || ArrayForQuestion[counterOfArrayForQuestion + 3] == randomQuestion || ArrayForQuestion[counterOfArrayForQuestion + 4] == randomQuestion || ArrayForQuestion[counterOfArrayForQuestion + 5] == randomQuestion || ArrayForQuestion[counterOfArrayForQuestion + 6] == randomQuestion || ArrayForQuestion[counterOfArrayForQuestion + 7] == randomQuestion || ArrayForQuestion[counterOfArrayForQuestion + 8] == randomQuestion || ArrayForQuestion[counterOfArrayForQuestion + 9] == randomQuestion)
	{

		Random();
	}
}
void SetBombOne()
{
	BombOne.x = 200;
	BombOne.y = 500;
	BombOne.w = 30;
	BombOne.h = 30;
	surfaceOfBombOne = IMG_Load("bomb.png");
	textureOfBombOne = SDL_CreateTextureFromSurface(renderer, surfaceOfBombOne);
}
void SetBombTwo()
{
	BombTwo.x = 300;
	BombTwo.y = 500;
	BombTwo.w = 30;
	BombTwo.h = 30;
	surfaceOfBombTwo = IMG_Load("bomb.png");
	textureOfBombTwo = SDL_CreateTextureFromSurface(renderer, surfaceOfBombTwo);
}
void Quiz()
{
	srand(time(0));

	cout << endl << endl << "Type only with small letters:" << endl;

	Random();
	cout << arrayOfQuestion[randomQuestion] << endl;

	getline(cin, answer);
	switch (randomQuestion)
	{
	case 0: {
		if (answer == "newtons")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your score" << endl;

		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'newtons\'" << endl;
			gameover -= 110;
			cout << "You decrease you score" << endl;
		}

		break;
	}
	case 1: {
		if (answer == "balanced")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your score" << endl;

		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'balanced\'" << endl;
			gameover -= 110;
			cout << "You decrease you score" << endl;

		}
		break;
	}
	case 2: {
		if (answer == "unbalanced")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your score" << endl;


		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'unbalanced\'" << endl;
			gameover -= 110;
			cout << "You decrease you score" << endl;
		}
		break;
	}
	case 3: {
		if (answer == "force")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your score" << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'force\'" << endl;
			gameover -= 110;
			cout << "You decrease you score" << endl;
		}
		break;
	}
	case 4: {
		if (answer == "net force")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your score" << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'net force\'" << endl;
			gameover -= 110;
			cout << "You decrease you score" << endl;
		}
		break;
	}
	case 5: {
		if (answer == "friction")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your score" << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'friction\'" << endl;
			gameover -= 110;
			cout << "You decrease you score" << endl;
		}
		break;
	}
	case 6: {
		if (answer == "+")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your score" << endl;

		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'+\'" << endl;
			gameover -= 110;
			cout << "You decrease you score" << endl;
		}
		break;
	}
	case 7: {
		if (answer == "-")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your score" << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'-\'" << endl;
			gameover -= 110;
			cout << "You decrease you score" << endl;
		}
		break;
	}
	case 8: {
		if (answer == "true")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your score" << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'true\'" << endl;
			gameover -= 110;
			cout << "You decrease you score" << endl;
		}
		break;
	}
	case 9: {
		if (answer == "false")
		{
			cout << "Correct" << endl;
			gameover += 150;
			cout << "You increase your score" << endl;
		}
		else {
			cout << "Wrong" << endl << "The correct answer is \'false\'" << endl;
			gameover -= 110;
			cout << "You decrease you score" << endl;
		}
		break;
	}

	}
	UpdateScore(gameover);

	ArrayForQuestion[fillerArrayForQuestion] = randomQuestion;
	fillerArrayForQuestion++;

}
void RenderDiver()
{
	//Copy textureOfDiver in diver rectangle
	SDL_RenderCopy(renderer, textureOfDiver, 0, &diver);


}
void FindKeys()
{

	if (SDLevent.type == SDL_KEYDOWN)
	{
		switch (SDLevent.key.keysym.sym)
		{
		case SDLK_LEFT:
		{
			LeftPosOfDiver -= IncreaseSpeedOfDiver;
			diver.x = LeftPosOfDiver;
			RightPosOfDiver = LeftPosOfDiver;




			RenderDiver();
			break;
		}
		case SDLK_RIGHT:
		{
			RightPosOfDiver += IncreaseSpeedOfDiver;
			diver.x = RightPosOfDiver;
			LeftPosOfDiver = RightPosOfDiver;




			RenderDiver();
			break;
		}
		}
	}
}
void RandomPosOfThePoint()
{
	if (FindCollisionOfPoint() || point.y < -30)
	{
		if (FindCollisionOfPoint())
		{
			gameover += 200;
			randomquiz++;
			if (randomquiz % 5 == 0)
			{

				if (randomquiz >= 50)
				{
					if (randomquiz == 50)
					{
						cout << endl << endl << "You Pass the Quiz!! Continue to play" << endl << endl;
						
						SDL_Delay(2000);

					}
					else
					{
						if (randomquiz % 5 == 0)
						{
							if (counterOfDecrease >= 2)
							{

							}
							else {
								DecreasePosOfPoint += 0.07;
								IncreaseSpeedOfDiver = 0.7;
								decreaseScore = 0.1;
							}

							counterOfDecrease++;

						}
					}

				}
				else {
					gameover -= 200;
					Quiz();
					cout << "Press \'Alt + Tab\' and WAIT to continue playing" << endl;
					SDL_Delay(4000);
					cout << "Ready?" << endl;
					SDL_Delay(2000);
					cout << "GOO!";
					SDL_Delay(1000);
					//clear console
					system("cls");
				}
				

			}
		}

		y = rand() % 20 + 500;
		randomagain:
		x = rand() % 520 + 55;

		if ((x >= BombOne.x - 50 && x <= BombOne.x) || (x <= BombOne.x + 50 && x >= BombOne.x) || (x >= BombTwo.x - 50 && x <= BombTwo.x) || (x <= BombTwo.x + 50 && x >= BombTwo.x))
		{
			goto randomagain;
		}
		else {
			point.x = x;
		}
		
		point.y = y;
		PosOfPoint = point.y;

	}
}
bool FindCollisionOfBombOne() 
{
	if (((round(BombOne.y) - round(diver.y) >= -35) && (round(BombOne.y) - round(diver.y) <= 35) && (round(BombOne.x) - round(diver.x) <= 20) && (round(BombOne.x) - round(diver.x) >= -20)))
	{
		return true;
		
		if (round(BombOne.y) - round(diver.y) == -35 && round(BombOne.x) - round(diver.x) >= -17)
		{
			return true;
			
			
		}
	}
	
	
}
bool FindCollisionOfBombTwo()
{
	if (((round(BombTwo.y) - round(diver.y) >= -35) && (round(BombTwo.y) - round(diver.y) <= 35) && (round(BombTwo.x) - round(diver.x) <= 20) && (round(BombTwo.x) - round(diver.x) >= -20)))
	{
	return true;
	
	if (round(BombTwo.y) - round(diver.y) == -35 && round(BombTwo.x) - round(diver.x) >= -17)
	{
		return true;
		
	}
	}
}
void RandomPosOfBombs()
{
	if (FindCollisionOfBombOne() || BombOne.y < -60 || BombTwo.y < -60 || FindCollisionOfBombTwo())
	{
		
		
		if (BombOne.y < -60)
		{
			
			x = rand() % 520 + 55;
			

			BombOne.x = x;
			
			

		}
		else if (BombTwo.y < -60)
		{
			
			x = rand() % 520 + 55;

			BombTwo.x = x;
			
		}
		else if(FindCollisionOfBombOne())
		{
			
			
				gameover -= 100;
				x = rand() % 520 + 55;
				y = rand() % 20 + 500;
				BombOne.y = y;
				BombOne.x = x;
				PosYOfBombOne = BombOne.y;
			
			
				
			
			
			
			
			
		}
		else if (FindCollisionOfBombTwo())
		{
			gameover -= 100;
			x = rand() % 520 + 55;
			y = rand() % 20 + 500;
			BombTwo.y = y;
			BombTwo.x = x;
			PosYOfBombTwo = BombTwo.y;
		}
		
		
		
		
		
		
		


	}
}
void MainLoop()
{

	LeftPosOfDiver = diver.x;
	PosOfPoint = point.y;
	RightPosOfDiver = diver.x;
	PosYOfBombOne = BombOne.y;
	PosYOfBombTwo = BombTwo.y;
	BubbleLeftY = bubbleLeft.y;
	BubbleRightY = bubbleRight.y;

	while (playing)
	{

		SDL_PollEvent(&SDLevent);


		if (SDLevent.type == SDL_QUIT)
		{

			cout << endl << "GoodBye";
			break;


		}

		FindKeys();

		Rendering();

		PosOfPoint -= DecreasePosOfPoint;
		PosYOfBombOne -= 0.3;
		PosYOfBombTwo -= 0.2;
		BubbleLeftY -= 0.15;
		BubbleRightY -= 0.08;
		bubbleLeft.y = BubbleLeftY;
		point.y = PosOfPoint;
		BombOne.y = PosYOfBombOne;
		BombTwo.y = PosYOfBombTwo;
		bubbleRight.y = BubbleRightY;


		if (bubbleLeft.y < -60)
		{
			BubbleLeftY = 500;

		}
		else if (bubbleRight.y < -60)
		{
			BubbleRightY = 500;

		}
		else if (BombOne.y < -60)
		{
			PosYOfBombOne = 500;
		}
		else if (BombTwo.y < -60)
		{
			PosYOfBombTwo = 500;
		}
		else if (diver.x < -10)
		{
			diver.x = 700;
			LeftPosOfDiver = diver.x;
			RightPosOfDiver = diver.x;

		}
		else if (diver.x > 710)
		{
			diver.x = 0;
			LeftPosOfDiver = diver.x;
			RightPosOfDiver = diver.x;
		}

		//Find collision and set random position of the point
		RandomPosOfThePoint();
		RandomPosOfBombs();
		gameover -= decreaseScore;
		UpdateScore(gameover);
		// set Game Over when score is less or equal to 0
		if (GameOver(gameover) == false)
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
	SetBombTwo();
	SetBombOne();
	SetscoreRect();
	SetTextureAndSurfaceOfPoint();
	SetTextureAndSurfaceOfDiver();
	SetTextureAndSurfaceOfBubbleleft();
	SetTextureAndSurfaceOfBubbleright();
}
