#pragma once

#include "ObjectStruct.h"

PLAYER* GetPlayer();

int GetStageID();

void SetStageID(int id);

int IsPlayingMaze();

void SetIsPlayingMaze(int value);

MAZEMAP* GetMazeMap();

STARTENDPOINT* GetStartEndPointArray();

#define MAZEENEMYSIZE 50
MAZEENEMY* GetMazeEnemyArray();

int IsPlayingBattle();

void SetIsPlayingBattle(int value);
