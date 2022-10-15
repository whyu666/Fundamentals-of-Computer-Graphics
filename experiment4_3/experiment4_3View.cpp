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

void CExperiment4_3View::ReadPoint() {  //���
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

void CExperiment4_3View::DrawPolygon(CDC *pDC) {  //���ƶ���α߽�
	CLine *line = new CLine;
	CP2 t;
	for(int i = 0; i < 8; i++) {  //���ƶ����
		if(i == 0) {
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}
	}
	line->LineTo(pDC, t);  //�պ϶����
	delete line;
}

void CExperiment4_3View::FillPolygon(CDC *pDC) {  //�������
	COLORREF BoundaryClr = RGB(0,0,0);  //�߽�ɫ
	COLORREF PixelClr;  //��ǰ���ص����ɫ
	pHead = new CStackNode;  //����ͷ���
	pHead->pNext = NULL;  //ջͷ����ָ������Ϊ��
	Push(Seed);	
	int x, y, x0 = Round(Seed.x), y0 = Round(Seed.y);  //x��y�����ж�������ͼ�ε�λ�ù�ϵ
	x = x0 - 1;
	while(BoundaryClr != pDC->GetPixel(x, y0) && SeedClr != pDC->GetPixel(x, y0)) {  //���ж�
		x--;
		if(x <= -rect.Width() / 2) {  //����ͻ��������
			return;
		}
	}
	y = y0 + 1;
	while(BoundaryClr != pDC->GetPixel(x0, y) && SeedClr != pDC->GetPixel(x0, y)) {  //�Ϸ��ж�
		y++;
		if(y >= rect.Height() / 2) {  //����ͻ������϶�
			return;
		}
	}
	x = x0 + 1;
	while(BoundaryClr != pDC->GetPixel(x, y0) && SeedClr != pDC->GetPixel(x, y0)) {  //�ҷ��ж�
		x++;
		if(x >= rect.Width() / 2) {  //����ͻ������Ҷ�	
			return;
		}
	}
	y = y0 - 1;
	while(BoundaryClr != pDC->GetPixel(x0, y) && SeedClr != pDC->GetPixel(x0, y)) {  //�·��ж�
		y--;
		if(y <= -rect.Height() / 2) {  //����ͻ������¶�
			return;
		}
	}
	while(pHead->pNext != NULL) {  //���ջ��Ϊ��
		CP2 PopPoint;
		Pop(PopPoint);
		if(SeedClr == pDC->GetPixel(Round(PopPoint.x), Round(PopPoint.y))) {
            continue;
        }
		pDC->SetPixelV(Round(PopPoint.x), Round(PopPoint.y), SeedClr);
		Left.x = PopPoint.x - 1;  //������ջ����������
		Left.y = PopPoint.y;
		PixelClr = pDC->GetPixel(Round(Left.x), Round(Left.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {  //���Ǳ߽�ɫ����δ�ó����ɫ
			Push(Left);  //��������ջ
        }
		LeftTop.x = PopPoint.x - 1;
		LeftTop.y = PopPoint.y + 1;  //������ջ�������Ϸ�����
		PixelClr = pDC->GetPixel(Round(LeftTop.x), Round(LeftTop.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(LeftTop);  //���Ϸ�������ջ
        }	
		Top.x = PopPoint.x;
		Top.y = PopPoint.y + 1;  //������ջ�����Ϸ�����
		PixelClr = pDC->GetPixel(Round(Top.x), Round(Top.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(Top);  //�Ϸ�������ջ
        }
		RightTop.x = PopPoint.x + 1;
		RightTop.y = PopPoint.y + 1;  //������ջ�������Ϸ�����
		PixelClr = pDC->GetPixel(Round(RightTop.x), Round(RightTop.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(RightTop);  //���Ϸ�������ջ
        }
		Right.x = PopPoint.x + 1;  //������ջ�����ҷ�����
		Right.y = PopPoint.y;
		PixelClr = pDC->GetPixel(Round(Right.x), Round(Right.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(Right);  //�ҷ�������ջ
        }
		RightBottom.x = PopPoint.x + 1;  //������ջ�������·�����
		RightBottom.y = PopPoint.y - 1;
		PixelClr = pDC->GetPixel(Round(RightBottom.x), Round(RightBottom.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(RightBottom);  //���·�������ջ
        }
		Bottom.x = PopPoint.x;
		Bottom.y = PopPoint.y - 1;  //������ջ�����·�����
		PixelClr = pDC->GetPixel(Round(Bottom.x), Round(Bottom.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(Bottom);  //�·�������ջ
        }
		LeftBottom.x = PopPoint.x - 1;
		LeftBottom.y = PopPoint.y - 1;  //������ջ�������·�����
		PixelClr = pDC->GetPixel(Round(LeftBottom.x), Round(LeftBottom.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(LeftBottom);  //���·�������ջ
        }
	}
	pDC->TextOut(rect.left + 50, rect.bottom - 20, "������");
	delete pHead;
	pHead = NULL;
}

void CExperiment4_3View::Push(CP2 point) {  //��ջ����
	pTop = new CStackNode;
	pTop->PixelPoint = point;
	pTop->pNext = pHead->pNext;
	pHead->pNext = pTop;
}

void CExperiment4_3View::Pop(CP2 &point) {  //��ջ����
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