#include "GameApp.h"
#include "ConsolePrint.h"
#include "LogsOutput.h"
#include "DefinedValues.h"

int g_GameRunFlag;

int Init()
{
    SetGameRunFlag(NULL);

    InitOutputBuffer();

    return 1;
}

void RunGame()
{
    SetGameRunFlag(1);
    while (GetGameRunFlag())
    {
        InsertInput();
        if (GetGameRunFlag())
        {
            Update();
            Draw();
        }
    }
}

void TurnOff()
{
    system("cls");
}

int InsertInput()
{
    int inputKey = _getch();
    if (inputKey == ESC_VALUE)
    {
        SetGameRunFlag(0);
    }

    return inputKey;
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
