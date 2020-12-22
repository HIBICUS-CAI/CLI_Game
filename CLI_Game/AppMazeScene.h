#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"

void InitMazeScene()
{
    CreateSceneNode(SCENENODE("maze", NULL,
        SCENECAMERA(POSITION_2D(1, 1), 80, 39)));

    CreateUIO("maze", POSITION_2D(82, 1), 37, 39, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"¥á¥¤¥ó£Õ£É"));
    GetUIObjByName("maze")->AddBtn(UI_BUTTON(-1, POSITION_2D(2, 10),
        (char*)"¥Æ¥¹¥ÈÓÃ", BTN_DESIGN::STRAIGHT));

    GetSceneNodeByName("maze")->SetBaseUIO(GetUIObjByName("maze"));
    SetSelectedBtn(GetUIObjByName("maze")->Buttons);
}

void UpdateMazeScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("maze"));
}

void CloseMazeScene()
{

}
