// AET.h: interface for the CAET class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AET_H__1FEF574D_E7E7_4166_808E_646D9AF1E754__INCLUDED_)
#define AFX_AET_H__1FEF574D_E7E7_4166_808E_646D9AF1E754__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Pi2.h"

class CAET {  //有效边表类
public:
	CAET();
	virtual ~CAET();
public:
	double x;  //当前x
	int    yMax;  //边的最大y值
	double k;  //斜率的倒数(x的增量)
	CPi2    pb;  //起点
	CPi2    pe;  //终点
	CAET    *next;
};

#endif // !defined(AFX_AET_H__1FEF574D_E7E7_4166_808E_646D9AF1E754__INCLUDED_)
