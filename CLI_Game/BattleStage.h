//------------------------------------------------------------------------
// �ե�������: BattleStage.h
// �C��: ���L�؇���v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// ���L�؇����ڻ�����
/// </summary>
void InitBattleStage();

/// <summary>
/// �ե����뤫����L�؇�Υǩ`�����i�߳���
/// </summary>
void LoadBattleStage();

/// <summary>
/// ���L�؇�򵱥��`��Υ����Хåե��˕����z��
/// </summary>
/// <param name="offset">���L�؇����Ф�ƫ����</param>
void DrawStageToCamBuffer(int offset);
