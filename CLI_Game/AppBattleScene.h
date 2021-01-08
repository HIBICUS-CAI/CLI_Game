//------------------------------------------------------------------------
// ファイル名: AppBattleScene.h
// 機能: 戦闘シーンの声明と更新など
//------------------------------------------------------------------------

#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"
#include "DeclaredObjects.h"
#include "BattleEnemy.h"
#include "MazeEnemy.h"
#include "Player.h"

/// <summary>
/// シーンの要素を作る
/// </summary>
void InitBattleScene()
{
    CreateSceneNode(SCENENODE("battle", NULL,
        SCENECAMERA(POSITION_2D(1, 1), CONSOLE_WIDTH - 2,
            CONSOLE_HEIGHT - 5)));

    CreateUIO("battle", POSITION_2D(1, CONSOLE_HEIGHT - 4),
        CONSOLE_WIDTH - 2, 4, UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("battle")->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"WASDで移動　Oでジャンプ　Pで攻撃"));
    GetUIObjByName("battle")->AddText(UI_TEXT(POSITION_2D(50, 1),
        (char*)"生命値 10"));
    GetUIObjByName("battle")->AddText(UI_TEXT(POSITION_2D(60, 1),
        (char*)"攻撃力 5"));
    GetUIObjByName("battle")->AddText(UI_TEXT(POSITION_2D(70, 1),
        (char*)"撃退力 3"));
    GetUIObjByName("battle")->AddBtn(UI_BUTTON(ENDBATTLE, POSITION_2D(3, 2),
        (char*)"テスト用", BTN_DESIGN::LINE));

    GetSceneNodeByName("battle")->SetBaseUIO(GetUIObjByName("battle"));
    SetSelectedBtn(NULL);
}

/// <summary>
/// 必要なものを更新する
/// </summary>
void UpdateBattleScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("battle"));

    int height = GetSceneNodeByName("battle")->GetCamAddr()->CameraHeight;
    int width = GetSceneNodeByName("battle")->GetCamAddr()->CameraWidth;
    char* buffer = GetSceneNodeByName("battle")->GetCamAddr()->GetCamBuffer();
    for (int i = 0; i < width; i++)
    {
        *(buffer + i) = '*';
        *(buffer + (height - 1) * width + i) = '*';
    }
    for (int i = 0; i < height - 2; i++)
    {
        *(buffer + (i + 1) * width) = '*';
        *(buffer + (i + 1) * width + width - 1) = '*';
    }

    (GetUIObjByName("battle")->Texts + 1)->
        ChangeTextTo("生命値 ", GetPlayer()->HP);
    (GetUIObjByName("battle")->Texts + 2)->
        ChangeTextTo("攻撃力 ", GetPlayer()->ATK);
    (GetUIObjByName("battle")->Texts + 3)->
        ChangeTextTo("撃退力 ", GetPlayer()->PUSH);
}

/// <summary>
/// 必要なものを閉じる
/// </summary>
void CloseBattleScene()
{

}
