// experiment4_1View.h : interface of the CExperiment4_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT4_1VIEW_H__043EBDB0_DC1E_4440_9B49_E3D5509099A7__INCLUDED_)
#define AFX_EXPERIMENT4_1VIEW_H__043EBDB0_DC1E_4440_9B49_E3D5509099A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "p2.h"
#include "line.h"

class CExperiment4_1View : public CView
{
protected: // create from serialization only
	CExperiment4_1View();
	DECLARE_DYNCREATE(CExperiment4_1View)

// Attributes
public:
	CExperiment4_1Doc* GetDocument();

// Operations
public:
	void ReadPoint();  //读入顶点表
	void DrawGraph(CDC *pDC);  //绘制图形
	void DrawPolygon(CDC *pDC);  //绘制多边形
	void FillPolygon(CDC *pDC);  //填充多边形

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment4_1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExperiment4_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CP2 P[30], P1[30];  //浮点点表

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment4_1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment4_1View.cpp
inline CExperiment4_1Doc* CExperiment4_1View::GetDocument()
   { return (CExperiment4_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT4_1VIEW_H__043EBDB0_DC1E_4440_9B49_E3D5509099A7__INCLUDED_)
