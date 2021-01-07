//------------------------------------------------------------------------
// �ե�������: Player.h
// �C��: �ץ쥤��`���v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// �ץ쥤��`�򤢤�λ�ä��O������
/// </summary>
/// <param name="pos">λ�ä�����</param>
void InitPlayer(POSITION_2D pos);

/// <summary>
/// �Ԍm�����r�ץ쥤��`�����ˤ��O������
/// </summary>
/// <param name="stage">���Ʃ`���η���</param>
/// <param name="pos">λ�ä�����</param>
void ResetPlayerPosTurnToStage(int stage, POSITION_2D pos);

/// <summary>
/// ���L���Ф��r�ץ쥤��`�����ˤ��O������
/// </summary>
void ResetPlayerPosInBattle();

/// <summary>
/// �Ԍm�Υץ쥤��`����¤���
/// </summary>
void UpdatePlayer();

/// <summary>
/// ���L���Ƥ���ץ쥤��`����¤���
/// </summary>
void UpdatePlayerInBattle();

/// <summary>
/// �ץ쥤��`�򥷩`��Υ����Хåե��˕����z��
/// </summary>
void DrawPlayerToCamBuffer();

/// <summary>
/// �ץ쥤��`��ǰ�򤭤��Ф�����
/// </summary>
void PlayerMoveForward();

/// <summary>
/// �ץ쥤��`�������Ф�����
/// </summary>
void PlayerMoveBack();

/// <summary>
/// �ץ쥤��`������Ф�����
/// </summary>
void PlayerTurnLeft();

/// <summary>
/// �ץ쥤��`���Ҥ��Ф�����
/// </summary>
void PlayerTurnRight();

/// <summary>
/// �ץ쥤��`���ҕ�Ĥˤʤ�
/// </summary>
void TurnOnPlayer();

/// <summary>
/// �ץ쥤��`�򲻿�ҕ�Ĥˤʤ�
/// </summary>
void TurnOffPlayer();

/// <summary>
/// ���L�Хץ쥤��`������Ф�����
/// </summary>
void PlayerBattleMoveLeft();

/// <summary>
/// ���L�Хץ쥤��`���Ҥ��Ф�����
/// </summary>
void PlayerBattleMoveRight();

/// <summary>
/// ���L�Хץ쥤��`�򥸥��פ�����
/// </summary>
void PlayerBattleJumpUp();

/// <summary>
/// ���L�Хץ쥤��`���Τ�̤��Ǥ��ʤ��������
/// </summary>
void PlayerBattleFallDown();

/// <summary>
/// ���L�Хץ쥤��`����ι���
/// </summary>
void PlayerAttack();

/// <summary>
/// ��ؤη��������Хå����åפ��O������
/// </summary>
/// <param name="value">���Ҥη���</param>
void SetLastestDirectionInput(int value);

/// <summary>
/// ǰ�ؤη���Хå����å����ݤ�ȡ��
/// </summary>
/// <returns>ǰ�ؤη���Хå����å�</returns>
int GetLastestDirectionInput();

/// <summary>
/// �ץ쥤��`������ꥻ�åȤ���
/// </summary>
void ResetPlayerStatus();

/// <summary>
/// �ץ쥤��`����������ꥻ�åȤ���
/// </summary>
void ResetPlayerHP();
