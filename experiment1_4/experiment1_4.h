// experiment1_4.h : main header file for the EXPERIMENT1_4 application
//

#if !defined(AFX_EXPERIMENT1_4_H__1C9EC2F2_1F6D_4E1F_8A6A_C90F9CEB47D6__INCLUDED_)
#define AFX_EXPERIMENT1_4_H__1C9EC2F2_1F6D_4E1F_8A6A_C90F9CEB47D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_4App:
// See experiment1_4.cpp for the implementation of this class
//

class CExperiment1_4App : public CWinApp
{
public:
	CExperiment1_4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment1_4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment1_4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT1_4_H__1C9EC2F2_1F6D_4E1F_8A6A_C90F9CEB47D6__INCLUDED_)
