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

    DWORD dw;
    SetPrintHandle(CreateThread(NULL, 0,
        (LPTHREAD_START_ROUTINE)PrintOutputBuffer,
        NULL, CREATE_SUSPENDED, &dw));

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH - 1; j++)
        {
            *(GetOutputBufferToUpdate() + i * CONSOLE_WIDTH + j) = '_';
        }
        *(GetOutputBufferToUpdate() + i * CONSOLE_WIDTH + CONSOLE_WIDTH - 1) = '\0';
    }

    //----------------------------------------------------
    CreateUIO(POSITION_2D(3, 20), 60, 15, UIO_DESIGN::STRAIGHT);
    GetUIObjByID(10000)->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"アホマン"));
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
    // TODO 修改此处的运行方式
    //---------------------------------------
    while (1)
    {
        system("cls");

        for (int i = 0; i < CONSOLE_HEIGHT; i++)
        {
            printf("%s\n", GetOutputBufferToPrint() + i * CONSOLE_WIDTH);
        }

        Sleep(16);
        SuspendThread(GetPrintHandle());
    }

    /*system("cls");

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        printf("%s\n", GetOutputBufferToPrint() + i * CONSOLE_WIDTH);
    }*/

    return;
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
