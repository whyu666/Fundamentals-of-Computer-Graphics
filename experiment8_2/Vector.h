// Vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR_H__3482D279_D890_4025_A4E1_4D74BE7BA0DD__INCLUDED_)
#define AFX_VECTOR_H__3482D279_D890_4025_A4E1_4D74BE7BA0DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P3.h"
#include "math.h"

class CVector {  //ʸ����
public:
	CVector();	
	CVector(CP3);
	CVector(CP3, CP3);
	virtual ~CVector();
	CVector Unit();  //��λʸ��
	double X();  //ʸ����x����
	double Y();  //ʸ����y����
	double Z();  //ʸ����z����
	double Mold();  //ʸ����ģ
	friend CVector operator +(CVector &, CVector &);  //ʸ����
	friend CVector operator -(CVector &, CVector &);  //ʸ����
	friend CVector operator *(CVector &, double); //ʸ������
	friend CVector operator /(CVector &, double); //ʸ������
	friend double Dot(CVector &, CVector &);  //ʸ�����
	friend CVector operator *(CVector &, CVector &);  //ʸ�����
public:
	double x, y, z;
};

#endif // !defined(AFX_VECTOR_H__3482D279_D890_4025_A4E1_4D74BE7BA0DD__INCLUDED_)
