#include "MazeMap.h"
#include "AppDeclared.h"
#include "Player.h"
#include "StartEndPoint.h"

void InitMazeMap()
{
    for (int i = 0; i < MAZEMAPMAXLENGTH; i++)
    {
        for (int j = 0; j < MAZEMAPMAXLENGTH; j++)
        {
            *(GetMazeMap()->GetMap() + i * MAZEMAPMAXLENGTH + j) = ' ';
        }
    }
}

void LoadMazeMap()
{
    switch (GetStageID())
    {
    case 1:
        LoadInfoFromFile("Maze1.txt");
        break;

    case 2:
        break;

    case 3:
        break;

    default:
        return;
    }
}

void UpdateMazeMap()
{
    char* camBuffer = GetCurrScene()->GetCamAddr()->GetCamBuffer();
    int camWidth = GetCurrScene()->GetCamAddr()->CameraWidth;
    int camHeight = GetCurrScene()->GetCamAddr()->CameraHeight;
    int playerPosX = GetPlayer()->ObjSelf.Position.posX;
    int playerPosY = GetPlayer()->ObjSelf.Position.posY;
    char* mapBuffer = GetMazeMap()->GetMap();

    int startPosX = playerPosX - camWidth / 2;
    int startPosY = playerPosY - camHeight / 2;

    for (int i = 0; i < camHeight; i++)
    {
        for (int j = 0; j < camWidth; j++)
        {
            *(camBuffer + i * camWidth + j) =
                *(mapBuffer + startPosY * MAZEMAPMAXLENGTH + startPosX +
                    i * MAZEMAPMAXLENGTH + j);
        }
    }
}

void LoadInfoFromFile(const char* fileName)
{
    FILE* pFile = NULL;
    int startX = 50;
    int startY = 50;
    int flag = 0;
    fopen_s(&pFile, fileName, "r");
    if (pFile == NULL)
    {
        ErrorLog("cannot open file");
        return;
    }

    while (flag != 3)
    {
        fscanf_s(pFile, "%d", &flag);
        if (flag == 1)
        {
            if (*(GetMazeMap()->GetMap() +
                (startY - 1) * MAZEMAPMAXLENGTH + startX) == '-' ||
                *(GetMazeMap()->GetMap() +
                    (startY - 1) * MAZEMAPMAXLENGTH + startX) == '|')
            {
                *(GetMazeMap()->GetMap() +
                    startY * MAZEMAPMAXLENGTH + startX) = '|';
            }
            else
            {
                *(GetMazeMap()->GetMap() +
                    startY * MAZEMAPMAXLENGTH + startX) = '-';
            }
            ++startX;
        }
        else if (flag == 0)
        {
            ++startX;
        }
        else if (flag == 4)
        {
            SetStartPointPos(POSITION_2D(startX, startY));
            *(GetMazeMap()->GetMap() +
                startY * MAZEMAPMAXLENGTH + startX) = 'S';
            ++startX;
        }
        else if (flag == 5)
        {
            SetEndPointPos(POSITION_2D(startX, startY));
            *(GetMazeMap()->GetMap() +
                startY * MAZEMAPMAXLENGTH + startX) = 'E';
            ++startX;
        }
        else if (flag == 2)
        {
            startX = 50;
            ++startY;
        }
    }
}
