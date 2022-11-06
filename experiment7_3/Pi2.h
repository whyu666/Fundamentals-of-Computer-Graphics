// Pi2.h: interface for the CPi2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PI2_H__C7E6B62B_77DB_490B_B8C7_0FE131F7B804__INCLUDED_)
#define AFX_PI2_H__C7E6B62B_77DB_490B_B8C7_0FE131F7B804__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RGB.h"

class CPi2 {  //二维顶点，y为整数值
public:
	CPi2();
	virtual ~CPi2();
	CPi2(double, int);
	double x;
	int    y;
	CRGB   c;
};

#endif // !defined(AFX_PI2_H__C7E6B62B_77DB_490B_B8C7_0FE131F7B804__INCLUDED_)
