#pragma once
#include<SDL.h>
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<time.h>
#include<string>
#include<SDL_image.h>
using namespace std;


void CreateWindow();
void SetThePoint();
void SetBubbleLeft();
void SetBubbleRight();
void Random();
void SetTextureAndSurfaceOfPoint();
void SetTextureAndSurfaceOfDiver();
void SetTextureAndSurfaceOfBubbleleft();
void SetTextureAndSurfaceOfBubbleright();
void SetDiver();
void SetscoreRect();
void UpdateScore(float gameover);
bool GameOver(float gameover);
bool FindCollisionOfPoint();
void SetBombOne();
void FindKeys();
void RandomPosOfThePoint();
bool FindCollisionOfBombTwo();
void RandomPosOfBombs();
void Rendering();
void RenderDiver();
bool FindCollisionOfBombOne();
void SetBombTwo();
void Quiz();
void MainLoop();
void Setting();