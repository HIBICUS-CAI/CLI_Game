#include "SceneManager.h"
#include "AppDeclared.h"
#include "AppTitleScene.h"
#include "AppStageSelectScene.h"
#include "AppMazeScene.h"

#define TITLESCENEFLAG 1
#define SELECTIONSCENEFLAG 2
#define MAZESCENEFLAG 3
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
        if (GetSceneNodeByName("title") == NULL)
        {
            InitTitleScene();
        }
        SetManagedCurrScene(GetSceneNodeByName("title"));
        SetSceneFlag(TITLESCENEFLAG);
        SetSelectedBtn(GetSceneNodeByName("title")->BaseUIObj->Buttons);
    }
    else if (!strcmp(GetManagedCurrScene()->SceneName, "title"))
    {
        if (GetSceneNodeByName("selection") == NULL)
        {
            InitSelectionScene();
        }
        SetManagedCurrScene(GetSceneNodeByName("selection"));
        SetSceneFlag(SELECTIONSCENEFLAG);
        SetSelectedBtn(GetSceneNodeByName("selection")->BaseUIObj->Buttons);
    }
    else if (!strcmp(GetManagedCurrScene()->SceneName, "selection"))
    {
        if (GetSceneNodeByName("maze") == NULL)
        {
            InitMazeScene();
        }
        SetManagedCurrScene(GetSceneNodeByName("maze"));
        SetSceneFlag(MAZESCENEFLAG);
        SetSelectedBtn(GetSceneNodeByName("maze")->BaseUIObj->Buttons);
    }
}

void UpdateCurrScene()
{
    switch (GetSceneFlag())
    {
    case TITLESCENEFLAG:
        UpdateTitleScene();
        break;

    case SELECTIONSCENEFLAG:
        UpdateSelectionScene();
        break;

    case MAZESCENEFLAG:
        UpdateMazeScene();
        break;

    default:
        ErrorLogI1("you don't have a scene flag witch is", GetSceneFlag());
        break;
    }
}

void SwitchSceneFrom(SCENENODE* sceneNode)
{
    SetManagedCurrScene(sceneNode);
    InitCurrScene();
    UpdateCurrScene();
}
