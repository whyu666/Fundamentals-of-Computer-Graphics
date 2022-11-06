// Vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR_H__86AC7952_C167_40A0_A148_F0D423B43143__INCLUDED_)
#define AFX_VECTOR_H__86AC7952_C167_40A0_A148_F0D423B43143__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P3.h"

class CVector {  //ʸ����
public:
	CVector();	
	virtual ~CVector();
	CVector(CP3 p);
	CVector(CP3 p1, CP3 p2);
	double X();  //ʸ����x����
	double Y();  //ʸ����y����
	double Z();  //ʸ����z����
	double Mold();  //ʸ����ģ
	CVector Unit();  //��λʸ��
	friend CVector operator +(CVector &, CVector &);  //ʸ����
	friend CVector operator -(CVector &, CVector &);  //ʸ����
	friend CVector operator *(CVector &, double);  //ʸ������
	friend CVector operator /(CVector &, double);  //ʸ������
	friend double Dot(CVector &, CVector &);  //ʸ�����
	friend CVector operator *(CVector &, CVector &);  //ʸ�����
public:
	double x, y, z;
};

#endif // !defined(AFX_VECTOR_H__86AC7952_C167_40A0_A148_F0D423B43143__INCLUDED_)
