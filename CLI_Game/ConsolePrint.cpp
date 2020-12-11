#include "ConsolePrint.h"
#include "DefinedValues.h"
#include "LogsOutput.h"
#include "Tools.h"

char g_OutputBuffer[CONSOLE_HEIGHT][CONSOLE_WIDTH];

void InitOutputBuffer()
{
    char changeConsoleSize[512];
    sprintf_s(changeConsoleSize, sizeof(changeConsoleSize),
        "mode con cols=%d lines=%d", CONSOLE_WIDTH, CONSOLE_HEIGHT + 1);
    system(changeConsoleSize);

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH - 1; j++)
        {
            g_OutputBuffer[i][j] = '_';
        }
        g_OutputBuffer[i][CONSOLE_WIDTH - 1] = '\0';
    }
}

void ClearOutputBuffer()
{
    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH - 1; j++)
        {
            g_OutputBuffer[i][j] = ' ';
        }
        g_OutputBuffer[i][CONSOLE_WIDTH - 1] = '\0';
    }
}

void PrintOutputBuffer()
{
    system("cls");

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        /*for (int j = 0; j < CONSOLE_WIDTH; j++)
        {
            printf("%c", g_OutputBuffer[i][j]);
        }*/
        printf("%s\n", g_OutputBuffer[i]);
    }
}

void UpdateOutputBuffer()
{
    ClearOutputBuffer();

    WriteStrInt1IntoOutputBufferByPos(POSITION_2D(1, 1),
        "FPS", 1000 / GetDeltaTime());

    WriteStrIntoOutputBufferByPos(POSITION_2D(5, 39), "двд█дс");
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
        g_OutputBuffer[startPos.posY][startPos.posX + i] = text[i];
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
        g_OutputBuffer[startPos.posY][startPos.posX + i] = temp[i];
    }
}
