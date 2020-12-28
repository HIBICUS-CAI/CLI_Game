#pragma once
#include "GameAppStructs.h"

#define STARTGAME 0x0003
#define GAMEHELP 0x0004
#define CLOSEHELP 0x0005
#define CLOSESELECT 0x0006
#define GETINMAZE1 0x0007
#define GETINMAZE2 0x0008
#define GETINMAZE3 0x0009
#define GIVEUPMAZE 0x000a
#define CLOSECLEARUP 0x000b
#define ENDBATTLE 0x000c
#define INPUTINFO 0x000d
#define PREVIOUSSTR 0x000e
#define NEXTSTR 0x000f

#define A_KANA 0x0010
#define I_KANA 0x0011
#define U_KANA 0x0012
#define E_KANA 0x0013
#define O_KANA 0x0014
#define KA_KANA 0x0015
#define KI_KANA 0x0016
#define KU_KANA 0x0017
#define KE_KANA 0x0018
#define KO_KANA 0x0019
#define SA_KANA 0x001a
#define SHI_KANA 0x001b
#define SU_KANA 0x001c
#define SE_KANA 0x001d
#define SO_KANA 0x001e
#define TA_KANA 0x001f
#define CHI_KANA 0x0020
#define TSU_KANA 0x0021
#define TE_KANA 0x0022
#define TO_KANA 0x0023
#define NA_KANA 0x0024
#define NI_KANA 0x0025
#define NU_KANA 0x0026
#define NE_KANA 0x0027
#define NO_KANA 0x0028
#define HA_KANA 0x0029
#define HI_KANA 0x002a
#define FU_KANA 0x002b
#define HE_KANA 0x002c
#define HO_KANA 0x002d
#define MA_KANA 0x002e
#define MI_KANA 0x002f
#define MU_KANA 0x0030
#define ME_KANA 0x0031
#define MO_KANA 0x0032
#define YA_KANA 0x0033
#define YU_KANA 0x0034
#define YO_KANA 0x0035
#define RA_KANA 0x0036
#define RI_KANA 0x0037
#define RU_KANA 0x0038
#define RE_KANA 0x0039
#define RO_KANA 0x003a
#define WA_KANA 0x003b
#define WO_KANA 0x003c
#define NN_KANA 0x003d

#define SCENENODESIZE 20

SCENENODE* GetSceneNodeArray();

void SetSceneNodeArray(int index, SCENENODE temp);

void SetCurrScene(SCENENODE* sceneNode);

SCENENODE* GetCurrScene();
