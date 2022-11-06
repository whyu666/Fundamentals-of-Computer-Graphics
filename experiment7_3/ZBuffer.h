// ZBuffer.h: interface for the CZBuffer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZBUFFER_H__54679269_EEBB_425B_948D_3714951FB06F__INCLUDED_)
#define AFX_ZBUFFER_H__54679269_EEBB_425B_948D_3714951FB06F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Pi3.h"  //��ά��ͷ�ļ�
#include "Bucket.h"  //Ͱͷ�ļ�
#include "Vector.h"  //ʸ��ͷ�ļ�

class CZBuffer {  //��Ȼ�����
public:
	CZBuffer();
    virtual ~CZBuffer();
	void CreateBucket();  //����Ͱ
	void CreateEdge();  //�߱�
	void AddEt(CAET *);  //�ϲ�ET��
	void EtOrder();  //ET������
	void Gouraud(CDC *);  //���
	void InitDeepBuffer(int, int, double);  //��ʼ����Ȼ���
    CRGB Interpolation(double, double, double, CRGB, CRGB);  //���Բ�ֵ
	void SetPoint(CPi3 *, int);
protected:
	int PNum;  //�������
	CPi3 *P;  //��������
	CAET *CurrentE, *HeadE, *Edge;
	CBucket *CurrentB, *HeadB;
	double **ZB;
	int Width, Height;  //��Ȼ����С����
};

#endif // !defined(AFX_ZBUFFER_H__54679269_EEBB_425B_948D_3714951FB06F__INCLUDED_)
