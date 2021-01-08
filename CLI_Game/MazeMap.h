//------------------------------------------------------------------------
// ファイル名: MazeMap.h
// 機能: 迷宮のマップに関しての処理
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// 迷宮を初期化する
/// </summary>
void InitMazeMap();

/// <summary>
/// 迷宮のデータを書き込む
/// </summary>
void LoadMazeMap();

/// <summary>
/// あるファイルから迷宮の設計を読み出す
/// </summary>
/// <param name="fileName">迷宮ファイル</param>
void LoadInfoFromFile(const char* fileName);

/// <summary>
/// 迷宮を更新する
/// </summary>
void UpdateMazeMap();
