//------------------------------------------------------------------------
// �ե�������: ObjectStruct.h
// �C��: ���`�����A�Θ����������
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// �ץ쥤��`������
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
/// �Ԍm�ФΔ�������
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
/// ���L�Д�������
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
/// �ژ�����
/// </summary>
struct WALL
{
    OBJECT ObjSelf;
    char Sprite[2];
};

#define MAZEMAPMAXLENGTH 250

/// <summary>
/// �Ԍm�؇혋����
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
/// ʼ��ȽK�㘋����
/// </summary>
struct STARTENDPOINT
{
    OBJECT ObjSelf;
    START_END_POINT PointFlag;
};
