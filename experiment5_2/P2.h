// P2.h: interface for the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2_H__FB6F0D10_5322_4E89_948C_C92E0C4657D6__INCLUDED_)
#define AFX_P2_H__FB6F0D10_5322_4E89_948C_C92E0C4657D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CP2  {
public:
	CP2();
	virtual ~CP2();
public:
	double x;  //直线段端点x坐标
	double y;  //直线段端点y坐标
	UINT  rc;  //直线段端点编码
};

#endif // !defined(AFX_P2_H__FB6F0D10_5322_4E89_948C_C92E0C4657D6__INCLUDED_)
