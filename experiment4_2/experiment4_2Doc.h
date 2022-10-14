// experiment4_2Doc.h : interface of the CExperiment4_2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT4_2DOC_H__375A7E08_4C2B_48C5_B0A1_0FF2925A6BE0__INCLUDED_)
#define AFX_EXPERIMENT4_2DOC_H__375A7E08_4C2B_48C5_B0A1_0FF2925A6BE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExperiment4_2Doc : public CDocument
{
protected: // create from serialization only
	CExperiment4_2Doc();
	DECLARE_DYNCREATE(CExperiment4_2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment4_2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExperiment4_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment4_2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT4_2DOC_H__375A7E08_4C2B_48C5_B0A1_0FF2925A6BE0__INCLUDED_)
