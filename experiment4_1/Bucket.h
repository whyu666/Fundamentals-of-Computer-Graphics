// Bucket.h: interface for the CBucket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUCKET_H__DC85B597_07D8_4DD0_83BD_8BB4512A3F45__INCLUDED_)
#define AFX_BUCKET_H__DC85B597_07D8_4DD0_83BD_8BB4512A3F45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AET.h"

class CBucket {
public:
	CBucket();
	virtual ~CBucket();
public:
	int ScanLine;  //扫描线
	CAET *pET;  //桶上的边表指针
	CBucket *pNext;
};

#endif // !defined(AFX_BUCKET_H__DC85B597_07D8_4DD0_83BD_8BB4512A3F45__INCLUDED_)
