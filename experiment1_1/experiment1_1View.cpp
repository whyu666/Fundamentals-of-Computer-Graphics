// experiment1_1View.cpp : implementation of the CExperiment1_1View class
//

#include "stdafx.h"
#include "experiment1_1.h"

#include "experiment1_1Doc.h"
#include "experiment1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1View

IMPLEMENT_DYNCREATE(CExperiment1_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment1_1View, CView)
	//{{AFX_MSG_MAP(CExperiment1_1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1View construction/destruction

CExperiment1_1View::CExperiment1_1View()
{
	// TODO: add construction code here

}

CExperiment1_1View::~CExperiment1_1View()
{
}

BOOL CExperiment1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1View drawing

void CExperiment1_1View::OnDraw(CDC* pDC)
{
	CExperiment1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;
    GetClientRect(&rect);
    pDC->SetMapMode(MM_ANISOTROPIC);
    pDC->SetWindowExt(rect.Width(), rect.Height());
    pDC->SetViewportExt(rect.Width(), -rect.Height());
    pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
    CPoint p0(-100, -50), p1(100, 50);
    CPen NewPen, *pOldPen;
    NewPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
    pOldPen = pDC->SelectObject(&NewPen);
    pDC->MoveTo(p0);
    pDC->LineTo(p1);
    pDC->SelectObject(pOldPen);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1View printing

BOOL CExperiment1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1View diagnostics

#ifdef _DEBUG
void CExperiment1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment1_1Doc* CExperiment1_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment1_1Doc)));
	return (CExperiment1_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1View message handlers
