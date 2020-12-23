#pragma once
#include "GameAppStructs.h"

#define STARTGAME 0x0003
#define GAMEHELP 0x0004
#define CLOSEHELP 0x0005
#define CLOSESELECT 0x0006
#define GETINMAZE1 0x0007
#define GETINMAZE2 0x0008
#define GETINMAZE3 0x0009
#define GIVEUPMAZE 0x000a
#define CLOSECLEARUP 0x000b

#define SCENENODESIZE 20

SCENENODE* GetSceneNodeArray();

void SetSceneNodeArray(int index, SCENENODE temp);

void SetCurrScene(SCENENODE* sceneNode);

SCENENODE* GetCurrScene();
