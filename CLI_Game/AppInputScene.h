#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"

void InitInputScene()
{
    CreateSceneNode(SCENENODE("input", NULL,
        SCENECAMERA(POSITION_2D(50, 0), 1, 1)));

    CreateUIO("input", POSITION_2D(1, 1), 118, 38, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("input")->AddText(UI_TEXT(POSITION_2D(3, 1),
        (char*)"�ץ쥤��`�Τ���ǰ��"));
    GetUIObjByName("input")->AddText(UI_TEXT(POSITION_2D(3, 2),
        (char*)"���ĥʥ��ޤΤ���ǰ��"));
    GetUIObjByName("input")->AddText(UI_TEXT(POSITION_2D(3, 3),
        (char*)"�����ʥ��ޤΤ���ǰ��"));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(A_KANA,
        POSITION_2D(4, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(KA_KANA,
        POSITION_2D(11, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(SA_KANA,
        POSITION_2D(18, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(TA_KANA,
        POSITION_2D(25, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NA_KANA,
        POSITION_2D(32, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(HA_KANA,
        POSITION_2D(39, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(MA_KANA,
        POSITION_2D(46, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(YA_KANA,
        POSITION_2D(53, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(RA_KANA,
        POSITION_2D(60, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(WA_KANA,
        POSITION_2D(67, 6),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NEXTSTR,
        POSITION_2D(82, 6),
        (char*)"�Ĥ�", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(I_KANA,
        POSITION_2D(4, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(KI_KANA,
        POSITION_2D(11, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(SHI_KANA,
        POSITION_2D(18, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(CHI_KANA,
        POSITION_2D(25, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NI_KANA,
        POSITION_2D(32, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(HI_KANA,
        POSITION_2D(39, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(MI_KANA,
        POSITION_2D(46, 8),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(RI_KANA,
        POSITION_2D(60, 8),
        (char*)"��", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(U_KANA,
        POSITION_2D(4, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(KU_KANA,
        POSITION_2D(11, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(SU_KANA,
        POSITION_2D(18, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(TSU_KANA,
        POSITION_2D(25, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NU_KANA,
        POSITION_2D(32, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(FU_KANA,
        POSITION_2D(39, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(MU_KANA,
        POSITION_2D(46, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(YU_KANA,
        POSITION_2D(53, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(RU_KANA,
        POSITION_2D(60, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(WO_KANA,
        POSITION_2D(67, 10),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(PREVIOUSSTR,
        POSITION_2D(82, 10),
        (char*)"�ޤ�", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(E_KANA,
        POSITION_2D(4, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(KE_KANA,
        POSITION_2D(11, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(SE_KANA,
        POSITION_2D(18, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(TE_KANA,
        POSITION_2D(25, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NE_KANA,
        POSITION_2D(32, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(HE_KANA,
        POSITION_2D(39, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(ME_KANA,
        POSITION_2D(46, 12),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(RE_KANA,
        POSITION_2D(60, 12),
        (char*)"��", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(O_KANA,
        POSITION_2D(4, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(KO_KANA,
        POSITION_2D(11, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(SO_KANA,
        POSITION_2D(18, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(TO_KANA,
        POSITION_2D(25, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NO_KANA,
        POSITION_2D(32, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(HO_KANA,
        POSITION_2D(39, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(MO_KANA,
        POSITION_2D(46, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(YO_KANA,
        POSITION_2D(53, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(RO_KANA,
        POSITION_2D(60, 14),
        (char*)"��", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NN_KANA,
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

void ResetInputBtn()
{
    char kana[49][3] = {
        "��","��","��","��","��",
        "��","��","��","��","��","",
        "��","��","��","��","��",
        "��","��","��",
        "��","��","��","��","��",
        "��","��","��","��","��","",
        "��","��","��","��","��",
        "��","��","��",
        "��","��","��","��","��",
        "��","��","��","��","��",""
    };

    int event[49] = {
        A_KANA,KA_KANA,SA_KANA,TA_KANA,NA_KANA,
        HA_KANA,MA_KANA,YA_KANA,RA_KANA,WA_KANA,1,
        I_KANA,KI_KANA,SHI_KANA,CHI_KANA,NI_KANA,
        HI_KANA,MI_KANA,RI_KANA,
        U_KANA,KU_KANA,SU_KANA,TSU_KANA,NU_KANA,
        FU_KANA,MU_KANA,YU_KANA,RU_KANA,WO_KANA,1,
        E_KANA,KE_KANA,SE_KANA,TE_KANA,NE_KANA,
        HE_KANA,ME_KANA,RE_KANA,
        O_KANA,KO_KANA,SO_KANA,TO_KANA,NO_KANA,
        HO_KANA,MO_KANA,YO_KANA,RO_KANA,NN_KANA,1
    };

    for (int i = 0; i < 49; i++)
    {
        if (i != 10 && i != 29 && i != 48)
        {
            (GetUIObjByName("input")->Buttons + i)->Event = event[i];
            strcpy_s((GetUIObjByName("input")->Buttons + i)->Text,
                sizeof(char) * 3, kana[i]);
        }
    }

    SetInputCount(0);
}
