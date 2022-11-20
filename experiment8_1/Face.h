// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__04B12E1C_2BC4_4BB9_9747_DC4058070E21__INCLUDED_)
#define AFX_FACE_H__04B12E1C_2BC4_4BB9_9747_DC4058070E21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RGB.h"

class CFace {  //面类
public:
	CFace();
	virtual ~CFace();
public:
	int En;  //面的边数
	int p[3];  //面的顶点号
};

#endif // !defined(AFX_FACE_H__04B12E1C_2BC4_4BB9_9747_DC4058070E21__INCLUDED_)
