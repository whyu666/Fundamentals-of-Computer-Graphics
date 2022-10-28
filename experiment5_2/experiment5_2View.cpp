// experiment5_2View.cpp : implementation of the CExperiment5_2View class
//

#include "stdafx.h"
#include "experiment5_2.h"

#include "experiment5_2Doc.h"
#include "experiment5_2View.h"

#include "math.h"
#include "InputDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define Round(d) int(floor(d + 0.5))

#define LEFT   1   //代表:0001
#define RIGHT  2   //代表:0010
#define BOTTOM 4   //代表:0100
#define TOP    8   //代表:1000

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2View

IMPLEMENT_DYNCREATE(CExperiment5_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment5_2View, CView)
	//{{AFX_MSG_MAP(CExperiment5_2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2View construction/destruction

CExperiment5_2View::CExperiment5_2View()
{
	// TODO: add construction code here
	Wxl = -300;
	Wyt = 100;
	Wxr = 300;
	Wyb = -100;
	PtCount = 0;
	//bDrawLine = FALSE;
}

CExperiment5_2View::~CExperiment5_2View()
{
}

BOOL CExperiment5_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2View drawing

void CExperiment5_2View::OnDraw(CDC* pDC)
{
	CExperiment5_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CInputDialog inputDlg;
	int nResponse = inputDlg.DoModal();
    if(nResponse == IDOK) {
		P[0].x = atoi(inputDlg.m_x1.GetBuffer(0));
		P[0].y = atoi(inputDlg.m_y1.GetBuffer(0));
		P[1].x = atoi(inputDlg.m_x2.GetBuffer(0));
		P[1].y = atoi(inputDlg.m_y2.GetBuffer(0));
		DoubleBuffer(pDC);
		CPoint temp0, temp1;
		temp0.x = P[0].x;
		temp0.y = P[0].y;
		temp1.x = P[1].x;
		temp1.y = P[1].y;
		pDC->MoveTo(temp0);
		pDC->LineTo(temp1);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2View printing

BOOL CExperiment5_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment5_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment5_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2View diagnostics

#ifdef _DEBUG
void CExperiment5_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment5_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment5_2Doc* CExperiment5_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment5_2Doc)));
	return (CExperiment5_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2View message handlers

void CExperiment5_2View::DoubleBuffer(CDC* pDC) {  //双缓冲
	CRect rect;  //定义客户区
	GetClientRect(&rect);  //获得客户区的大小
	pDC->SetMapMode(MM_ANISOTROPIC);  //pDC自定义坐标系
	pDC->SetWindowExt(rect.Width(), rect.Height());  //设置窗口范围
	pDC->SetViewportExt(rect.Width(), -rect.Height());  //设置视区范围,x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);  //客户区中心为原点
	CDC memDC;  //内存DC
	memDC.CreateCompatibleDC(pDC);  //创建一个与显示pDC兼容的内存memDC
	CBitmap NewBitmap, *pOldBitmap;  //内存中承载的临时位图 
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());  //创建兼容位图 
	pOldBitmap=memDC.SelectObject(&NewBitmap);  //将兼容位图选入memDC 
	memDC.FillSolidRect(rect, pDC->GetBkColor());  //按原来背景填充客户区，否则是黑色
	memDC.SetMapMode(MM_ANISOTROPIC);  //memDC自定义坐标系
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	DrawWindowRect(&memDC);  //绘制窗口
	if(PtCount >= 1) {
		memDC.MoveTo(Round(P[0].x), Round(P[0].y));
		memDC.LineTo(Round(P[1].x), Round(P[1].y));
	}
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);  //将内存memDC中的位图拷贝到显示pDC中
	memDC.SelectObject(pOldBitmap);  //恢复位图
	NewBitmap.DeleteObject();  //删除位图

	Cohen();
}

void CExperiment5_2View::DrawWindowRect(CDC* pDC) {  //绘制裁剪窗口
	pDC->SetTextColor(RGB(0, 255, 0));
	CPen NewPen3, *pOldPen3;  //定义3个像素宽度的画笔
	NewPen3.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	pOldPen3 = pDC->SelectObject(&NewPen3);
    pDC->Rectangle(Wxl, Wyt, Wxr, Wyb);
	pDC->SelectObject(pOldPen3);
	NewPen3.DeleteObject();
}

void CExperiment5_2View::Cohen() {  //Cohen-Sutherland算法
	CP2 p;  //交点坐标
	EnCode(P[0]);  //起点编码
	EnCode(P[1]);  //终点编码
	while(P[0].rc != 0 || P[1].rc != 0) {  //处理至少一个顶点在窗口之外的情况
		if((P[0].rc & P[1].rc)!=0) {  //简弃之
			PtCount = 0;
			return;
		}
		if(0 == P[0].rc) {  //确保P[0]位于窗口之外
			CP2 temp;
			temp = P[0];
			P[0] = P[1];
			P[1] = temp;
		}
		UINT RC = P[0].rc;
		double k = (P[1].y - P[0].y) / (P[1].x - P[0].x);  //直线段的斜率
		//窗口边界按左、右、下、上的顺序裁剪直线段
		if(RC & LEFT) {  //P[0]点位于窗口的左侧
			p.x = Wxl;  //计算交点y坐标
			p.y = k * (p.x - P[0].x) + P[0].y;
		}
		else if(RC & RIGHT) {  //P[0]点位于窗口的右侧
			p.x = Wxr;  //计算交点y坐标
			p.y = k * (p.x - P[0].x) + P[0].y;
		}
		else if(RC & BOTTOM) {  //P[0]点位于窗口的下侧
			p.y = Wyb;  //计算交点x坐标
			p.x = (p.y - P[0].y) / k + P[0].x;
		}			
		else if(RC & TOP) {  //P[0]点位于窗口的上侧
			p.y = Wyt;  //计算交点x坐标
			p.x = (p.y - P[0].y) / k + P[0].x;
		}
		EnCode(p);
		P[0] = p;
	}
}

void CExperiment5_2View::EnCode(CP2 &pt) {  //端点编码函数
	pt.rc = 0;
	if(pt.x < Wxl) {
		pt.rc = pt.rc | LEFT;
	}
	else if(pt.x > Wxr) {
		pt.rc = pt.rc | RIGHT;
	}
	if(pt.y < Wyb) {
		pt.rc = pt.rc | BOTTOM;
	}
	else if(pt.y > Wyt) {
		pt.rc = pt.rc | TOP;
	}
}