// experiment4_3View.h : interface of the CExperiment4_3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT4_3VIEW_H__75CF8CC5_D657_45AB_ACA3_E1A0DF5526B8__INCLUDED_)
#define AFX_EXPERIMENT4_3VIEW_H__75CF8CC5_D657_45AB_ACA3_E1A0DF5526B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Line.h"
#include "StackNode.h"


class CExperiment4_3View : public CView
{
protected: // create from serialization only
	CExperiment4_3View();
	DECLARE_DYNCREATE(CExperiment4_3View)

// Attributes
public:
	CExperiment4_3Doc* GetDocument();

// Operations
public:
	void ReadPoint();  //���붥���
	void DrawGraph(CDC *pDC);  //����ͼ��
	void DrawPolygon(CDC *pDC);  //���ƶ����
	void FillPolygon(CDC *pDC);  //�������
	void Push(CP2 point);  //��ջ
	void Pop(CP2 &point);  //��ջ

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment4_3View)
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
	virtual ~CExperiment4_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CRect rect;  //����ͻ���
	COLORREF SeedClr;  //����ɫ
	CP2 P[8];  //���
	CStackNode *pHead, *pTop;  //���ָ��
	CP2 Seed, Left, Top, Right, Bottom, LeftTop, RightTop, RightBottom, LeftBottom;  //���Ӽ���˸��ڽӵ�

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment4_3View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment4_3View.cpp
inline CExperiment4_3Doc* CExperiment4_3View::GetDocument()
   { return (CExperiment4_3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT4_3VIEW_H__75CF8CC5_D657_45AB_ACA3_E1A0DF5526B8__INCLUDED_)
