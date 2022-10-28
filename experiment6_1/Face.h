// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__B151D5F4_F4F7_4912_B8A3_EA7F944456E5__INCLUDED_)
#define AFX_FACE_H__B151D5F4_F4F7_4912_B8A3_EA7F944456E5__INCLUDED_

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

#endif // !defined(AFX_FACE_H__B151D5F4_F4F7_4912_B8A3_EA7F944456E5__INCLUDED_)
