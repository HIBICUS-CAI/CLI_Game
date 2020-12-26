#pragma once
#include "DeclaredObjects.h"

#define STOP_MOVING 0
#define GO_FORWARD 1
#define GO_BACK 2
#define TURN_LEFT 3
#define TURN_RIGHT 4

void InitMazeEnemy();

void SetMazeEnemy(POSITION_2D pos);

void UpdateMazeEnemy();

void UpdateSingleMazeEnemy(MAZEENEMY* mazeEnemy);

void ScanPlayer(MAZEENEMY* mazeEnemy);

void ManageMazeEnemyMove(MAZEENEMY* mazeEnemy);

void MazeEnemyMoveForward(MAZEENEMY* mazeEnemy);

void MazeEnemyMoveBack(MAZEENEMY* mazeEnemy);

void MazeEnemyTurnLeft(MAZEENEMY* mazeEnemy);

void MazeEnemyTurnRight(MAZEENEMY* mazeEnemy);

void TurnOnAllEnemy();

void TurnOffAllEnemy();
