#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"
#include "DeclaredObjects.h"
#include "Player.h"
#include "MazeMap.h"
#include "StartEndPoint.h"
#include "MazeEnemy.h"
#include "Tools.h"
#include "BattleStage.h"
#include "BattleEnemy.h"

void AppInit()
{
    InitSceneNodes();
    InitPlayer(POSITION_2D(0, 0));
    InitMazeMap();
    InitStartEndPoint();
    InitMazeEnemy();
    InitBattleStage();
    InitBattleEnemy();

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
    if (IsPlayingBattle())
    {
        DrawStageToCamBuffer(0);
        UpdatePlayerInBattle();
        UpdateBattleEnemy();
        DrawBattleEnemyToCamBuffer();
        DrawPlayerToCamBuffer();
    }

    DrawScene(GetManagedCurrScene());
}

void AppTurnOff()
{

}

void AppPostPrint()
{
    for (int i = 0; i < MAZEENEMYSIZE; i++)
    {
        if ((GetMazeEnemyArray() + i)->Visible == 1)
        {
            int width = GetCurrScene()->GetCamAddr()->CameraWidth;
            int height = GetCurrScene()->GetCamAddr()->CameraHeight;
            POSITION_2D position =
                (GetMazeEnemyArray() + i)->ObjSelf.Position -
                GetPlayer()->ObjSelf.Position;
            if ((position.posX * position.posX <
                (width / 2 * width / 2)) &&
                (position.posY * position.posY <
                    (height / 2 * height / 2)))
            {
                position =
                    POSITION_2D(width / 2, height / 2) + position +
                    GetCurrScene()->GetCamAddr()->CameraPosition;
                COORD drawPos;
                drawPos.X = position.posX;
                drawPos.Y = position.posY;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), drawPos);
                ChangeColorInConsole(BLACK_RED);
                char temp[3];
                temp[0] = *((GetMazeEnemyArray() + i)->Sprite);
                temp[1] = *((GetMazeEnemyArray() + i)->Sprite + 1);
                temp[2] = '\0';
                printf("%s", temp);
                ResetColorInConsole();
            }
        }
    }

    if (IsPlayingBattle())
    {
        for (int i = 0; i < BATTLEENEMYSIZE; i++)
        {
            if ((GetBattleEnemyArray() + i)->ID == -1)
            {
                break;
            }

            if ((GetBattleEnemyArray() + i)->Visible == 1)
            {
                int width = GetManagedCurrScene()->GetCamAddr()->
                    CameraWidth;
                int height = GetManagedCurrScene()->GetCamAddr()->
                    CameraHeight;
                POSITION_2D pos =
                    (GetBattleEnemyArray() + i)->ObjSelf.Position;
                POSITION_2D camPos =
                    GetManagedCurrScene()->GetCamAddr()->CameraPosition;
                pos = pos + camPos;

                COORD drawPos;
                drawPos.X = pos.posX;
                drawPos.Y = pos.posY;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), drawPos);

                if ((float)(GetBattleEnemyArray() + i)->HP /
                    (float)BATTLEENEMYMAXHP > 0.75f)
                {
                    ChangeColorInConsole(BLACK_YELLOW);
                }
                else if ((float)(GetBattleEnemyArray() + i)->HP /
                    (float)BATTLEENEMYMAXHP > 0.5f)
                {
                    ChangeColorInConsole(BLACK_RED);
                }
                else if ((float)(GetBattleEnemyArray() + i)->HP /
                    (float)BATTLEENEMYMAXHP > 0.25f)
                {
                    ChangeColorInConsole(BLACK_DARKRED);
                }
                else if ((float)(GetBattleEnemyArray() + i)->HP /
                    (float)BATTLEENEMYMAXHP > 0.f)
                {
                    ChangeColorInConsole(BLACK_DARKYELLOW);
                }
                else
                {
                    continue;
                }

                char temp[3];
                temp[0] = *((GetMazeEnemyArray() + i)->Sprite);
                temp[1] = *((GetMazeEnemyArray() + i)->Sprite + 1);
                temp[2] = '\0';
                printf("%s", temp);
                ResetColorInConsole();
            }
        }
    }
}

void AppKeyboardEvent(int keyCode)
{
    if (keyCode == O_VALUE)
    {
        char* camBuffer = GetManagedCurrScene()->GetCamAddr()->GetCamBuffer();
        int camWidth = GetManagedCurrScene()->GetCamAddr()->CameraWidth;
        POSITION_2D battlePos = GetPlayer()->ObjInBattle.Position;
        if (IsPlayingBattle() &&
            (*(camBuffer + (battlePos.posY + 1) * camWidth +
                battlePos.posX) == '-' ||
                *(camBuffer + (battlePos.posY + 1) * camWidth +
                    battlePos.posX + 1) == '-'))
        {
            DebugLog("jump");
            PlayerBattleJumpUp();
        }
    }
    if (keyCode == P_VALUE)
    {
        if (IsPlayingBattle())
        {
            DebugLog("attack");
            PlayerAttack();
        }
    }
    if (keyCode == W_VALUE)
    {
        if (!strcmp(GetManagedCurrScene()->SceneName, "maze"))
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
        else if (!strcmp(GetManagedCurrScene()->SceneName, "battle"))
        {

        }
    }
    if (keyCode == S_VALUE)
    {
        if (!strcmp(GetManagedCurrScene()->SceneName, "maze"))
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
        else if (!strcmp(GetManagedCurrScene()->SceneName, "battle"))
        {

        }
    }
    if (keyCode == A_VALUE)
    {
        if (!strcmp(GetManagedCurrScene()->SceneName, "maze"))
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
        else if (!strcmp(GetManagedCurrScene()->SceneName, "battle"))
        {
            char* camBuffer = GetManagedCurrScene()->GetCamAddr()->GetCamBuffer();
            int camWidth = GetManagedCurrScene()->GetCamAddr()->CameraWidth;
            POSITION_2D battlePos = GetPlayer()->ObjInBattle.Position;
            if (battlePos.posX >= 3 &&
                *(camBuffer + battlePos.posY * camWidth +
                    battlePos.posX - 1) != '-' &&
                *(camBuffer + battlePos.posY * camWidth +
                    battlePos.posX - 2) != '-')
            {
                PlayerBattleMoveLeft();
            }
            SetLastestDirectionInput(0);
        }
    }
    if (keyCode == D_VALUE)
    {
        if (!strcmp(GetManagedCurrScene()->SceneName, "maze"))
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
        else if (!strcmp(GetManagedCurrScene()->SceneName, "battle"))
        {
            char* camBuffer = GetManagedCurrScene()->GetCamAddr()->GetCamBuffer();
            int camWidth = GetManagedCurrScene()->GetCamAddr()->CameraWidth;
            POSITION_2D battlePos = GetPlayer()->ObjInBattle.Position;
            if (battlePos.posX <= 114 &&
                *(camBuffer + battlePos.posY * camWidth +
                    battlePos.posX + 1) != '-' &&
                *(camBuffer + battlePos.posY * camWidth +
                    battlePos.posX + 2) != '-')
            {
                PlayerBattleMoveRight();
            }
            SetLastestDirectionInput(1);
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

    case INPUTINFO:
        SwitchSceneToName("input");
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
        GetPlayer()->HP = 2000;
        ResetPlayerPosInBattle();
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
        InitMazeEnemy();
        break;

    case CLOSECLEARUP:
        GetUIObjByName("after-clear")->TurnOff();
        SetSelectedBtn(GetUIObjByName("selection")->Buttons);
        GetUIObjByName("after-clear")->Texts->
            ChangeTextTo("¥¹¥Æ©`¥¸¥¯¥ê¥¢¤·¤Þ¤·¤¿£¡");
        (GetUIObjByName("after-clear")->Texts + 1)->
            ChangeTextTo("¤ª¤á¤Ç¤È¤¦¤´¤¶¤¤¤Þ¤¹£¡");
        break;

    case ENDBATTLE:
        TurnOffAllBattleEnemy();
        ClearBattleEnemyArray();
        SwitchSceneToName("maze");
        SetIsPlayingBattle(0);
        SetIsPlayingMaze(1);
        TurnOnAllEnemy();
        ResetPlayerPosInBattle();
        break;

    default:
        break;
    }
}
