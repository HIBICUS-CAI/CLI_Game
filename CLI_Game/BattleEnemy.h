//------------------------------------------------------------------------
// �t�@�C����: BattleEnemy.h
// �@�\: �퓬�G�Ɋւ��Ă̏���
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// �퓬�G�z�������������
/// </summary>
void InitBattleEnemy();

/// <summary>
/// �퓬�G���X�V����
/// </summary>
void UpdateBattleEnemy();

/// <summary>
/// �퓬�G�𓖃V�[���̃J�����o�b�t�@�ɏ�������
/// </summary>
void DrawBattleEnemyToCamBuffer();

/// <summary>
/// �퓬�G�̏����ʒu�𗐐��Őݒ�
/// </summary>
void SetEnemyToBattleRandomly();

/// <summary>
/// �퓬�G��S���폜
/// </summary>
void ClearBattleEnemyArray();

/// <summary>
/// �S�Ă̐퓬�G��s���I�ɂȂ�
/// </summary>
void TurnOffAllBattleEnemy();

/// <summary>
/// �S�Ă̐퓬�G�����I�ɂȂ�
/// </summary>
void TurnOnAllBattleEnemy();

/// <summary>
/// �v���C���[�̍U����茂��
/// </summary>
/// <param name="enemy">�퓬�G�w���̃|�C���^</param>
/// <param name="direction">���ނ̕���</param>
void PushEnemyByPlayer(BATTLEENEMY* enemy, int direction);
