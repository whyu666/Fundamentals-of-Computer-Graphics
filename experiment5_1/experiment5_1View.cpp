// experiment5_1View.cpp : implementation of the CExperiment5_1View class
//

#include "stdafx.h"
#include "experiment5_1.h"

#include "experiment5_1Doc.h"
#include "experiment5_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_1View

IMPLEMENT_DYNCREATE(CExperiment5_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment5_1View, CView)
	//{{AFX_MSG_MAP(CExperiment5_1View)
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_MENUSTART, OnUpdateMenustart)
	ON_COMMAND(ID_MENUSTART, OnMenustart)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_1View construction/destruction

CExperiment5_1View::CExperiment5_1View()
{
	// TODO: add construction code here
	beta = 0;
	Play = false;
}

CExperiment5_1View::~CExperiment5_1View()
{
}

BOOL CExperiment5_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_1View drawing

void CExperiment5_1View::OnDraw(CDC* pDC)
{
	CExperiment5_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	ReadPoint();
	DoubleBuffer();
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_1View printing

BOOL CExperiment5_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment5_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment5_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_1View diagnostics

#ifdef _DEBUG
void CExperiment5_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment5_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment5_1Doc* CExperiment5_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment5_1Doc)));
	return (CExperiment5_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_1View message handlers

void CExperiment5_1View::GetMaxX() {  //求屏幕最大x值
	CRect rect;
	GetClientRect(&rect);
    MaxX = rect.right;
}

void CExperiment5_1View::GetMaxY() {  //求屏幕最大y值
	CRect rect;
	GetClientRect(&rect);
    MaxY = rect.bottom;
}

void CExperiment5_1View::ReadPoint() {
	a = 100, b = 200;
	POld[0][0] = -a / 2;  //正方形顶点齐次坐标
    POld[0][1 ]= -(b - a / 2);
    POld[0][2] = 1;
	POld[1][0] = -a / 2;
    POld[1][1] = -(b + a / 2);
    POld[1][2] = 1;
	POld[2][0] = a/2;
    POld[2][1] = -(b + a / 2);
    POld[2][2] = 1;
	POld[3][0] = a / 2;
    POld[3][1] = -(b - a / 2);
    POld[3][2] = 1;	
}

void CExperiment5_1View::DrawPolygon(CDC *pDC, double p[][3]) {  //绘制多边形函数
	double x, y;
	for(int i = 0; i < 4; i++) {
		if(i == 0) {
			pDC->MoveTo(ROUND(p[i][0]), ROUND(p[i][1]));
			x = p[i][0];
            y = p[i][1];
		}
		else {
            pDC->LineTo(ROUND(p[i][0]), ROUND(p[i][1]));
        }
	}
	pDC->LineTo(ROUND(x), ROUND(y));
}


void CExperiment5_1View::DoubleBuffer() {  //双缓冲函数
	double Tx = 0, Ty = b;
	//平移变换矩阵
	T1[0][0] = 1;
    T1[0][1] = 0;
    T1[0][2] = 0;
	T1[1][0] = 0;
    T1[1][1] = 1;
    T1[1][2] = 0;
	T1[2][0] = -Tx;
    T1[2][1] = Ty;
    T1[2][2] = 1;
	//逆时针自转变换矩阵
	T2[0][0] = cos(beta * PI / 180);
    T2[0][1] = sin(beta * PI / 180);
    T2[0][2] = 0;
	T2[1][0] = -sin(beta * PI / 180);
    T2[1][1] = cos(beta * PI / 180);
    T2[1][2] = 0;
	T2[2][0] = 0;
    T2[2][1] = 0;
    T2[2][2] = 1;
	//反平移变换矩阵
	T3[0][0] = 1;
    T3[0][1] = 0;
    T3[0][2] = 0;
	T3[1][0] = 0;
    T3[1][1] = 1;
    T3[1][2] = 0;
	T3[2][0] = Tx;
    T3[2][1] =-Ty;
    T3[2][2] = 1;
	MultiMatrix(POld, T1);
	MultiMatrix(POld, T2);
	MultiMatrix(POld, T3);
	CDC *pDC = GetDC();  //客户区DC	
	GetMaxX();
    GetMaxY();
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(MaxX, MaxY);
	pDC->SetViewportExt(MaxX, -MaxY);
	pDC->SetViewportOrg(MaxX / 2, MaxY / 2);
	CDC	MemDC, Picture;
	MemDC.CreateCompatibleDC(pDC);
	MemDC.SetMapMode(MM_ANISOTROPIC);
	MemDC.SetWindowExt(MaxX, MaxY);
	MemDC.SetViewportExt(MaxX, -MaxY);
	MemDC.SetViewportOrg(MaxX / 2, MaxY / 2);
	CBitmap NewBitmap, *OldBitmap;
	NewBitmap.LoadBitmap(IDB_BITMAP);
	OldBitmap = MemDC.SelectObject(&NewBitmap);
	MemDC.BitBlt(-MaxX / 2, -MaxY / 2, MaxX, MaxY, &Picture, -MaxX / 2, -MaxY / 2, SRCCOPY);
	DrawCoor(&MemDC);
	DrawPolygon(&MemDC, POld);
	pDC->BitBlt(-MaxX / 2, -MaxY / 2, MaxX, MaxY, &MemDC, -MaxX / 2, -MaxY / 2, SRCCOPY);
	ReleaseDC(pDC);
	MemDC.SelectObject(OldBitmap);	
	NewBitmap.DeleteObject();
}

void CExperiment5_1View::MultiMatrix(double P0[][3], double T[3][3]) {  //矩阵相乘
	int i, j;
	for(i = 0; i < 4; i++) {
        for(j = 0; j < 3; j++) {
            PNew[i][j] = P0[i][0] * T[0][j] + P0[i][1] * T[1][j] + P0[i][2] * T[2][j];
        }
    }
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 3; j++) {
            POld[i][j] = PNew[i][j];
        }
	}
}

void CExperiment5_1View::DrawCoor(CDC *pDC) {  //绘制坐标系函数
	CPen NewPen, *OldPen;
	NewPen.CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	OldPen = pDC->SelectObject(&NewPen);
	pDC->MoveTo(-100, 0);
	pDC->LineTo(100, 0);
	pDC->MoveTo(0, 0);
	pDC->LineTo(0, -b);
	pDC->SelectObject(OldPen);
	NewPen.DeleteObject();	
}

void CExperiment5_1View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	beta = 10;
	DoubleBuffer();	
	CView::OnTimer(nIDEvent);
}

void CExperiment5_1View::OnUpdateMenustart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(Play) {
		pCmdUI->SetCheck(TRUE);
	    pCmdUI->SetText("停止");
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
		pCmdUI->SetText("开始");
	}
}

void CExperiment5_1View::OnMenustart() 
{
	// TODO: Add your command handler code here
	Play = Play ? FALSE : TRUE;
	if (Play) {  //设置动画的时间步
		SetTimer(1, 15, NULL);
	}
	else {
		KillTimer(1);
	}
}
