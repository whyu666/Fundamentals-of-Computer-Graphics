// experiment5_2.h : main header file for the EXPERIMENT5_2 application
//

#if !defined(AFX_EXPERIMENT5_2_H__79683C24_3C12_496C_9A57_753C52117FEE__INCLUDED_)
#define AFX_EXPERIMENT5_2_H__79683C24_3C12_496C_9A57_753C52117FEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2App:
// See experiment5_2.cpp for the implementation of this class
//

class CExperiment5_2App : public CWinApp
{
public:
	CExperiment5_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment5_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment5_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT5_2_H__79683C24_3C12_496C_9A57_753C52117FEE__INCLUDED_)
