// TestView.h : interface of the CTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTVIEW_H__1110FB37_9777_4A54_A57C_07F860D64C2D__INCLUDED_)
#define AFX_TESTVIEW_H__1110FB37_9777_4A54_A57C_07F860D64C2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//���openglͷ�ļ���ʼ
#include "gl\gl.h"//���Ŀ�(gl)
#include "gl\glu.h"//ʵ�ÿ�(glu)
#include "gl\glaux.h"//������(aux)
//���openglͷ�ļ�����

class CTestView : public CView
{
protected: // create from serialization only
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// Attributes
public:
	CTestDoc* GetDocument();

// Operations
public:
	void OnDrawScene();//��������
	void Texture();//��������
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestView)
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
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	HGLRC rc;//��Ⱦ������
	CClientDC *m_pDC;//�ͻ����豸������
	GLfloat  wAngleX;//x����ת��
	GLfloat  wAngleY; //y����ת��
    GLfloat  wAngleZ;//z����ת��
	float    a;//������߳�Ϊ2a
	GLuint	texture[6];//��������
	BOOL Play;//���������߼�����
// Generated message map functions
protected:
	//{{AFX_MSG(CTestView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnUpdateMenuDraw(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMenuPlay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TestView.cpp
inline CTestDoc* CTestView::GetDocument()
   { return (CTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTVIEW_H__1110FB37_9777_4A54_A57C_07F860D64C2D__INCLUDED_)
