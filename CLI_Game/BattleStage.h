//------------------------------------------------------------------------
// �t�@�C����: BattleStage.h
// �@�\: �퓬�n�}�Ɋւ��Ă̏���
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// �퓬�n�}������������
/// </summary>
void InitBattleStage();

/// <summary>
/// �t�@�C������퓬�n�}�̃f�[�^��ǂݏo��
/// </summary>
void LoadBattleStage();

/// <summary>
/// �퓬�n�}�𓖃V�[���̃J�����o�b�t�@�ɏ�������
/// </summary>
/// <param name="offset">�퓬�n�}�z��̕Έڗ�</param>
void DrawStageToCamBuffer(int offset);
