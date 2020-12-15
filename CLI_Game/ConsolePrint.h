#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"

void InitOutputBuffer();

void ClearOutputBuffer();

void PrintOutputBuffer();

void UpdateOutputBuffer();

void WriteCharIntoOutputBuffer(POSITION_2D position, const char text);

void WriteStrIntoOutputBufferByPos(POSITION_2D startPos, const char* text);

void WriteStrInt1IntoOutputBufferByPos(POSITION_2D startPos, const char* text, int value);

void CloseMTPrint();
