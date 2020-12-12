#pragma once

#include <conio.h>
#include <windows.h>
#include "Structs.h"

void InitInputQueue();

QUEUE_INT* CreateInputQueue();

void Input();

void InsertInput();

void InsertInputMT();

void TurnOffMTInput();

void DisposeInput();

void DispatchInput(int keyCode);

QUEUE_INT* GetInputQueue();
