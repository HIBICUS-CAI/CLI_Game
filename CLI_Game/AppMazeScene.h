#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"
#include "DeclaredObjects.h"

void InitMazeScene()
{
    CreateSceneNode(SCENENODE("maze", NULL,
        SCENECAMERA(POSITION_2D(1, 1), 80, 39)));

    CreateUIO("maze", POSITION_2D(82, 1), 37, 39, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"Ending(E)へ�鬚�いましょう��"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 3),
        (char*)"伏凋�｡�10"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 4),
        (char*)"好�珍Α�10"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 5),
        (char*)"�塚冒Α�10"));
    GetUIObjByName("maze")->AddBtn(UI_BUTTON(-1, POSITION_2D(2, 10),
        (char*)"テスト喘", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("maze")->AddBtn(UI_BUTTON(GIVEUPMAZE, POSITION_2D(2, 15),
        (char*)"GIVE UP", BTN_DESIGN::STRAIGHT));

    GetSceneNodeByName("maze")->SetBaseUIO(GetUIObjByName("maze"));
    SetSelectedBtn(GetUIObjByName("maze")->Buttons);
}

void UpdateMazeScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("maze"));

    (GetUIObjByName("maze")->Texts + 1)->
        ChangeTextTo("伏凋�� ", GetPlayer()->HP);
    (GetUIObjByName("maze")->Texts + 2)->
        ChangeTextTo("好�珍� ", GetPlayer()->ATK);
    (GetUIObjByName("maze")->Texts + 3)->
        ChangeTextTo("�塚冒� ", GetPlayer()->PUSH);
}

void CloseMazeScene()
{

}
