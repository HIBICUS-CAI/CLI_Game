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
