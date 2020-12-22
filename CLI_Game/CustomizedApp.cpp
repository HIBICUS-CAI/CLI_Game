#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"

void AppInit()
{
    InitSceneNodes();

    SwitchSceneFrom(NULL);
}

void AppUpdate()
{
    UpdateCurrScene();

    DrawScene(GetManagedCurrScene());
}

void AppTurnOff()
{

}

void AppKeyboardEvent(int keyCode)
{
    if (keyCode == W_VALUE)
    {
        DebugLog("go forward");
    }
    if (keyCode == S_VALUE)
    {
        DebugLog("go back");
    }
    if (keyCode == A_VALUE)
    {
        DebugLog("turn left");
    }
    if (keyCode == D_VALUE)
    {
        DebugLog("turn right");
    }
}

void AppButtonEvent(int value)
{
    switch (value)
    {
    case STARTGAME:
        SwitchSceneFrom(GetSceneNodeByName("title"));
        break;

    case GAMEHELP:
        GetUIObjByName("help")->TurnOn();
        SetSelectedBtn(GetUIObjByName("help")->Buttons);
        break;

    case CLOSEHELP:
        GetUIObjByName("help")->TurnOff();
        SetSelectedBtn(GetUIObjByName("title")->Buttons + 1);
        break;

    case CLOSESELECT:
        SwitchSceneFrom(NULL);
        break;

    case GETINMAZE1:
        DebugLog("maze1");
        SwitchSceneFrom(GetSceneNodeByName("selection"));
        break;

    case GETINMAZE2:
        DebugLog("maze2");
        SwitchSceneFrom(GetSceneNodeByName("selection"));
        break;

    case GETINMAZE3:
        DebugLog("maze3");
        SwitchSceneFrom(GetSceneNodeByName("selection"));
        break;

    default:
        break;
    }
}
