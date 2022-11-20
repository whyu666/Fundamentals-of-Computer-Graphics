// experiment8_1.h : main header file for the EXPERIMENT8_1 application
//

#if !defined(AFX_EXPERIMENT8_1_H__41A21C71_0C60_40E9_8C5D_9A13A252816E__INCLUDED_)
#define AFX_EXPERIMENT8_1_H__41A21C71_0C60_40E9_8C5D_9A13A252816E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1App:
// See experiment8_1.cpp for the implementation of this class
//

class CExperiment8_1App : public CWinApp
{
public:
	CExperiment8_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExperiment8_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExperiment8_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPERIMENT8_1_H__41A21C71_0C60_40E9_8C5D_9A13A252816E__INCLUDED_)
