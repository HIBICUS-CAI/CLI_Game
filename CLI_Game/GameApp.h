#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Structs.h"

int Init();

void RunGame();

void TurnOff();

void Update();

void Draw();

void SetGameRunFlag(int value);

int GetGameRunFlag();
