//------------------------------------------------------------------------
// �t�@�C����: Player.h
// �@�\: �v���C���[�Ɋւ��Ă̏���
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// �v���C���[������ʒu�ɐݒ肷��
/// </summary>
/// <param name="pos">�ʒu�̍��W</param>
void InitPlayer(POSITION_2D pos);

/// <summary>
/// ���{����鎞�v���C���[�̍��W��ݒ肷��
/// </summary>
/// <param name="stage">�X�e�[�W�̔ԍ�</param>
/// <param name="pos">�ʒu�̍��W</param>
void ResetPlayerPosTurnToStage(int stage, POSITION_2D pos);

/// <summary>
/// �퓬���s�����v���C���[�̍��W��ݒ肷��
/// </summary>
void ResetPlayerPosInBattle();

/// <summary>
/// ���{�̃v���C���[���X�V����
/// </summary>
void UpdatePlayer();

/// <summary>
/// �퓬���Ă���v���C���[���X�V����
/// </summary>
void UpdatePlayerInBattle();

/// <summary>
/// �v���C���[���V�[���̃J�����o�b�t�@�ɏ�������
/// </summary>
void DrawPlayerToCamBuffer();

/// <summary>
/// �v���C���[��O�����ɍs������
/// </summary>
void PlayerMoveForward();

/// <summary>
/// �v���C���[�����ɍs������
/// </summary>
void PlayerMoveBack();

/// <summary>
/// �v���C���[�����ɍs������
/// </summary>
void PlayerTurnLeft();

/// <summary>
/// �v���C���[���E�ɍs������
/// </summary>
void PlayerTurnRight();

/// <summary>
/// �v���C���[�����I�ɂȂ�
/// </summary>
void TurnOnPlayer();

/// <summary>
/// �v���C���[��s���I�ɂȂ�
/// </summary>
void TurnOffPlayer();

/// <summary>
/// �퓬���v���C���[�����ɍs������
/// </summary>
void PlayerBattleMoveLeft();

/// <summary>
/// �퓬���v���C���[���E�ɍs������
/// </summary>
void PlayerBattleMoveRight();

/// <summary>
/// �퓬���v���C���[���W�����v������
/// </summary>
void PlayerBattleJumpUp();

/// <summary>
/// �퓬���v���C���[����������ł��Ȃ��Ɨ�����
/// </summary>
void PlayerBattleFallDown();

/// <summary>
/// �퓬���v���C���[����̍U��
/// </summary>
void PlayerAttack();

/// <summary>
/// ����̕������̓o�b�N�A�b�v��ݒ肷��
/// </summary>
/// <param name="value">���E�̕���</param>
void SetLastestDirectionInput(int value);

/// <summary>
/// �O��̕����o�b�N�A�b�v���e���擾
/// </summary>
/// <returns>�O��̕����o�b�N�A�b�v</returns>
int GetLastestDirectionInput();

/// <summary>
/// �v���C���[�̏������Z�b�g����
/// </summary>
void ResetPlayerStatus();

/// <summary>
/// �v���C���[�̐����l�����Z�b�g����
/// </summary>
void ResetPlayerHP();
