//------------------------------------------------------------------------
// �t�@�C����: AppMazeScene.h
// �@�\: ���{�V�[���̐����ƍX�V�Ȃ�
//------------------------------------------------------------------------

#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"
#include "DeclaredObjects.h"

/// <summary>
/// �V�[���̗v�f�����
/// </summary>
void InitMazeScene()
{
    CreateSceneNode(SCENENODE("maze", NULL,
        SCENECAMERA(POSITION_2D(1, 1), 80, 39)));

    CreateUIO("maze", POSITION_2D(82, 1), 37, 39, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"Ending(E)�֌������܂��傤�I"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 3),
        (char*)"�����l�@10"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 4),
        (char*)"�U���́@10"));
    GetUIObjByName("maze")->AddText(UI_TEXT(POSITION_2D(2, 5),
        (char*)"���ޗ́@10"));
    GetUIObjByName("maze")->AddBtn(UI_BUTTON(-1, POSITION_2D(2, 10),
        (char*)"�e�X�g�p", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("maze")->AddBtn(UI_BUTTON(GIVEUPMAZE, POSITION_2D(2, 15),
        (char*)"GIVE UP", BTN_DESIGN::STRAIGHT));

    GetSceneNodeByName("maze")->SetBaseUIO(GetUIObjByName("maze"));
    SetSelectedBtn(GetUIObjByName("maze")->Buttons);
}

/// <summary>
/// �K�v�Ȃ��̂��X�V����
/// </summary>
void UpdateMazeScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("maze"));

    (GetUIObjByName("maze")->Texts + 1)->
        ChangeTextTo("�����l ", GetPlayer()->HP);
    (GetUIObjByName("maze")->Texts + 2)->
        ChangeTextTo("�U���� ", GetPlayer()->ATK);
    (GetUIObjByName("maze")->Texts + 3)->
        ChangeTextTo("���ޗ� ", GetPlayer()->PUSH);
}

/// <summary>
/// �K�v�Ȃ��̂����
/// </summary>
void CloseMazeScene()
{

}
