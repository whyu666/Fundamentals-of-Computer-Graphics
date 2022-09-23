// experiment2_3.h : main header file for the EXPERIMENT2_3 application
//

#if !defined(AFX_EXPERIMENT2_3_H__325B1977_7CE8_402D_AA0D_92F55A24762B__INCLUDED_)
#define AFX_EXPERIMENT2_3_H__325B1977_7CE8_402D_AA0D_92F55A24762B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_3App:
// See experiment2_3.cpp for the implementation of this class
//

class CExperiment2_3App : public CWinApp
{
public:
	CExperiment2_3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment2_3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment2_3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT2_3_H__325B1977_7CE8_402D_AA0D_92F55A24762B__INCLUDED_)
