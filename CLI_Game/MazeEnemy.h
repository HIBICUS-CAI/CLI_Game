//------------------------------------------------------------------------
// �ե�������: MazeEnemy.h
// �C��: �Ԍm�Δ����v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once
#include "DeclaredObjects.h"

#define STOP_MOVING 0
#define GO_FORWARD 1
#define GO_BACK 2
#define TURN_LEFT 3
#define TURN_RIGHT 4

/// <summary>
/// �����Ф���ڻ�����
/// </summary>
void InitMazeEnemy();

/// <summary>
/// ����λ�ä��O������
/// </summary>
/// <param name="pos">λ�ä�����</param>
void SetMazeEnemy(POSITION_2D pos);

/// <summary>
/// ȫ�ƤΔ�����¤���
/// </summary>
void UpdateMazeEnemy();

/// <summary>
/// ��������¤���
/// </summary>
/// <param name="mazeEnemy">��ָ��Υݥ���</param>
void UpdateSingleMazeEnemy(MAZEENEMY* mazeEnemy);

/// <summary>
/// ���딳���ץ쥤��`���������
/// </summary>
/// <param name="mazeEnemy">��ָ��Υݥ���</param>
void ScanPlayer(MAZEENEMY* mazeEnemy);

/// <summary>
/// ���딳���ƄӤ������
/// </summary>
/// <param name="mazeEnemy">��ָ��Υݥ���</param>
void ManageMazeEnemyMove(MAZEENEMY* mazeEnemy);

/// <summary>
/// ���딳��ǰ�򤭤��Ф�����
/// </summary>
/// <param name="mazeEnemy">��ָ��Υݥ���</param>
void MazeEnemyMoveForward(MAZEENEMY* mazeEnemy);

/// <summary>
/// ���딳�������Ф�����
/// </summary>
/// <param name="mazeEnemy">��ָ��Υݥ���</param>
void MazeEnemyMoveBack(MAZEENEMY* mazeEnemy);

/// <summary>
/// ���딳������Ф�����
/// </summary>
/// <param name="mazeEnemy">��ָ��Υݥ���</param>
void MazeEnemyTurnLeft(MAZEENEMY* mazeEnemy);

/// <summary>
/// ���딳���Ҥ��Ф�����
/// </summary>
/// <param name="mazeEnemy">��ָ��Υݥ���</param>
void MazeEnemyTurnRight(MAZEENEMY* mazeEnemy);

/// <summary>
/// ȫ�ƤΔ����ҕ�Ĥˤʤ�
/// </summary>
void TurnOnAllEnemy();

/// <summary>
/// ȫ�ƤΔ��򲻿�ҕ�Ĥˤʤ�
/// </summary>
void TurnOffAllEnemy();
