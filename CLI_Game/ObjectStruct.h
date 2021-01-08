//------------------------------------------------------------------------
// ファイル名: ObjectStruct.h
// 機能: ゲーム上階の構造体の声明
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// プレイヤー構造体
/// </summary>
struct PLAYER
{
    OBJECT ObjSelf;
    OBJECT ObjInBattle;
    char Sprite[2];
    int Visible;

    int HP;
    int ATK;
    int PUSH;

    void TurnOn()
    {
        Visible = 1;
    }

    void TurnOff()
    {
        Visible = 0;
    }
};

/// <summary>
/// 迷宮中の敵構造体
/// </summary>
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

#define BATTLEENEMYMAXHP 20
/// <summary>
/// 戦闘中敵構造体
/// </summary>
struct BATTLEENEMY
{
    int ID;
    OBJECT ObjSelf;
    char Sprite[2];
    int Visible;

    int HP;
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

/// <summary>
/// 壁構造体
/// </summary>
struct WALL
{
    OBJECT ObjSelf;
    char Sprite[2];
};

#define MAZEMAPMAXLENGTH 250

/// <summary>
/// 迷宮地図構造体
/// </summary>
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

/// <summary>
/// 始点と終点構造体
/// </summary>
struct STARTENDPOINT
{
    OBJECT ObjSelf;
    START_END_POINT PointFlag;
};
