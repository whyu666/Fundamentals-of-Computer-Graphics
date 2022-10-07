// 3_1View.h : interface of the CMy3_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_3_1VIEW_H__C91186C6_9024_460B_9D7B_8B92E19E9EBD__INCLUDED_)
#define AFX_3_1VIEW_H__C91186C6_9024_460B_9D7B_8B92E19E9EBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy3_1View : public CView
{
protected: // create from serialization only
	CMy3_1View();
	DECLARE_DYNCREATE(CMy3_1View)

// Attributes
public:
	CMy3_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy3_1View)
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
	virtual ~CMy3_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy3_1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 3_1View.cpp
inline CMy3_1Doc* CMy3_1View::GetDocument()
   { return (CMy3_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_3_1VIEW_H__C91186C6_9024_460B_9D7B_8B92E19E9EBD__INCLUDED_)
