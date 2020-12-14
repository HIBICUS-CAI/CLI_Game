#pragma once

#include "DefinedValues.h"
#include "Structs.h"

#define DELTATIME 32

int GetDeclaredDeltaTime();

void SetDeclaredDeltaTime(int value);

char* GetOutputBuffer();

#define UIOBJSIZE 10000

UIOBJECT* GetUIObj();

int* GetUIOIndex();

void SetUIOIndex(int value);

void AddUIOIndex();
