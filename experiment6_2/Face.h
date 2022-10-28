// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__6B25B4F7_DA9F_4629_907D_AAFF216A875C__INCLUDED_)
#define AFX_FACE_H__6B25B4F7_DA9F_4629_907D_AAFF216A875C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFace {
public:
	CFace();
	virtual ~CFace();
	int En;  //面的边数
	int p[4];  //面的顶点号
};

#endif // !defined(AFX_FACE_H__6B25B4F7_DA9F_4629_907D_AAFF216A875C__INCLUDED_)
