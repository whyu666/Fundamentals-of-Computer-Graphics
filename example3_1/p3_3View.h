// p3_3View.h : interface of the CP3_3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_P3_3VIEW_H__1D3A6DFB_F907_4567_802C_19377E8CFB72__INCLUDED_)
#define AFX_P3_3VIEW_H__1D3A6DFB_F907_4567_802C_19377E8CFB72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CP3_3View : public CView
{
protected: // create from serialization only
	CP3_3View();
	DECLARE_DYNCREATE(CP3_3View)

// Attributes
public:
	CP3_3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CP3_3View)
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
	virtual ~CP3_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CP3_3View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in p3_3View.cpp
inline CP3_3Doc* CP3_3View::GetDocument()
   { return (CP3_3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_P3_3VIEW_H__1D3A6DFB_F907_4567_802C_19377E8CFB72__INCLUDED_)
