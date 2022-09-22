// experiment1_1.h : main header file for the EXPERIMENT1_1 application
//

#if !defined(AFX_EXPERIMENT1_1_H__D26E03E3_315B_41D1_B622_A7BCAFC93FAC__INCLUDED_)
#define AFX_EXPERIMENT1_1_H__D26E03E3_315B_41D1_B622_A7BCAFC93FAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1App:
// See experiment1_1.cpp for the implementation of this class
//

class CExperiment1_1App : public CWinApp
{
public:
	CExperiment1_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment1_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment1_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT1_1_H__D26E03E3_315B_41D1_B622_A7BCAFC93FAC__INCLUDED_)
