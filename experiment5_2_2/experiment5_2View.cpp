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

#define ROUND(a) int(a + 0.5)  //四舍五入
#define LEFT 1  //编码0001
#define RIGHT 2  //编码0010
#define BOTTOM 4  //编码0100
#define TOP 8  //编码1000

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
	 wxl = 100;
	 wxr = 400;
	 wyb = 200;
	 wyt = 500;
	 vxl = 750;
	 vxr = 1150;
	 vyb = 250;
	 vyt = 450;
	 a = (vxr - vxl) / (wxr - wxl);
	 b = vxl - wxl * a;
	 c = (vyt - vyb) / (wyt - wyb);
	 d = vyb - wyb * c;
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
	CPen Pen1, Pen2, Pen3, *pOldPen;  //定义3个像素的画笔
	Pen1.CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	pOldPen = pDC->SelectObject(&Pen1);
	//绘制窗口
	pDC->MoveTo(ROUND(wxl), ROUND(wyt));
	pDC->LineTo(ROUND(wxr), ROUND(wyt));
	pDC->LineTo(ROUND(wxr), ROUND(wyb));
	pDC->LineTo(ROUND(wxl), ROUND(wyb));
	pDC->LineTo(ROUND(wxl), ROUND(wyt));
	pDC->TextOut((ROUND(wxl) + ROUND(wxr)) / 2, ROUND(wyb) - 20, "窗口");  //窗口标题
	pDC->SelectObject(pOldPen);
	Pen1.DeleteObject();	
	Pen2.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	pOldPen = pDC->SelectObject(&Pen2);
	//绘制视区
	pDC->MoveTo(ROUND(vxl), ROUND(vyt));
	pDC->LineTo(ROUND(vxr), ROUND(vyt));
	pDC->LineTo(ROUND(vxr), ROUND(vyb));
	pDC->LineTo(ROUND(vxl), ROUND(vyb));
	pDC->LineTo(ROUND(vxl), ROUND(vyt));
	pDC->TextOut((ROUND(vxl) + ROUND(vxr)) / 2, ROUND(vyb) - 20, "视区");  //视区标题
	pDC->SelectObject(pOldPen);
	Pen2.DeleteObject();
	//绘制窗口与视区的分割线
	GetClientRect(&Rect);  //获得客户区的大小
	Pen3.CreatePen(PS_SOLID, 3, RGB(128, 128, 128));
	pOldPen = pDC->SelectObject(&Pen3);
	pDC->MoveTo(Rect.Width() / 2, 0);
	pDC->LineTo(Rect.Width() / 2, Rect.Height());	
	pDC->SelectObject(pOldPen);
	Pen3.DeleteObject();

	CClientDC dc(this);
	double xw1, yw1, xw2, yw2;
	CInputDialog dlg;	
	if(dlg.DoModal() == IDOK) {
		xw1 = atoi(dlg.m_x1.GetBuffer(0));
		xw2 = atoi(dlg.m_x2.GetBuffer(0));
		yw1 = atoi(dlg.m_y1.GetBuffer(0));
		yw2 = atoi(dlg.m_y2.GetBuffer(0));		
	}
	//RedrawWindow();  //刷新屏幕	
	//窗口绘制直线
	dc.MoveTo(ROUND(xw1), ROUND(yw1));
	dc.LineTo(ROUND(xw2), ROUND(yw2));	
	clip(xw1, yw1, xw2, yw2);
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

void CExperiment5_2View::clip(double xw1,double yw1,double xw2,double yw2) {  //裁剪函数
	double xv1, yv1, xv2, yv2;
	double x, y;
	BOOL Change;
	CClientDC dc(this);
	RC1 = EnCode(xw1, yw1);
	RC2 = EnCode(xw2, yw2);
	while(TRUE) {
		Change = FALSE;	
		if((RC1 | RC2) == 0) {//简取之
			//计算视区坐标
			xv1 = a * xw1 + b;
			yv1 = c * yw1 + d;
			xv2 = a * xw2 + b;
			yv2 = c * yw2 + d;
			dc.MoveTo(ROUND(xv1), ROUND(yv1));
			dc.LineTo(ROUND(xv2), ROUND(yv2));
			return;
		}
		else if((RC1 & RC2) != 0) {  //简弃之
			return;
		}
		else {
			if(RC1 == 0) {  //如果P1点在窗口内，交换P1和P2，保证P1点在窗口外
				//交换点的坐标值
				double tx, ty;
				tx = xw1;
				ty = yw1;
				xw1 = xw2;
				yw1 = yw2;
				xw2 = tx;
				yw2 = ty;
				//交换点的编码值
				unsigned int RC;
				RC = RC1;
				RC1 = RC2;
				RC2 = RC;
				}
			if(RC1 & LEFT) {  //P1点位于窗口的左侧
				x = wxl;
				y = yw1 + (yw2 - yw1) * (x - xw1) / (xw2 - xw1);
				xw1 = x;
				yw1 = y;
				Change = TRUE;
				RC1 = EnCode(xw1, yw1);
				RC2 = EnCode(xw2 , yw2);
			}			
			if(RC1 & RIGHT) {  //P1点位于窗口的右侧
				x = wxr;
				y = yw1 + (yw2 - yw1) * (x - xw1) / (xw2 - xw1);
				xw1 = x;
				yw1 = y;
				Change = TRUE;
				RC1 = EnCode(xw1, yw1);
				RC2 = EnCode(xw2, yw2);
			}				
			if(RC1 & BOTTOM) {  //P1点位于窗口的下侧
				y = wyb;
				x = xw1 + (xw2 - xw1) * (y - yw1) / (yw2 - yw1);
				xw1 = x;
				yw1 = y;
				Change = TRUE;
				RC1 = EnCode(xw1, yw1);
				RC2 = EnCode(xw2, yw2);
			}			
			if(RC1 & TOP) {  //P1点位于窗口的上侧
				y = wyt;
				x = xw1 + (xw2 - xw1) * (y - yw1) / (yw2 - yw1);
				xw1 = x;
				yw1 = y;
				Change = TRUE;
				RC1 = EnCode(xw1, yw1);
				RC2 = EnCode(xw2, yw2);
			}
			if(Change == FALSE) {
				return;
			}			
		}
	}
}

unsigned int CExperiment5_2View::EnCode(double x, double y) {  //编码函数，顺序左右下上
	unsigned int RC = 0;	
	if(x < wxl) {
		RC=RC | LEFT;
	}
	if(x > wxr) {
		RC = RC | RIGHT;
	}
	if(y < wyb) {
		RC = RC | BOTTOM;
	}
	if(y > wyt) {
		RC = RC | TOP;
	}
	return RC;
}