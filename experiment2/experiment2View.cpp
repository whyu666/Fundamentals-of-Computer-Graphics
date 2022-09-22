// experiment2View.cpp : implementation of the CExperiment2View class
//

#include "stdafx.h"
#include "experiment2.h"

#include "experiment2Doc.h"
#include "experiment2View.h"

#include "InputRectangle.h"
#include "Rectangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment2View

IMPLEMENT_DYNCREATE(CExperiment2View, CView)

BEGIN_MESSAGE_MAP(CExperiment2View, CView)
	//{{AFX_MSG_MAP(CExperiment2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment2View construction/destruction

CExperiment2View::CExperiment2View()
{
	// TODO: add construction code here

}

CExperiment2View::~CExperiment2View()
{
}

BOOL CExperiment2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment2View drawing

void CExperiment2View::OnDraw(CDC* pDC)
{
	CExperiment2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CInputRectangle inputDlg;
    int nResponse = inputDlg.DoModal();
    if(nResponse == IDOK)
    {
        CDC *pDC = GetDC();
        CRect rect;
        GetClientRect(&rect);
        pDC->SetMapMode(MM_ANISOTROPIC);
        pDC->SetWindowExt(rect.Width(), rect.Height());
        pDC->SetViewportExt(rect.Width(), -rect.Height());
        pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
        rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
        pDC->Rectangle(rect);//清空屏幕
        int length = atoi(inputDlg.m_Length.GetBuffer(0));
        int width = atoi(inputDlg.m_Width.GetBuffer(0));
        CRectangle crect(length, width);
        CString perimeter_text, area_text;
        perimeter_text.Format("长方形的周长为：%.2f", crect.Perimeter());
        area_text.Format("长方形的面积为：%.2f", crect.Area());
        pDC->TextOut(0, 0, perimeter_text);
        pDC->TextOut(0, 20, area_text);
        ReleaseDC(pDC);
    }
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment2View printing

BOOL CExperiment2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment2View diagnostics

#ifdef _DEBUG
void CExperiment2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment2Doc* CExperiment2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment2Doc)));
	return (CExperiment2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment2View message handlers
