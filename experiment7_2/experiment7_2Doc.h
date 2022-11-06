// experiment7_2Doc.h : interface of the CExperiment7_2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT7_2DOC_H__AC467449_2C1A_4A49_8A2E_39639C3CA209__INCLUDED_)
#define AFX_EXPERIMENT7_2DOC_H__AC467449_2C1A_4A49_8A2E_39639C3CA209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExperiment7_2Doc : public CDocument
{
protected: // create from serialization only
	CExperiment7_2Doc();
	DECLARE_DYNCREATE(CExperiment7_2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment7_2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExperiment7_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment7_2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT7_2DOC_H__AC467449_2C1A_4A49_8A2E_39639C3CA209__INCLUDED_)
