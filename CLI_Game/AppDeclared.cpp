#include "AppDeclared.h"

SCENENODE g_SceneNodes[SCENENODESIZE];

SCENENODE* GetSceneNodeArray()
{
    return g_SceneNodes;
}

void SetSceneNodeArray(int index, SCENENODE temp)
{
    g_SceneNodes[index] = temp;
}
