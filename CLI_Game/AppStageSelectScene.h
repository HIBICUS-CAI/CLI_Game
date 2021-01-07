//------------------------------------------------------------------------
// ファイル名: AppStageSelectScene.h
// 機能: ステージ選択シーンの声明と更新など
//------------------------------------------------------------------------

#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"


/// <summary>
/// シーンの要素を作る
/// </summary>
void InitSelectionScene()
{
    CreateSceneNode(SCENENODE("selection", NULL,
        SCENECAMERA(POSITION_2D(10, 5), 50, 17)));

    CreateUIO("selection", POSITION_2D(10, 24), 50, 10, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(GETINMAZE1, POSITION_2D(2, 3),
        (char*)"ステージ１", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(GETINMAZE2, POSITION_2D(15, 3),
        (char*)"ステージ２", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(GETINMAZE3, POSITION_2D(28, 3),
        (char*)"ステージ３", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(CLOSESELECT, POSITION_2D(40, 8),
        (char*)"閉じる", BTN_DESIGN::LINE));

    CreateUIO("after-clear", POSITION_2D(20, 20), 50, 10, UIO_DESIGN::STAR,
        GetUIObjByName("selection"));
    GetUIObjByName("after-clear")->AddText(UI_TEXT(POSITION_2D(3, 1),
        (char*)"ステージクリアしました！"));
    GetUIObjByName("after-clear")->AddText(UI_TEXT(POSITION_2D(3, 2),
        (char*)"おめでとうございます！"));
    GetUIObjByName("after-clear")->AddBtn(UI_BUTTON(CLOSECLEARUP, POSITION_2D(15, 5),
        (char*)"閉じる", BTN_DESIGN::LINE));
    GetUIObjByName("selection")->AddChild(GetUIObjByName("after-clear"));

    SetSelectedBtn(GetUIObjByName("selection")->Buttons);
    GetSceneNodeByName("selection")->SetBaseUIO(GetUIObjByName("selection"));
}

/// <summary>
/// 必要なものを更新する
/// </summary>
void UpdateSelectionScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("selection"));
    char* temp = GetSceneNodeByName("selection")->GetCamAddr()->GetCamBuffer();
    int width = GetSceneNodeByName("selection")->GetCamAddr()->CameraWidth;
    int height = GetSceneNodeByName("selection")->GetCamAddr()->CameraHeight;

    *(temp + 8 * width + 14) = '1';
    *(temp + 8 * width + 15) = '1';
    *(temp + 8 * width + 16) = '1';
    *(temp + 8 * width + 24) = '2';
    *(temp + 8 * width + 25) = '2';
    *(temp + 8 * width + 26) = '2';
    *(temp + 8 * width + 34) = '3';
    *(temp + 8 * width + 35) = '3';
    *(temp + 8 * width + 36) = '3';
}

/// <summary>
/// 必要なものを閉じる
/// </summary>
void CloseSelectionScene()
{

}
