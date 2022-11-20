// experiment8_1View.h : interface of the CExperiment8_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT8_1VIEW_H__F11DAB42_62C6_4F1F_B1F1_89017D2EA9EA__INCLUDED_)
#define AFX_EXPERIMENT8_1VIEW_H__F11DAB42_62C6_4F1F_B1F1_89017D2EA9EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"
#include "Face.h"
#include "Fill.h"

class CExperiment8_1View : public CView
{
protected: // create from serialization only
	CExperiment8_1View();
	DECLARE_DYNCREATE(CExperiment8_1View)

// Attributes
public:
	CExperiment8_1Doc* GetDocument();

// Operations
public:
	void GetMaxX();  //获得屏幕的最大x值
	void GetMaxY();  //获得屏幕的最大y值
	void ReadPointFlat();  //读入恒定颜色六边形顶点表
	void ReadPointSmooth();  //读入顶点表
	void ReadFace();  //读入面表
	void DrawHexagon(CP2 *);  //绘制六边形

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment8_1View)
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
	virtual ~CExperiment8_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int MaxX, MaxY;  //屏幕水平和垂直的最大坐标
	CP2 Pf[7], Ps[7];  //点表
	CFace F[6];  //面表
	bool Flag;  //恒定和渐变六边形区别标志
	CFill fill;  //填充类对象

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment8_1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment8_1View.cpp
inline CExperiment8_1Doc* CExperiment8_1View::GetDocument()
   { return (CExperiment8_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT8_1VIEW_H__F11DAB42_62C6_4F1F_B1F1_89017D2EA9EA__INCLUDED_)
