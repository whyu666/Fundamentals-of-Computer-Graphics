// experiment1_1Doc.h : interface of the CExperiment1_1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT1_1DOC_H__C69B15EA_D5C3_42CA_9C9F_2950D3F8E741__INCLUDED_)
#define AFX_EXPERIMENT1_1DOC_H__C69B15EA_D5C3_42CA_9C9F_2950D3F8E741__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExperiment1_1Doc : public CDocument
{
protected: // create from serialization only
	CExperiment1_1Doc();
	DECLARE_DYNCREATE(CExperiment1_1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment1_1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExperiment1_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment1_1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT1_1DOC_H__C69B15EA_D5C3_42CA_9C9F_2950D3F8E741__INCLUDED_)
