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

#define BATTLESTAGEWIDTH 116
#define BATTLESTAGEHEIGHT 33
#define BATTLESTAGECOUNT 3
char* GetBattleStageByOffset(int offset);

#define BATTLEENEMYSIZE 50
BATTLEENEMY* GetBattleEnemyArray();
