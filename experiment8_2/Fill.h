// Fill.h: interface for the CFill class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILL_H__364E4E26_83AA_4C61_8AB1_EC8DE5CC0810__INCLUDED_)
#define AFX_FILL_H__364E4E26_83AA_4C61_8AB1_EC8DE5CC0810__INCLUDED_

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

#endif // !defined(AFX_FILL_H__364E4E26_83AA_4C61_8AB1_EC8DE5CC0810__INCLUDED_)
