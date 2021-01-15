//------------------------------------------------------------------------
// �t�@�C����: AppStageSelectScene.h
// �@�\: �X�e�[�W�I���V�[���̐����ƍX�V�Ȃ�
//------------------------------------------------------------------------

#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"
#include "DeclaredObjects.h"


/// <summary>
/// �V�[���̗v�f�����
/// </summary>
void InitSelectionScene()
{
    CreateSceneNode(SCENENODE("selection", NULL,
        SCENECAMERA(POSITION_2D(35, 5), 50, 17)));

    CreateUIO("selection", POSITION_2D(35, 24), 60, 15, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);

    GetUIObjByName("selection")->AddText(UI_TEXT(POSITION_2D(2, 10),
        (char*)"�����l�@10"));
    GetUIObjByName("selection")->AddText(UI_TEXT(POSITION_2D(22, 10),
        (char*)"�U���́@10"));
    GetUIObjByName("selection")->AddText(UI_TEXT(POSITION_2D(42, 10),
        (char*)"���ޗ́@10"));

    GetUIObjByName("selection")->AddBtn(UI_BUTTON(GETINMAZE1, POSITION_2D(6, 3),
        (char*)"�X�e�[�W�P", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(GETINMAZE2, POSITION_2D(19, 3),
        (char*)"�X�e�[�W�Q", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(GETINMAZE3, POSITION_2D(32, 3),
        (char*)"�X�e�[�W�R", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("selection")->AddBtn(UI_BUTTON(CLOSESELECT, POSITION_2D(50, 8),
        (char*)"����", BTN_DESIGN::LINE));

    CreateUIO("after-clear", POSITION_2D(35, 20), 50, 10, UIO_DESIGN::STAR,
        GetUIObjByName("selection"));
    GetUIObjByName("after-clear")->AddText(UI_TEXT(POSITION_2D(3, 1),
        (char*)"�X�e�[�W�N���A���܂����I"));
    GetUIObjByName("after-clear")->AddText(UI_TEXT(POSITION_2D(3, 2),
        (char*)"���߂łƂ��������܂��I"));
    GetUIObjByName("after-clear")->AddBtn(UI_BUTTON(CLOSECLEARUP, POSITION_2D(15, 5),
        (char*)"����", BTN_DESIGN::LINE));
    GetUIObjByName("selection")->AddChild(GetUIObjByName("after-clear"));

    SetSelectedBtn(GetUIObjByName("selection")->Buttons);
    GetSceneNodeByName("selection")->SetBaseUIO(GetUIObjByName("selection"));
}

/// <summary>
/// �K�v�Ȃ��̂��X�V����
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

    (GetUIObjByName("selection")->Texts + 0)->
        ChangeTextTo("�����l ", GetPlayer()->HP);
    (GetUIObjByName("selection")->Texts + 1)->
        ChangeTextTo("�U���� ", GetPlayer()->ATK);
    (GetUIObjByName("selection")->Texts + 2)->
        ChangeTextTo("���ޗ� ", GetPlayer()->PUSH);
}

/// <summary>
/// �K�v�Ȃ��̂����
/// </summary>
void CloseSelectionScene()
{

}
