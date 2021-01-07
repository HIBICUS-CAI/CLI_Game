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

int GetBattleStageToOffset();

void RandomlySetBattleStageOffset();

#define BATTLEENEMYSIZE 50
BATTLEENEMY* GetBattleEnemyArray();

char* GetPlayerName();

void SetPlayerName(char* name);

int GetInputHP();

void SetInputHP(int hp);

int GetInputATK();

void SetInputATK(int atk);

int GetInputPUSH();

void SetInputPUSH(int push);

int IsInputting();

void SetIsInputting(int value);

UI_TEXT* GetInputtingStr();

void SetInputtingStr(UI_TEXT* text);

int GetInputIndex();

void SetInputIndex(int value);

int GetInputCount();

void SetInputCount(int value);
