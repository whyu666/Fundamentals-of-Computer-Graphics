// experiment4_2View.cpp : implementation of the CExperiment4_2View class
//

#include "stdafx.h"
#include "experiment4_2.h"

#include "experiment4_2Doc.h"
#include "experiment4_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_2View

IMPLEMENT_DYNCREATE(CExperiment4_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment4_2View, CView)
	//{{AFX_MSG_MAP(CExperiment4_2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_2View construction/destruction

CExperiment4_2View::CExperiment4_2View()
{
	// TODO: add construction code here

}

CExperiment4_2View::~CExperiment4_2View()
{
}

BOOL CExperiment4_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_2View drawing

void CExperiment4_2View::OnDraw(CDC* pDC)
{
	CExperiment4_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	DrawGraph(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_2View printing

BOOL CExperiment4_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment4_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment4_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_2View diagnostics

#ifdef _DEBUG
void CExperiment4_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment4_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment4_2Doc* CExperiment4_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment4_2Doc)));
	return (CExperiment4_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_2View message handlers

void CExperiment4_2View::ReadPoint() {  //点表
	P[0].x = 50;
	P[0].y = 100;
	P[1].x = -150;
	P[1].y = 300;
	P[2].x = -250;
	P[2].y = 50;
	P[3].x = -150;
	P[3].y = -250;
	P[4].x = 0;
	P[4].y = -50;
	P[5].x = 100;
	P[5].y = -250;
	P[6].x = 300;
	P[6].y = 150;
}

void CExperiment4_2View::DrawGraph(CDC *pDC) {  //绘制图形
	CRect rect;  //定义客户区
	GetClientRect(&rect);  //获得客户区的大小
   	pDC->SetMapMode(MM_ANISOTROPIC);  //自定义坐标系
	pDC->SetWindowExt(rect.Width(), rect.Height());  //设置窗口比例
	pDC->SetViewportExt(rect.Width(), -rect.Height());   //设置视区比例，且x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);  //设置客户区中心为坐标系原点
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);  //矩形与客户区重合
	DrawPolygon(pDC);  //绘制多边形
	FillPolygon(pDC);  //填充多边形
}

void CExperiment4_2View::DrawPolygon(CDC *pDC) {
	for(int i = 0; i < 7; i++) {  //计算多边形边界
		if(P[i].x > MaxX) {
            MaxX = P[i].x;
        }
		if(P[i].x < MinX) {
            MinX = P[i].x;
        }
		if(P[i].y > MaxY) {
            MaxY = P[i].y;
        }
		if(P[i].y < MinY) {
            MinY = P[i].y;
        }
	}
	CLine *line = new CLine;
	CP2 t;
	for(i = 0; i < 7; i++) {  //绘制多边形
		if(i == 0) {
			line->MoveTo(pDC, P[i]);
			t =P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}
	}
	line->LineTo(pDC,t);  //闭合多边形
	line->MoveTo(pDC,CP2(MinX, MinY));  //绘制包围盒
	line->LineTo(pDC,CP2(MinX, MaxY));
	line->LineTo(pDC,CP2(MaxX, MaxY));
	line->LineTo(pDC,CP2(MaxX, MinY));
	line->LineTo(pDC,CP2(MinX, MinY));	
	delete line;
}

void CExperiment4_2View::FillPolygon(CDC *pDC) {
	COLORREF BClr = RGB(255, 255, 255);  //背景色
	COLORREF FClr = RGB(255, 0, 0);  //填充色
	int ymin, ymax;  //边的最小y值与最大y值
	double x, y, k;  //x,y当前点，k斜率的倒数
	for(int i = 0; i < 7; i++) {  //循环多边形所有边
		int j = (i + 1) % 7;
		k = (P[i].x - P[j].x) / (P[i].y - P[j].y);  //计算1/k
		if(P[i].y < P[j].y) {  //得到每条边y的最大值与最小值
			ymin = Round(P[i].y);
			ymax = Round(P[j].y);
			x = P[i].x;  //得到x|ymin
		}
		else {
			ymin = Round(P[j].y);
			ymax = Round(P[i].y);
			x = P[j].x;
		}
		for(y = ymin; y < ymax; y++) {  //沿每一条边循环扫描线
			for(int m = Round(x); m < MaxX; m++) {  //对每一条扫描线与边的交点的右侧像素循环
				if(FClr == pDC->GetPixel(m, Round(y))) {  //如果是填充色
					pDC->SetPixelV(m, Round(y), BClr);  //置为背景色
                }
				else {
                    pDC->SetPixelV(m, Round(y), FClr);  //置为填充色
                }	
			}
			x+=k;  //计算下一条扫描线的x起点坐标
		}
	}
}

void CExperiment4_2View::OnInitialUpdate() {
	CView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	ReadPoint();
	MinX = P[0].x;
	MaxX = P[0].x;
	MinY = P[0].y;
	MaxY = P[0].y;
}