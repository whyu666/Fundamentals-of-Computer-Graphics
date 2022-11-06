// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__5E20667A_3305_4971_835D_1B2FC6398090__INCLUDED_)
#define AFX_FACE_H__5E20667A_3305_4971_835D_1B2FC6398090__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFace {  //面类
public:
	CFace();
	virtual ~CFace();
public:
	int En;  //面的边数
	int p[4];  //面的顶点号
};

#endif // !defined(AFX_FACE_H__5E20667A_3305_4971_835D_1B2FC6398090__INCLUDED_)
