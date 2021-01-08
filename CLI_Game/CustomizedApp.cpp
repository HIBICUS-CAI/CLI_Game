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
        DrawStageToCamBuffer(GetBattleStageToOffset());
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

    if (IsInputting())
    {
        UI_TEXT* temp = GetInputtingStr();
        POSITION_2D pos = temp->Position;

        COORD drawPos;
        drawPos.X = pos.posX;
        drawPos.Y = pos.posY;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), drawPos);
        ChangeColorInConsole(WHITE_BLACK);
        printf("%s", temp->Text);
        ResetColorInConsole();
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
        SetIsInputting(0);
        SetInputtingStr(NULL);
        ResetPlayerStatus();
        break;

    case INPUTINFO:
        SwitchSceneToName("input");
        GetUIObjByName("input")->Texts->
            ChangeTextTo("プレイヤーのお名前：");
        (GetUIObjByName("input")->Texts + 1)->
            ChangeTextTo("攻撃ナカマのお名前：");
        (GetUIObjByName("input")->Texts + 2)->
            ChangeTextTo("強さナカマのお名前：");
        SetIsInputting(1);
        SetInputIndex(0);
        SetInputtingStr(GetUIObjByName("input")->Texts);
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
            ChangeTextTo("ステージクリアしました！");
        (GetUIObjByName("after-clear")->Texts + 1)->
            ChangeTextTo("おめでとうございます！");
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

    case PREVIOUSSTR:
        if (GetInputIndex() > 0)
        {
            SetInputIndex(GetInputIndex() - 1);
            SetInputtingStr(GetUIObjByName("input")->
                Texts + GetInputIndex());
        }
        break;

    case NEXTSTR:
        if (GetInputIndex() < 2)
        {
            SetInputIndex(GetInputIndex() + 1);
            SetInputtingStr(GetUIObjByName("input")->
                Texts + GetInputIndex());
        }
        break;

    case A_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "あ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 0)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 0)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case I_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "い";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 11)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 11)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case U_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "う";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 19)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 19)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case E_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "え";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 30)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 30)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case O_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "お";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 38)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 38)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case KA_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "か";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 1)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 1)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case KI_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "き";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 12)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 12)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case KU_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "く";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 20)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 20)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case KE_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "け";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 31)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 31)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case KO_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "こ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 39)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 39)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case SA_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "さ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 2)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 2)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case SHI_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "し";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 13)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 13)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case SU_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "す";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 21)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 21)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case SE_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "せ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 32)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 32)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case SO_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "そ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 40)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 40)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case TA_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "た";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 3)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 3)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }
    break;

    case CHI_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ち";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 14)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 14)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case TSU_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "つ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 22)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 22)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case TE_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "て";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 33)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 33)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case TO_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "と";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 41)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 41)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case NA_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "な";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 4)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 4)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case NI_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "に";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 15)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 15)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case NU_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ぬ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 23)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 23)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case NE_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ね";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 34)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 34)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case NO_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "の";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 42)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 42)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case HA_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "は";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 5)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 5)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case HI_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ひ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 16)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 16)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case FU_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ふ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 24)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 24)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case HE_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "へ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 35)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 35)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case HO_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ほ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 43)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 43)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case MA_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ま";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 6)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 6)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case MI_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "み";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 17)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 17)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case MU_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "む";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 25)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 25)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case ME_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "め";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 36)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 36)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case MO_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "も";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 44)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 44)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case YA_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "や";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 7)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 7)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case YU_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ゆ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 26)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 26)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case YO_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "よ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 45)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 45)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case RA_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ら";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 8)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 8)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case RI_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "り";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 18)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 18)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case RU_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "る";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 27)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 27)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case RE_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "れ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 37)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 37)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case RO_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ろ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 46)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 46)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case WA_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "わ";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 9)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 9)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case WO_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "を";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 28)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 28)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    case NN_KANA:
    {
        if (GetInputCount() < 18)
        {
            SetInputCount(GetInputCount() + 1);
            char temp[3] = "ん";
            char text[512];
            sprintf_s(text, sizeof(text), "%s%s",
                GetInputtingStr()->Text, temp);
            GetInputtingStr()->ChangeTextTo((const char*)text);
            (GetUIObjByName("input")->Buttons + 47)->Event = -1;
            strcpy_s((GetUIObjByName("input")->Buttons + 47)->Text,
                sizeof(char) * 3, "  ");
        }

        break;
    }

    default:
        break;
    }
}
