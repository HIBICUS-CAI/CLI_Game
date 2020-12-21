#include "CustomizedApp.h"
#include "AppTitleScene.h"

void AppInit()
{
    InitSceneNodes();

    InitTitleScene();
}

void AppUpdate()
{
    UpdateTitleScene();
    DrawScene(GetSceneNodeByName("title"));
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
        DebugLog("to start game");
        break;

    case GAMEHELP:
        GetUIObjByName("help")->TurnOn();
        SetSelectedBtn(GetUIObjByName("help")->Buttons);
        break;

    case CLOSEHELP:
        GetUIObjByName("help")->TurnOff();
        SetSelectedBtn(GetUIObjByName("title")->Buttons);
        break;

    default:
        break;
    }
}
