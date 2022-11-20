// Fill.h: interface for the CFill class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILL_H__2676A7BF_FE83_4D7C_A191_AA44827258B5__INCLUDED_)
#define AFX_FILL_H__2676A7BF_FE83_4D7C_A191_AA44827258B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Bucket.h"

class CFill {  //�����
public:
	CFill();
	virtual ~CFill();
	void SetPoint(CPi2 *p, int);  //��ĳ�ʼ��
	void CreateBucket();  //����Ͱ
	void CreateEdge();  //�߱�
	void AddEt(CAET *);  //�ϲ�ET��
	void EtOrder();  //ET������
	void Gouraud(CDC *);  //�������
    CRGB Interpolation(double, double, double, CRGB, CRGB);  //���Բ�ֵ
	protected:
	int     PNum;  //�������
	CPi2    *P;  //�������궯̬����
	CAET    *HeadE, *CurrentE, *Edge;  //��Ч�߱���ָ��
	CBucket *HeadB, *CurrentB;  //Ͱ����ָ��
};

#endif // !defined(AFX_FILL_H__2676A7BF_FE83_4D7C_A191_AA44827258B5__INCLUDED_)
