// experiment1_3View.cpp : implementation of the CExperiment1_3View class
//

#include "stdafx.h"
#include "experiment1_3.h"

#include "experiment1_3Doc.h"
#include "experiment1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_3View

IMPLEMENT_DYNCREATE(CExperiment1_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment1_3View, CView)
	//{{AFX_MSG_MAP(CExperiment1_3View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_3View construction/destruction

CExperiment1_3View::CExperiment1_3View()
{
	// TODO: add construction code here

}

CExperiment1_3View::~CExperiment1_3View()
{
}

BOOL CExperiment1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_3View drawing

void CExperiment1_3View::OnDraw(CDC* pDC)
{
	CExperiment1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;
    GetClientRect(&rect);
    pDC->SetMapMode(MM_ANISOTROPIC);
    pDC->SetWindowExt(rect.Width(), rect.Height());
    pDC->SetViewportExt(rect.Width(), -rect.Height());
    pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
    rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
    CRect rect1(CPoint(-250, 50), CPoint(250, 150));
    CRect rect2(CPoint(-250, -150), CPoint(250, -50));
    CBrush Brush(HS_BDIAGONAL, RGB(255, 0, 0));     //¶¨ÒåºìÉ«ÒõÓ°»­Ë¢
    CBrush *pOldBrush = pDC->SelectObject(&Brush);  //Ñ¡È¡»­Ë¢
    pDC->FillRect(&rect1, &Brush);                  //ÒõÓ°Ìî³ä¾ØÐÎ
    pDC->FillSolidRect(&rect2, RGB(255, 0, 0));     //ºìÉ«Ìî³ä¾ØÐÎ
    pDC->SelectObject(pOldBrush);                   //»Ö¸´»­Ë¢
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_3View printing

BOOL CExperiment1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_3View diagnostics

#ifdef _DEBUG
void CExperiment1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment1_3Doc* CExperiment1_3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment1_3Doc)));
	return (CExperiment1_3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_3View message handlers
