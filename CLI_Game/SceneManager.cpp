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
    if (!strcmp(GetManagedCurrScene()->SceneName, "title"))
    {
        SetSceneFlag(TITLESCENEFLAG);
        SetSelectedBtn(GetSceneNodeByName("title")->BaseUIObj->Buttons);
    }
    else if (!strcmp(GetManagedCurrScene()->SceneName, "selection"))
    {
        SetSceneFlag(SELECTIONSCENEFLAG);
        SetSelectedBtn(GetSceneNodeByName("selection")->BaseUIObj->Buttons);
    }
    else if (!strcmp(GetManagedCurrScene()->SceneName, "maze"))
    {
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

void SwitchSceneToName(const char* sceneName)
{
    SCENENODE* scene = GetSceneNodeByName(sceneName);
    if (scene == NULL)
    {
        if (!strcmp(sceneName,"title"))
        {
            InitTitleScene();
        }
        else if (!strcmp(sceneName, "selection"))
        {
            InitSelectionScene();
        }
        else if (!strcmp(sceneName, "maze"))
        {
            InitMazeScene();
        }

        scene = GetSceneNodeByName(sceneName);
    }
    SetManagedCurrScene(scene);
    InitCurrScene();
    UpdateCurrScene();
}
