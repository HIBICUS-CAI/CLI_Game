#include "DeclaredObjects.h"

PLAYER g_Player;

PLAYER* GetPlayer()
{
    return &g_Player;
}

int g_StageID = 0;

int GetStageID()
{
    return g_StageID;
}

void SetStageID(int id)
{
    g_StageID = id;
}

int g_IsPlayingMaze = 0;

int IsPlayingMaze()
{
    return g_IsPlayingMaze;
}

void SetIsPlayingMaze(int value)
{
    g_IsPlayingMaze = value;
}

MAZEMAP g_MazeMap;

MAZEMAP* GetMazeMap()
{
    return &g_MazeMap;
}

STARTENDPOINT g_StartEndPoint[2];

STARTENDPOINT* GetStartEndPointArray()
{
    return g_StartEndPoint;
}

MAZEENEMY g_MazeEnemy[MAZEENEMYSIZE];

MAZEENEMY* GetMazeEnemyArray()
{
    return g_MazeEnemy;
}

BATTLEENEMY g_BattleEnemy[BATTLEENEMYSIZE];

BATTLEENEMY* GetBattleEnemyArray()
{
    return g_BattleEnemy;
}

int g_PlayingBattle = 0;

int IsPlayingBattle()
{
    return g_PlayingBattle;
}

void SetIsPlayingBattle(int value)
{
    g_PlayingBattle = value;
}

char g_BattleStage[BATTLESTAGECOUNT][BATTLESTAGEHEIGHT * BATTLESTAGEWIDTH];

char* GetBattleStageByOffset(int offset)
{
    return g_BattleStage[offset];
}

char g_InputName[11];
int g_InputHP;
int g_InputATK;
int g_InputPUSH;

char* GetPlayerName()
{
    return g_InputName;
}

void SetPlayerName(char* name)
{
    strcpy_s(g_InputName, sizeof(g_InputName), name);
}

int GetInputHP()
{
    return g_InputHP;
}

void SetInputHP(int hp)
{
    g_InputHP = hp;
}

int GetInputATK()
{
    return g_InputATK;
}

void SetInputATK(int atk)
{
    g_InputATK = atk;
}

int GetInputPUSH()
{
    return g_InputPUSH;
}

void SetInputPUSH(int push)
{
    g_InputPUSH = push;
}

int g_IsInputting = 0;

UI_TEXT* gp_InputtingStr = NULL;

int IsInputting()
{
    return g_IsInputting;
}

void SetIsInputting(int value)
{
    g_IsInputting = value;
}

UI_TEXT* GetInputtingStr()
{
    return gp_InputtingStr;
}

void SetInputtingStr(UI_TEXT* text)
{
    gp_InputtingStr = text;
}

int g_InputIndex = 0;

int GetInputIndex()
{
    return g_InputIndex;
}

void SetInputIndex(int value)
{
    g_InputIndex = value;
}
