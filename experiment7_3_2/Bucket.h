// Bucket.h: interface for the CBucket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUCKET_H__01CBBC32_454E_421E_B53D_01CDC417D04B__INCLUDED_)
#define AFX_BUCKET_H__01CBBC32_454E_421E_B53D_01CDC417D04B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AET.h"

class CBucket {  //Õ∞¿‡
public:
	CBucket();
	virtual ~CBucket();
public:
	int     ScanLine;
	CAET    *pET;
	CBucket *next;
};

#endif // !defined(AFX_BUCKET_H__01CBBC32_454E_421E_B53D_01CDC417D04B__INCLUDED_)
