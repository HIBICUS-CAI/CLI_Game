#include "GameApp.h"
#include "LogsOutput.h"
#include "KeyboardValue.h"

int g_GameRunFlag;

#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40

int Init()
{
    g_GameRunFlag = NULL;
    char changeConsoleSize[512];
    sprintf_s(changeConsoleSize, sizeof(changeConsoleSize),
        "mode con cols=%d lines=%d", CONSOLE_WIDTH, CONSOLE_HEIGHT + 1);
    system(changeConsoleSize);

    return 1;
}

void RunGame()
{
    SetGameRunFlag(1);
    while (g_GameRunFlag)
    {
        if (InsertInput())
        {
            Update();
            Draw();
        }
    }
    system("cls");
}

void TurnOff()
{

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

}

void Draw()
{
    system("cls");

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH; j++)
        {
            printf("a");
        }
        printf("\n");
    }
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
