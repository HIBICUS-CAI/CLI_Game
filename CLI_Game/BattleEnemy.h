//------------------------------------------------------------------------
// ファイル名: BattleEnemy.h
// 機能: 戦闘敵に関しての処理
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// 戦闘敵配列を初期化する
/// </summary>
void InitBattleEnemy();

/// <summary>
/// 戦闘敵を更新する
/// </summary>
void UpdateBattleEnemy();

/// <summary>
/// 戦闘敵を当シーンのカメラバッファに書き込む
/// </summary>
void DrawBattleEnemyToCamBuffer();

/// <summary>
/// 戦闘敵の初期位置を乱数で設定
/// </summary>
void SetEnemyToBattleRandomly();

/// <summary>
/// 戦闘敵を全部削除
/// </summary>
void ClearBattleEnemyArray();

/// <summary>
/// 全ての戦闘敵を不可視的になる
/// </summary>
void TurnOffAllBattleEnemy();

/// <summary>
/// 全ての戦闘敵を可視的になる
/// </summary>
void TurnOnAllBattleEnemy();

/// <summary>
/// プレイヤーの攻撃より撃退
/// </summary>
/// <param name="enemy">戦闘敵指向のポインタ</param>
/// <param name="direction">撃退の方向</param>
void PushEnemyByPlayer(BATTLEENEMY* enemy, int direction);
