#include "GameApp.h"
#include "ConsolePrint.h"
#include "LogsOutput.h"
#include "DefinedValues.h"
#include "Tools.h"

int g_GameRunFlag;
QUEUE_INT* g_InputQueue;

int Init()
{
    SetGameRunFlag(NULL);

    InitQueue();
    InitOutputBuffer();

    return 1;
}

void InitQueue()
{
    g_InputQueue = CreateInputQueue();
}

QUEUE_INT* CreateInputQueue()
{
    QUEUE_INT* inputQueue = (QUEUE_INT*)malloc(sizeof(QUEUE_INT));
    inputQueue->Top = CreateQueue();
    inputQueue->End = inputQueue->Top;

    return inputQueue;
}

void RunGame()
{
#ifdef RUNCONTINUOUS
    static HANDLE hHandleInput = NULL;
    DWORD dw1;
    hHandleInput = CreateThread(NULL, 0,
        (LPTHREAD_START_ROUTINE)InsertInputMT, NULL, 0, &dw1);
#endif // RUNCONTINUOUS
    SetGameRunFlag(1);
    while (GetGameRunFlag())
    {
        int startTime = clock();
#ifdef RUNCONTINUOUS
        DisposeInput();
#endif // RUNCONTINUOUS
#ifndef RUNCONTINUOUS
        InsertInput();
        DisposeInput();
#endif // !RUNCONTINUOUS

        if (GetGameRunFlag())
        {
            Update();
            Draw();
        }
        int endTime = clock();
        g_InputQueue;

        SetDeltaTime(endTime - startTime);

#ifdef LOCKFPS
        if (GetDeltaTime() < DELTATIME)
        {
            Sleep(DELTATIME - GetDeltaTime());
        }
#endif // LOCKFPS

    }
#ifdef RUNCONTINUOUS
    CloseHandle(hHandleInput);
#endif // RUNCONTINUOUS

}

void TurnOff()
{
    system("cls");
}

void InsertInput()
{
    EnQueue(GetInputQueue()->End, _getch());
}

void InsertInputMT()
{
    while (1)
    {
        EnQueue(GetInputQueue()->End, _getch());
    }
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

void Update()
{
    UpdateOutputBuffer();
}

void Draw()
{
    PrintOutputBuffer();
}

void SetGameRunFlag(int value)
{
    if (g_GameRunFlag == NULL)
    {
        int temp = 1;
        g_GameRunFlag = temp;
    }

    if (value == 0)
    {
        g_GameRunFlag = 0;
    }
    else
    {
        g_GameRunFlag = 1;
    }
}

int GetGameRunFlag()
{
    return g_GameRunFlag;
}

QUEUE_INT* GetInputQueue()
{
    return g_InputQueue;
}
