#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"
#include "DeclaredObjects.h"
#include "Player.h"
#include "MazeMap.h"
#include "StartEndPoint.h"
#include "MazeEnemy.h"

void AppInit()
{
    InitSceneNodes();
    InitPlayer(POSITION_2D(0, 0));
    InitMazeMap();
    InitStartEndPoint();
    InitMazeEnemy();

    SwitchSceneToName("title");
}

void AppUpdate()
{
    UpdateCurrScene();

    UpdatePlayer();
    if (IsPlayingMaze())
    {
        UpdateMazeMap();
        UpdateStartEndPoint();
        UpdateMazeEnemy();
        DrawPlayerToCamBuffer();
    }

    DrawScene(GetManagedCurrScene());
}

void AppTurnOff()
{

}

void AppKeyboardEvent(int keyCode)
{
    if (keyCode == W_VALUE)
    {

        if (*(GetMazeMap()->GetMap() +
            (GetPlayer()->ObjSelf.Position.posY - 1) * MAZEMAPMAXLENGTH +
            GetPlayer()->ObjSelf.Position.posX) == '-' ||
            *(GetMazeMap()->GetMap() +
                (GetPlayer()->ObjSelf.Position.posY - 1) * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX) == '|' ||
            *(GetMazeMap()->GetMap() +
                (GetPlayer()->ObjSelf.Position.posY - 1) * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX + 1) == '-' ||
            *(GetMazeMap()->GetMap() +
                (GetPlayer()->ObjSelf.Position.posY - 1) * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX + 1) == '|')
        {

        }
        else
        {
            PlayerMoveForward();
        }
    }
    if (keyCode == S_VALUE)
    {
        if (*(GetMazeMap()->GetMap() +
            (GetPlayer()->ObjSelf.Position.posY + 1) * MAZEMAPMAXLENGTH +
            GetPlayer()->ObjSelf.Position.posX) == '-' ||
            *(GetMazeMap()->GetMap() +
                (GetPlayer()->ObjSelf.Position.posY + 1) * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX) == '|' ||
            *(GetMazeMap()->GetMap() +
                (GetPlayer()->ObjSelf.Position.posY + 1) * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX + 1) == '-' ||
            *(GetMazeMap()->GetMap() +
                (GetPlayer()->ObjSelf.Position.posY + 1) * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX + 1) == '|')
        {

        }
        else
        {
            PlayerMoveBack();
        }
    }
    if (keyCode == A_VALUE)
    {
        if (*(GetMazeMap()->GetMap() +
            GetPlayer()->ObjSelf.Position.posY * MAZEMAPMAXLENGTH +
            GetPlayer()->ObjSelf.Position.posX - 1) == '-' ||
            *(GetMazeMap()->GetMap() +
                GetPlayer()->ObjSelf.Position.posY * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX - 1) == '|' ||
            *(GetMazeMap()->GetMap() +
                GetPlayer()->ObjSelf.Position.posY * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX - 2) == '-' ||
            *(GetMazeMap()->GetMap() +
                GetPlayer()->ObjSelf.Position.posY * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX - 2) == '|')
        {

        }
        else
        {
            PlayerTurnLeft();
        }
    }
    if (keyCode == D_VALUE)
    {
        if (*(GetMazeMap()->GetMap() +
            GetPlayer()->ObjSelf.Position.posY * MAZEMAPMAXLENGTH +
            GetPlayer()->ObjSelf.Position.posX + 2) == '-' ||
            *(GetMazeMap()->GetMap() +
                GetPlayer()->ObjSelf.Position.posY * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX + 2) == '|' ||
            *(GetMazeMap()->GetMap() +
                GetPlayer()->ObjSelf.Position.posY * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX + 3) == '-' ||
            *(GetMazeMap()->GetMap() +
                GetPlayer()->ObjSelf.Position.posY * MAZEMAPMAXLENGTH +
                GetPlayer()->ObjSelf.Position.posX + 3) == '|')
        {

        }
        else
        {
            PlayerTurnRight();
        }
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
        LoadMazeMap();
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

    case CLOSECLEARUP:
        GetUIObjByName("after-clear")->TurnOff();
        SetSelectedBtn(GetUIObjByName("selection")->Buttons);
        break;

    default:
        break;
    }
}
