// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__04B12E1C_2BC4_4BB9_9747_DC4058070E21__INCLUDED_)
#define AFX_FACE_H__04B12E1C_2BC4_4BB9_9747_DC4058070E21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RGB.h"

class CFace {  //����
public:
	CFace();
	virtual ~CFace();
public:
	int En;  //��ı���
	int p[3];  //��Ķ����
};

#endif // !defined(AFX_FACE_H__04B12E1C_2BC4_4BB9_9747_DC4058070E21__INCLUDED_)
