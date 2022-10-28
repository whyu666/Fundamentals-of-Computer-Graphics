// experiment6_2.h : main header file for the EXPERIMENT6_2 application
//

#if !defined(AFX_EXPERIMENT6_2_H__1497388B_642E_4096_A6E8_6EC825B95A2A__INCLUDED_)
#define AFX_EXPERIMENT6_2_H__1497388B_642E_4096_A6E8_6EC825B95A2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_2App:
// See experiment6_2.cpp for the implementation of this class
//

class CExperiment6_2App : public CWinApp
{
public:
	CExperiment6_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment6_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment6_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT6_2_H__1497388B_642E_4096_A6E8_6EC825B95A2A__INCLUDED_)
