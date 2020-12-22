#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"

void InitSelectionScene()
{
    CreateSceneNode(SCENENODE("selection", NULL,
        SCENECAMERA(POSITION_2D(10, 5), 50, 17)));

    CreateUIO("selection", POSITION_2D(10, 24), 50, 10, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(-1, POSITION_2D(2, 3),
        (char*)"¥¹¥Æ©`¥¸£±", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(-1, POSITION_2D(15, 3),
        (char*)"¥¹¥Æ©`¥¸£²", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(-1, POSITION_2D(28, 3),
        (char*)"¥¹¥Æ©`¥¸£³", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(CLOSESELECT, POSITION_2D(40, 8),
        (char*)"é]¤¸¤ë", BTN_DESIGN::LINE));

    SetSelectedBtn(GetUIObjByName("selection")->Buttons);
    GetSceneNodeByName("selection")->SetBaseUIO(GetUIObjByName("selection"));
}

void UpdateSelectionScene()
{
    char* temp = GetSceneNodeByName("selection")->GetCamAddr()->GetCamBuffer();
    int width = GetSceneNodeByName("selection")->GetCamAddr()->CameraWidth;
    int height = GetSceneNodeByName("selection")->GetCamAddr()->CameraHeight;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(temp + i * width + j) = ' ';
        }
    }

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

void CloseSelectionScene()
{

}
