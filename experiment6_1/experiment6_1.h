// experiment6_1.h : main header file for the EXPERIMENT6_1 application
//

#if !defined(AFX_EXPERIMENT6_1_H__CF3C5E8C_FF15_4C21_A90E_33C278C15A11__INCLUDED_)
#define AFX_EXPERIMENT6_1_H__CF3C5E8C_FF15_4C21_A90E_33C278C15A11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1App:
// See experiment6_1.cpp for the implementation of this class
//

class CExperiment6_1App : public CWinApp
{
public:
	CExperiment6_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment6_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment6_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT6_1_H__CF3C5E8C_FF15_4C21_A90E_33C278C15A11__INCLUDED_)
