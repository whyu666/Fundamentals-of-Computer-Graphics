// P2.h: interface for the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2_H__4A6E05D6_9FF4_46C3_AC91_86A41308B2AC__INCLUDED_)
#define AFX_P2_H__4A6E05D6_9FF4_46C3_AC91_86A41308B2AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RGB.h"

class CP2 {  //∂˛Œ¨µ„¿‡
public:
	CP2();
	virtual ~CP2();
	CP2(double,double);
	double x;
	double y;
	CRGB   c;
};


#endif // !defined(AFX_P2_H__4A6E05D6_9FF4_46C3_AC91_86A41308B2AC__INCLUDED_)
