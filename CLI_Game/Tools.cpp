#include "Tools.h"

int g_DeltaTime = 16;

void SetDeltaTime(int time)
{
    g_DeltaTime = time;
}

int GetDeltaTime()
{
    return g_DeltaTime;
}

int GetIntValueBit(int value)
{
    int flag = 0;
    int bits = 0;
    int baseNum = 1;
    while (flag == 0)
    {
        flag = value / baseNum;
        if (flag != 0)
        {
            ++bits;
            baseNum *= 10;
        }
    }

    return bits;
}
