// p3_3.h : main header file for the P3_3 application
//

#if !defined(AFX_P3_3_H__CD086575_5A9A_482A_89FA_E531DB5773B3__INCLUDED_)
#define AFX_P3_3_H__CD086575_5A9A_482A_89FA_E531DB5773B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CP3_3App:
// See p3_3.cpp for the implementation of this class
//

class CP3_3App : public CWinApp
{
public:
	CP3_3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CP3_3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CP3_3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_P3_3_H__CD086575_5A9A_482A_89FA_E531DB5773B3__INCLUDED_)
