//------------------------------------------------------------------------
// �ե�������: BattleEnemy.h
// �C��: ���L�����v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// ���L�����Ф���ڻ�����
/// </summary>
void InitBattleEnemy();

/// <summary>
/// ���L������¤���
/// </summary>
void UpdateBattleEnemy();

/// <summary>
/// ���L���򵱥��`��Υ����Хåե��˕����z��
/// </summary>
void DrawBattleEnemyToCamBuffer();

/// <summary>
/// ���L���γ���λ�ä��������O��
/// </summary>
void SetEnemyToBattleRandomly();

/// <summary>
/// ���L����ȫ������
/// </summary>
void ClearBattleEnemyArray();

/// <summary>
/// ȫ�ƤΑ��L���򲻿�ҕ�Ĥˤʤ�
/// </summary>
void TurnOffAllBattleEnemy();

/// <summary>
/// ȫ�ƤΑ��L�����ҕ�Ĥˤʤ�
/// </summary>
void TurnOnAllBattleEnemy();

/// <summary>
/// �ץ쥤��`�ι��Ĥ�����
/// </summary>
/// <param name="enemy">���L��ָ��Υݥ���</param>
/// <param name="direction">���ˤη���</param>
void PushEnemyByPlayer(BATTLEENEMY* enemy, int direction);
