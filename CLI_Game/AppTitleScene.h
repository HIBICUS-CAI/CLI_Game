//------------------------------------------------------------------------
// �ե�������: AppTitleScene.h
// �C��: �����ȥ륷�`��������ȸ��¤ʤ�
//------------------------------------------------------------------------

#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"

//----------------------------------
float test = 0.f;
int testflag = 1;

/// <summary>
/// ���`���Ҫ�ؤ�����
/// </summary>
void InitTitleScene()
{
    CreateSceneNode(SCENENODE("title", NULL,
        SCENECAMERA(POSITION_2D(2, 2), 20, 17)));

    CreateUIO("title", POSITION_2D(20, 20), 20, 6, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("title")->AddBtn(UI_BUTTON(INPUTINFO, POSITION_2D(6, 2),
        (char*)"�_ʼ", BTN_DESIGN::LINE));
    GetUIObjByName("title")->AddBtn(UI_BUTTON(GAMEHELP, POSITION_2D(6, 4),
        (char*)"�h��", BTN_DESIGN::LINE));
    GetUIObjByName("title")->AddText(UI_TEXT(POSITION_2D(6, 8),
        (char*)"[IJKL�ǥܥ�����x�k������]"));
    GetUIObjByName("title")->AddText(UI_TEXT(POSITION_2D(6, 9),
        (char*)"[SPACE�ǥܥ����g�Ф�����]"));

    CreateUIO("help", POSITION_2D(20, 20), 40, 6, UIO_DESIGN::STAR,
        GetUIObjByName("title"));
    GetUIObjByName("help")->AddText(UI_TEXT(POSITION_2D(3, 1),
        (char*)"WASD��������ƄӤ�����"));
    GetUIObjByName("help")->AddText(UI_TEXT(POSITION_2D(3, 2),
        (char*)"IJKL�ǥܥ�����x�k������"));
    GetUIObjByName("help")->AddText(UI_TEXT(POSITION_2D(3, 3),
        (char*)"SPACE�ǥܥ����g�Ф�����"));
    GetUIObjByName("help")->AddBtn(UI_BUTTON(CLOSEHELP, POSITION_2D(15, 5),
        (char*)"�]����", BTN_DESIGN::LINE));
    GetUIObjByName("title")->AddChild(GetUIObjByName("help"));

    SetSelectedBtn(GetUIObjByName("title")->Buttons);
    GetSceneNodeByName("title")->SetBaseUIO(GetUIObjByName("title"));
}

/// <summary>
/// ��Ҫ�ʤ�Τ���¤���
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
/// ��Ҫ�ʤ�Τ��������]����
/// </summary>
void CloseTitleScene()
{

}
