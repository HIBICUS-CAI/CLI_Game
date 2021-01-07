//------------------------------------------------------------------------
// �ե�������: AppMazeScene.h
// �C��: �Ԍm���`��������ȸ��¤ʤ�
//------------------------------------------------------------------------

#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"
#include "DeclaredObjects.h"

/// <summary>
/// ���`���Ҫ�ؤ�����
/// </summary>
void InitMazeScene()
{
    CreateSceneNode(SCENENODE("maze", NULL,
        SCENECAMERA(POSITION_2D(1, 1), 80, 39)));

    CreateUIO("maze", POSITION_2D(82, 1), 37, 39, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"Ending(E)���򤫤��ޤ��礦��"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 3),
        (char*)"��������10"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 4),
        (char*)"��������10"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 5),
        (char*)"��������10"));
    GetUIObjByName("maze")->AddBtn(UI_BUTTON(-1, POSITION_2D(2, 10),
        (char*)"�ƥ�����", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("maze")->AddBtn(UI_BUTTON(GIVEUPMAZE, POSITION_2D(2, 15),
        (char*)"GIVE UP", BTN_DESIGN::STRAIGHT));

    GetSceneNodeByName("maze")->SetBaseUIO(GetUIObjByName("maze"));
    SetSelectedBtn(GetUIObjByName("maze")->Buttons);
}

/// <summary>
/// ��Ҫ�ʤ�Τ���¤���
/// </summary>
void UpdateMazeScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("maze"));

    (GetUIObjByName("maze")->Texts + 1)->
        ChangeTextTo("������ ", GetPlayer()->HP);
    (GetUIObjByName("maze")->Texts + 2)->
        ChangeTextTo("������ ", GetPlayer()->ATK);
    (GetUIObjByName("maze")->Texts + 3)->
        ChangeTextTo("������ ", GetPlayer()->PUSH);
}

/// <summary>
/// ��Ҫ�ʤ�Τ��]����
/// </summary>
void CloseMazeScene()
{

}
