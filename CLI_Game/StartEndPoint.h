//------------------------------------------------------------------------
// �ե�������: StartEndPoint.h
// �C��: ʼ��ȽK��ΙC��
//------------------------------------------------------------------------

#pragma once

#include "DeclaredObjects.h"

/// <summary>
/// ʼ��ȽK�����ڻ�����
/// </summary>
void InitStartEndPoint();

/// <summary>
/// ���¤ǵ��Ť��ɤ�����_�J
/// </summary>
void UpdateStartEndPoint();

/// <summary>
/// ʼ��򤢤�λ�ä��O������
/// </summary>
/// <param name="pos">λ�ä�����</param>
void SetStartPointPos(POSITION_2D pos);

/// <summary>
/// �K��򤢤�λ�ä��O������
/// </summary>
/// <param name="pos">λ�ä�����</param>
void SetEndPointPos(POSITION_2D pos);
