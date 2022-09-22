// Rectangle.cpp: implementation of the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "experiment2.h"
#include "Rectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRectangle::CRectangle(int newLength, int newWidth)
{
	length = newLength;
	width = newWidth;
}

CRectangle::~CRectangle()
{

}

double CRectangle::Perimeter()
{
	return length * 2 + width * 2;
}

double CRectangle::Area()
{
	return length * width;
}