// AET.h: interface for the CAET class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AET_H__1FEF574D_E7E7_4166_808E_646D9AF1E754__INCLUDED_)
#define AFX_AET_H__1FEF574D_E7E7_4166_808E_646D9AF1E754__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Pi2.h"

class CAET {  //��Ч�߱���
public:
	CAET();
	virtual ~CAET();
public:
	double x;  //��ǰx
	int    yMax;  //�ߵ����yֵ
	double k;  //б�ʵĵ���(x������)
	CPi2    pb;  //���
	CPi2    pe;  //�յ�
	CAET    *next;
};

#endif // !defined(AFX_AET_H__1FEF574D_E7E7_4166_808E_646D9AF1E754__INCLUDED_)
