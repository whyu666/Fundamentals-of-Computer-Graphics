// experiment1_2View.cpp : implementation of the CExperiment1_2View class
//

#include "stdafx.h"
#include "experiment1_2.h"

#include "experiment1_2Doc.h"
#include "experiment1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2View

IMPLEMENT_DYNCREATE(CExperiment1_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment1_2View, CView)
	//{{AFX_MSG_MAP(CExperiment1_2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2View construction/destruction

CExperiment1_2View::CExperiment1_2View()
{
	// TODO: add construction code here

}

CExperiment1_2View::~CExperiment1_2View()
{
}

BOOL CExperiment1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2View drawing

void CExperiment1_2View::OnDraw(CDC* pDC)
{
	CExperiment1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;
    GetClientRect(&rect);
    pDC->SetMapMode(MM_ANISOTROPIC);
    pDC->SetWindowExt(rect.Width(), rect.Height());
    pDC->SetViewportExt(rect.Width(), -rect.Height());
    pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
    rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
    rect.DeflateRect(100, 100);
    CPen NewPen, *pOldPen;
    NewPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
    pOldPen = pDC->SelectObject(&NewPen);
    CBrush NewBrush, *pOldBrush;
    NewBrush.CreateSolidBrush(RGB(255, 0, 0));
    pOldBrush = pDC->SelectObject(&NewBrush);
    pDC->Rectangle(rect);
    pDC->RoundRect(rect, CPoint(50, 50));
    pDC->SelectObject(pOldPen);
    pDC->SelectObject(pOldBrush);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2View printing

BOOL CExperiment1_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment1_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment1_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2View diagnostics

#ifdef _DEBUG
void CExperiment1_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment1_2Doc* CExperiment1_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment1_2Doc)));
	return (CExperiment1_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2View message handlers
