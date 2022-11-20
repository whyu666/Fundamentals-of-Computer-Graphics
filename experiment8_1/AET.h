// AET.h: interface for the CAET class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AET_H__193C28AC_43A1_4D10_B3BD_C56E42D509CD__INCLUDED_)
#define AFX_AET_H__193C28AC_43A1_4D10_B3BD_C56E42D509CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Pi2.h"

class CAET {  //有效边表类
public:
	CAET();
	virtual ~CAET();
public:
	double x;
	int    yMax;
	double k;
	CPi2   pb;  //起点
	CPi2   pe;  //终点
	CAET   *next;
};

#endif // !defined(AFX_AET_H__193C28AC_43A1_4D10_B3BD_C56E42D509CD__INCLUDED_)
