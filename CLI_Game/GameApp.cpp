#include "GameApp.h"
#include "ConsolePrint.h"
#include "LogsOutput.h"
#include "DefinedValues.h"
#include "InputDispose.h"
#include "Tools.h"

int g_GameRunFlag;

int Init()
{
    SetGameRunFlag(NULL);

    InitInputQueue();
    InitOutputBuffer();

    return 1;
}

void RunGame()
{
    SetGameRunFlag(1);
    
    while (GetGameRunFlag())
    {
        int startTime = clock();

        Input();
        if (GetGameRunFlag())
        {
            Update();
            Draw();
        }
        int endTime = clock();

        SetDeltaTime(endTime - startTime);

#ifdef LOCKFPS
        if (GetDeltaTime() < DELTATIME)
        {
            Sleep(DELTATIME - GetDeltaTime());
        }
#endif // LOCKFPS
    }
    TurnOffMTInput();
}

void TurnOff()
{
    system("cls");
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
