#include "GameApp.h"
#include "ConsolePrint.h"
#include "LogsOutput.h"
#include "DefinedValues.h"
#include "InputDispose.h"
#include "UIObject.h"
#include "Tools.h"

int g_GameRunFlag;

int Init()
{
    system("mode con cp select=936&&cls");

    SetGameRunFlag(NULL);

    InitUIObj();
    InitInputQueue();
    InitOutputBuffer();
    InitTitle();

    //----------------------------------------------------
    CreateUIO(POSITION_2D(3, 3), 60, 15, UIO_DESIGN::STRAIGHT);
    GetUIObjByID(10001)->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"アホアホマン"));

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
}

void TurnOff()
{
    TurnOffMTInput();
    CloseTitle();
    system("cls");
}

void Update()
{
    UpdateOutputBuffer();

    //----------------------------------------------------
    DrawUIO(GetUIObjByID(10000));
    DrawUIO(GetUIObjByID(10001));
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
