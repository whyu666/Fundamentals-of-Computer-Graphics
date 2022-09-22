// experiment1_4View.cpp : implementation of the CExperiment1_4View class
//

#include "stdafx.h"
#include "experiment1_4.h"

#include "experiment1_4Doc.h"
#include "experiment1_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_4View

IMPLEMENT_DYNCREATE(CExperiment1_4View, CView)

BEGIN_MESSAGE_MAP(CExperiment1_4View, CView)
	//{{AFX_MSG_MAP(CExperiment1_4View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_4View construction/destruction

CExperiment1_4View::CExperiment1_4View()
{
	// TODO: add construction code here

}

CExperiment1_4View::~CExperiment1_4View()
{
}

BOOL CExperiment1_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_4View drawing

void CExperiment1_4View::OnDraw(CDC* pDC)
{
	CExperiment1_4Doc* pDoc = GetDocument();
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
    CBrush NewBrush, *pOldBrush;
    pOldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);   //选择透明画刷
    int r = rect.Height() / 2;                                  //定义圆的半径
    CRect rect1(CPoint(-r, -r), CPoint(r, r));                  //定义圆的外接矩形
    pDC->Ellipse(rect1);                                        //绘制圆
    pDC->Ellipse(rect);                                         //绘制椭圆
    pDC->Rectangle(rect);                                       //绘制外接矩形
    pDC->SelectObject(pOldBrush);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_4View printing

BOOL CExperiment1_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment1_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment1_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_4View diagnostics

#ifdef _DEBUG
void CExperiment1_4View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment1_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment1_4Doc* CExperiment1_4View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment1_4Doc)));
	return (CExperiment1_4Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_4View message handlers
