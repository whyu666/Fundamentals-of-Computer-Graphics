// SetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "SetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog


CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetDlg)
	m_position1 = _T("");
	m_position2 = _T("");
	m_position3 = _T("");
	m_color1 = _T("");
	m_color2 = _T("");
	m_color3 = _T("");
	m_move_phi = 0.0;
	m_move_theta = 0.0;
	m_move_dz = 0.0;
	m_move_dy = 0.0;
	m_move_dx = 0.0;
	//}}AFX_DATA_INIT

	light=-1;
	material=-1;
	reset=-1;
}


void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetDlg)
	DDX_Text(pDX, IDC_EDIT1, m_position1);
	DDX_Text(pDX, IDC_EDIT2, m_position2);
	DDX_Text(pDX, IDC_EDIT3, m_position3);
	DDX_Text(pDX, IDC_EDIT4, m_color1);
	DDX_Text(pDX, IDC_EDIT5, m_color2);
	DDX_Text(pDX, IDC_EDIT6, m_color3);
	DDX_Text(pDX, IDC_EDIT_PHI, m_move_phi);
	DDV_MinMaxDouble(pDX, m_move_phi, 0., 180.);
	DDX_Text(pDX, IDC_EDIT_THETA, m_move_theta);
	DDX_Text(pDX, IDC_EDIT_DZ, m_move_dz);
	DDX_Text(pDX, IDC_EDIT_DY, m_move_dy);
	DDX_Text(pDX, IDC_EDIT_DX, m_move_dx);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialog)
	//{{AFX_MSG_MAP(CSetDlg)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio6)
	ON_BN_CLICKED(IDC_RADIO7, OnRadio7)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetDlg message handlers

void CSetDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	light=0;
}

void CSetDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	light=1;
}

void CSetDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	light=2;
}

void CSetDlg::OnOK() 
{
	// TODO: Add extra validation here
	CDialog::OnOK();
}

void CSetDlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	material=0;
}

void CSetDlg::OnRadio5() 
{
	// TODO: Add your control notification handler code here
	material=1;
}

void CSetDlg::OnRadio6() 
{
	// TODO: Add your control notification handler code here
	material=2;
}

void CSetDlg::OnRadio7() 
{
	// TODO: Add your control notification handler code here
	material=3;
}

void CSetDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	reset=1;
}
