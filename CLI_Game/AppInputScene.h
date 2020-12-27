#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"

void InitInputScene()
{
    FILE* pFile = NULL;
    fopen_s(&pFile, "katagana.txt", "r");
    if (pFile == NULL)
    {
        ErrorLog("cannot open file");
        return;
    }
    int kanaCount = 48;
    char kana[48][3];
    for (int i = 0; i < kanaCount; i++)
    {
        fscanf_s(pFile, "%s", *(kana + i), 3);
    }
    fclose(pFile);

    CreateSceneNode(SCENENODE("input", NULL,
        SCENECAMERA(POSITION_2D(0, 0), 1, 1)));

    CreateUIO("input", POSITION_2D(1, 1), 118, 38, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("input")->AddText(UI_TEXT(POSITION_2D(3, 1),
        (char*)"�ץ쥤��`�Τ���ǰ��"));
    GetUIObjByName("input")->AddText(UI_TEXT(POSITION_2D(3, 2),
        (char*)"���ĥʥ��ޤΤ���ǰ��"));
    GetUIObjByName("input")->AddText(UI_TEXT(POSITION_2D(3, 3),
        (char*)"�����ʥ��ޤΤ���ǰ��"));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(4, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(11, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(18, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(25, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(32, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(39, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(46, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(53, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(60, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(67, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(82, 6),
        (char*)"�Ĥ�", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(4, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(11, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(18, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(25, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(32, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(39, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(46, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(60, 8),
        (char*)"��", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(4, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(11, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(18, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(25, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(32, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(39, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(46, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(53, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(60, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(67, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(82, 10),
        (char*)"�ޤ�", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(4, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(11, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(18, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(25, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(32, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(39, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(46, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(60, 12),
        (char*)"��", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(4, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(11, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(18, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(25, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(32, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(39, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(46, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(53, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(60, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(-1,
        POSITION_2D(67, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(STARTGAME,
        POSITION_2D(82, 14),
        (char*)"�M��", BTN_DESIGN::LINE));

    SetSelectedBtn(GetUIObjByName("input")->Buttons);
    GetSceneNodeByName("input")->SetBaseUIO(GetUIObjByName("input"));
}

void UpdateInputScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("input"));
}
