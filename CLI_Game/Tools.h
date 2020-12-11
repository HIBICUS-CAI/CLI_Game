#pragma once

#include <stdlib.h>
#include "Structs.h"

#define DELTATIME 16

void SetDeltaTime(int time);

int GetDeltaTime();

int GetIntValueBit(int value);

QSINGLENODE* CreateQueue();

QSINGLENODE* EnQueue(QSINGLENODE* end, int data);

int DeQueue(QSINGLENODE* top, QSINGLENODE* end);
