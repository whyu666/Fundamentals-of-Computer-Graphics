// experiment2_3Doc.h : interface of the CExperiment2_3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPERIMENT2_3DOC_H__DBB3A24C_4D54_40A5_8E0A_F7301A11914A__INCLUDED_)
#define AFX_EXPERIMENT2_3DOC_H__DBB3A24C_4D54_40A5_8E0A_F7301A11914A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExperiment2_3Doc : public CDocument
{
protected: // create from serialization only
	CExperiment2_3Doc();
	DECLARE_DYNCREATE(CExperiment2_3Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment2_3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExperiment2_3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExperiment2_3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT2_3DOC_H__DBB3A24C_4D54_40A5_8E0A_F7301A11914A__INCLUDED_)
