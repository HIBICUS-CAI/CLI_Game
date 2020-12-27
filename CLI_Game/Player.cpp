#include "Player.h"
#include "AppDeclared.h"
#include "SceneManager.h"
#include "SceneNode.h"

int g_JumpFlag = 0;
int g_JumpCounter = 0;

void InitPlayer(POSITION_2D pos)
{
    GetPlayer()->HP = 20;
    GetPlayer()->ATK = 10;
    GetPlayer()->PUSH = 5;
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
        if (battlePos.posY <= 33)
        {
            *(buffer + battlePos.posY * width + battlePos.posX) =
                *(GetPlayer()->Sprite);
            *(buffer + battlePos.posY * width + battlePos.posX + 1) =
                *(GetPlayer()->Sprite + 1);
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

}
