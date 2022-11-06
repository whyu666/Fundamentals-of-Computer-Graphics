// experiment7_1View.h : interface of the CExperiment7_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT7_1VIEW_H__CCC502AA_F25C_4555_8051_9D253B0E7906__INCLUDED_)
#define AFX_EXPERIMENT7_1VIEW_H__CCC502AA_F25C_4555_8051_9D253B0E7906__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Line.h"  //����ֱ����
#include "Face.h"  //��������
#include "Vector.h"  //����ʸ����


class CExperiment7_1View : public CView
{
protected: // create from serialization only
	CExperiment7_1View();
	DECLARE_DYNCREATE(CExperiment7_1View)

// Attributes
public:
	CExperiment7_1Doc* GetDocument();

// Operations
public:
	void ReadPoint();  //������
	void ReadFace();  //�������
	void InitParameter();  //������ʼ��
	void PerProject(CP3);  //͸��ͶӰ
	void DoubleBuffer();  //˫�����ͼ
	void DrawObject(CDC *);  //����������
	void DrawFace(CDC *,int);  //���Ʊ���		

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment7_1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExperiment7_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CP3 P[10];  //���
	CFace F[10];  //���
	double R, Theta, Phi, d;  //R,Theta,Phi���ӵ����û�����ϵ�������ꣻd���Ӿ�
	double k[9];  //���㳣��
	CP3 ViewPoint;  //�ӵ�������
	CP2 ScreenP;  //��Ļ����ϵ�Ķ�ά�����

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment7_1View)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment7_1View.cpp
inline CExperiment7_1Doc* CExperiment7_1View::GetDocument()
   { return (CExperiment7_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT7_1VIEW_H__CCC502AA_F25C_4555_8051_9D253B0E7906__INCLUDED_)
