#include "Player.h"
#include "AppDeclared.h"

void InitPlayer(POSITION_2D pos)
{
    GetPlayer()->ObjSelf.Position = pos;
    GetPlayer()->ObjSelf.Width = 2;
    GetPlayer()->ObjSelf.Height = 1;
    GetPlayer()->ObjSelf.ColliRadius = 1.f;
    char temp[3] = "��";
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

void UpdatePlayer()
{
    if (!IsPlayingMaze())
    {
        switch (GetStageID())
        {
        case 1:
            ResetPlayerPosTurnToStage(GetStageID(), POSITION_2D(1, 1));
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

    DrawPlayerToCamBuffer();
}

void DrawPlayerToCamBuffer()
{
    char* buffer = GetCurrScene()->GetCamAddr()->GetCamBuffer();
    int width = GetCurrScene()->GetCamAddr()->CameraWidth;
    int height = GetCurrScene()->GetCamAddr()->CameraHeight;
    int playerPosX = GetPlayer()->ObjSelf.Position.posX;
    int playerPosY = GetPlayer()->ObjSelf.Position.posY;

    if (playerPosX<0 || (playerPosX + 1)>width ||
        playerPosY<0 || playerPosY>height)
    {
        ErrorLog("player's position overflowed");
    }

    *(buffer + playerPosY * width + playerPosX) =
        *(GetPlayer()->Sprite);
    *(buffer + playerPosY * width + playerPosX + 1) =
        *(GetPlayer()->Sprite + 1);
}

void TurnOnPlayer()
{
    GetPlayer()->Visible = 1;
}

void TurnOffPlayer()
{
    GetPlayer()->Visible = 0;
}

void MoveForward()
{
    --GetPlayer()->ObjSelf.Position.posY;
}

void MoveBack()
{
    ++GetPlayer()->ObjSelf.Position.posY;
}

void TurnLeft()
{
    GetPlayer()->ObjSelf.Position.posX -= 2;
}

void TurnRight()
{
    GetPlayer()->ObjSelf.Position.posX += 2;
}
