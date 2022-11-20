// Pi2.h: interface for the CPi2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PI2_H__D5776C92_8DF9_4D6C_9234_05716963E2FE__INCLUDED_)
#define AFX_PI2_H__D5776C92_8DF9_4D6C_9234_05716963E2FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RGB.h"

class CPi2 {  //��ά���࣬y����ȡ����
public:
	CPi2();
	virtual ~CPi2();
	CPi2(double, int);
	double x;
	int    y;
	CRGB   c;
};

#endif // !defined(AFX_PI2_H__D5776C92_8DF9_4D6C_9234_05716963E2FE__INCLUDED_)
