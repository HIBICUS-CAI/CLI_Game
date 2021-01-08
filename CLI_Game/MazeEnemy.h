//------------------------------------------------------------------------
// ファイル名: MazeEnemy.h
// 機能: 迷宮の敵に関しての処理
//------------------------------------------------------------------------

#pragma once
#include "DeclaredObjects.h"

#define STOP_MOVING 0
#define GO_FORWARD 1
#define GO_BACK 2
#define TURN_LEFT 3
#define TURN_RIGHT 4

/// <summary>
/// 敵配列を初期化する
/// </summary>
void InitMazeEnemy();

/// <summary>
/// 敵の位置を設定する
/// </summary>
/// <param name="pos">位置の座標</param>
void SetMazeEnemy(POSITION_2D pos);

/// <summary>
/// 全ての敵を更新する
/// </summary>
void UpdateMazeEnemy();

/// <summary>
/// 各敵を更新する
/// </summary>
/// <param name="mazeEnemy">敵指向のポインタ</param>
void UpdateSingleMazeEnemy(MAZEENEMY* mazeEnemy);

/// <summary>
/// ある敵がプレイヤーを検索する
/// </summary>
/// <param name="mazeEnemy">敵指向のポインタ</param>
void ScanPlayer(MAZEENEMY* mazeEnemy);

/// <summary>
/// ある敵の移動を管理する
/// </summary>
/// <param name="mazeEnemy">敵指向のポインタ</param>
void ManageMazeEnemyMove(MAZEENEMY* mazeEnemy);

/// <summary>
/// ある敵を前向きに行かせる
/// </summary>
/// <param name="mazeEnemy">敵指向のポインタ</param>
void MazeEnemyMoveForward(MAZEENEMY* mazeEnemy);

/// <summary>
/// ある敵を後ろに行かせる
/// </summary>
/// <param name="mazeEnemy">敵指向のポインタ</param>
void MazeEnemyMoveBack(MAZEENEMY* mazeEnemy);

/// <summary>
/// ある敵を左に行かせる
/// </summary>
/// <param name="mazeEnemy">敵指向のポインタ</param>
void MazeEnemyTurnLeft(MAZEENEMY* mazeEnemy);

/// <summary>
/// ある敵を右に行かせる
/// </summary>
/// <param name="mazeEnemy">敵指向のポインタ</param>
void MazeEnemyTurnRight(MAZEENEMY* mazeEnemy);

/// <summary>
/// 全ての敵を可視的になる
/// </summary>
void TurnOnAllEnemy();

/// <summary>
/// 全ての敵を不可視的になる
/// </summary>
void TurnOffAllEnemy();
