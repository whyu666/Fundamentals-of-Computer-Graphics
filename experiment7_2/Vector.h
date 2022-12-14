// Vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR_H__446F4ABB_0B19_4246_B6FF_1294C170F439__INCLUDED_)
#define AFX_VECTOR_H__446F4ABB_0B19_4246_B6FF_1294C170F439__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P3.h"
#include "Pi3.h"

class CVector {  //矢量类
public:
	CVector();	
	CVector(CP3 &p);
	CVector(CPi3 &p);
	CVector(CP3 p1, CP3 p2);
	CVector(CPi3 p1, CPi3 p2);
	virtual ~CVector();
	CVector Unit();  //单位矢量
	double X();  //矢量的x坐标
	double Y();  //矢量的y坐标
	double Z();  //矢量的z坐标
	double Mold();  //矢量的模
	friend CVector operator +(CVector &, CVector &);  //矢量和
	friend CVector operator -(CVector &, CVector &);  //矢量差
	friend CVector operator *(CVector &, double);  //矢量积
	friend double Dot(CVector &, CVector &);  //矢量点积
	friend CVector operator /(CVector &, double);  //矢量数除
	friend CVector operator *(CVector &, CVector &);  //矢量叉积
private:
	double x, y, z;
};

#endif // !defined(AFX_VECTOR_H__446F4ABB_0B19_4246_B6FF_1294C170F439__INCLUDED_)
