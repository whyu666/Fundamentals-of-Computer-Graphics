// Light.h: interface for the CLight class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIGHT_H__3D0D415B_C1A0_4B56_95D9_A0C504964113__INCLUDED_)
#define AFX_LIGHT_H__3D0D415B_C1A0_4B56_95D9_A0C504964113__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P3.h"
#include "RGB.h"

class CLight {  //��Դ��
public:
	CLight();
	virtual ~CLight();
	void SetDiffuse(CRGB);  //���ù�Դ���������
	void SetSpecular(CRGB);  //���ù�Դ�ľ��淴���
	void SetPosition(double, double, double);  //���ù�Դ��ֱ������λ��
	void SetGlobal(double, double, double);  //���ù�Դ��������λ��
	void SetCoef(double, double, double);  //���ù�ǿ��˥��ϵ��
	void SetOnOff(BOOL);  //���ù�Դ����״̬	
	void GlobalToXYZ();  //������ת��Ϊֱ������	
public:
	CRGB L_Diffuse;  //�����������ɫ
	CRGB L_Specular;  //��ľ���߹���ɫ
	CP3  L_Position;  //��Դ��λ��
	double L_R,L_Phi,L_Theta;  //��Դ������
	double L_C0;  //����˥��ϵ��
	double L_C1;  //����˥��ϵ��
	double L_C2;  //����˥��ϵ��
	BOOL L_OnOff;  //��Դ����
};

#endif // !defined(AFX_LIGHT_H__3D0D415B_C1A0_4B56_95D9_A0C504964113__INCLUDED_)
