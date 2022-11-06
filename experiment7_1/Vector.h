// Vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR_H__86AC7952_C167_40A0_A148_F0D423B43143__INCLUDED_)
#define AFX_VECTOR_H__86AC7952_C167_40A0_A148_F0D423B43143__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P3.h"

class CVector {  //矢量类
public:
	CVector();	
	virtual ~CVector();
	CVector(CP3 p);
	CVector(CP3 p1, CP3 p2);
	double X();  //矢量的x坐标
	double Y();  //矢量的y坐标
	double Z();  //矢量的z坐标
	double Mold();  //矢量的模
	CVector Unit();  //单位矢量
	friend CVector operator +(CVector &, CVector &);  //矢量和
	friend CVector operator -(CVector &, CVector &);  //矢量差
	friend CVector operator *(CVector &, double);  //矢量数乘
	friend CVector operator /(CVector &, double);  //矢量数除
	friend double Dot(CVector &, CVector &);  //矢量点积
	friend CVector operator *(CVector &, CVector &);  //矢量叉积
public:
	double x, y, z;
};

#endif // !defined(AFX_VECTOR_H__86AC7952_C167_40A0_A148_F0D423B43143__INCLUDED_)
