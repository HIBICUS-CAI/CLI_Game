#pragma once

#include "GameAppStructs.h"

struct PLAYER
{
    OBJECT ObjSelf;
    OBJECT ObjInBattle;
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
    int IsDead;

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

struct BATTLEENEMY
{
    int ID;
    OBJECT ObjSelf;
    char Sprite[2];
    int Visible;

    int LeftMoveFlag;

    void TurnOn()
    {
        Visible = 1;
    }

    void TurnOff()
    {
        Visible = 0;
    }

    void SwitchLeftMoveFlag()
    {
        if (LeftMoveFlag)
        {
            LeftMoveFlag = 0;
        }
        else
        {
            LeftMoveFlag = 1;
        }
    }

    void Move()
    {
        if (LeftMoveFlag)
        {
            --ObjSelf.Position.posX;
        }
        else
        {
            ++ObjSelf.Position.posX;
        }
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
