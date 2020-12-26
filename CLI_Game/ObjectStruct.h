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

struct MAZEENEMY
{
    int ID;
    OBJECT ObjSelf;
    char Sprite[2];
    int Visible;

    int ScanFlag;
    int MovingFlag;

    void TurnOn()
    {
        Visible = 1;
    }

    void TurnOff()
    {
        Visible = 0;
    }
};

struct WALL
{
    OBJECT ObjSelf;
    char Sprite[2];
};

#define MAZEMAPMAXLENGTH 250

struct MAZEMAP
{
    char Map[MAZEMAPMAXLENGTH * MAZEMAPMAXLENGTH];

    char* GetMap()
    {
        return Map;
    }
};

enum class START_END_POINT
{
    START_POINT,
    END_POINT
};

struct STARTENDPOINT
{
    OBJECT ObjSelf;
    START_END_POINT PointFlag;
};
