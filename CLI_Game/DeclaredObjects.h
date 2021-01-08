//------------------------------------------------------------------------
// ファイル名: DeclaredObjects.h
// 機能: 上階グローバル変数の声明
//------------------------------------------------------------------------

#pragma once

#include "ObjectStruct.h"

/// <summary>
/// プレイヤーを取得
/// </summary>
/// <returns>プレイヤー指向のポインタ</returns>
PLAYER* GetPlayer();

/// <summary>
/// ステージ番号を取得
/// </summary>
/// <returns>ステージの番号</returns>
int GetStageID();

/// <summary>
/// ステージの番号を設定
/// </summary>
/// <param name="id">ステージの番号</param>
void SetStageID(int id);

/// <summary>
/// 今は迷宮部分を行うかどうか
/// </summary>
/// <returns>迷宮部分やっている標識</returns>
int IsPlayingMaze();

/// <summary>
/// 今は迷宮部分を行うかどうかを設定
/// </summary>
/// <param name="value">やっている標識或いはやっていない標識</param>
void SetIsPlayingMaze(int value);

/// <summary>
/// 迷宮を取得
/// </summary>
/// <returns>迷宮指向のポインタ</returns>
MAZEMAP* GetMazeMap();

/// <summary>
/// 始点と終点を取得
/// </summary>
/// <returns>始点と終点の配列</returns>
STARTENDPOINT* GetStartEndPointArray();

#define MAZEENEMYSIZE 50
/// <summary>
/// 迷宮敵を取得
/// </summary>
/// <returns>迷宮敵の配列</returns>
MAZEENEMY* GetMazeEnemyArray();

/// <summary>
/// 今は戦闘部分を行うかどうか
/// </summary>
/// <returns>戦闘部分やっている標識</returns>
int IsPlayingBattle();

/// <summary>
/// 今は戦闘部分を行うかどうかを設定
/// </summary>
/// <param name="value">やっている標識或いはやっていない標識</param>
void SetIsPlayingBattle(int value);

#define BATTLESTAGEWIDTH 116
#define BATTLESTAGEHEIGHT 33
#define BATTLESTAGECOUNT 3
/// <summary>
/// 戦闘地図を取得
/// </summary>
/// <param name="offset">偏移量</param>
/// <returns>ある戦闘地図指向のポインタ</returns>
char* GetBattleStageByOffset(int offset);

/// <summary>
/// 地図偏移量を取得
/// </summary>
/// <returns>地図配列の偏移量</returns>
int GetBattleStageToOffset();

/// <summary>
/// 使う地図の番号を乱数で設定
/// </summary>
void RandomlySetBattleStageOffset();

#define BATTLEENEMYSIZE 50
/// <summary>
/// 戦闘敵の配列を取得
/// </summary>
/// <returns>戦闘敵の配列</returns>
BATTLEENEMY* GetBattleEnemyArray();

/// <summary>
/// プレイヤーの名前を取得
/// </summary>
/// <returns>プレイヤーの名前</returns>
char* GetPlayerName();

/// <summary>
/// プレイヤーの名前を設定
/// </summary>
/// <param name="name">設定したい文字配列</param>
void SetPlayerName(char* name);

/// <summary>
/// プレイヤーの生命値を取得
/// </summary>
/// <returns>プレイヤーの生命値</returns>
int GetInputHP();

/// <summary>
/// プレイヤーの生命値を設定
/// </summary>
/// <param name="hp">設定したい値</param>
void SetInputHP(int hp);

/// <summary>
/// プレイヤーの攻撃力を取得
/// </summary>
/// <returns>プレイヤーの攻撃力</returns>
int GetInputATK();

/// <summary>
/// プレイヤーの攻撃力を設定
/// </summary>
/// <param name="atk">設定したい値</param>
void SetInputATK(int atk);

/// <summary>
/// プレイヤーの撃退力を取得
/// </summary>
/// <returns>プレイヤーの撃退力</returns>
int GetInputPUSH();

/// <summary>
/// プレイヤーの撃退力を設定
/// </summary>
/// <param name="push">設定したい値</param>
void SetInputPUSH(int push);

/// <summary>
/// 今は名前を入力しているかどうか
/// </summary>
/// <returns>入力している標識</returns>
int IsInputting();

/// <summary>
/// 今は名前を入力しているかどうかを設定
/// </summary>
/// <param name="value">しているかどうかの標識</param>
void SetIsInputting(int value);

/// <summary>
/// 入力している文字内容を取得
/// </summary>
/// <returns>文字内容指向のポインタ</returns>
UI_TEXT* GetInputtingStr();

/// <summary>
/// 入力している文字内容を設定
/// </summary>
/// <param name="text">文字内容指向のポインタ</param>
void SetInputtingStr(UI_TEXT* text);

/// <summary>
/// 入力番号を取得
/// </summary>
/// <returns>入力番号</returns>
int GetInputIndex();

/// <summary>
/// 入力番号を設定
/// </summary>
/// <param name="value">入力番号</param>
void SetInputIndex(int value);

/// <summary>
/// 入力された文字の数を取得
/// </summary>
/// <returns>入力された文字数</returns>
int GetInputCount();

/// <summary>
/// 入力された文字の数を設定
/// </summary>
/// <param name="value">入力された文字数</param>
void SetInputCount(int value);
