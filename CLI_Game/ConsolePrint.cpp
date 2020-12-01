#include "ConsolePrint.h"
#include "DefinedValues.h"
#include "LogsOutput.h"

char g_OutputBuffer[CONSOLE_HEIGHT][CONSOLE_WIDTH];

void InitOutputBuffer()
{
    char changeConsoleSize[512];
    sprintf_s(changeConsoleSize, sizeof(changeConsoleSize),
        "mode con cols=%d lines=%d", CONSOLE_WIDTH, CONSOLE_HEIGHT + 1);
    system(changeConsoleSize);

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH; j++)
        {
            g_OutputBuffer[i][j] = '_';
        }
    }
}

void ClearOutputBuffer()
{
    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH; j++)
        {
            g_OutputBuffer[i][j] = ' ';
        }
    }
}

void PrintOutputBuffer()
{
    system("cls");

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH; j++)
        {
            printf("%c", g_OutputBuffer[i][j]);
        }
    }
}

void UpdateOutputBuffer()
{
    ClearOutputBuffer();

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
