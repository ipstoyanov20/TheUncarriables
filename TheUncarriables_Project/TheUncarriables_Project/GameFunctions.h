#pragma once
#include<SDL.h> // include SDL
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<time.h>
#include<string>
#include<SDL_image.h> // Here we can use images in SDL
using namespace std;


void CreateWindow();
void SetThePoint();
void SetBubbleLeft();
void SetBubbleRight();
void SetTextureAndSurfaceOfPoint();
void SetTextureAndSurfaceOfDiver();
void SetTextureAndSurfaceOfBubbleleft();
void SetTextureAndSurfaceOfBubbleright();
void SetDiver();
void SetscoreRect();
void UpdateScore(float gameover);
bool GameOver(float gameover);
bool FindCollusion();
void Quiz();
void MainLoop();
void Setting();