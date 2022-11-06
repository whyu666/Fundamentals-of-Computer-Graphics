// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__EE571A1F_D9DF_46E0_8BFE_83EF048F1422__INCLUDED_)
#define AFX_LINE_H__EE571A1F_D9DF_46E0_8BFE_83EF048F1422__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"

class CLine {  //直线类
public:
	CLine();
	virtual ~CLine();
    void MoveTo(CDC *, CP2);  //移动到指定位置
	void MoveTo(CDC *, int, int);  //重载函数
	void LineTo(CDC *, CP2);  //通用直线的整数Bresenham算法,不包含终点坐标
	void LineTo(CDC *, int, int);  //重载函数
	int Sign(int);  //返回-1,0,1当自变量为<0,=0,>0
public:
	CP2 P1;  //直线起点坐标
	CP2 P2;  //直线终点坐标
};

#endif // !defined(AFX_LINE_H__EE571A1F_D9DF_46E0_8BFE_83EF048F1422__INCLUDED_)
