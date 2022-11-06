// AET.h: interface for the CAET class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AET_H__6650B22F_3282_4541_930A_AEBF6F9B7D2E__INCLUDED_)
#define AFX_AET_H__6650B22F_3282_4541_930A_AEBF6F9B7D2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Pi3.h"

class CAET {  //��Ч�߱���
public:
	CAET();
	virtual ~CAET();
public:
	double x;  //��ǰx
	int    yMax;  //�ߵ����yֵ
	double k;  //б�ʵĵ���(x������)
	CPi3    pb;  //���
	CPi3    pe;  //�յ�
	CAET   *next;
};

#endif // !defined(AFX_AET_H__6650B22F_3282_4541_930A_AEBF6F9B7D2E__INCLUDED_)
