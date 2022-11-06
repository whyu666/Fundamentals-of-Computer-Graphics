// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__EE571A1F_D9DF_46E0_8BFE_83EF048F1422__INCLUDED_)
#define AFX_LINE_H__EE571A1F_D9DF_46E0_8BFE_83EF048F1422__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"

class CLine {  //ֱ����
public:
	CLine();
	virtual ~CLine();
    void MoveTo(CDC *, CP2);  //�ƶ���ָ��λ��
	void MoveTo(CDC *, int, int);  //���غ���
	void LineTo(CDC *, CP2);  //ͨ��ֱ�ߵ�����Bresenham�㷨,�������յ�����
	void LineTo(CDC *, int, int);  //���غ���
	int Sign(int);  //����-1,0,1���Ա���Ϊ<0,=0,>0
public:
	CP2 P1;  //ֱ���������
	CP2 P2;  //ֱ���յ�����
};

#endif // !defined(AFX_LINE_H__EE571A1F_D9DF_46E0_8BFE_83EF048F1422__INCLUDED_)
