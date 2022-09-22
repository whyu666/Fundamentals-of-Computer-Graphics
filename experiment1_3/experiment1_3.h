// experiment1_3.h : main header file for the EXPERIMENT1_3 application
//

#if !defined(AFX_EXPERIMENT1_3_H__19C6D29F_42AD_4502_8AF2_E9D62B876AF2__INCLUDED_)
#define AFX_EXPERIMENT1_3_H__19C6D29F_42AD_4502_8AF2_E9D62B876AF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_3App:
// See experiment1_3.cpp for the implementation of this class
//

class CExperiment1_3App : public CWinApp
{
public:
	CExperiment1_3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment1_3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment1_3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT1_3_H__19C6D29F_42AD_4502_8AF2_E9D62B876AF2__INCLUDED_)
