// experiment2_3View.h : interface of the CExperiment2_3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT2_3VIEW_H__A1BDAC2C_50DE_463D_B3CD_4ACD9F34C0D6__INCLUDED_)
#define AFX_EXPERIMENT2_3VIEW_H__A1BDAC2C_50DE_463D_B3CD_4ACD9F34C0D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExperiment2_3View : public CView
{
protected: // create from serialization only
	CExperiment2_3View();
	DECLARE_DYNCREATE(CExperiment2_3View)

// Attributes
public:
	CExperiment2_3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment2_3View)
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
	virtual ~CExperiment2_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment2_3View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in experiment2_3View.cpp
inline CExperiment2_3Doc* CExperiment2_3View::GetDocument()
   { return (CExperiment2_3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT2_3VIEW_H__A1BDAC2C_50DE_463D_B3CD_4ACD9F34C0D6__INCLUDED_)
