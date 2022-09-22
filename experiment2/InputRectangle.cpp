// InputRectangle.cpp : implementation file
//

#include "stdafx.h"
#include "experiment2.h"
#include "InputRectangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputRectangle dialog


CInputRectangle::CInputRectangle(CWnd* pParent /*=NULL*/)
	: CDialog(CInputRectangle::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInputRectangle)
	m_Length = _T("");
	m_Width = _T("");
	//}}AFX_DATA_INIT
}


void CInputRectangle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputRectangle)
	DDX_Text(pDX, IDC_LENGTH, m_Length);
	DDX_Text(pDX, IDC_WIDTH, m_Width);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInputRectangle, CDialog)
	//{{AFX_MSG_MAP(CInputRectangle)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputRectangle message handlers
