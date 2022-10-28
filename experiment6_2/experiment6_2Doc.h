// experiment6_2Doc.h : interface of the CExperiment6_2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT6_2DOC_H__547779E0_72B4_4FF6_8AB0_02C2E680BC1D__INCLUDED_)
#define AFX_EXPERIMENT6_2DOC_H__547779E0_72B4_4FF6_8AB0_02C2E680BC1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExperiment6_2Doc : public CDocument
{
protected: // create from serialization only
	CExperiment6_2Doc();
	DECLARE_DYNCREATE(CExperiment6_2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment6_2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExperiment6_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment6_2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT6_2DOC_H__547779E0_72B4_4FF6_8AB0_02C2E680BC1D__INCLUDED_)
