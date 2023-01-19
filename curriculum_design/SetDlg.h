#if !defined(AFX_SETDLG_H__42B9464A_97CA_4F09_B21E_FF9336863200__INCLUDED_)
#define AFX_SETDLG_H__42B9464A_97CA_4F09_B21E_FF9336863200__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog

class CSetDlg : public CDialog
{
// Construction
public:
	CSetDlg(CWnd* pParent = NULL);   // standard constructor

	int light;
	int material;
	int reset;

// Dialog Data
	//{{AFX_DATA(CSetDlg)
	enum { IDD = IDD_SET };
	CString	m_position1;
	CString	m_position2;
	CString	m_position3;
	CString	m_color1;
	CString	m_color2;
	CString	m_color3;
	double	m_move_phi;
	double	m_move_theta;
	double	m_move_dz;
	double	m_move_dy;
	double	m_move_dx;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetDlg)
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	virtual void OnOK();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	afx_msg void OnRadio7();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETDLG_H__42B9464A_97CA_4F09_B21E_FF9336863200__INCLUDED_)
