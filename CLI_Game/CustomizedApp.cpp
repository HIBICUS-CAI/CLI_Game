#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"
#include "DeclaredObjects.h"
#include "Player.h"

void AppInit()
{
    InitSceneNodes();
    InitPlayer(POSITION_2D(0, 0));

    SwitchSceneToName("title");
}

void AppUpdate()
{
    UpdateCurrScene();
    UpdatePlayer();

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
        MoveForward();
    }
    if (keyCode == S_VALUE)
    {
        DebugLog("go back");
        MoveBack();
    }
    if (keyCode == A_VALUE)
    {
        DebugLog("turn left");
        TurnLeft();
    }
    if (keyCode == D_VALUE)
    {
        DebugLog("turn right");
        TurnRight();
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
        SetStageID(1);
        break;

    case GETINMAZE2:
        SwitchSceneToName("maze");
        SetStageID(2);
        break;

    case GETINMAZE3:
        SwitchSceneToName("maze");
        SetStageID(3);
        break;

    case GIVEUPMAZE:
        SwitchSceneToName("selection");
        SetStageID(0);
        SetIsPlayingMaze(0);
        break;

    default:
        break;
    }
}
