// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__5E20667A_3305_4971_835D_1B2FC6398090__INCLUDED_)
#define AFX_FACE_H__5E20667A_3305_4971_835D_1B2FC6398090__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFace {  //����
public:
	CFace();
	virtual ~CFace();
public:
	int En;  //��ı���
	int p[4];  //��Ķ����
};

#endif // !defined(AFX_FACE_H__5E20667A_3305_4971_835D_1B2FC6398090__INCLUDED_)
