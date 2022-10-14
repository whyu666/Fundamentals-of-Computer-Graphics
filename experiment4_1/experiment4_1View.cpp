// experiment4_1View.cpp : implementation of the CExperiment4_1View class
//

#include "stdafx.h"
#include "experiment4_1.h"

#include "experiment4_1Doc.h"
#include "experiment4_1View.h"

#define Round(d) int(floor(d + 0.5))  //四舍五入宏定义

#include "Fill.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_1View

IMPLEMENT_DYNCREATE(CExperiment4_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment4_1View, CView)
	//{{AFX_MSG_MAP(CExperiment4_1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_1View construction/destruction

CExperiment4_1View::CExperiment4_1View()
{
	// TODO: add construction code here

}

CExperiment4_1View::~CExperiment4_1View()
{
}

BOOL CExperiment4_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_1View drawing

void CExperiment4_1View::OnDraw(CDC* pDC)
{
	CExperiment4_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	DrawGraph(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_1View printing

BOOL CExperiment4_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment4_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment4_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_1View diagnostics

#ifdef _DEBUG
void CExperiment4_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment4_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment4_1Doc* CExperiment4_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment4_1Doc)));
	return (CExperiment4_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_1View message handlers

void CExperiment4_1View::ReadPoint() {  //点表
	//(-200,-50)(-100,-50)(-100,50)  (-200,50)(-200,-50)(-100,50)
	//(100,-50)(200,-50)(100,50)  (100,50)(200,50)(200,-50)
	P[0].x = -200;
	P[0].y = -50;
	P[1].x= -100;
	P[1].y = -50;
	P[2].x = -100;
	P[2].y = 50;
	P[3].x = -200;
	P[3].y = 50;
	P[4].x = -200;
	P[4].y = -50;
	P[5].x = -100;
	P[5].y = 50;
	P[6].x = 100;
	P[6].y = -50;
	P[7].x = 200;
	P[7].y = -50;
	P[8].x = 100;
	P[8].y = 50;
	P[9].x = 100;
	P[9].y = 50;
	P[10].x = 200;
	P[10].y = 50;
	P[11].x = 200;
	P[11].y = -50;
}

void CExperiment4_1View::DrawGraph(CDC *pDC) {  //绘制图形
	CRect rect;  //定义客户区
	GetClientRect(&rect);  //获得客户区的大小
   	pDC->SetMapMode(MM_ANISOTROPIC);  //自定义坐标系
	pDC->SetWindowExt(rect.Width(), rect.Height());  //设置窗口比例
	pDC->SetViewportExt(rect.Width(), -rect.Height());   //设置视区比例，且x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);  //设置客户区中心为坐标系原点
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);  //矩形与客户区重合
	//DrawPolygon(pDC);  //绘制多边形
	FillPolygon(pDC);  //填充多边形
	
}

void CExperiment4_1View::DrawPolygon(CDC *pDC) {  //绘制多边形边界
	CLine *line = new CLine;
	CP2 t;
	int i;
	for(i = 0; i < 3; i++) {  //绘制多边形
		if(i == 0) {
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}		
	}
	line->LineTo(pDC,t);  //闭合多边形
	for(i = 3; i < 6; i++) {
		if(i == 3) {
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}		
	}
	line->LineTo(pDC,t);
	for(i = 6; i < 9; i++) {
		if(i == 6) {
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}		
	}
	line->LineTo(pDC,t);
	for(i = 9; i < 12; i++) {
		if(i == 9) {
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}		
	}
	line->LineTo(pDC,t);
	delete line;
}

void CExperiment4_1View::FillPolygon(CDC *pDC) {  //填充多边形
	int i;
	for(i = 0; i < 3; i++) {  //转储顶点坐标，y坐标取为整数
		P1[i].x = P[i].x;
		P1[i].y = Round(P[i].y);
	}
	CFill *fill1 = new CFill;  //动态分配内存
	fill1->SetPoint(P1, 3);  //初始化Fill对象
	fill1->CreateBucket();  //建立桶表
	fill1->CreateEdge();  //建立边表
    fill1->Gouraud(pDC);  //填充多边形
	delete fill1;  //撤销内存
	Sleep(200);
	for(i = 0; i < 3; i++) {
		P1[i].x = P[i + 3].x;
		P1[i].y = Round(P[i + 3].y);
	}
	CFill *fill2 = new CFill;
	fill2->SetPoint(P1, 3);
	fill2->CreateBucket();
	fill2->CreateEdge();
    fill2->Gouraud(pDC);
	delete fill2;
	Sleep(200);
	for(i = 0; i < 3; i++) {
		P1[i].x = P[i + 6].x;
		P1[i].y = Round(P[i + 6].y);
	} 
	CFill *fill3 = new CFill;
	fill3->SetPoint(P1, 3);
	fill3->CreateBucket();
	fill3->CreateEdge();
    fill3->Gouraud(pDC);
	delete fill3;
	Sleep(200);
	for(i = 0; i < 3; i++) {
		P1[i].x = P[i + 9].x;
		P1[i].y = Round(P[i + 9].y);
	}
	CFill *fill4 = new CFill;
	fill4->SetPoint(P1, 3);
	fill4->CreateBucket();
	fill4->CreateEdge();
    fill4->Gouraud(pDC);
	delete fill4;
}

void CExperiment4_1View::OnInitialUpdate() {
	CView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	ReadPoint();
}