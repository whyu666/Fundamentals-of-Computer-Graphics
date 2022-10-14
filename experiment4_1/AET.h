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
	double x;  //当前扫描线与有效边交点的x坐标
	int yMax;  //边的最大y值
	double k;  //斜率的倒数
	CP2 ps;  //边的起点
	CP2 pe;  //边的终点
	CAET *pNext;
};

#endif // !defined(AFX_AET_H__DF980BD3_7B99_4F84_9CA3_D21DA98C12F2__INCLUDED_)
