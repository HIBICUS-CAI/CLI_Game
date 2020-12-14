#pragma once

#include <stdlib.h>
#include <time.h>
#include "Structs.h"

#define DELTATIME 32

void SetDeltaTime(int time);

int GetDeltaTime();

int GetIntValueBit(int value);

QSINGLENODE* CreateQueue();

QSINGLENODE* EnQueue(QSINGLENODE* end, int data);

int DeQueue(QSINGLENODE* top, QSINGLENODE* end);

void SetRandomBySeed(int seedNum);

void SetRandom();

int CreateRandomNumIn(int minNum, int maxNum);
