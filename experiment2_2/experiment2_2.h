// experiment2_2.h : main header file for the EXPERIMENT2_2 application
//

#if !defined(AFX_EXPERIMENT2_2_H__F5968F5B_6D6E_4AB6_B555_90794DCEF5B7__INCLUDED_)
#define AFX_EXPERIMENT2_2_H__F5968F5B_6D6E_4AB6_B555_90794DCEF5B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2App:
// See experiment2_2.cpp for the implementation of this class
//

class CExperiment2_2App : public CWinApp
{
public:
	CExperiment2_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment2_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment2_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT2_2_H__F5968F5B_6D6E_4AB6_B555_90794DCEF5B7__INCLUDED_)
