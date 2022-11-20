// AET.h: interface for the CAET class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AET_H__193C28AC_43A1_4D10_B3BD_C56E42D509CD__INCLUDED_)
#define AFX_AET_H__193C28AC_43A1_4D10_B3BD_C56E42D509CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Pi2.h"

class CAET {  //��Ч�߱���
public:
	CAET();
	virtual ~CAET();
public:
	double x;
	int    yMax;
	double k;
	CPi2   pb;  //���
	CPi2   pe;  //�յ�
	CAET   *next;
};

#endif // !defined(AFX_AET_H__193C28AC_43A1_4D10_B3BD_C56E42D509CD__INCLUDED_)