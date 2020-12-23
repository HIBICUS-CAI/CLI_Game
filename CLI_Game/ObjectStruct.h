#pragma once

#include "GameAppStructs.h"

struct PLAYER
{
    OBJECT ObjSelf;
    char Sprite[2];
    int Visible;

    void TurnOn()
    {
        Visible = 1;
    }

    void TurnOff()
    {
        Visible = 0;
    }
};
