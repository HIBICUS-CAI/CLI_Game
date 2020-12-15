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

char g_OutputBuffer[2][CONSOLE_HEIGHT * CONSOLE_WIDTH];
int g_SwapFlag = 0;
static HANDLE g_HandlePrint = NULL;

HANDLE GetPrintHandle()
{
    return g_HandlePrint;
}

void SetPrintHandle(HANDLE handle)
{
    g_HandlePrint = handle;
}

void SwapPrintChain()
{
    if (g_SwapFlag == 1)
    {
        g_SwapFlag = 0;
    }
    else if (g_SwapFlag == 0)
    {
        g_SwapFlag = 1;
    }
}

char* GetOutputBufferToPrint()
{
    return g_OutputBuffer[g_SwapFlag];
}

char* GetOutputBufferToUpdate()
{
    if (g_SwapFlag)
    {
        return g_OutputBuffer[g_SwapFlag - 1];
    }
    else
    {
        return g_OutputBuffer[g_SwapFlag + 1];
    }
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
