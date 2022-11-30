// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__3265CBC6_026B_4057_AAC6_13751E267752__INCLUDED_)
#define AFX_FACE_H__3265CBC6_026B_4057_AAC6_13751E267752__INCLUDED_

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

#endif // !defined(AFX_FACE_H__3265CBC6_026B_4057_AAC6_13751E267752__INCLUDED_)
