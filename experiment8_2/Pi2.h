// Pi2.h: interface for the CPi2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PI2_H__4C516479_CF2C_4591_A62E_86BF4B838C94__INCLUDED_)
#define AFX_PI2_H__4C516479_CF2C_4591_A62E_86BF4B838C94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RGB.h"

class CPi2 {  //二维点类，y坐标取整数
public:
	CPi2();
	virtual ~CPi2();
	CPi2(double, int);
	double x;
	int    y;
	CRGB   c;
};

#endif // !defined(AFX_PI2_H__4C516479_CF2C_4591_A62E_86BF4B838C94__INCLUDED_)
