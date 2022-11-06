// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__8510F01A_C8F8_4902_A5A3_A79AA1F5FDDA__INCLUDED_)
#define AFX_RGB_H__8510F01A_C8F8_4902_A5A3_A79AA1F5FDDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB {  //��ɫ��
public:
	CRGB();
	CRGB(double, double, double);
	friend CRGB operator+(CRGB &, CRGB &);
	friend CRGB operator*(double, CRGB &);
	virtual ~CRGB();
public:
	double red;  //��ɫ����
	double green;  //��ɫ����
	double blue;  //��ɫ����
};

#endif // !defined(AFX_RGB_H__8510F01A_C8F8_4902_A5A3_A79AA1F5FDDA__INCLUDED_)
