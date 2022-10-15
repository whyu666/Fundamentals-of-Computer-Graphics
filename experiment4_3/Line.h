// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__DEAD88EA_6F38_4951_A8CA_1467F4E1A387__INCLUDED_)
#define AFX_LINE_H__DEAD88EA_6F38_4951_A8CA_1467F4E1A387__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"

class CLine
{
public:
	CLine();
	virtual ~CLine();
	void MoveTo(CDC *, CP2);
	void MoveTo(CDC *, double, double);
	void LineTo(CDC *, CP2);
	void LineTo(CDC *, double, double);
public:
	CP2 P0;
	CP2 P1;
};

#endif // !defined(AFX_LINE_H__DEAD88EA_6F38_4951_A8CA_1467F4E1A387__INCLUDED_)
