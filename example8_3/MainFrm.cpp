// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Test.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_GETMINMAXINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	FullScreen=false;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	int choice=MessageBox("�Ƿ�ȫ����ʾ��","ѡ����ʾģʽ",MB_YESNOCANCEL|MB_ICONQUESTION);
	if(choice==IDCANCEL)
	{
		exit(-1);
	}
   if(choice==IDYES)
	{
		FullScreen =TRUE;//ѡ��ȫ��ģʽ
	}			
 	if (FullScreen)						
	{//ȫ����ʾ
		FullScreen=TRUE;
		CRect winme,clientme;
		GetWindowRect(&winme);
		RepositionBars(0,0xffff,AFX_IDW_PANE_FIRST,reposQuery,&clientme);
		ClientToScreen(&clientme);
		int fullwide=GetSystemMetrics(SM_CXSCREEN);	
		int fullhide=GetSystemMetrics(SM_CYSCREEN);
		mefullscreen.left=winme.left-clientme.left;
		mefullscreen.top=winme.top-clientme.top;
		mefullscreen.right=winme.right-clientme.right+fullwide;
		mefullscreen.bottom=winme.bottom-clientme.bottom+fullhide;
		WINDOWPLACEMENT winfull;
		winfull.length=sizeof(WINDOWPLACEMENT);
		winfull.flags=0;
		winfull.showCmd=SW_SHOWNORMAL;
		winfull.rcNormalPosition=mefullscreen;
		SetWindowPlacement(&winfull);		
	}
	else
	{
		if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
			| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
			!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
		{
			TRACE0("Failed to create toolbar\n");
			return -1;      // fail to create
		}
		
		if (!m_wndStatusBar.Create(this) ||
			!m_wndStatusBar.SetIndicators(indicators,
			sizeof(indicators)/sizeof(UINT)))
		{
			TRACE0("Failed to create status bar\n");
			return -1;      // fail to create
		}
		
		// TODO: Delete these three lines if you don't want the toolbar to
		//  be dockable
		m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
		EnableDocking(CBRS_ALIGN_ANY);
		DockControlBar(&m_wndToolBar);
	}
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	// TODO: Add your message handler code here and/or call default
	if(FullScreen)
	{
		lpMMI->ptMaxSize.x=mefullscreen.Width();
		lpMMI->ptMaxSize.y=mefullscreen.Height();
		lpMMI->ptMaxPosition.x=mefullscreen.left;
		lpMMI->ptMaxPosition.y=mefullscreen.top;
		lpMMI->ptMaxTrackSize.x=mefullscreen.Width();
		lpMMI->ptMaxTrackSize.y=mefullscreen.Height();
	}
	CFrameWnd::OnGetMinMaxInfo(lpMMI);
}
