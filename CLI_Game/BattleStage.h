//------------------------------------------------------------------------
// ファイル名: BattleStage.h
// 機能: 戦闘地図に関しての処理
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// 戦闘地図を初期化する
/// </summary>
void InitBattleStage();

/// <summary>
/// ファイルから戦闘地図のデータを読み出す
/// </summary>
void LoadBattleStage();

/// <summary>
/// 戦闘地図を当シーンのカメラバッファに書き込む
/// </summary>
/// <param name="offset">戦闘地図配列の偏移量</param>
void DrawStageToCamBuffer(int offset);
