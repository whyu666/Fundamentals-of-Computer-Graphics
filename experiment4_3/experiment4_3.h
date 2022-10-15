// experiment4_3.h : main header file for the EXPERIMENT4_3 application
//

#if !defined(AFX_EXPERIMENT4_3_H__8CDB7289_03A1_448F_A619_28EB3CD97DD1__INCLUDED_)
#define AFX_EXPERIMENT4_3_H__8CDB7289_03A1_448F_A619_28EB3CD97DD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3App:
// See experiment4_3.cpp for the implementation of this class
//

class CExperiment4_3App : public CWinApp
{
public:
	CExperiment4_3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment4_3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment4_3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT4_3_H__8CDB7289_03A1_448F_A619_28EB3CD97DD1__INCLUDED_)
