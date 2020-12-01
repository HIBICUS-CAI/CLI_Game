#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"

void InitOutputBuffer();

void ClearOutputBuffer();

void PrintOutputBuffer();

void UpdateOutputBuffer();

void WriteStrIntoOutputBufferByPos(POSITION_2D startPos, const char* text);
