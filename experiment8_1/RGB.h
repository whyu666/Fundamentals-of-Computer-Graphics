// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__F431DA3C_13B8_419C_9CC3_7BB1C5413F32__INCLUDED_)
#define AFX_RGB_H__F431DA3C_13B8_419C_9CC3_7BB1C5413F32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB  //颜色类
{
public:
	CRGB();
	CRGB(double, double, double);
	friend CRGB operator+(CRGB &, CRGB &);
	friend CRGB operator*(double, CRGB &);
	virtual ~CRGB();
public:
	double red;  //红色分量
	double green;  //绿色分量
	double blue;  //蓝色分量
};

#endif // !defined(AFX_RGB_H__F431DA3C_13B8_419C_9CC3_7BB1C5413F32__INCLUDED_)
