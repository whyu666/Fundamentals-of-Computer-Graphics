// P2.h: interface for the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2_H__E0C65A4E_B3AA_400C_AEC5_87F27E135FE8__INCLUDED_)
#define AFX_P2_H__E0C65A4E_B3AA_400C_AEC5_87F27E135FE8__INCLUDED_

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

#endif // !defined(AFX_P2_H__E0C65A4E_B3AA_400C_AEC5_87F27E135FE8__INCLUDED_)
