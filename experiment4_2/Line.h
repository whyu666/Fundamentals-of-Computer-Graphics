// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__F34FE9B4_87EE_444D_8D6C_4F07F6B49811__INCLUDED_)
#define AFX_LINE_H__F34FE9B4_87EE_444D_8D6C_4F07F6B49811__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"

class CLine {
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

#endif // !defined(AFX_LINE_H__F34FE9B4_87EE_444D_8D6C_4F07F6B49811__INCLUDED_)
