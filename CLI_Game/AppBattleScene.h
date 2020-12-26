#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"

void InitBattleScene()
{
    CreateSceneNode(SCENENODE("battle", NULL,
        SCENECAMERA(POSITION_2D(1, 1), CONSOLE_WIDTH - 2,
            CONSOLE_HEIGHT - 5)));

    CreateUIO("battle", POSITION_2D(1, CONSOLE_HEIGHT - 4),
        CONSOLE_WIDTH - 2, 4, UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("battle")->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"WASD¤ÇÒÆ„Ó¡¡O¤Ç¥¸¥ã¥ó¥×¡¡P¤Ç¹¥“Ä"));
    GetUIObjByName("battle")->AddBtn(UI_BUTTON(ENDBATTLE, POSITION_2D(3, 2),
        (char*)"¥Æ¥¹¥ÈÓÃ", BTN_DESIGN::LINE));

    GetSceneNodeByName("battle")->SetBaseUIO(GetUIObjByName("battle"));
    SetSelectedBtn(NULL);
}

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
}

void CloseBattleScene()
{

}
