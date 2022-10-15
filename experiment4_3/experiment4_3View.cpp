// experiment4_3View.cpp : implementation of the CExperiment4_3View class
//

#include "stdafx.h"
#include "experiment4_3.h"

#include "experiment4_3Doc.h"
#include "experiment4_3View.h"

#include <math.h>
#define Round(d) int(floor(d + 0.5))

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3View

IMPLEMENT_DYNCREATE(CExperiment4_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment4_3View, CView)
	//{{AFX_MSG_MAP(CExperiment4_3View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3View construction/destruction

CExperiment4_3View::CExperiment4_3View()
{
	// TODO: add construction code here

}

CExperiment4_3View::~CExperiment4_3View()
{
}

BOOL CExperiment4_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3View drawing

void CExperiment4_3View::OnDraw(CDC* pDC)
{
	CExperiment4_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	DrawGraph(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3View printing

BOOL CExperiment4_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment4_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment4_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3View diagnostics

#ifdef _DEBUG
void CExperiment4_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment4_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment4_3Doc* CExperiment4_3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment4_3Doc)));
	return (CExperiment4_3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3View message handlers

void CExperiment4_3View::ReadPoint() {  //点表
	P[0].x = 0;
	P[0].y = -200;
	P[1].x = -200;
	P[1].y = -200;
	P[2].x = -200;
	P[2].y = 0;
	P[3].x = -1;
	P[3].y = 0;
	P[4].x = -1;
	P[4].y = 199;
	P[5].x = 199;
	P[5].y = 199;
	P[6].x = 199;
	P[6].y = -1;
	P[7].x = 0;
	P[7].y = -1;
}

void CExperiment4_3View::DrawGraph(CDC *pDC) {
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2,-rect.Height() / 2);
	DrawPolygon(pDC);

	Seed = CP2(30, 20);
	//Seed = CP2(-30, -20);
	
	FillPolygon(pDC);
}

void CExperiment4_3View::DrawPolygon(CDC *pDC) {  //绘制多边形边界
	CLine *line = new CLine;
	CP2 t;
	for(int i = 0; i < 8; i++) {  //绘制多边形
		if(i == 0) {
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}
	}
	line->LineTo(pDC, t);  //闭合多边形
	delete line;
}

void CExperiment4_3View::FillPolygon(CDC *pDC) {  //填充多边形
	COLORREF BoundaryClr = RGB(0,0,0);  //边界色
	COLORREF PixelClr;  //当前像素点的颜色
	pHead = new CStackNode;  //建立头结点
	pHead->pNext = NULL;  //栈头结点的指针域总为空
	Push(Seed);	
	int x, y, x0 = Round(Seed.x), y0 = Round(Seed.y);  //x，y用于判断种子与图形的位置关系
	x = x0 - 1;
	while(BoundaryClr != pDC->GetPixel(x, y0) && SeedClr != pDC->GetPixel(x, y0)) {  //左方判断
		x--;
		if(x <= -rect.Width() / 2) {  //到达客户区最左端
			return;
		}
	}
	y = y0 + 1;
	while(BoundaryClr != pDC->GetPixel(x0, y) && SeedClr != pDC->GetPixel(x0, y)) {  //上方判断
		y++;
		if(y >= rect.Height() / 2) {  //到达客户区最上端
			return;
		}
	}
	x = x0 + 1;
	while(BoundaryClr != pDC->GetPixel(x, y0) && SeedClr != pDC->GetPixel(x, y0)) {  //右方判断
		x++;
		if(x >= rect.Width() / 2) {  //到达客户区最右端	
			return;
		}
	}
	y = y0 - 1;
	while(BoundaryClr != pDC->GetPixel(x0, y) && SeedClr != pDC->GetPixel(x0, y)) {  //下方判断
		y--;
		if(y <= -rect.Height() / 2) {  //到达客户区最下端
			return;
		}
	}
	while(pHead->pNext != NULL) {  //如果栈不为空
		CP2 PopPoint;
		Pop(PopPoint);
		if(SeedClr == pDC->GetPixel(Round(PopPoint.x), Round(PopPoint.y))) {
            continue;
        }
		pDC->SetPixelV(Round(PopPoint.x), Round(PopPoint.y), SeedClr);
		Left.x = PopPoint.x - 1;  //搜索出栈结点的左方像素
		Left.y = PopPoint.y;
		PixelClr = pDC->GetPixel(Round(Left.x), Round(Left.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {  //不是边界色并且未置成填充色
			Push(Left);  //左方像素入栈
        }
		LeftTop.x = PopPoint.x - 1;
		LeftTop.y = PopPoint.y + 1;  //搜索出栈结点的左上方像素
		PixelClr = pDC->GetPixel(Round(LeftTop.x), Round(LeftTop.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(LeftTop);  //左上方像素入栈
        }	
		Top.x = PopPoint.x;
		Top.y = PopPoint.y + 1;  //搜索出栈结点的上方像素
		PixelClr = pDC->GetPixel(Round(Top.x), Round(Top.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(Top);  //上方像素入栈
        }
		RightTop.x = PopPoint.x + 1;
		RightTop.y = PopPoint.y + 1;  //搜索出栈结点的右上方像素
		PixelClr = pDC->GetPixel(Round(RightTop.x), Round(RightTop.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(RightTop);  //右上方像素入栈
        }
		Right.x = PopPoint.x + 1;  //搜索出栈结点的右方像素
		Right.y = PopPoint.y;
		PixelClr = pDC->GetPixel(Round(Right.x), Round(Right.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(Right);  //右方像素入栈
        }
		RightBottom.x = PopPoint.x + 1;  //搜索出栈结点的右下方像素
		RightBottom.y = PopPoint.y - 1;
		PixelClr = pDC->GetPixel(Round(RightBottom.x), Round(RightBottom.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(RightBottom);  //右下方像素入栈
        }
		Bottom.x = PopPoint.x;
		Bottom.y = PopPoint.y - 1;  //搜索出栈结点的下方像素
		PixelClr = pDC->GetPixel(Round(Bottom.x), Round(Bottom.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(Bottom);  //下方像素入栈
        }
		LeftBottom.x = PopPoint.x - 1;
		LeftBottom.y = PopPoint.y - 1;  //搜索出栈结点的左下方像素
		PixelClr = pDC->GetPixel(Round(LeftBottom.x), Round(LeftBottom.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(LeftBottom);  //左下方像素入栈
        }
	}
	pDC->TextOut(rect.left + 50, rect.bottom - 20, "填充完毕");
	delete pHead;
	pHead = NULL;
}

void CExperiment4_3View::Push(CP2 point) {  //入栈函数
	pTop = new CStackNode;
	pTop->PixelPoint = point;
	pTop->pNext = pHead->pNext;
	pHead->pNext = pTop;
}

void CExperiment4_3View::Pop(CP2 &point) {  //出栈函数
	if(pHead->pNext != NULL) {
		pTop = pHead->pNext;
		pHead->pNext = pTop->pNext;
		point = pTop->PixelPoint;
		delete pTop;
	}
}

void CExperiment4_3View::OnInitialUpdate() {
	CView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	SeedClr = RGB(0, 0, 255);
	ReadPoint();
}