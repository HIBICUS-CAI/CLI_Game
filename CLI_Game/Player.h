#pragma once

#include "DeclaredObjects.h"

void InitPlayer(POSITION_2D pos);

void ResetPlayerPosTurnToStage(int stage, POSITION_2D pos);

void UpdatePlayer();

void DrawPlayerToCamBuffer();

void MoveForward();

void MoveBack();

void TurnLeft();

void TurnRight();

void TurnOnPlayer();

void TurnOffPlayer();
