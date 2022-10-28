// experiment6_2View.h : interface of the CExperiment6_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT6_2VIEW_H__1E6C1330_47D8_4852_8794_5DB73E40B151__INCLUDED_)
#define AFX_EXPERIMENT6_2VIEW_H__1E6C1330_47D8_4852_8794_5DB73E40B151__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Face.h"


class CExperiment6_2View : public CView
{
protected: // create from serialization only
	CExperiment6_2View();
	DECLARE_DYNCREATE(CExperiment6_2View)

// Attributes
public:
	CExperiment6_2Doc* GetDocument();

// Operations
public:
	void GetMaxY();  //�����Ļ�����yֵ����
	void GetMaxX();  //�����Ļ�����xֵ����
	void ReadPoint();  //���붥�㺯��
	void ReadFace();  //�����溯��
	void DrawPolygon();  //���ƶ����庯��
	void Project(const double P3[][4], double P2[][3], const int);  //б�Ȳ�ͶӰ�任
	void MultiMatrix(double P[][4], int T[][4]);  //�������
	void Line(CDC *, CPoint p[], int num);  //���ƶ���α��ߺ���
	void ClearMatrix(int A[4][4]);  //���������
	void DrawVView();  //��������ͼ����
	void DrawHView();  //���Ƹ���ͼ����
	void DrawWView();  //��������ͼ����
	void DrawTriView();  //��������ͼ����

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment6_2View)
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
	virtual ~CExperiment6_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int MaxX, MaxY;  //��Ļx��y���������
	double P3[10][4];  //��ά����
	double P2[10][3];  //��ά����
	CFace F[7];  //���
	int TV[4][4];  //����ͼ�任����
	int TH[4][4];  //����ͼ�任����
	int TW[4][4];  //����ͼ�任����
	double Tri[10][4];  //����ͼ�任��ľ���

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment6_2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment6_2View.cpp
inline CExperiment6_2Doc* CExperiment6_2View::GetDocument()
   { return (CExperiment6_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT6_2VIEW_H__1E6C1330_47D8_4852_8794_5DB73E40B151__INCLUDED_)
