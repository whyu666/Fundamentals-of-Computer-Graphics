// Rectangle.h: interface for the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__C8F8E1D3_C966_4E6F_B66E_960171819FF4__INCLUDED_)
#define AFX_RECTANGLE_H__C8F8E1D3_C966_4E6F_B66E_960171819FF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRectangle  
{
public:
	CRectangle(int newLength, int newWidth);
	virtual ~CRectangle();
	double Perimeter();
	double Area();

private:
	int length, width;

};

#endif // !defined(AFX_RECTANGLE_H__C8F8E1D3_C966_4E6F_B66E_960171819FF4__INCLUDED_)
