// Light.h: interface for the CLight class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIGHT_H__ACA1A2A6_E72D_4EBC_B919_5C0AC538F456__INCLUDED_)
#define AFX_LIGHT_H__ACA1A2A6_E72D_4EBC_B919_5C0AC538F456__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P3.h"
#include "RGB.h"

class CLight  //��Դ��
{
public:
	CLight();
	virtual ~CLight();
	void SetDiffuse(CRGB);//���ù�Դ���������
	void SetSpecular(CRGB);//���ù�Դ�ľ��淴���
	void SetPosition(double,double,double);//���ù�Դ��ֱ������λ��
	void SetGlobal(double,double,double);//���ù�Դ��������λ��
	void SetCoef(double,double,double);//���ù�ǿ��˥��ϵ��
	void SetOnOff(BOOL);//���ù�Դ����״̬	
	void GlobalToXYZ();//������ת��Ϊֱ������
	void XYZToGlobal();//ֱ������ת��Ϊ������
	

	void Step();//��Դλ�ò���
	//int Move(int frame);//��Դλ��֡���ã�


public:
	CRGB L_Diffuse;//�����������ɫ	
	CRGB L_Specular;//��ľ���߹���ɫ
	CP3 L_Position;//��Դ��λ��
	double L_R,L_Phi,L_Theta;//��Դ������(px,deg,deg)
	double L_C0;//����˥��ϵ��
	double L_C1;//����˥��ϵ��
	double L_C2;//����˥��ϵ��
	BOOL L_OnOff;//��Դ����

	//int nMoveMode;//�ƶ�ģʽ��0�̶���1��������ת��2ƽ��
	//����Ϊ��������������ת����ֵ
	double dStepPhi,dMaxPhi;
	double dStepTheta,dMaxTheta;
	double dStepX,dMaxX;
	double dStepY,dMaxY;
	double dStepZ,dMaxZ;
};

#endif // !defined(AFX_LIGHT_H__ACA1A2A6_E72D_4EBC_B919_5C0AC538F456__INCLUDED_)
