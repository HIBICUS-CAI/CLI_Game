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

    ResetColorInConsole();

    InitUIObj();
    InitInputQueue();
    InitOutputBuffer();
    InitTitle();

    //----------------------------------------------------
    /*GetUIObjByID(10000)->AddChild(
        CreateUIO("child", POSITION_2D(3, 3), 60, 15, UIO_DESIGN::STRAIGHT, 0));
    GetUIObjByID(10001)->AddParent(GetUIObjByID(10001));
    GetUIObjByID(10001)->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"アホアホマン"));
    GetUIObjByName("child")->AddBtn(UI_BUTTON(0, POSITION_2D(3, 3),
        (char*)"ボタン1", BTN_DESIGN::LINE));
    GetUIObjByName("child")->AddBtn(UI_BUTTON(0, POSITION_2D(9, 4),
        (char*)"ボタン2", BTN_DESIGN::LINE));
    GetUIObjByName("child")->AddBtn(UI_BUTTON(TEST_CLOSETHIS, POSITION_2D(10, 7),
        (char*)"閉じる", BTN_DESIGN::STRAIGHT));*/

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
#ifdef MUTIPRINT
            //-----------------------------------------------
            // TODO 修改此处多线程的启动方式，最好可以重复使用已有的线程
            /*DWORD dw;
            SetPrintHandle(CreateThread(NULL, 0,
                (LPTHREAD_START_ROUTINE)PrintOutputBuffer,
                NULL, CREATE_SUSPENDED, &dw));*/

            ResumeThread(GetPrintHandle());
            Update();

            //WaitForSingleObject(GetPrintHandle(), 0);
            //SuspendThread(GetPrintHandle());

            SwapPrintChain();
#else
            Update();
            Draw();
            SwapPrintChain();
#endif // MUTIPRINT
        }
        int endTime = clock();

        SetDeltaTime(endTime - startTime);

#ifdef LOCKFPS
        if (GetDeltaTime() < DELTATIME)
        {
            Sleep(DELTATIME - GetDeltaTime());
        }
#endif // LOCKFPS
        //        endTime = clock();
        //        SetDeltaTime(endTime - startTime);
    }
}

void TurnOff()
{
    TurnOffMTInput();
    CloseTitle();
#ifdef MUTIPRINT
    CloseMTPrint();
    DeleteCriticalSection(GetSwapChainCS());
#endif // MUTIPRINT
    system("cls");
}

void Update()
{
#ifdef MUTIPRINT
    EnterCriticalSection(GetSwapChainCS());
#endif // MUTIPRINT

    UpdateOutputBuffer();

    //----------------------------------------------------
    /*DrawUIO(GetUIObjByName("parent"));*/

#ifdef MUTIPRINT
    LeaveCriticalSection(GetSwapChainCS());
#endif // MUTIPRINT

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
