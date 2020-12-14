#include "DeclaredValues.h"

int g_DeltaTime = DELTATIME;

int GetDeclaredDeltaTime()
{
    return g_DeltaTime;
}

void SetDeclaredDeltaTime(int value)
{
    g_DeltaTime = value;
}

char g_OutputBuffer[CONSOLE_HEIGHT * CONSOLE_WIDTH];

char* GetOutputBuffer()
{
    return g_OutputBuffer;
}

UIOBJECT g_UIObjs[UIOBJSIZE];
int g_UIObjIndex;

UIOBJECT* GetUIObj()
{
    return g_UIObjs;
}

int* GetUIOIndex()
{
    return &g_UIObjIndex;
}

void SetUIOIndex(int value)
{
    *GetUIOIndex() = value;
}

void AddUIOIndex()
{
    ++g_UIObjIndex;
}
