#if !defined(AFX_INPUTRECTANGLE_H__D4282A44_E41E_4452_9E80_D6A6013A1C81__INCLUDED_)
#define AFX_INPUTRECTANGLE_H__D4282A44_E41E_4452_9E80_D6A6013A1C81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputRectangle.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInputRectangle dialog

class CInputRectangle : public CDialog
{
// Construction
public:
	CInputRectangle(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInputRectangle)
	enum { IDD = IDD_INPUT_RECTANGLE };
	CString	m_Length;
	CString	m_Width;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputRectangle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInputRectangle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTRECTANGLE_H__D4282A44_E41E_4452_9E80_D6A6013A1C81__INCLUDED_)
