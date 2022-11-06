// Pi3.h: interface for the CPi3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PI3_H__CAB91A43_8AA7_4F37_8E25_F1B6B3BFC0B1__INCLUDED_)
#define AFX_PI3_H__CAB91A43_8AA7_4F37_8E25_F1B6B3BFC0B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Pi2.h"

class CPi3:public CPi2 {  //三维顶点，y为整数值
public:
	CPi3();
	virtual ~CPi3();
	CPi3(double, int, double);
	double z;
};

#endif // !defined(AFX_PI3_H__CAB91A43_8AA7_4F37_8E25_F1B6B3BFC0B1__INCLUDED_)
