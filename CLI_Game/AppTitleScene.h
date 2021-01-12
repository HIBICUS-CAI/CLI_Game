//------------------------------------------------------------------------
// �t�@�C����: AppTitleScene.h
// �@�\: �^�C�g���V�[���̐����ƍX�V�Ȃ�
//------------------------------------------------------------------------

#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"

//----------------------------------
float test = 0.f;
int testflag = 1;

/// <summary>
/// �V�[���̗v�f�����
/// </summary>
void InitTitleScene()
{
    CreateSceneNode(SCENENODE("title", NULL,
        SCENECAMERA(POSITION_2D(2, 2), 20, 17)));

    CreateUIO("title", POSITION_2D(20, 20), 20, 6, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("title")->AddBtn(UI_BUTTON(INPUTINFO, POSITION_2D(6, 2),
        (char*)"�J�n", BTN_DESIGN::LINE));
    GetUIObjByName("title")->AddBtn(UI_BUTTON(GAMEHELP, POSITION_2D(6, 4),
        (char*)"����", BTN_DESIGN::LINE));
    GetUIObjByName("title")->AddText(UI_TEXT(POSITION_2D(6, 8),
        (char*)"[IJKL�Ń{�^����I��������]"));
    GetUIObjByName("title")->AddText(UI_TEXT(POSITION_2D(6, 9),
        (char*)"[SPACE�Ń{�^�������s������]"));

    CreateUIO("help", POSITION_2D(20, 20), 40, 6, UIO_DESIGN::STAR,
        GetUIObjByName("title"));
    GetUIObjByName("help")->AddText(UI_TEXT(POSITION_2D(3, 1),
        (char*)"WASD�Ől�����ړ�������"));
    GetUIObjByName("help")->AddText(UI_TEXT(POSITION_2D(3, 2),
        (char*)"IJKL�Ń{�^����I��������"));
    GetUIObjByName("help")->AddText(UI_TEXT(POSITION_2D(3, 3),
        (char*)"SPACE�Ń{�^�������s������"));
    GetUIObjByName("help")->AddBtn(UI_BUTTON(CLOSEHELP, POSITION_2D(15, 5),
        (char*)"����", BTN_DESIGN::LINE));
    GetUIObjByName("title")->AddChild(GetUIObjByName("help"));

    SetSelectedBtn(GetUIObjByName("title")->Buttons);
    GetSceneNodeByName("title")->SetBaseUIO(GetUIObjByName("title"));
}

/// <summary>
/// �K�v�Ȃ��̂��X�V����
/// </summary>
void UpdateTitleScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("title"));

    char* temp = GetSceneNodeByName("title")->GetCamAddr()->GetCamBuffer();
    for (int i = 0; i < GetSceneNodeByName("title")->GetCamAddr()->CameraHeight; i++)
    {
        for (int j = 0; j < GetSceneNodeByName("title")->GetCamAddr()->CameraWidth; j++)
        {
            *(temp + i * GetSceneNodeByName("title")->GetCamAddr()->CameraWidth + j) = '*';
        }
    }

    if (testflag)
    {
        for (int i = 0 + 4; i < 8 + 4; i++)
        {
            for (int j = 0 + 5; j < 10 + 5; j++)
            {
                *(temp + i * GetSceneNodeByName("title")->
                    GetCamAddr()->CameraWidth + j) = '-';
            }
        }

        test += (float)50.f / DELTATIME;
        if (test >= 100.f)
        {
            testflag = 0;
        }
    }
    else
    {
        for (int i = 0 + 4; i < 8 + 4; i++)
        {
            for (int j = 0 + 5; j < 10 + 5; j++)
            {
                *(temp + i * GetSceneNodeByName("title")->
                    GetCamAddr()->CameraWidth + j) = '|';
            }
        }
        test -= (float)50.f / DELTATIME;
        if (test <= 0.f)
        {
            testflag = 1;
        }
    }
}

/// <summary>
/// �K�v�Ȃ��̂��폜�A����
/// </summary>
void CloseTitleScene()
{

}
