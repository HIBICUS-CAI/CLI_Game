//------------------------------------------------------------------------
// �t�@�C����: StartEndPoint.h
// �@�\: �n�_�ƏI�_�̋@�\
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// �n�_�ƏI�_������������
/// </summary>
void InitStartEndPoint();

/// <summary>
/// �X�V�œ������ǂ������m�F
/// </summary>
void UpdateStartEndPoint();

/// <summary>
/// �n�_������ʒu�ɐݒ肷��
/// </summary>
/// <param name="pos">�ʒu�̍��W</param>
void SetStartPointPos(POSITION_2D pos);

/// <summary>
/// �I�_������ʒu�ɐݒ肷��
/// </summary>
/// <param name="pos">�ʒu�̍��W</param>
void SetEndPointPos(POSITION_2D pos);
