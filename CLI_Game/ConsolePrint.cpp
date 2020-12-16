#include "ConsolePrint.h"
#include "DefinedValues.h"
#include "LogsOutput.h"
#include "Tools.h"
#include "DeclaredValues.h"
#include "UIObject.h"

void InitOutputBuffer()
{
    char changeConsoleSize[512];
    sprintf_s(changeConsoleSize, sizeof(changeConsoleSize),
        "mode con cols=%d lines=%d", CONSOLE_WIDTH, CONSOLE_HEIGHT + 1);
    system(changeConsoleSize);

#ifdef MUTIPRINT
    InitializeCriticalSection(GetSwapChainCS());

    DWORD dw;
    SetPrintHandle(CreateThread(NULL, 0,
        (LPTHREAD_START_ROUTINE)PrintOutputBuffer,
        NULL, CREATE_SUSPENDED, &dw));
#endif // MUTIPRINT

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH - 1; j++)
        {
            *(GetOutputBufferToUpdate() + i * CONSOLE_WIDTH + j) = '_';
        }
        *(GetOutputBufferToUpdate() + i * CONSOLE_WIDTH + CONSOLE_WIDTH - 1) = '\0';
    }

    //----------------------------------------------------
    CreateUIO("parent", POSITION_2D(3, 20), 60, 15, UIO_DESIGN::STRAIGHT);
    GetUIObjByID(10000)->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"���ۥޥ�"));
    GetUIObjByName("parent")->TurnOn();
    GetUIObjByName("parent")->AddBtn(UI_BUTTON(POSITION_2D(3, 3), (char*)"�_��", BTN_DESIGN::LINE));
    GetUIObjByName("parent")->AddBtn(UI_BUTTON(POSITION_2D(10, 7), (char*)"�]����", BTN_DESIGN::STRAIGHT));
    SetSelectedBtn(GetUIObjByName("parent")->Buttons + 0);
}

void ClearOutputBuffer()
{
    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH - 1; j++)
        {
            *(GetOutputBufferToUpdate() + i * CONSOLE_WIDTH + j) = ' ';
        }
        *(GetOutputBufferToUpdate() + i * CONSOLE_WIDTH + CONSOLE_WIDTH - 1) = '\0';
    }
}

void PrintOutputBuffer()
{
#ifdef MUTIPRINT
    // TODO �޸Ĵ˴������з�ʽ
    //---------------------------------------
    while (1)
    {
        system("cls");

        for (int i = 0; i < CONSOLE_HEIGHT; i++)
        {
            printf("%s\n", GetOutputBufferToPrint() + i * CONSOLE_WIDTH);
        }

        Sleep(DELTATIME);
        SuspendThread(GetPrintHandle());
    }
#else
    system("cls");

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        printf("%s\n", GetOutputBufferToPrint() + i * CONSOLE_WIDTH);
    }
#endif // MUTIPRINT

    return;
}

void CloseMTPrint()
{
    CloseHandle(GetPrintHandle());
}

void UpdateOutputBuffer()
{
    ClearOutputBuffer();

    int deltaTime = GetDeltaTime();
    if (!deltaTime)
    {
        ++deltaTime;
    }
    WriteStrInt1IntoOutputBufferByPos(POSITION_2D(0, 0),
        "FPS", 1000 / deltaTime);
}

void WriteCharIntoOutputBuffer(POSITION_2D position, const char text)
{
    if (position.posX > CONSOLE_WIDTH)
    {
        ErrorLogI2(
            "overflow when writing string into ouput buffer at position",
            position.posX, position.posY);
    }
    *(GetOutputBufferToUpdate() + position.posY * CONSOLE_WIDTH + position.posX) = text;
}

void WriteStrIntoOutputBufferByPos(POSITION_2D startPos, const char* text)
{
    int size = 0;
    while (text[size] != '\0')
    {
        ++size;
    }
    for (int i = 0; i < size; i++)
    {
        if (startPos.posX + i > CONSOLE_WIDTH)
        {
            ErrorLogI2(
                "overflow when writing string into ouput buffer at position",
                startPos.posX, startPos.posY);
        }
        *(GetOutputBufferToUpdate() + startPos.posY * CONSOLE_WIDTH + startPos.posX + i) = text[i];
    }
}

void WriteStrInt1IntoOutputBufferByPos(POSITION_2D startPos, const char* text, int value)
{
    char temp[512];
    sprintf_s(temp, sizeof(temp), "%s : %d", text, value);

    int size = 0;
    while (temp[size] != '\0')
    {
        ++size;
    }
    for (int i = 0; i < size; i++)
    {
        if (startPos.posX + i > CONSOLE_WIDTH)
        {
            ErrorLogI2(
                "overflow when writing string into ouput buffer at position",
                startPos.posX, startPos.posY);
        }
        *(GetOutputBufferToUpdate() + startPos.posY * CONSOLE_WIDTH + startPos.posX + i) = temp[i];
    }
}
