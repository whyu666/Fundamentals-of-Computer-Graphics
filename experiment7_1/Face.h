// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__F4E64A96_604F_40CD_879D_63FB898BA8A2__INCLUDED_)
#define AFX_FACE_H__F4E64A96_604F_40CD_879D_63FB898BA8A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFace {  //面类
public:
	CFace();
	virtual ~CFace();
public:
	int En;  //面的边数
	int p[10];  //面的顶点号
};

#endif // !defined(AFX_FACE_H__F4E64A96_604F_40CD_879D_63FB898BA8A2__INCLUDED_)
