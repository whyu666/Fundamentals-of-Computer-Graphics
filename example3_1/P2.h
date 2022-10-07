// P2.h: interface for the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2_H__BF2CD0BB_0D43_4E42_AF24_E8787FDCEA22__INCLUDED_)
#define AFX_P2_H__BF2CD0BB_0D43_4E42_AF24_E8787FDCEA22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CP2  
{
public:
	CP2();
	virtual ~CP2();
	CP2(double x,double y)
	{
		this->x=x;
		this->y=y;
	}
public:
	double x;
	double y;

};

#endif // !defined(AFX_P2_H__BF2CD0BB_0D43_4E42_AF24_E8787FDCEA22__INCLUDED_)
