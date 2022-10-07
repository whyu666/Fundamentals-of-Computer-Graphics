// p3_3View.cpp : implementation of the CP3_3View class
//

#include "stdafx.h"
#include "p3_3.h"
#include "P2.h"
#include "Line.h"
#include "p3_3Doc.h"
#include "p3_3View.h"
#include "InputDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CP3_3View

IMPLEMENT_DYNCREATE(CP3_3View, CView)

BEGIN_MESSAGE_MAP(CP3_3View, CView)
	//{{AFX_MSG_MAP(CP3_3View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CP3_3View construction/destruction

CP3_3View::CP3_3View()
{
	// TODO: add construction code here

}

CP3_3View::~CP3_3View()
{
}

BOOL CP3_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CP3_3View drawing

void CP3_3View::OnDraw(CDC* pDC)
{
	CP3_3Doc* pDoc = GetDocument();
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
// CP3_3View printing

BOOL CP3_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CP3_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CP3_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CP3_3View diagnostics

#ifdef _DEBUG
void CP3_3View::AssertValid() const
{
	CView::AssertValid();
}

void CP3_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CP3_3Doc* CP3_3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CP3_3Doc)));
	return (CP3_3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CP3_3View message handlers
