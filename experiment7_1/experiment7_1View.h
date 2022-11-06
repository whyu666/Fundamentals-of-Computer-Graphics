// experiment7_1View.h : interface of the CExperiment7_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT7_1VIEW_H__CCC502AA_F25C_4555_8051_9D253B0E7906__INCLUDED_)
#define AFX_EXPERIMENT7_1VIEW_H__CCC502AA_F25C_4555_8051_9D253B0E7906__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Line.h"  //包含直线类
#include "Face.h"  //包含面类
#include "Vector.h"  //包含矢量类


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
	void ReadPoint();  //读入点表
	void ReadFace();  //读入面表
	void InitParameter();  //参数初始化
	void PerProject(CP3);  //透视投影
	void DoubleBuffer();  //双缓冲绘图
	void DrawObject(CDC *);  //绘制正方体
	void DrawFace(CDC *,int);  //绘制表面		

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
	CP3 P[10];  //点表
	CFace F[10];  //面表
	double R, Theta, Phi, d;  //R,Theta,Phi：视点在用户坐标系的球坐标；d：视距
	double k[9];  //运算常量
	CP3 ViewPoint;  //视点球坐标
	CP2 ScreenP;  //屏幕坐标系的二维坐标点

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
