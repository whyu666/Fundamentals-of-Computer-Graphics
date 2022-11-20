// Bucket.h: interface for the CBucket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUCKET_H__FF3602B4_B200_4DC1_9DDC_2787D4996C65__INCLUDED_)
#define AFX_BUCKET_H__FF3602B4_B200_4DC1_9DDC_2787D4996C65__INCLUDED_

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

#endif // !defined(AFX_BUCKET_H__FF3602B4_B200_4DC1_9DDC_2787D4996C65__INCLUDED_)
