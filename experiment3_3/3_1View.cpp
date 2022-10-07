// 3_1View.cpp : implementation of the CMy3_1View class
//

#include "stdafx.h"
#include "3_1.h"

#include "3_1Doc.h"
#include "3_1View.h"

#include "P2.h"
#include "Line.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy3_1View

IMPLEMENT_DYNCREATE(CMy3_1View, CView)

BEGIN_MESSAGE_MAP(CMy3_1View, CView)
	//{{AFX_MSG_MAP(CMy3_1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy3_1View construction/destruction

CMy3_1View::CMy3_1View()
{
	// TODO: add construction code here

}

CMy3_1View::~CMy3_1View()
{
}

BOOL CMy3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy3_1View drawing

void CMy3_1View::OnDraw(CDC* pDC)
{
	CMy3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	

	CInputDlg dlg;
	dlg.DoModal();
	
	CP2 p0(dlg.m_x0,dlg.m_y0), p1(dlg.m_x1,dlg.m_y1);
	CLine line;
	line.MoveTo(pDC,p0);
	line.LineTo(pDC,p1);
}

/////////////////////////////////////////////////////////////////////////////
// CMy3_1View printing

BOOL CMy3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy3_1View diagnostics

#ifdef _DEBUG
void CMy3_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3_1Doc* CMy3_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3_1Doc)));
	return (CMy3_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy3_1View message handlers
