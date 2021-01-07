//------------------------------------------------------------------------
// �ե�������: MazeMap.h
// �C��: �Ԍm�Υޥåפ��v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// �Ԍm����ڻ�����
/// </summary>
void InitMazeMap();

/// <summary>
/// �Ԍm�Υǩ`��������z��
/// </summary>
void LoadMazeMap();

/// <summary>
/// ����ե����뤫���Ԍm���OӋ���i�߳���
/// </summary>
/// <param name="fileName">�Ԍm�ե�����</param>
void LoadInfoFromFile(const char* fileName);

/// <summary>
/// �Ԍm����¤���
/// </summary>
void UpdateMazeMap();
