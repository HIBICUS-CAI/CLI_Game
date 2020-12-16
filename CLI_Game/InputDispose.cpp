#include "InputDispose.h"
#include "DefinedValues.h"
#include "Tools.h"
#include "LogsOutput.h"
#include "GameApp.h"

QUEUE_INT* g_InputQueue;
static HANDLE g_HandleInput = NULL;

void InitInputQueue()
{
    g_InputQueue = CreateInputQueue();

#ifdef RUNCONTINUOUS
    DWORD dw1;
    g_HandleInput = CreateThread(NULL, 0,
        (LPTHREAD_START_ROUTINE)InsertInputMT, NULL, 0, &dw1);
#endif // RUNCONTINUOUS
}

QUEUE_INT* CreateInputQueue()
{
    QUEUE_INT* inputQueue = (QUEUE_INT*)malloc(sizeof(QUEUE_INT));
    inputQueue->Top = CreateQueue();
    inputQueue->End = inputQueue->Top;

    return inputQueue;
}

void Input()
{
#ifdef RUNCONTINUOUS
    DisposeInput();
#endif // RUNCONTINUOUS
#ifndef RUNCONTINUOUS
    InsertInput();
    DisposeInput();
#endif // !RUNCONTINUOUS
}

void InsertInput()
{
    EnQueue(GetInputQueue()->End, _getch());
}

void InsertInputMT()
{
    int temp;
    while (1)
    {
        EnQueue(GetInputQueue()->End, temp = _getch());
        if (temp == ESC_VALUE)
        {
            break;
        }
    }
}

void TurnOffMTInput()
{
#ifdef RUNCONTINUOUS
    CloseHandle(g_HandleInput);
#endif // RUNCONTINUOUS
}

void DisposeInput()
{
    while (GetInputQueue()->Top->Next != NULL)
    {
        DispatchInput(DeQueue(GetInputQueue()->Top, GetInputQueue()->End));
    }
}

void DispatchInput(int keyCode)
{
    DebugLogI1("input", keyCode);
    if (keyCode == -1)
    {
        return;
    }

    if (keyCode == ESC_VALUE)
    {
        SetGameRunFlag(0);
    }
}

QUEUE_INT* GetInputQueue()
{
    return g_InputQueue;
}

CRITICAL_SECTION g_CSSwapChain;

CRITICAL_SECTION* GetSwapChainCS()
{
    return &g_CSSwapChain;
}
