#pragma once

#include "DeclaredObjects.h"

void InitPlayer(POSITION_2D pos);

void ResetPlayerPosTurnToStage(int stage, POSITION_2D pos);

void UpdatePlayer();

void DrawPlayerToCamBuffer();

void PlayerMoveForward();

void PlayerMoveBack();

void PlayerTurnLeft();

void PlayerTurnRight();

void TurnOnPlayer();

void TurnOffPlayer();
