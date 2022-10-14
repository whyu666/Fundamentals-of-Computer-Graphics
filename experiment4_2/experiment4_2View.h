// experiment4_2View.h : interface of the CExperiment4_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT4_2VIEW_H__A2A992F5_A5F9_4D22_8E43_AEBA60EAED53__INCLUDED_)
#define AFX_EXPERIMENT4_2VIEW_H__A2A992F5_A5F9_4D22_8E43_AEBA60EAED53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "math.h"
#define Round(d) int(floor(d + 0.5))
#include "Line.h"

class CExperiment4_2View : public CView
{
protected: // create from serialization only
	CExperiment4_2View();
	DECLARE_DYNCREATE(CExperiment4_2View)

// Attributes
public:
	CExperiment4_2Doc* GetDocument();

// Operations
public:
	void ReadPoint();//读入顶点表
	void DrawGraph(CDC *pDC);//绘制图形
	void DrawPolygon(CDC *pDC);//绘制多边形
	void FillPolygon(CDC *pDC);//填充多边形
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment4_2View)
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
	virtual ~CExperiment4_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CP2 P[7];  //点表
	double MaxX, MinX, MaxY, MinY;  //包围盒的对角点

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment4_2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment4_2View.cpp
inline CExperiment4_2Doc* CExperiment4_2View::GetDocument()
   { return (CExperiment4_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT4_2VIEW_H__A2A992F5_A5F9_4D22_8E43_AEBA60EAED53__INCLUDED_)
