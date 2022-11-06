// Vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR_H__8C972371_1C22_4E15_A2A8_3CE42319C9CB__INCLUDED_)
#define AFX_VECTOR_H__8C972371_1C22_4E15_A2A8_3CE42319C9CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P3.h"
#include "Pi3.h"

class CVector  //ʸ����
{
public:
	CVector();	
	CVector(CP3 &);
	CVector(CPi3 &);
	CVector(CP3 p1,CP3 p2);
	CVector(CPi3 p1,CPi3 p2);
	virtual ~CVector();
	CVector Unit();//��λʸ��
	double X();//ʸ����x����
	double Y();//ʸ����y����
	double Z();//ʸ����z����
	double Mold();//ʸ����ģ
	friend CVector operator +(CVector &,CVector &);//ʸ����
	friend CVector operator -(CVector &,CVector &);//ʸ����
	friend CVector operator *(CVector &,double);//ʸ����
	friend double Dot(CVector &,CVector &);//ʸ�����
	friend CVector operator /(CVector &,double);//ʸ������
	friend CVector operator *(CVector &,CVector &);//ʸ�����
private:
	double x,y,z;
};

#endif // !defined(AFX_VECTOR_H__8C972371_1C22_4E15_A2A8_3CE42319C9CB__INCLUDED_)
