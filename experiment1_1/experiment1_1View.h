// experiment1_1View.h : interface of the CExperiment1_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT1_1VIEW_H__899CFB0E_4074_46A6_BA9F_B1BACC204159__INCLUDED_)
#define AFX_EXPERIMENT1_1VIEW_H__899CFB0E_4074_46A6_BA9F_B1BACC204159__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExperiment1_1View : public CView
{
protected: // create from serialization only
	CExperiment1_1View();
	DECLARE_DYNCREATE(CExperiment1_1View)

// Attributes
public:
	CExperiment1_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment1_1View)
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
	virtual ~CExperiment1_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment1_1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment1_1View.cpp
inline CExperiment1_1Doc* CExperiment1_1View::GetDocument()
   { return (CExperiment1_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT1_1VIEW_H__899CFB0E_4074_46A6_BA9F_B1BACC204159__INCLUDED_)
