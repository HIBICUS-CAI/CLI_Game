//------------------------------------------------------------------------
// ファイル名: Player.h
// 機能: プレイヤーに関しての処理
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// プレイヤーをある位置に設定する
/// </summary>
/// <param name="pos">位置の座標</param>
void InitPlayer(POSITION_2D pos);

/// <summary>
/// 迷宮を入る時プレイヤーの座標を設定する
/// </summary>
/// <param name="stage">ステージの番号</param>
/// <param name="pos">位置の座標</param>
void ResetPlayerPosTurnToStage(int stage, POSITION_2D pos);

/// <summary>
/// 戦闘を行う時プレイヤーの座標を設定する
/// </summary>
void ResetPlayerPosInBattle();

/// <summary>
/// 迷宮のプレイヤーを更新する
/// </summary>
void UpdatePlayer();

/// <summary>
/// 戦闘しているプレイヤーを更新する
/// </summary>
void UpdatePlayerInBattle();

/// <summary>
/// プレイヤーをシーンのカメラバッファに書き込む
/// </summary>
void DrawPlayerToCamBuffer();

/// <summary>
/// プレイヤーを前向きに行かせる
/// </summary>
void PlayerMoveForward();

/// <summary>
/// プレイヤーを後ろに行かせる
/// </summary>
void PlayerMoveBack();

/// <summary>
/// プレイヤーを左に行かせる
/// </summary>
void PlayerTurnLeft();

/// <summary>
/// プレイヤーを右に行かせる
/// </summary>
void PlayerTurnRight();

/// <summary>
/// プレイヤーを可視的になる
/// </summary>
void TurnOnPlayer();

/// <summary>
/// プレイヤーを不可視的になる
/// </summary>
void TurnOffPlayer();

/// <summary>
/// 戦闘中プレイヤーを左に行かせる
/// </summary>
void PlayerBattleMoveLeft();

/// <summary>
/// 戦闘中プレイヤーを右に行かせる
/// </summary>
void PlayerBattleMoveRight();

/// <summary>
/// 戦闘中プレイヤーをジャンプさせる
/// </summary>
void PlayerBattleJumpUp();

/// <summary>
/// 戦闘中プレイヤーが何も踏んでいないと落ちる
/// </summary>
void PlayerBattleFallDown();

/// <summary>
/// 戦闘中プレイヤーからの攻撃
/// </summary>
void PlayerAttack();

/// <summary>
/// 今回の方向入力バックアップを設定する
/// </summary>
/// <param name="value">左右の方向</param>
void SetLastestDirectionInput(int value);

/// <summary>
/// 前回の方向バックアップ内容を取得
/// </summary>
/// <returns>前回の方向バックアップ</returns>
int GetLastestDirectionInput();

/// <summary>
/// プレイヤーの情報をリセットする
/// </summary>
void ResetPlayerStatus();

/// <summary>
/// プレイヤーの生命値をリセットする
/// </summary>
void ResetPlayerHP();
