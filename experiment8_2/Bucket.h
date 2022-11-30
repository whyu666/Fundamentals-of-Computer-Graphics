// Bucket.h: interface for the CBucket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUCKET_H__DDF2A6CE_ABE5_49EA_8D49_DAF6AA99E371__INCLUDED_)
#define AFX_BUCKET_H__DDF2A6CE_ABE5_49EA_8D49_DAF6AA99E371__INCLUDED_

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

#endif // !defined(AFX_BUCKET_H__DDF2A6CE_ABE5_49EA_8D49_DAF6AA99E371__INCLUDED_)
