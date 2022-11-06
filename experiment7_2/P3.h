// P3.h: interface for the CP3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P3_H__8BDBFB0A_4DF9_4EBB_A5DA_07D28F53D6D6__INCLUDED_)
#define AFX_P3_H__8BDBFB0A_4DF9_4EBB_A5DA_07D28F53D6D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"

class CP3:public CP2 {  //»˝Œ¨∂•µ„¿‡
public:
	CP3();
	virtual ~CP3();
	CP3(double, double, double);
public:
	double z;
};

#endif // !defined(AFX_P3_H__8BDBFB0A_4DF9_4EBB_A5DA_07D28F53D6D6__INCLUDED_)
