// experiment5_2View.h : interface of the CExperiment5_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT5_2VIEW_H__031DB91F_00EF_4A1F_B839_0BADB8F37998__INCLUDED_)
#define AFX_EXPERIMENT5_2VIEW_H__031DB91F_00EF_4A1F_B839_0BADB8F37998__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"


class CExperiment5_2View : public CView
{
protected: // create from serialization only
	CExperiment5_2View();
	DECLARE_DYNCREATE(CExperiment5_2View)

// Attributes
public:
	CExperiment5_2Doc* GetDocument();

// Operations
public:
	void clip(double, double, double, double);  //裁剪函数
	unsigned int EnCode(double, double);  //编码函数

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment5_2View)
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
	virtual ~CExperiment5_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	double wxl, wxr, wyb, wyt, vxl, vxr, vyb, vyt;  //定义窗口与视口
	unsigned int RC1, RC2;  //直线端点的编码
	double a, b, c, d;  //窗视变换系数 
	CRect Rect;

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment5_2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment5_2View.cpp
inline CExperiment5_2Doc* CExperiment5_2View::GetDocument()
   { return (CExperiment5_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT5_2VIEW_H__031DB91F_00EF_4A1F_B839_0BADB8F37998__INCLUDED_)
