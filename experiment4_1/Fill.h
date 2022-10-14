// Fill.h: interface for the CFill class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILL_H__941B7423_A51E_4150_8594_D0FBE50405F4__INCLUDED_)
#define AFX_FILL_H__941B7423_A51E_4150_8594_D0FBE50405F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Bucket.h"
#include "P2.h"

class CFill {
public:
	CFill();
	virtual ~CFill();
	void SetPoint(CP2 *p, int);  //��ʼ��
	void CreateBucket();  //����Ͱ
	void CreateEdge();  //�߱�
	void AddET(CAET *);  //�ϲ�ET��
	void ETOrder();  //ET������
	void Gouraud(CDC *);  //�������
 	void ClearMemory();  //�����ڴ�
	void DeleteAETChain(CAET* pAET);  //ɾ���߱�
protected:
	int PNum;  //�������
	CP2 *P;  //�������궯̬����
	CAET *pHeadE, *pCurrentE, *pEdge;  //��Ч�߱���ָ��
	CBucket *pHeadB, *pCurrentB;  //Ͱ����ָ��
};

#endif // !defined(AFX_FILL_H__941B7423_A51E_4150_8594_D0FBE50405F4__INCLUDED_)
