#pragma once

#include "DeclaredObjects.h"

void InitPlayer(POSITION_2D pos);

void ResetPlayerPosTurnToStage(int stage, POSITION_2D pos);

void ResetPlayerPosInBattle();

void UpdatePlayer();

void UpdatePlayerInBattle();

void DrawPlayerToCamBuffer();

void PlayerMoveForward();

void PlayerMoveBack();

void PlayerTurnLeft();

void PlayerTurnRight();

void TurnOnPlayer();

void TurnOffPlayer();

void PlayerBattleMoveLeft();

void PlayerBattleMoveRight();

void PlayerBattleJumpUp();

void PlayerBattleFallDown();
