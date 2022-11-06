// experiment7_2View.h : interface of the CExperiment7_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT7_2VIEW_H__05D08C59_AF03_432A_9ECD_985767D37810__INCLUDED_)
#define AFX_EXPERIMENT7_2VIEW_H__05D08C59_AF03_432A_9ECD_985767D37810__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Face.h"
#include "Bucket.h"
#include "ZBuffer.h"
#include "P3.h"


class CExperiment7_2View : public CView
{
protected: // create from serialization only
	CExperiment7_2View();
	DECLARE_DYNCREATE(CExperiment7_2View)

// Attributes
public:
	CExperiment7_2Doc* GetDocument();

// Operations
public:
	void ReadPoint();  //读入顶点表
	void ReadFace();  //读入面表
	void DoubleBuffer();  //双缓冲
	void DrawObject(CDC *);  //绘制交叉面

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment7_2View)
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
	virtual ~CExperiment7_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CP3 P[3][8], PNew[3][8];  //点表
	CFace F[6];  //面表
	CZBuffer zbuf;  //声明CZBuffer对象

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment7_2View)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment7_2View.cpp
inline CExperiment7_2Doc* CExperiment7_2View::GetDocument()
   { return (CExperiment7_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT7_2VIEW_H__05D08C59_AF03_432A_9ECD_985767D37810__INCLUDED_)
