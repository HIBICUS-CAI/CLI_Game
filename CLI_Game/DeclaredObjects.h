//------------------------------------------------------------------------
// �ե�������: DeclaredObjects.h
// �C��: ���A����`�Х����������
//------------------------------------------------------------------------

#pragma once

#include "ObjectStruct.h"

/// <summary>
/// �ץ쥤��`��ȡ��
/// </summary>
/// <returns>�ץ쥤��`ָ��Υݥ���</returns>
PLAYER* GetPlayer();

/// <summary>
/// ���Ʃ`�����Ť�ȡ��
/// </summary>
/// <returns>���Ʃ`���η���</returns>
int GetStageID();

/// <summary>
/// ���Ʃ`���η��Ť��O��
/// </summary>
/// <param name="id">���Ʃ`���η���</param>
void SetStageID(int id);

/// <summary>
/// ����Ԍm���֤��Ф����ɤ���
/// </summary>
/// <returns>�Ԍm���֤�äƤ�����R</returns>
int IsPlayingMaze();

/// <summary>
/// ����Ԍm���֤��Ф����ɤ������O��
/// </summary>
/// <param name="value">��äƤ�����R�򤤤Ϥ�äƤ��ʤ����R</param>
void SetIsPlayingMaze(int value);

/// <summary>
/// �Ԍm��ȡ��
/// </summary>
/// <returns>�Ԍmָ��Υݥ���</returns>
MAZEMAP* GetMazeMap();

/// <summary>
/// ʼ��ȽK���ȡ��
/// </summary>
/// <returns>ʼ��ȽK�������</returns>
STARTENDPOINT* GetStartEndPointArray();

#define MAZEENEMYSIZE 50
/// <summary>
/// �Ԍm����ȡ��
/// </summary>
/// <returns>�Ԍm��������</returns>
MAZEENEMY* GetMazeEnemyArray();

/// <summary>
/// ��ϑ��L���֤��Ф����ɤ���
/// </summary>
/// <returns>���L���֤�äƤ�����R</returns>
int IsPlayingBattle();

/// <summary>
/// ��ϑ��L���֤��Ф����ɤ������O��
/// </summary>
/// <param name="value">��äƤ�����R�򤤤Ϥ�äƤ��ʤ����R</param>
void SetIsPlayingBattle(int value);

#define BATTLESTAGEWIDTH 116
#define BATTLESTAGEHEIGHT 33
#define BATTLESTAGECOUNT 3
/// <summary>
/// ���L�؇��ȡ��
/// </summary>
/// <param name="offset">ƫ����</param>
/// <returns>������L�؇�ָ��Υݥ���</returns>
char* GetBattleStageByOffset(int offset);

/// <summary>
/// �؇�ƫ������ȡ��
/// </summary>
/// <returns>�؇����Ф�ƫ����</returns>
int GetBattleStageToOffset();

/// <summary>
/// ʹ���؇�η��Ť��������O��
/// </summary>
void RandomlySetBattleStageOffset();

#define BATTLEENEMYSIZE 50
/// <summary>
/// ���L�������Ф�ȡ��
/// </summary>
/// <returns>���L��������</returns>
BATTLEENEMY* GetBattleEnemyArray();

/// <summary>
/// �ץ쥤��`����ǰ��ȡ��
/// </summary>
/// <returns>�ץ쥤��`����ǰ</returns>
char* GetPlayerName();

/// <summary>
/// �ץ쥤��`����ǰ���O��
/// </summary>
/// <param name="name">�O����������������</param>
void SetPlayerName(char* name);

/// <summary>
/// �ץ쥤��`����������ȡ��
/// </summary>
/// <returns>�ץ쥤��`��������</returns>
int GetInputHP();

/// <summary>
/// �ץ쥤��`�����������O��
/// </summary>
/// <param name="hp">�O����������</param>
void SetInputHP(int hp);

/// <summary>
/// �ץ쥤��`�ι�������ȡ��
/// </summary>
/// <returns>�ץ쥤��`�ι�����</returns>
int GetInputATK();

/// <summary>
/// �ץ쥤��`�ι��������O��
/// </summary>
/// <param name="atk">�O����������</param>
void SetInputATK(int atk);

/// <summary>
/// �ץ쥤��`�Γ�������ȡ��
/// </summary>
/// <returns>�ץ쥤��`�Γ�����</returns>
int GetInputPUSH();

/// <summary>
/// �ץ쥤��`�Γ��������O��
/// </summary>
/// <param name="push">�O����������</param>
void SetInputPUSH(int push);

/// <summary>
/// �����ǰ���������Ƥ��뤫�ɤ���
/// </summary>
/// <returns>�������Ƥ�����R</returns>
int IsInputting();

/// <summary>
/// �����ǰ���������Ƥ��뤫�ɤ������O��
/// </summary>
/// <param name="value">���Ƥ��뤫�ɤ����Θ��R</param>
void SetIsInputting(int value);

/// <summary>
/// �������Ƥ����������ݤ�ȡ��
/// </summary>
/// <returns>��������ָ��Υݥ���</returns>
UI_TEXT* GetInputtingStr();

/// <summary>
/// �������Ƥ����������ݤ��O��
/// </summary>
/// <param name="text">��������ָ��Υݥ���</param>
void SetInputtingStr(UI_TEXT* text);

/// <summary>
/// �������Ť�ȡ��
/// </summary>
/// <returns>��������</returns>
int GetInputIndex();

/// <summary>
/// �������Ť��O��
/// </summary>
/// <param name="value">��������</param>
void SetInputIndex(int value);

/// <summary>
/// �������줿���֤�����ȡ��
/// </summary>
/// <returns>�������줿������</returns>
int GetInputCount();

/// <summary>
/// �������줿���֤������O��
/// </summary>
/// <param name="value">�������줿������</param>
void SetInputCount(int value);
