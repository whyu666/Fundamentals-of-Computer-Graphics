// P2.h: interface for the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2_H__1ED17C04_3EC3_404F_921A_CF192D45D994__INCLUDED_)
#define AFX_P2_H__1ED17C04_3EC3_404F_921A_CF192D45D994__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CP2
{
public:
	CP2();
	virtual ~CP2();
	CP2(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
public:
	double x;
	double y;
};

#endif // !defined(AFX_P2_H__1ED17C04_3EC3_404F_921A_CF192D45D994__INCLUDED_)
