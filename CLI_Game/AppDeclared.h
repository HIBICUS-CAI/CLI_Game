#pragma once
#include "GameAppStructs.h"

#define STARTGAME 0x0003
#define GAMEHELP 0x0004
#define CLOSEHELP 0x0005

#define SCENENODESIZE 20

SCENENODE* GetSceneNodeArray();

void SetSceneNodeArray(int index, SCENENODE temp);

void SetCurrScene(SCENENODE* sceneNode);

SCENENODE* GetCurrScene();
