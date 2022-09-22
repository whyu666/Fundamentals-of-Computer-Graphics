// experiment1_2.h : main header file for the EXPERIMENT1_2 application
//

#if !defined(AFX_EXPERIMENT1_2_H__ADB4A25F_B855_42E4_9576_A2A66D44221E__INCLUDED_)
#define AFX_EXPERIMENT1_2_H__ADB4A25F_B855_42E4_9576_A2A66D44221E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2App:
// See experiment1_2.cpp for the implementation of this class
//

class CExperiment1_2App : public CWinApp
{
public:
	CExperiment1_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment1_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment1_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT1_2_H__ADB4A25F_B855_42E4_9576_A2A66D44221E__INCLUDED_)
