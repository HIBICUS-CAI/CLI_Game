//------------------------------------------------------------------------
// �t�@�C����: MazeEnemy.h
// �@�\: ���{�̓G�Ɋւ��Ă̏���
//------------------------------------------------------------------------

#pragma once
#include "DeclaredObjects.h"

#define STOP_MOVING 0
#define GO_FORWARD 1
#define GO_BACK 2
#define TURN_LEFT 3
#define TURN_RIGHT 4

/// <summary>
/// �G�z�������������
/// </summary>
void InitMazeEnemy();

/// <summary>
/// �G�̈ʒu��ݒ肷��
/// </summary>
/// <param name="pos">�ʒu�̍��W</param>
void SetMazeEnemy(POSITION_2D pos);

/// <summary>
/// �S�Ă̓G���X�V����
/// </summary>
void UpdateMazeEnemy();

/// <summary>
/// �e�G���X�V����
/// </summary>
/// <param name="mazeEnemy">�G�w���̃|�C���^</param>
void UpdateSingleMazeEnemy(MAZEENEMY* mazeEnemy);

/// <summary>
/// ����G���v���C���[����������
/// </summary>
/// <param name="mazeEnemy">�G�w���̃|�C���^</param>
void ScanPlayer(MAZEENEMY* mazeEnemy);

/// <summary>
/// ����G�̈ړ����Ǘ�����
/// </summary>
/// <param name="mazeEnemy">�G�w���̃|�C���^</param>
void ManageMazeEnemyMove(MAZEENEMY* mazeEnemy);

/// <summary>
/// ����G��O�����ɍs������
/// </summary>
/// <param name="mazeEnemy">�G�w���̃|�C���^</param>
void MazeEnemyMoveForward(MAZEENEMY* mazeEnemy);

/// <summary>
/// ����G�����ɍs������
/// </summary>
/// <param name="mazeEnemy">�G�w���̃|�C���^</param>
void MazeEnemyMoveBack(MAZEENEMY* mazeEnemy);

/// <summary>
/// ����G�����ɍs������
/// </summary>
/// <param name="mazeEnemy">�G�w���̃|�C���^</param>
void MazeEnemyTurnLeft(MAZEENEMY* mazeEnemy);

/// <summary>
/// ����G���E�ɍs������
/// </summary>
/// <param name="mazeEnemy">�G�w���̃|�C���^</param>
void MazeEnemyTurnRight(MAZEENEMY* mazeEnemy);

/// <summary>
/// �S�Ă̓G�����I�ɂȂ�
/// </summary>
void TurnOnAllEnemy();

/// <summary>
/// �S�Ă̓G��s���I�ɂȂ�
/// </summary>
void TurnOffAllEnemy();
