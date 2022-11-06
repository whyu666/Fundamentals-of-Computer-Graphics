// experiment7_2View.cpp : implementation of the CExperiment7_2View class
//

#include "stdafx.h"
#include "experiment7_2.h"

#include "experiment7_2Doc.h"
#include "experiment7_2View.h"

#define PI 3.1415926  //Բ����
#include "math.h"  //��ѧͷ�ļ�
#define ROUND(a) int(a + 0.5)  //��������

#include "ZBuffer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_2View

IMPLEMENT_DYNCREATE(CExperiment7_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment7_2View, CView)
	//{{AFX_MSG_MAP(CExperiment7_2View)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_2View construction/destruction

CExperiment7_2View::CExperiment7_2View()
{
	// TODO: add construction code here

}

CExperiment7_2View::~CExperiment7_2View()
{
}

BOOL CExperiment7_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_2View drawing

void CExperiment7_2View::OnDraw(CDC* pDC)
{
	CExperiment7_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	ReadPoint();
	ReadFace();
	DoubleBuffer();
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_2View printing

BOOL CExperiment7_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment7_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment7_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_2View diagnostics

#ifdef _DEBUG
void CExperiment7_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment7_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment7_2Doc* CExperiment7_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment7_2Doc)));
	return (CExperiment7_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_2View message handlers

void CExperiment7_2View::ReadPoint() {  //���
	int i;	
	//���������ɫ��
	P[0][0].x = -150;
	P[0][0].y = -200;
	P[0][0].z = 300;
	P[0][1].x = -150;
	P[0][1].y = -200;
	P[0][1].z = 300;

	P[0][2].x = -150;
	P[0][2].y = 200;
	P[0][2].z = 0;
	P[0][3].x = -150;
	P[0][3].y = 200;
	P[0][3].z = 0;

	P[0][4].x = -100;
	P[0][4].y = -200;
	P[0][4].z = 300;
	P[0][5].x = -100;
	P[0][5].y = -200;
	P[0][5].z = 300;

	P[0][6].x = -100;
	P[0][6].y = 200;
	P[0][6].z = 0;
	P[0][7].x = -100;
	P[0][7].y = 200;
	P[0][7].z = 0;

	for(i = 0; i < 8; i++) {  //������ɫ��ֵ
		P[0][i].c = CRGB(0.0, 1.0, 0.0);
	}
	
	//�Ҳ�������ɫ��
	P[1][0].x = 100;
	P[1][0].y = -200;
	P[1][0].z = 100;
	P[1][1].x = 100;
	P[1][1].y = -200;
	P[1][1].z = 100;

	P[1][2].x = 100;
	P[1][2].y = 200;
	P[1][2].z = 200;
	P[1][3].x = 100;
	P[1][3].y = 200;
	P[1][3].z = 100;

	P[1][4].x = 150;
	P[1][4].y = -200;
	P[1][4].z = 100;
	P[1][5].x = 150;
	P[1][5].y = -200;
	P[1][5].z = 100;

	P[1][6].x = 150;
	P[1][6].y = 200;
	P[1][6].z = 200;
	P[1][7].x = 150;
	P[1][7].y = 200;
	P[1][7].z = 200;
	for(i = 0; i < 8; i++) {
		P[1][i].c = CRGB(0.0, 0.0, 1.0);
	}

	//�²�ᣨ��ɫ��
	//����
	P[2][0].x = -200;
	P[2][0].y = -150;
	P[2][0].z = 200;
	P[2][1].x = -200;
	P[2][1].y = -150;
	P[2][1].z = 200;

	//����
	P[2][2].x = -200;
	P[2][2].y = -100;
	P[2][2].z = 200;
	P[2][3].x = -200;
	P[2][3].y = -100;
	P[2][3].z = 200;

	//����
	P[2][4].x = 200;
	P[2][4].y = -150;
	P[2][4].z = 150;
	P[2][5].x = 200;
	P[2][5].y = -150;
	P[2][5].z = 150;

	//����
	P[2][6].x = 200;
	P[2][6].y = -100;
	P[2][6].z = 150;
	P[2][7].x = 200;
	P[2][7].y = -100;
	P[2][7].z = 150;
	for(i = 0; i < 8; i++) {
		P[2][i].c = CRGB(1.0, 1.0, 0.0);
	}

	//�ϲ�ᣨ��ɫ��
	P[3][0].x = -200;
	P[3][0].y = 100;
	P[3][0].z = 100;
	P[3][1].x = -200;
	P[3][1].y = 150;
	P[3][1].z = 100;

	P[3][2].x = -200;
	P[3][2].y = 150;
	P[3][2].z = 100;
	P[3][3].x = -200;
	P[3][3].y = 150;
	P[3][3].z = 100;

	P[3][4].x = 200;
	P[3][4].y = 100;
	P[3][4].z = 0;
	P[3][5].x = 200;
	P[3][5].y = 100;
	P[3][5].z = 0;

	P[3][6].x = 200;
	P[3][6].y = 150;
	P[3][6].z = 0;
	P[3][7].x = 200;
	P[3][7].y = 150;
	P[3][7].z = 0;
	for(i = 0; i < 8; i++) {
		P[3][i].c = CRGB(1.0, 0.0, 0.0);
	}


}

void CExperiment7_2View::ReadFace() {  //���
	//��ı�������Ķ����ź������ɫ
	F[0].En = 4;
	F[0].p[0] = 0;  //ÿ�����ĺ���
	F[0].p[1] = 3;
	F[0].p[2] = 2;
	F[0].p[3] = 1;
	F[1].En = 4;
	F[1].p[0] = 4;  //ÿ������ǰ��
	F[1].p[1] = 5;
	F[1].p[2] = 6;
	F[1].p[3] = 7;
	F[2].En = 4;
	F[2].p[0] = 0;  //ÿ����������
	F[2].p[1] = 4;
	F[2].p[2] = 7;
	F[2].p[3] = 3;
	F[3].En = 4;
	F[3].p[0] = 1;  //ÿ����������
	F[3].p[1] = 2;
	F[3].p[2] = 6;
	F[3].p[3] = 5;
	F[4].En = 4;
	F[4].p[0] = 3;  //ÿ�����Ķ���
	F[4].p[1] = 7;
	F[4].p[2] = 6;
	F[4].p[3] = 2;
	F[5].En = 4;
	F[5].p[0] = 0;  //ÿ�����ĵ���
	F[5].p[1] = 1;
	F[5].p[2] = 5;
	F[5].p[3] = 4;
}

void CExperiment7_2View::DoubleBuffer() {  //˫����
	CRect Rect;
	GetClientRect(&Rect);
	CDC *pDC = GetDC();
	pDC->SetMapMode(MM_ANISOTROPIC);  //�Զ�������ϵ
	pDC->SetWindowExt(Rect.Width(), Rect.Height());
	pDC->SetViewportExt(Rect.Width(), -Rect.Height());  //x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(Rect.Width() / 2, Rect.Height() / 2);  //��Ļ����Ϊԭ��	
	CDC	MemDC, Picture;
	MemDC.CreateCompatibleDC(pDC);
	MemDC.SetMapMode(MM_ANISOTROPIC);
	MemDC.SetWindowExt(Rect.Width(), Rect.Height());
	MemDC.SetViewportExt(Rect.Width(), -Rect.Height());
	MemDC.SetViewportOrg(Rect.Width() / 2, Rect.Height() / 2);
	CBitmap NewBitmap, *OldBitmap;
	NewBitmap.LoadBitmap(IDB_BITMAP1);
	OldBitmap = MemDC.SelectObject(&NewBitmap);
	MemDC.BitBlt(-Rect.Width() / 2, -Rect.Height() / 2, Rect.Width(), Rect.Height(), &Picture, -Rect.Width() / 2, -Rect.Height() / 2, SRCCOPY);
	DrawObject(&MemDC);
	pDC->BitBlt(-Rect.Width() / 2, -Rect.Height() / 2, Rect.Width(), Rect.Height(), &MemDC, -Rect.Width() / 2, -Rect.Height() / 2, SRCCOPY);
	ReleaseDC(pDC);
	MemDC.SelectObject(OldBitmap);	
	NewBitmap.DeleteObject();	
}

void CExperiment7_2View::DrawObject(CDC *pDC) {  //���ƽ�����
	CPi3 Point[4];	
	zbuf.InitDeepBuffer(800, 800, -1000);  //��ȳ�ʼ��
	for(int nBar = 0; nBar < 4; nBar++) {
		for(int nFace = 0; nFace < 6; nFace++) {
			for(int nEdge=0;nEdge<F[nFace].En;nEdge++) {  //��ѭ��
				Point[nEdge].x = P[nBar][F[nFace].p[nEdge]].x;
				Point[nEdge].y = ROUND(P[nBar][F[nFace].p[nEdge]].y);
				Point[nEdge].z = P[nBar][F[nFace].p[nEdge]].z;
				Point[nEdge].c = P[nBar][F[nFace].p[nEdge]].c;
			}
			zbuf.SetPoint(Point,4);			
			zbuf.CreateBucket();  //����Ͱ��
			zbuf.CreateEdge();  //�����߱�
			zbuf.Gouraud(pDC);  //��ɫ��������ı���
		}
	}
}

BOOL CExperiment7_2View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	/*
	CRect Rect;   
	GetClientRect(&Rect);   
	pDC->FillSolidRect(Rect, RGB(0, 0, 0));
	*/
	
	return true;
	
	
	//return CView::OnEraseBkgnd(pDC);
}
