#pragma once

#include "AppDeclared.h"
#include "UIObject.h"
#include "DeclaredValues.h"

SCENENODE* GetSceneNodeByID(int id);

SCENENODE* GetSceneNodeByName(const char* name);

void InitSceneNodes();

void ClearSceneCamBuffer(SCENENODE* sceneNode);

void CreateSceneNode(SCENENODE sceneNode);

void DrawScene(SCENENODE* sceneNode);
