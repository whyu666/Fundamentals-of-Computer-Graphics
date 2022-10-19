// experiment5_1Doc.h : interface of the CExperiment5_1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT5_1DOC_H__6A65D459_730F_40D9_9D02_89D4BAF7C1EE__INCLUDED_)
#define AFX_EXPERIMENT5_1DOC_H__6A65D459_730F_40D9_9D02_89D4BAF7C1EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExperiment5_1Doc : public CDocument
{
protected: // create from serialization only
	CExperiment5_1Doc();
	DECLARE_DYNCREATE(CExperiment5_1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment5_1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExperiment5_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment5_1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT5_1DOC_H__6A65D459_730F_40D9_9D02_89D4BAF7C1EE__INCLUDED_)
