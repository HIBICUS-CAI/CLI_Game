//------------------------------------------------------------------------
// ファイル名: StartEndPoint.h
// 機能: 始点と終点の機能
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// 始点と終点を初期化する
/// </summary>
void InitStartEndPoint();

/// <summary>
/// 更新で到着かどうかを確認
/// </summary>
void UpdateStartEndPoint();

/// <summary>
/// 始点をある位置に設定する
/// </summary>
/// <param name="pos">位置の座標</param>
void SetStartPointPos(POSITION_2D pos);

/// <summary>
/// 終点をある位置に設定する
/// </summary>
/// <param name="pos">位置の座標</param>
void SetEndPointPos(POSITION_2D pos);
