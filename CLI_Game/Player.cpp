#include "Player.h"
#include "AppDeclared.h"
#include "SceneManager.h"
#include "SceneNode.h"
#include "BattleEnemy.h"
#include "MazeEnemy.h"

int g_JumpFlag = 0;
int g_JumpCounter = 0;
int g_AttackCoolDown = 0;
int g_LastestDirectionInput;

void InitPlayer(POSITION_2D pos)
{
    GetPlayer()->HP = 20;
    GetPlayer()->ATK = 5;
    GetPlayer()->PUSH = 20;
    GetPlayer()->ObjSelf.Position = pos;
    GetPlayer()->ObjSelf.Width = 2;
    GetPlayer()->ObjSelf.Height = 1;
    GetPlayer()->ObjSelf.ColliRadius = 1.f;
    GetPlayer()->ObjInBattle.Position = POSITION_2D(59, 32);
    GetPlayer()->ObjInBattle.Width = 2;
    GetPlayer()->ObjInBattle.Height = 1;
    GetPlayer()->ObjInBattle.ColliRadius = 1.f;
    char temp[3] = "¡ô";
    *(GetPlayer()->Sprite) = temp[0];
    *(GetPlayer()->Sprite + 1) = temp[1];
    GetPlayer()->TurnOn();
}

void ResetPlayerPosTurnToStage(int stage, POSITION_2D pos)
{
    if (stage == 1 || stage == 2 || stage == 3)
    {
        TurnOnPlayer();
        GetPlayer()->ObjSelf.Position = pos;
        SetIsPlayingMaze(1);
    }
}

void ResetPlayerPosInBattle()
{
    GetPlayer()->ObjInBattle.Position = POSITION_2D(59, 32);
}

void UpdatePlayer()
{
    if (!IsPlayingMaze() && !IsPlayingBattle())
    {
        switch (GetStageID())
        {
        case 1:
            ResetPlayerPosTurnToStage(GetStageID(),
                (GetStartEndPointArray()->ObjSelf.Position));
            break;

        case 2:
            ResetPlayerPosTurnToStage(GetStageID(), POSITION_2D(40, 20));
            break;

        case 3:
            ResetPlayerPosTurnToStage(GetStageID(), POSITION_2D(1, 38));
            break;

        default:
            return;
        }
    }
}

void UpdatePlayerInBattle()
{
    if (GetPlayer()->HP <= 0)
    {
        ClearBattleEnemyArray();
        TurnOffAllEnemy();
        SetStageID(0);
        SetIsPlayingMaze(0);
        SetIsPlayingBattle(0);
        SwitchSceneToName("selection");
        GetUIObjByName("after-clear")->TurnOn();
        GetUIObjByName("after-clear")->Texts->ChangeTextTo("Ï§¤·¤¤¤Ç¤¹£¡");
        (GetUIObjByName("after-clear")->Texts + 1)->
            ChangeTextTo("¤â¤¦Ò»»ØîBˆ¤Ã¤Æ¤¯¤À¤µ¤¤£¡");
        SetSelectedBtn(GetUIObjByName("after-clear")->Buttons);
    }

    char* camBuffer = GetManagedCurrScene()->GetCamAddr()->GetCamBuffer();
    int camWidth = GetManagedCurrScene()->GetCamAddr()->CameraWidth;
    POSITION_2D battlePos = GetPlayer()->ObjInBattle.Position;

    if (g_JumpFlag)
    {
        if (g_JumpFlag++ <= 5)
        {
            GetPlayer()->ObjInBattle.Position.posY -= 1;
        }
        else
        {
            g_JumpFlag = 0;
        }
    }

    if (*(camBuffer + (battlePos.posY + 1) * camWidth +
        battlePos.posX) != '-' ||
        *(camBuffer + (battlePos.posY + 1) * camWidth +
            battlePos.posX + 1) != '-')
    {
        if (!g_JumpFlag)
        {
            PlayerBattleFallDown();
        }
    }
}

void DrawPlayerToCamBuffer()
{
    char* buffer = GetCurrScene()->GetCamAddr()->GetCamBuffer();
    int width = GetCurrScene()->GetCamAddr()->CameraWidth;
    int height = GetCurrScene()->GetCamAddr()->CameraHeight;

    if (IsPlayingMaze())
    {
        *(buffer + height / 2 * width + width / 2) =
            *(GetPlayer()->Sprite);
        *(buffer + height / 2 * width + width / 2 + 1) =
            *(GetPlayer()->Sprite + 1);
    }
    else if (IsPlayingBattle())
    {
        POSITION_2D battlePos = GetPlayer()->ObjInBattle.Position;
        if (battlePos.posY <= 33 && battlePos.posY >= 3)
        {
            *(buffer + battlePos.posY * width + battlePos.posX) =
                *(GetPlayer()->Sprite);
            *(buffer + battlePos.posY * width + battlePos.posX + 1) =
                *(GetPlayer()->Sprite + 1);
        }
        if (g_AttackCoolDown)
        {
            switch (g_LastestDirectionInput)
            {
            case 0:
                if (battlePos.posX >= 3 && battlePos.posX <= 115)
                {
                    *(buffer + battlePos.posY * width +
                        battlePos.posX - 1) = '-';
                    *(buffer + battlePos.posY * width +
                        battlePos.posX - 2) = '<';
                }
                else
                {
                    *(buffer + battlePos.posY * width +
                        battlePos.posX - 1) = '-';
                }
                break;

            case 1:
                if (battlePos.posX >= 3 && battlePos.posX <= 115)
                {
                    *(buffer + battlePos.posY * width +
                        battlePos.posX + 2) = '-';
                    *(buffer + battlePos.posY * width +
                        battlePos.posX + 3) = '>';
                }
                else
                {
                    *(buffer + battlePos.posY * width +
                        battlePos.posX + 2) = '-';
                }
                break;

            default:
                break;
            }

            --g_AttackCoolDown;
        }
    }
}

void TurnOnPlayer()
{
    GetPlayer()->Visible = 1;
}

void TurnOffPlayer()
{
    GetPlayer()->Visible = 0;
}

void PlayerMoveForward()
{
    --GetPlayer()->ObjSelf.Position.posY;
}

void PlayerMoveBack()
{
    ++GetPlayer()->ObjSelf.Position.posY;
}

void PlayerTurnLeft()
{
    GetPlayer()->ObjSelf.Position.posX -= 2;
}

void PlayerTurnRight()
{
    GetPlayer()->ObjSelf.Position.posX += 2;
}

void PlayerBattleMoveLeft()
{
    GetPlayer()->ObjInBattle.Position.posX -= 2;
}

void PlayerBattleMoveRight()
{
    GetPlayer()->ObjInBattle.Position.posX += 2;
}

void PlayerBattleJumpUp()
{
    if (!g_JumpFlag)
    {
        GetPlayer()->ObjInBattle.Position.posY -= 1;
        g_JumpFlag = 1;
    }
}

void PlayerBattleFallDown()
{
    GetPlayer()->ObjInBattle.Position.posY += 1;
}

void PlayerAttack()
{
    if (!g_AttackCoolDown)
    {
        g_AttackCoolDown = 10;

        for (int i = 0; i < BATTLEENEMYSIZE; i++)
        {
            if ((GetBattleEnemyArray() + i)->ID == -1)
            {
                break;
            }

            if ((GetBattleEnemyArray() + i)->HP > 0)
            {
                if (g_LastestDirectionInput)
                {
                    if ((GetBattleEnemyArray() + i)->
                        ObjSelf.GetDeltaYWith(GetPlayer()->ObjInBattle) <= 1 &&
                        (GetBattleEnemyArray() + i)->
                        ObjSelf.GetDeltaYWith(GetPlayer()->ObjInBattle) >= -1 &&
                        (GetBattleEnemyArray() + i)->
                        ObjSelf.GetDeltaXWith(GetPlayer()->ObjInBattle) <= 6 &&
                        (GetBattleEnemyArray() + i)->
                        ObjSelf.GetDeltaXWith(GetPlayer()->ObjInBattle) >= 0)
                    {
                        PushEnemyByPlayer(GetBattleEnemyArray() + i,
                            g_LastestDirectionInput);
                        (GetBattleEnemyArray() + i)->HP -= GetPlayer()->ATK;
                    }
                }
                else
                {
                    if ((GetBattleEnemyArray() + i)->
                        ObjSelf.GetDeltaYWith(GetPlayer()->ObjInBattle) <= 1 &&
                        (GetBattleEnemyArray() + i)->
                        ObjSelf.GetDeltaYWith(GetPlayer()->ObjInBattle) >= -1 &&
                        (GetBattleEnemyArray() + i)->
                        ObjSelf.GetDeltaXWith(GetPlayer()->ObjInBattle) <= 0 &&
                        (GetBattleEnemyArray() + i)->
                        ObjSelf.GetDeltaXWith(GetPlayer()->ObjInBattle) >= -6)
                    {
                        PushEnemyByPlayer(GetBattleEnemyArray() + i,
                            g_LastestDirectionInput);
                        (GetBattleEnemyArray() + i)->HP -= GetPlayer()->ATK;
                    }
                }
            }
        }
    }
}

void SetLastestDirectionInput(int value)
{
    g_LastestDirectionInput = value;
}

int GetLastestDirectionInput()
{
    return g_LastestDirectionInput;
}

void ResetPlayerStatus()
{
    char hpText[40];
    char atkText[40];
    char pushText[40];

    strcpy_s(hpText, sizeof(hpText),
        (GetUIObjByName("input")->Texts + 0)->Text + 20);
    strcpy_s(atkText, sizeof(hpText),
        (GetUIObjByName("input")->Texts + 1)->Text + 20);
    strcpy_s(pushText, sizeof(hpText),
        (GetUIObjByName("input")->Texts + 2)->Text + 20);

    int hpLen = strlen(hpText);
    int atkLen = strlen(atkText);
    int pushLen = strlen(pushText);

    if (!hpLen)
    {
        GetPlayer()->HP = 1 + 100;
    }
    else
    {
        int hp = 0;
        for (int i = 0; i < hpLen; i++)
        {
            if (hpText[i] < 0)
            {
                hp -= hpText[i];
            }
            else
            {
                hp += hpText[i];
            }
        }
        hp /= hpLen;
        GetPlayer()->HP = hp + 100;
        DebugLogI1("hp", hp + 100);
    }

    if (!atkLen)
    {
        GetPlayer()->ATK = 1 + 3;
    }
    else
    {
        int atk = 0;
        for (int i = 0; i < atkLen; i++)
        {
            if (atkText[i] < 0)
            {
                atk -= atkText[i];
            }
            else
            {
                atk += atkText[i];
            }
        }
        atk /= atkLen;
        GetPlayer()->ATK = atk + 3;
        DebugLogI1("atk", atk + 3);
    }

    if (!pushLen)
    {
        GetPlayer()->PUSH = 1 + 10;
    }
    else
    {
        int push = 0;
        for (int i = 0; i < pushLen; i++)
        {
            if (pushText[i] < 0)
            {
                push -= pushText[i];
            }
            else
            {
                push += pushText[i];
            }
        }
        push /= pushLen;
        GetPlayer()->PUSH = push + 10;
        DebugLogI1("push", push + 10);
    }
}

void ResetPlayerHP()
{
    GetPlayer()->HP = GetInputHP();
}
