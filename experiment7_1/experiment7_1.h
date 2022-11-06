// experiment7_1.h : main header file for the EXPERIMENT7_1 application
//

#if !defined(AFX_EXPERIMENT7_1_H__B11D5C66_D39A_4B0B_9534_0A666D3C9203__INCLUDED_)
#define AFX_EXPERIMENT7_1_H__B11D5C66_D39A_4B0B_9534_0A666D3C9203__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1App:
// See experiment7_1.cpp for the implementation of this class
//

class CExperiment7_1App : public CWinApp
{
public:
	CExperiment7_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment7_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment7_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT7_1_H__B11D5C66_D39A_4B0B_9534_0A666D3C9203__INCLUDED_)
