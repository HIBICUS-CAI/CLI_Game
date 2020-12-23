#include "MazeMap.h"
#include "AppDeclared.h"
#include "Player.h"

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
    if (!IsPlayingMaze())
    {
        switch (GetStageID())
        {
        case 1:
            
            break;

        case 2:
            break;

        case 3:
            break;

        default:
            return;
        }
    }
}

void UpdateMazeMap()
{
    LoadMazeMap();
}
