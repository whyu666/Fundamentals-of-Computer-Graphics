// AET.h: interface for the CAET class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AET_H__DF980BD3_7B99_4F84_9CA3_D21DA98C12F2__INCLUDED_)
#define AFX_AET_H__DF980BD3_7B99_4F84_9CA3_D21DA98C12F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"

class CAET {
public:
	CAET();
	virtual ~CAET();
public:
	double x;  //��ǰɨ��������Ч�߽����x����
	int yMax;  //�ߵ����yֵ
	double k;  //б�ʵĵ���
	CP2 ps;  //�ߵ����
	CP2 pe;  //�ߵ��յ�
	CAET *pNext;
};

#endif // !defined(AFX_AET_H__DF980BD3_7B99_4F84_9CA3_D21DA98C12F2__INCLUDED_)
