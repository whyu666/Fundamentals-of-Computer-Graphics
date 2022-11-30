// experiment8_2View.h : interface of the CExperiment8_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT8_2VIEW_H__5EAB2FCE_F249_4619_A30C_821204D7C96C__INCLUDED_)
#define AFX_EXPERIMENT8_2VIEW_H__5EAB2FCE_F249_4619_A30C_821204D7C96C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Vector.h"  //包含矢量类
#include "Face.h"  //包含面类
#include "Lighting.h"  //包含光照类
#include "Fill.h"  //包含填充类

class CExperiment8_2View : public CView
{
protected: // create from serialization only
	CExperiment8_2View();
	DECLARE_DYNCREATE(CExperiment8_2View)

// Attributes
public:
	CExperiment8_2Doc* GetDocument();

// Operations
public:
	void ReadPoint();  //读入顶点表
	void ReadFace();  //读入面表
	void InitParameter();  //参数初始化
	void PerProject(CP3);  //透视投影
	void DoubleBuffer();  //双缓冲
	void DrawObject(CDC *);  //绘制正方体

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment8_2View)
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
	virtual ~CExperiment8_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	double R, Theta, Phi;  //视点在用户坐标系中的球坐标
	double d;  //视距
	CP3 P[8];  //点表
	CFace F[6];  //面表
	double k[9];  //运算常量
	CP3 ViewPoint;  //视点球坐标
	CP2 ScreenP;  //屏幕坐标系的二维坐标点
	CLighting *pLight;  //光源环境
	CMaterial *pMaterial;  //物体材质
	int LightNum;  //光源数量
	CFill fill;  //填充类对象

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment8_2View)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment8_2View.cpp
inline CExperiment8_2Doc* CExperiment8_2View::GetDocument()
   { return (CExperiment8_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT8_2VIEW_H__5EAB2FCE_F249_4619_A30C_821204D7C96C__INCLUDED_)
