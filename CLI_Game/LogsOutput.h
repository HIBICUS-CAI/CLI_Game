#pragma once

#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

void DebugLog(const char* text);

void DebugLogI1(const char* text, const int value);

void DebugLogI2(const char* text, const int value1, const int value2);

void DebugLogToFile(const char* text);

void ErrorLog(const char* text);
