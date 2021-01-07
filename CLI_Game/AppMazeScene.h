//------------------------------------------------------------------------
// ファイル名: AppMazeScene.h
// 機能: 迷宮シーンの声明と更新など
//------------------------------------------------------------------------

#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"
#include "DeclaredObjects.h"

/// <summary>
/// シーンの要素を作る
/// </summary>
void InitMazeScene()
{
    CreateSceneNode(SCENENODE("maze", NULL,
        SCENECAMERA(POSITION_2D(1, 1), 80, 39)));

    CreateUIO("maze", POSITION_2D(82, 1), 37, 39, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"Ending(E)へ向かいましょう！"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 3),
        (char*)"生命値　10"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 4),
        (char*)"攻撃力　10"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 5),
        (char*)"撃退力　10"));
    GetUIObjByName("maze")->AddBtn(UI_BUTTON(-1, POSITION_2D(2, 10),
        (char*)"テスト用", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("maze")->AddBtn(UI_BUTTON(GIVEUPMAZE, POSITION_2D(2, 15),
        (char*)"GIVE UP", BTN_DESIGN::STRAIGHT));

    GetSceneNodeByName("maze")->SetBaseUIO(GetUIObjByName("maze"));
    SetSelectedBtn(GetUIObjByName("maze")->Buttons);
}

/// <summary>
/// 必要なものを更新する
/// </summary>
void UpdateMazeScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("maze"));

    (GetUIObjByName("maze")->Texts + 1)->
        ChangeTextTo("生命値 ", GetPlayer()->HP);
    (GetUIObjByName("maze")->Texts + 2)->
        ChangeTextTo("攻撃力 ", GetPlayer()->ATK);
    (GetUIObjByName("maze")->Texts + 3)->
        ChangeTextTo("撃退力 ", GetPlayer()->PUSH);
}

/// <summary>
/// 必要なものを閉じる
/// </summary>
void CloseMazeScene()
{

}
