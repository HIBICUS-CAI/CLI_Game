//------------------------------------------------------------------------
// �t�@�C����: MazeMap.h
// �@�\: ���{�̃}�b�v�Ɋւ��Ă̏���
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// ���{������������
/// </summary>
void InitMazeMap();

/// <summary>
/// ���{�̃f�[�^����������
/// </summary>
void LoadMazeMap();

/// <summary>
/// ����t�@�C��������{�̐݌v��ǂݏo��
/// </summary>
/// <param name="fileName">���{�t�@�C��</param>
void LoadInfoFromFile(const char* fileName);

/// <summary>
/// ���{���X�V����
/// </summary>
void UpdateMazeMap();
