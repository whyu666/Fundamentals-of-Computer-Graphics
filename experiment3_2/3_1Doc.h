// 3_1Doc.h : interface of the CMy3_1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_3_1DOC_H__3B213658_9ABA_4982_BEB4_33490FA24A17__INCLUDED_)
#define AFX_3_1DOC_H__3B213658_9ABA_4982_BEB4_33490FA24A17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy3_1Doc : public CDocument
{
protected: // create from serialization only
	CMy3_1Doc();
	DECLARE_DYNCREATE(CMy3_1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy3_1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy3_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy3_1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_3_1DOC_H__3B213658_9ABA_4982_BEB4_33490FA24A17__INCLUDED_)
