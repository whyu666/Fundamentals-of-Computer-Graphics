// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__8510F01A_C8F8_4902_A5A3_A79AA1F5FDDA__INCLUDED_)
#define AFX_RGB_H__8510F01A_C8F8_4902_A5A3_A79AA1F5FDDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB {  //颜色类
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

#endif // !defined(AFX_RGB_H__8510F01A_C8F8_4902_A5A3_A79AA1F5FDDA__INCLUDED_)
