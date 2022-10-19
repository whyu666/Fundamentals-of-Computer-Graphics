// experiment5_1View.h : interface of the CExperiment5_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT5_1VIEW_H__805A7351_431E_4DB6_AB73_8511979AFA3C__INCLUDED_)
#define AFX_EXPERIMENT5_1VIEW_H__805A7351_431E_4DB6_AB73_8511979AFA3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "math.h"
#define ROUND(a) int(a + 0.5)
#define PI 3.1415926


class CExperiment5_1View : public CView
{
protected: // create from serialization only
	CExperiment5_1View();
	DECLARE_DYNCREATE(CExperiment5_1View)

// Attributes
public:
	CExperiment5_1Doc* GetDocument();

// Operations
public:
	void GetMaxX();  //�����Ļ�����xֵ����
    void GetMaxY();  //�����Ļ�����yֵ����
	void DrawPolygon(CDC *,double P[4][3]);  //���ƶ����
	void MultiMatrix(double P0[][3],double T[3][3]);  //����˷�
	void ReadPoint();  //���붥������
	void DoubleBuffer();  //˫����
	void DrawCoor(CDC *);  //����������
	BOOL Play;  //��������

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment5_1View)
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
	virtual ~CExperiment5_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int MaxX, MaxY;  //��Ļx��y���������
	int a, b;  //�����α߳�������λ��
	double POld[4][3];  //�������ζ���
	double PNew[4][3];  //�������ζ���
	double beta;  //ת��
	double T1[3][3];  //ƽ�Ʊ任����
	double T2[3][3];  //��ת�任����
	double T3[3][3];  //��ƽ�Ʊ任����

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment5_1View)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnUpdateMenustart(CCmdUI* pCmdUI);
	afx_msg void OnMenustart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment5_1View.cpp
inline CExperiment5_1Doc* CExperiment5_1View::GetDocument()
   { return (CExperiment5_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT5_1VIEW_H__805A7351_431E_4DB6_AB73_8511979AFA3C__INCLUDED_)
