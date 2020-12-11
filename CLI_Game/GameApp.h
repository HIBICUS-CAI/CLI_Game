#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Structs.h"

#define RUNCONTINUOUS

#ifdef RUNCONTINUOUS
//#define LOCKFPS
#endif // RUNCONTINUOUS

int Init();

void InitQueue();

QUEUE_INT* CreateInputQueue();

void RunGame();

void TurnOff();

void InsertInput();

void InsertInputMT();

void DisposeInput();

void DispatchInput(int keyCode);

void Update();

void Draw();

void SetGameRunFlag(int value);

int GetGameRunFlag();

QUEUE_INT* GetInputQueue();
