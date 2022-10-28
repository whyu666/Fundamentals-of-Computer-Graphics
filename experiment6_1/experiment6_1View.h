// experiment6_1View.h : interface of the CExperiment6_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT6_1VIEW_H__A476F134_9EC2_4169_A083_8237B1722DB3__INCLUDED_)
#define AFX_EXPERIMENT6_1VIEW_H__A476F134_9EC2_4169_A083_8237B1722DB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Face.h"
#include "P3.h"


class CExperiment6_1View : public CView
{
protected: // create from serialization only
	CExperiment6_1View();
	DECLARE_DYNCREATE(CExperiment6_1View)

// Attributes
public:
	CExperiment6_1Doc* GetDocument();

// Operations
public:
	void ReadPoint();  //点表
	void ReadFace();  //面表
	void DrawCube();  //绘制立方体
	CP2 Project(CP3 P0);  //斜平行投影
	void Line(CDC *, int, CP2 p[]);  //绘制直线

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment6_1View)
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
	virtual ~CExperiment6_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CP3 P3[8];  //三维变换点
	CP2 P2;  //二维变换点
	double alpha,beta;  //α和β
	CFace  F[6];  //面表
	CRect Rect;

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment6_1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment6_1View.cpp
inline CExperiment6_1Doc* CExperiment6_1View::GetDocument()
   { return (CExperiment6_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT6_1VIEW_H__A476F134_9EC2_4169_A083_8237B1722DB3__INCLUDED_)
