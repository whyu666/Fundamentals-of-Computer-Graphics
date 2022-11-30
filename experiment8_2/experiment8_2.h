// experiment8_2.h : main header file for the EXPERIMENT8_2 application
//

#if !defined(AFX_EXPERIMENT8_2_H__95D1334E_7599_49B9_8C0F_5E4CE1949D57__INCLUDED_)
#define AFX_EXPERIMENT8_2_H__95D1334E_7599_49B9_8C0F_5E4CE1949D57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_2App:
// See experiment8_2.cpp for the implementation of this class
//

class CExperiment8_2App : public CWinApp
{
public:
	CExperiment8_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment8_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment8_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT8_2_H__95D1334E_7599_49B9_8C0F_5E4CE1949D57__INCLUDED_)
