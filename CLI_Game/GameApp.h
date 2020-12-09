#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

//#define RUNCONTINUOUS
//#define LOCKFPS

int Init();

void RunGame();

void TurnOff();

int InsertInput();

void Update();

void Draw();

void SetGameRunFlag(int value);

int GetGameRunFlag();
