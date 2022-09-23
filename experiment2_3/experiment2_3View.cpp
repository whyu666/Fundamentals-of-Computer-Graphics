// experiment2_3View.cpp : implementation of the CExperiment2_3View class
//

#include "stdafx.h"
#include "experiment2_3.h"

#include "experiment2_3Doc.h"
#include "experiment2_3View.h"

#include "math.h"
#include "InputDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_3View

IMPLEMENT_DYNCREATE(CExperiment2_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment2_3View, CView)
	//{{AFX_MSG_MAP(CExperiment2_3View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_3View construction/destruction

CExperiment2_3View::CExperiment2_3View()
{
	// TODO: add construction code here

}

CExperiment2_3View::~CExperiment2_3View()
{
}

BOOL CExperiment2_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_3View drawing

int round(double number)
{
    return (number > 0.0) ? (number + 0.5) : (number - 0.5); 
}

void CExperiment2_3View::OnDraw(CDC* pDC)
{
	CExperiment2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CInputDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		CRect rect;
		GetClientRect(&rect);
		//将坐标轴及原点移至中央
		pDC->SetMapMode(MM_ANISOTROPIC);
		pDC->SetWindowExt(rect.Width(), rect.Height());
		pDC->SetViewportExt(rect.Width(), -rect.Height());
		pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
		rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
		int r = 200, n = 5, k = 0, j; //r为初始最大的分割圆半径，j为交互传入的递归次数
		j = atoi(dlg.m_input.GetBuffer(0));
		double PI = 3.1415926;
		CPoint P[5]; //5等分圆得到五个顶点
		double Theta = 2 * PI / n;
		double Alta = PI / 10;
		double Ethta = PI / 5;
		double lr = 1 / (cos(Ethta) * cos(Ethta) * 4); //每次递归分割圆的缩小比例
		CPen blackPen, bluePen, * pOldPen;
		blackPen.CreatePen(0, 1, RGB(0, 0, 0));
		bluePen.CreatePen(0, 1, RGB(0, 0, 255));
		int i;
		while (k < j)
		{ 
			for (i = 0; i < n; i++) { 
				P[i].x = round(r  * cos(i * Theta + Alta * (1+k*2)));
				P[i].y = round(r  * sin(i * Theta + Alta * (1+k*2)));
			}
			pOldPen = pDC->SelectObject(&bluePen);
			for (i = 0; i < n; i++)
			{ 
				pDC->MoveTo(P[i]);
				pDC->LineTo(P[(i + 2) % 5]); //隔点绘制五角星
			}
			pDC->SelectObject(pOldPen);
			pOldPen = pDC->SelectObject(&blackPen);
			for (i = 0; i < n; i++)
			{ 
				pDC->MoveTo(P[i]);
				pDC->LineTo(P[(i + 1) % 5]); //连续点绘制正五边形
			}
			pDC->SelectObject(pOldPen);
			r = r * lr;
			k++;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_3View printing

BOOL CExperiment2_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment2_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment2_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_3View diagnostics

#ifdef _DEBUG
void CExperiment2_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment2_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment2_3Doc* CExperiment2_3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment2_3Doc)));
	return (CExperiment2_3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_3View message handlers
