#pragma once

#include <stdlib.h>
#include <time.h>
#include "Structs.h"
#include "DeclaredValues.h"

void SetDeltaTime(int time);

int GetDeltaTime();

void ShowFPSMT();

void InitTitle();

void CloseTitle();

int GetIntValueBit(int value);

QSINGLENODE* CreateQueue();

QSINGLENODE* EnQueue(QSINGLENODE* end, int data);

int DeQueue(QSINGLENODE* top, QSINGLENODE* end);

void SetRandomBySeed(int seedNum);

void SetRandom();

int CreateRandomNumIn(int minNum, int maxNum);

void ChangeColorInConsole(int color);

void ResetColorInConsole();
