//------------------------------------------------------------------------
// �ե�������: AppBattleScene.h
// �C��: ���L���`��������ȸ��¤ʤ�
//------------------------------------------------------------------------

#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"
#include "DeclaredObjects.h"
#include "BattleEnemy.h"
#include "MazeEnemy.h"
#include "Player.h"

/// <summary>
/// ���`���Ҫ�ؤ�����
/// </summary>
void InitBattleScene()
{
    CreateSceneNode(SCENENODE("battle", NULL,
        SCENECAMERA(POSITION_2D(1, 1), CONSOLE_WIDTH - 2,
            CONSOLE_HEIGHT - 5)));

    CreateUIO("battle", POSITION_2D(1, CONSOLE_HEIGHT - 4),
        CONSOLE_WIDTH - 2, 4, UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("battle")->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"WASD���Ƅӡ�O�ǥ����ס�P�ǹ���"));
    GetUIObjByName("battle")->AddText(UI_TEXT(POSITION_2D(50, 1),
        (char*)"������ 10"));
    GetUIObjByName("battle")->AddText(UI_TEXT(POSITION_2D(60, 1),
        (char*)"������ 5"));
    GetUIObjByName("battle")->AddText(UI_TEXT(POSITION_2D(70, 1),
        (char*)"������ 3"));
    GetUIObjByName("battle")->AddBtn(UI_BUTTON(ENDBATTLE, POSITION_2D(3, 2),
        (char*)"�ƥ�����", BTN_DESIGN::LINE));

    GetSceneNodeByName("battle")->SetBaseUIO(GetUIObjByName("battle"));
    SetSelectedBtn(NULL);
}

/// <summary>
/// ��Ҫ�ʤ�Τ���¤���
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
        ChangeTextTo("������ ", GetPlayer()->HP);
    (GetUIObjByName("battle")->Texts + 2)->
        ChangeTextTo("������ ", GetPlayer()->ATK);
    (GetUIObjByName("battle")->Texts + 3)->
        ChangeTextTo("������ ", GetPlayer()->PUSH);
}

/// <summary>
/// ��Ҫ�ʤ�Τ��]����
/// </summary>
void CloseBattleScene()
{

}
