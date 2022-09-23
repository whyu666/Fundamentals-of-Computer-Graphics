// experiment2_2View.cpp : implementation of the CExperiment2_2View class
//

#include "stdafx.h"
#include "experiment2_2.h"

#include "experiment2_2Doc.h"
#include "experiment2_2View.h"

#include "math.h"
#include "InputDialog.h"
#define PI 3.14

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2View

IMPLEMENT_DYNCREATE(CExperiment2_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment2_2View, CView)
	//{{AFX_MSG_MAP(CExperiment2_2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2View construction/destruction

CExperiment2_2View::CExperiment2_2View()
{
	// TODO: add construction code here

}

CExperiment2_2View::~CExperiment2_2View()
{
}

BOOL CExperiment2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2View drawing

void CExperiment2_2View::OnDraw(CDC* pDC)
{
	CExperiment2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CInputDialog dlg;
	if(dlg.DoModal() == IDOK) //点击“确认”引发事件
	{
		BigCircle = atoi(dlg.m_R.GetBuffer(0));
		SmallCircle = atoi(dlg.m_r.GetBuffer(0));
		CRect rect;
		GetClientRect(&rect);
		pDC->SetMapMode(MM_ANISOTROPIC);
		pDC->SetWindowExt(rect.Width(),rect.Height());
		pDC->SetViewportExt(rect.Width(),-rect.Height());
		pDC->SetViewportOrg(rect.Width() / 2,rect.Height() / 2);
		rect.OffsetRect(-rect.Width() / 2,-rect.Height() / 2);
		//设置画刷
		CBrush *pOldBrush;
		pOldBrush=(CBrush*)pDC->SelectStockObject(NULL_BRUSH);
		//设置圆的参数
		double a = 0;
		for(; a < 2 * PI; )
		{
			CRect rect2(CPoint(BigCircle * cos(a) - SmallCircle, BigCircle*sin(a) - SmallCircle), 
				CPoint(BigCircle * cos(a) + SmallCircle, BigCircle * sin(a) + SmallCircle));
			pDC->Ellipse(rect2);
			a = a + (2 * PI / 40);
		}
		pDC->SelectObject(pOldBrush);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2View printing

BOOL CExperiment2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2View diagnostics

#ifdef _DEBUG
void CExperiment2_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment2_2Doc* CExperiment2_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment2_2Doc)));
	return (CExperiment2_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2View message handlers
