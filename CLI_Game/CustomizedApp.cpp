#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"

void AppInit()
{
    InitSceneNodes();

    SwitchSceneToName("title");
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
        SwitchSceneToName("selection");
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
        SwitchSceneToName("title");
        break;

    case GETINMAZE1:
        SwitchSceneToName("maze");
        break;

    case GETINMAZE2:
        SwitchSceneToName("maze");
        break;

    case GETINMAZE3:
        SwitchSceneToName("maze");
        break;

    case GIVEUPMAZE:
        SwitchSceneToName("selection");
        break;

    default:
        break;
    }
}
