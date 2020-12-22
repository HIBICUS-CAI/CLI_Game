#include "SceneManager.h"
#include "AppDeclared.h"
#include "AppTitleScene.h"

#define TITLESCENEFLAG 1
int g_SceneFlag;

void SetSceneFlag(int flag)
{
    g_SceneFlag = flag;
}

int GetSceneFlag()
{
    return g_SceneFlag;
}

void SetManagedCurrScene(SCENENODE* sceneNode)
{
    SetCurrScene(sceneNode);
}

SCENENODE* GetManagedCurrScene()
{
    return GetCurrScene();
}

void InitCurrScene()
{
    if (GetManagedCurrScene() == NULL)
    {
        InitTitleScene();
        SetManagedCurrScene(GetSceneNodeByName("title"));
        SetSceneFlag(TITLESCENEFLAG);
    }
    else if (strcmp(GetManagedCurrScene()->SceneName, "title"))
    {
        /*SetSceneFlag(TITLESCENEFLAG);
        InitTitleScene();*/
    }
}

void UpdateCurrScene()
{
    switch (GetSceneFlag())
    {
    case TITLESCENEFLAG:
        UpdateTitleScene();
        break;

    default:
        ErrorLogI1("you don't have a scene flag witch is", GetSceneFlag());
        break;
    }
}

void SwitchSceneTo(SCENENODE* sceneNode)
{
    SetManagedCurrScene(sceneNode);
    InitCurrScene();
    UpdateCurrScene();
}
