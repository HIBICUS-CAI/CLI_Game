#pragma once

#include "CustomizedApp.h"
#include "SceneNode.h"

void InitInputScene()
{
    CreateSceneNode(SCENENODE("input", NULL,
        SCENECAMERA(POSITION_2D(0, 0), 1, 1)));

    CreateUIO("input", POSITION_2D(1, 1), 118, 38, UIO_DESIGN::STRAIGHT,
        NULL, NULL, 1);
    GetUIObjByName("input")->AddText(UI_TEXT(POSITION_2D(3, 1),
        (char*)"プレイヤーのお名前："));
    GetUIObjByName("input")->AddText(UI_TEXT(POSITION_2D(3, 2),
        (char*)"攻撃ナカマのお名前："));
    GetUIObjByName("input")->AddText(UI_TEXT(POSITION_2D(3, 3),
        (char*)"強さナカマのお名前："));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(A_KANA,
        POSITION_2D(4, 6),
        (char*)"あ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(KA_KANA,
        POSITION_2D(11, 6),
        (char*)"か", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(SA_KANA,
        POSITION_2D(18, 6),
        (char*)"さ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(TA_KANA,
        POSITION_2D(25, 6),
        (char*)"た", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NA_KANA,
        POSITION_2D(32, 6),
        (char*)"な", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(HA_KANA,
        POSITION_2D(39, 6),
        (char*)"は", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(MA_KANA,
        POSITION_2D(46, 6),
        (char*)"ま", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(YA_KANA,
        POSITION_2D(53, 6),
        (char*)"や", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(RA_KANA,
        POSITION_2D(60, 6),
        (char*)"ら", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(WA_KANA,
        POSITION_2D(67, 6),
        (char*)"わ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NEXTSTR,
        POSITION_2D(82, 6),
        (char*)"つぎ", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(I_KANA,
        POSITION_2D(4, 8),
        (char*)"い", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(KI_KANA,
        POSITION_2D(11, 8),
        (char*)"き", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(SHI_KANA,
        POSITION_2D(18, 8),
        (char*)"し", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(CHI_KANA,
        POSITION_2D(25, 8),
        (char*)"ち", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NI_KANA,
        POSITION_2D(32, 8),
        (char*)"に", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(HI_KANA,
        POSITION_2D(39, 8),
        (char*)"ひ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(MI_KANA,
        POSITION_2D(46, 8),
        (char*)"み", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(RI_KANA,
        POSITION_2D(60, 8),
        (char*)"り", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(U_KANA,
        POSITION_2D(4, 10),
        (char*)"う", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(KU_KANA,
        POSITION_2D(11, 10),
        (char*)"く", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(SU_KANA,
        POSITION_2D(18, 10),
        (char*)"す", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(TSU_KANA,
        POSITION_2D(25, 10),
        (char*)"つ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NU_KANA,
        POSITION_2D(32, 10),
        (char*)"ぬ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(FU_KANA,
        POSITION_2D(39, 10),
        (char*)"ふ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(MU_KANA,
        POSITION_2D(46, 10),
        (char*)"む", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(YU_KANA,
        POSITION_2D(53, 10),
        (char*)"ゆ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(RU_KANA,
        POSITION_2D(60, 10),
        (char*)"る", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(WO_KANA,
        POSITION_2D(67, 10),
        (char*)"を", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(PREVIOUSSTR,
        POSITION_2D(82, 10),
        (char*)"まえ", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(E_KANA,
        POSITION_2D(4, 12),
        (char*)"え", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(KE_KANA,
        POSITION_2D(11, 12),
        (char*)"け", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(SE_KANA,
        POSITION_2D(18, 12),
        (char*)"せ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(TE_KANA,
        POSITION_2D(25, 12),
        (char*)"て", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NE_KANA,
        POSITION_2D(32, 12),
        (char*)"ね", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(HE_KANA,
        POSITION_2D(39, 12),
        (char*)"へ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(ME_KANA,
        POSITION_2D(46, 12),
        (char*)"め", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(RE_KANA,
        POSITION_2D(60, 12),
        (char*)"れ", BTN_DESIGN::LINE));

    GetUIObjByName("input")->AddBtn(UI_BUTTON(O_KANA,
        POSITION_2D(4, 14),
        (char*)"お", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(KO_KANA,
        POSITION_2D(11, 14),
        (char*)"こ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(SO_KANA,
        POSITION_2D(18, 14),
        (char*)"そ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(TO_KANA,
        POSITION_2D(25, 14),
        (char*)"と", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NO_KANA,
        POSITION_2D(32, 14),
        (char*)"の", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(HO_KANA,
        POSITION_2D(39, 14),
        (char*)"ほ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(MO_KANA,
        POSITION_2D(46, 14),
        (char*)"も", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(YO_KANA,
        POSITION_2D(53, 14),
        (char*)"よ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(RO_KANA,
        POSITION_2D(60, 14),
        (char*)"ろ", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(NN_KANA,
        POSITION_2D(67, 14),
        (char*)"ん", BTN_DESIGN::LINE));
    GetUIObjByName("input")->AddBtn(UI_BUTTON(STARTGAME,
        POSITION_2D(82, 14),
        (char*)"進む", BTN_DESIGN::LINE));

    SetSelectedBtn(GetUIObjByName("input")->Buttons);
    GetSceneNodeByName("input")->SetBaseUIO(GetUIObjByName("input"));
}

void UpdateInputScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("input"));
}
