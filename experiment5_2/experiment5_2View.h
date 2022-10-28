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
	void DoubleBuffer(CDC* pDC);  //双缓冲
	void DrawWindowRect(CDC *);  //绘制裁剪窗口
	void Cohen();  //裁剪函数
	void EnCode(CP2 &);  //编码函数
	CP2  Convert(CPoint point);  //坐标系转换

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
	CP2 P[2];  //直线的起点和终点
	int PtCount;  //顶点个数
	int	 Wxl,Wxr;  //窗口左上角点
	int  Wyb,Wyt;  //窗口右下角点

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
