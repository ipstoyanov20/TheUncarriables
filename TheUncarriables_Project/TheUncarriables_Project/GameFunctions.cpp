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

namespace sdlProperties
{
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
}





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

	SDL_CreateWindowAndRenderer(700, 500, 0, &sdlProperties::window, &sdlProperties::renderer);
	SDL_SetWindowTitle(sdlProperties::window, "TheUncarriables");
	SDL_SetWindowPosition(sdlProperties::window, 700, SDL_WINDOWPOS_CENTERED);
}
void SetThePoint()
{
	sdlProperties::point.x = 100;

	sdlProperties::point.y = 500;

	sdlProperties::point.h = 30;

	sdlProperties::point.w = 30;
}
void SetscoreRect()
{
	sdlProperties::scoreRect.x = 600;
	sdlProperties::scoreRect.h = 50;
	sdlProperties::scoreRect.w = 60;
	sdlProperties::scoreRect.y = 0;
	sdlProperties::font = TTF_OpenFont("arial.ttf", 25);

}
void UpdateScore(float gameover)
{
	int firstPartOfFloat = round(gameover);
	string score = to_string(firstPartOfFloat);
	sdlProperties::scoreSurface = TTF_RenderText_Solid(sdlProperties::font, score.c_str(), sdlProperties::color);
	sdlProperties::scoreTexture = SDL_CreateTextureFromSurface(sdlProperties::renderer, sdlProperties::scoreSurface);
}
void SetBubbleLeft()
{

	sdlProperties::bubbleLeft.x = 10;

	sdlProperties::bubbleLeft.y = 500;

	sdlProperties::bubbleLeft.h = 50;

	sdlProperties::bubbleLeft.w = 50;
}

void SetBubbleRight()
{

	sdlProperties::bubbleRight.x = 650;

	sdlProperties::bubbleRight.y = 500;

	sdlProperties::bubbleRight.h = 50;

	sdlProperties::bubbleRight.w = 50;
}
void SetTextureAndSurfaceOfPoint()
{
	sdlProperties::surfaceOfPoint = IMG_Load("shield.png");
	sdlProperties::textureOfPoint = SDL_CreateTextureFromSurface(sdlProperties::renderer, sdlProperties::surfaceOfPoint);
}
void SetTextureAndSurfaceOfDiver()
{
	sdlProperties::surfaceOfDiver = IMG_Load("diver.png");
	sdlProperties::textureOfDiver = SDL_CreateTextureFromSurface(sdlProperties::renderer, sdlProperties::surfaceOfDiver);
}
void SetTextureAndSurfaceOfBubbleleft()
{
	sdlProperties::surfaceOfBubbleLeft = IMG_Load("bubble.png");
	sdlProperties::textureOfBubbleLeft = SDL_CreateTextureFromSurface(sdlProperties::renderer, sdlProperties::surfaceOfBubbleLeft);
}
void SetTextureAndSurfaceOfBubbleright()
{
	sdlProperties::surfaceOfBubbleRight = IMG_Load("bubble2.png");
	sdlProperties::textureOfBubbleRight = SDL_CreateTextureFromSurface(sdlProperties::renderer, sdlProperties::surfaceOfBubbleRight);
}
void SetDiver()
{
	sdlProperties::diver.h = 50;
	sdlProperties::diver.w = 30;
	sdlProperties::diver.y = 50;

	sdlProperties::diver.x = 200;
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
	if (((round(sdlProperties::point.y) - round(sdlProperties::diver.y) >= -35) && (round(sdlProperties::point.y) - round(sdlProperties::diver.y) <= 35) && (round(sdlProperties::point.x) - round(sdlProperties::diver.x) <= 21) && (round(sdlProperties::point.x) - round(sdlProperties::diver.x) >= -21)))
	{
		return true;
		if (round(sdlProperties::point.y) - round(sdlProperties::point.y) == -35 && round(sdlProperties::point.x) - round(sdlProperties::diver.x) >= -17)
		{
			return true;
		}
	}

}
void Rendering()
{
	//Copy textureOfPoint in point rectangle
	SDL_RenderCopy(sdlProperties::renderer, sdlProperties::textureOfPoint, 0, &sdlProperties::point);
	//Copy textureOfDiver in diver rectangle
	SDL_RenderCopy(sdlProperties::renderer, sdlProperties::textureOfDiver, 0, &sdlProperties::diver);
	//Copy textureOfBubbleLeft in bubbleLeft rectangle
	SDL_RenderCopy(sdlProperties::renderer, sdlProperties::textureOfBubbleLeft, 0, &sdlProperties::bubbleLeft);

	SDL_RenderCopy(sdlProperties::renderer, sdlProperties::textureOfBombOne, 0, &sdlProperties::BombOne);
	SDL_RenderCopy(sdlProperties::renderer, sdlProperties::textureOfBombTwo, 0, &sdlProperties::BombTwo);
	//Copy textureOfBubbleRight in bubbleRight rectangle
	SDL_RenderCopy(sdlProperties::renderer, sdlProperties::textureOfBubbleRight, 0, &sdlProperties::bubbleRight);
	//Copy scoreTexture in scoreRect rectangle
	SDL_RenderCopy(sdlProperties::renderer, sdlProperties::scoreTexture, 0, &sdlProperties::scoreRect);
	//Set Background color to the window
	SDL_SetRenderDrawColor(sdlProperties::renderer, 51, 153, 255, 255);
	//present renderer and visualisation of all shapes
	SDL_RenderPresent(sdlProperties::renderer);
	//Clear renderer for next position of all shapes
	SDL_RenderClear(sdlProperties::renderer);
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
	sdlProperties::BombOne.x = 200;
	sdlProperties::BombOne.y = 500;
	sdlProperties::BombOne.w = 30;
	sdlProperties::BombOne.h = 30;
	sdlProperties::surfaceOfBombOne = IMG_Load("bomb.png");
	sdlProperties::textureOfBombOne = SDL_CreateTextureFromSurface(sdlProperties::renderer, sdlProperties::surfaceOfBombOne);
}
void SetBombTwo()
{
	sdlProperties::BombTwo.x = 300;
	sdlProperties::BombTwo.y = 500;
	sdlProperties::BombTwo.w = 30;
	sdlProperties::BombTwo.h = 30;
	sdlProperties::surfaceOfBombTwo = IMG_Load("bomb.png");
	sdlProperties::textureOfBombTwo = SDL_CreateTextureFromSurface(sdlProperties::renderer, sdlProperties::surfaceOfBombTwo);
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
	SDL_RenderCopy(sdlProperties::renderer, sdlProperties::textureOfDiver, 0, &sdlProperties::diver);


}
void FindKeys()
{

	if (sdlProperties::SDLevent.type == SDL_KEYDOWN)
	{
		switch (sdlProperties::SDLevent.key.keysym.sym)
		{
		case SDLK_LEFT:
		{
			LeftPosOfDiver -= IncreaseSpeedOfDiver;
			sdlProperties::diver.x = LeftPosOfDiver;
			RightPosOfDiver = LeftPosOfDiver;




			RenderDiver();
			break;
		}
		case SDLK_RIGHT:
		{
			RightPosOfDiver += IncreaseSpeedOfDiver;
			sdlProperties::diver.x = RightPosOfDiver;
			LeftPosOfDiver = RightPosOfDiver;




			RenderDiver();
			break;
		}
		}
	}
}
void RandomPosOfThePoint()
{
	if (FindCollisionOfPoint() || sdlProperties::point.y < -30)
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

		if ((x >= sdlProperties::BombOne.x - 50 && x <= sdlProperties::BombOne.x) || (x <= sdlProperties::BombOne.x + 50 && x >= sdlProperties::BombOne.x) || (x >= sdlProperties::BombTwo.x - 50 && x <= sdlProperties::BombTwo.x) || (x <= sdlProperties::BombTwo.x + 50 && x >= sdlProperties::BombTwo.x))
		{
			goto randomagain;
		}
		else {
			sdlProperties::point.x = x;
		}
		
		sdlProperties::point.y = y;
		PosOfPoint = sdlProperties::point.y;

	}
}
bool FindCollisionOfBombOne() 
{
	if (((round(sdlProperties::BombOne.y) - round(sdlProperties::diver.y) >= -35) && (round(sdlProperties::BombOne.y) - round(sdlProperties::diver.y) <= 35) && (round(sdlProperties::BombOne.x) - round(sdlProperties::diver.x) <= 20) && (round(sdlProperties::BombOne.x) - round(sdlProperties::diver.x) >= -20)))
	{
		return true;
		
		if (round(sdlProperties::BombOne.y) - round(sdlProperties::diver.y) == -35 && round(sdlProperties::BombOne.x) - round(sdlProperties::diver.x) >= -17)
		{
			return true;
			
			
		}
	}
	
	
}
bool FindCollisionOfBombTwo()
{
	if (((round(sdlProperties::BombTwo.y) - round(sdlProperties::diver.y) >= -35) && (round(sdlProperties::BombTwo.y) - round(sdlProperties::diver.y) <= 35) && (round(sdlProperties::BombTwo.x) - round(sdlProperties::diver.x) <= 20) && (round(sdlProperties::BombTwo.x) - round(sdlProperties::diver.x) >= -20)))
	{
	return true;
	
	if (round(sdlProperties::BombTwo.y) - round(sdlProperties::diver.y) == -35 && round(sdlProperties::BombTwo.x) - round(sdlProperties::diver.x) >= -17)
	{
		return true;
		
	}
	}
}
void RandomPosOfBombs()
{
	if (FindCollisionOfBombOne() || sdlProperties::BombOne.y < -60 || sdlProperties::BombTwo.y < -60 || FindCollisionOfBombTwo())
	{
		
		
		if (sdlProperties::BombOne.y < -60)
		{
			
			x = rand() % 520 + 55;
			

			sdlProperties::BombOne.x = x;
			
			

		}
		else if (sdlProperties::BombTwo.y < -60)
		{
			
			x = rand() % 520 + 55;

			sdlProperties::BombTwo.x = x;
			
		}
		else if(FindCollisionOfBombOne())
		{
			
			
				gameover -= 100;
				x = rand() % 520 + 55;
				y = rand() % 20 + 500;
				sdlProperties::BombOne.y = y;
				sdlProperties::BombOne.x = x;
				PosYOfBombOne = sdlProperties::BombOne.y;
			
			
				
			
			
			
			
			
		}
		else if (FindCollisionOfBombTwo())
		{
			gameover -= 100;
			x = rand() % 520 + 55;
			y = rand() % 20 + 500;
			sdlProperties::BombTwo.y = y;
			sdlProperties::BombTwo.x = x;
			PosYOfBombTwo = sdlProperties::BombTwo.y;
		}
		
		
		
		
		
		
		


	}
}
void MainLoop()
{

	LeftPosOfDiver = sdlProperties::diver.x;
	PosOfPoint = sdlProperties::point.y;
	RightPosOfDiver = sdlProperties::diver.x;
	PosYOfBombOne = sdlProperties::BombOne.y;
	PosYOfBombTwo = sdlProperties::BombTwo.y;
	BubbleLeftY = sdlProperties::bubbleLeft.y;
	BubbleRightY = sdlProperties::bubbleRight.y;

	while (playing)
	{

		SDL_PollEvent(&sdlProperties::SDLevent);


		if (sdlProperties::SDLevent.type == SDL_QUIT)
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
		sdlProperties::bubbleLeft.y = BubbleLeftY;
		sdlProperties::point.y = PosOfPoint;
		sdlProperties::BombOne.y = PosYOfBombOne;
		sdlProperties::BombTwo.y = PosYOfBombTwo;
		sdlProperties::bubbleRight.y = BubbleRightY;


		if (sdlProperties::bubbleLeft.y < -60)
		{
			BubbleLeftY = 500;

		}
		else if (sdlProperties::bubbleRight.y < -60)
		{
			BubbleRightY = 500;

		}
		else if (sdlProperties::BombOne.y < -60)
		{
			PosYOfBombOne = 500;
		}
		else if (sdlProperties::BombTwo.y < -60)
		{
			PosYOfBombTwo = 500;
		}
		else if (sdlProperties::diver.x < -10)
		{
			sdlProperties::diver.x = 700;
			LeftPosOfDiver = sdlProperties::diver.x;
			RightPosOfDiver = sdlProperties::diver.x;

		}
		else if (sdlProperties::diver.x > 710)
		{
			sdlProperties::diver.x = 0;
			LeftPosOfDiver = sdlProperties::diver.x;
			RightPosOfDiver = sdlProperties::diver.x;
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
