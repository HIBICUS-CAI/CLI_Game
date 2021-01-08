//------------------------------------------------------------------------
// �t�@�C����: DeclaredObjects.h
// �@�\: ��K�O���[�o���ϐ��̐���
//------------------------------------------------------------------------

#pragma once

#include "ObjectStruct.h"

/// <summary>
/// �v���C���[���擾
/// </summary>
/// <returns>�v���C���[�w���̃|�C���^</returns>
PLAYER* GetPlayer();

/// <summary>
/// �X�e�[�W�ԍ����擾
/// </summary>
/// <returns>�X�e�[�W�̔ԍ�</returns>
int GetStageID();

/// <summary>
/// �X�e�[�W�̔ԍ���ݒ�
/// </summary>
/// <param name="id">�X�e�[�W�̔ԍ�</param>
void SetStageID(int id);

/// <summary>
/// ���͖��{�������s�����ǂ���
/// </summary>
/// <returns>���{��������Ă���W��</returns>
int IsPlayingMaze();

/// <summary>
/// ���͖��{�������s�����ǂ�����ݒ�
/// </summary>
/// <param name="value">����Ă���W�������͂���Ă��Ȃ��W��</param>
void SetIsPlayingMaze(int value);

/// <summary>
/// ���{���擾
/// </summary>
/// <returns>���{�w���̃|�C���^</returns>
MAZEMAP* GetMazeMap();

/// <summary>
/// �n�_�ƏI�_���擾
/// </summary>
/// <returns>�n�_�ƏI�_�̔z��</returns>
STARTENDPOINT* GetStartEndPointArray();

#define MAZEENEMYSIZE 50
/// <summary>
/// ���{�G���擾
/// </summary>
/// <returns>���{�G�̔z��</returns>
MAZEENEMY* GetMazeEnemyArray();

/// <summary>
/// ���͐퓬�������s�����ǂ���
/// </summary>
/// <returns>�퓬��������Ă���W��</returns>
int IsPlayingBattle();

/// <summary>
/// ���͐퓬�������s�����ǂ�����ݒ�
/// </summary>
/// <param name="value">����Ă���W�������͂���Ă��Ȃ��W��</param>
void SetIsPlayingBattle(int value);

#define BATTLESTAGEWIDTH 116
#define BATTLESTAGEHEIGHT 33
#define BATTLESTAGECOUNT 3
/// <summary>
/// �퓬�n�}���擾
/// </summary>
/// <param name="offset">�Έڗ�</param>
/// <returns>����퓬�n�}�w���̃|�C���^</returns>
char* GetBattleStageByOffset(int offset);

/// <summary>
/// �n�}�Έڗʂ��擾
/// </summary>
/// <returns>�n�}�z��̕Έڗ�</returns>
int GetBattleStageToOffset();

/// <summary>
/// �g���n�}�̔ԍ��𗐐��Őݒ�
/// </summary>
void RandomlySetBattleStageOffset();

#define BATTLEENEMYSIZE 50
/// <summary>
/// �퓬�G�̔z����擾
/// </summary>
/// <returns>�퓬�G�̔z��</returns>
BATTLEENEMY* GetBattleEnemyArray();

/// <summary>
/// �v���C���[�̖��O���擾
/// </summary>
/// <returns>�v���C���[�̖��O</returns>
char* GetPlayerName();

/// <summary>
/// �v���C���[�̖��O��ݒ�
/// </summary>
/// <param name="name">�ݒ肵���������z��</param>
void SetPlayerName(char* name);

/// <summary>
/// �v���C���[�̐����l���擾
/// </summary>
/// <returns>�v���C���[�̐����l</returns>
int GetInputHP();

/// <summary>
/// �v���C���[�̐����l��ݒ�
/// </summary>
/// <param name="hp">�ݒ肵�����l</param>
void SetInputHP(int hp);

/// <summary>
/// �v���C���[�̍U���͂��擾
/// </summary>
/// <returns>�v���C���[�̍U����</returns>
int GetInputATK();

/// <summary>
/// �v���C���[�̍U���͂�ݒ�
/// </summary>
/// <param name="atk">�ݒ肵�����l</param>
void SetInputATK(int atk);

/// <summary>
/// �v���C���[�̌��ޗ͂��擾
/// </summary>
/// <returns>�v���C���[�̌��ޗ�</returns>
int GetInputPUSH();

/// <summary>
/// �v���C���[�̌��ޗ͂�ݒ�
/// </summary>
/// <param name="push">�ݒ肵�����l</param>
void SetInputPUSH(int push);

/// <summary>
/// ���͖��O����͂��Ă��邩�ǂ���
/// </summary>
/// <returns>���͂��Ă���W��</returns>
int IsInputting();

/// <summary>
/// ���͖��O����͂��Ă��邩�ǂ�����ݒ�
/// </summary>
/// <param name="value">���Ă��邩�ǂ����̕W��</param>
void SetIsInputting(int value);

/// <summary>
/// ���͂��Ă��镶�����e���擾
/// </summary>
/// <returns>�������e�w���̃|�C���^</returns>
UI_TEXT* GetInputtingStr();

/// <summary>
/// ���͂��Ă��镶�����e��ݒ�
/// </summary>
/// <param name="text">�������e�w���̃|�C���^</param>
void SetInputtingStr(UI_TEXT* text);

/// <summary>
/// ���͔ԍ����擾
/// </summary>
/// <returns>���͔ԍ�</returns>
int GetInputIndex();

/// <summary>
/// ���͔ԍ���ݒ�
/// </summary>
/// <param name="value">���͔ԍ�</param>
void SetInputIndex(int value);

/// <summary>
/// ���͂��ꂽ�����̐����擾
/// </summary>
/// <returns>���͂��ꂽ������</returns>
int GetInputCount();

/// <summary>
/// ���͂��ꂽ�����̐���ݒ�
/// </summary>
/// <param name="value">���͂��ꂽ������</param>
void SetInputCount(int value);
