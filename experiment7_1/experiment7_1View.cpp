// experiment7_1View.cpp : implementation of the CExperiment7_1View class
//

#include "stdafx.h"
#include "experiment7_1.h"

#include "experiment7_1Doc.h"
#include "experiment7_1View.h"

#define ROUND(a) int(a + 0.5) //��������
#define PI 3.1415926  //Բ����
#include "math.h"  //��ѧͷ�ļ�

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1View

IMPLEMENT_DYNCREATE(CExperiment7_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment7_1View, CView)
	//{{AFX_MSG_MAP(CExperiment7_1View)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1View construction/destruction

CExperiment7_1View::CExperiment7_1View()
{
	// TODO: add construction code here
	R = 800.0;
	d = 1000;
	Phi = 0;
	Theta = -90;	

}

CExperiment7_1View::~CExperiment7_1View()
{
}

BOOL CExperiment7_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1View drawing

void CExperiment7_1View::OnDraw(CDC* pDC)
{
	CExperiment7_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	ReadPoint();
	ReadFace();
	InitParameter();
	DoubleBuffer();
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1View printing

BOOL CExperiment7_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment7_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment7_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1View diagnostics

#ifdef _DEBUG
void CExperiment7_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment7_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment7_1Doc* CExperiment7_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment7_1Doc)));
	return (CExperiment7_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1View message handlers


void CExperiment7_1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar) {
	case VK_UP:
		Phi -= 10;  //�趨����
		break;
	case VK_DOWN:
		Phi += 10;
		break;
	case VK_LEFT:
		Theta -= 10;
		break;
	case VK_RIGHT:
		Theta += 10;
		break;
	default:
		break;
	}
	InitParameter();
	DoubleBuffer();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CExperiment7_1View::ReadPoint() {  //���
	int a = 100;  //�߳�
	P[0].x = -a;
	P[0].y = -a;
	P[0].z = -a;
	P[1].x = a;
	P[1].y = -a;
	P[1].z = -a;
	P[2].x = a;
	P[2].y = a;
	P[2].z = -a;
	P[3].x = -a;
	P[3].y = a;
	P[3].z = -a;
	P[4].x = -a;
	P[4].y = -a;
	P[4].z = a;
	P[5].x = a;
	P[5].y = -a;
	P[5].z = a;
	P[6].x = a;
	P[6].y = a;
	P[6].z = a;
	P[7].x = -a;
	P[7].y = a;
	P[7].z = a;
}

void CExperiment7_1View::ReadFace() {  //���
	//��ı�������Ķ�����
	F[0].En = 4;
	F[1].En = 4;
	F[2].En = 4;
	F[3].En = 4;
	F[4].En = 4;
	F[5].En = 4;
	//ǰ��
	F[0].p[0] = 4;
	F[0].p[1] = 5;
	F[0].p[2] = 6;
	F[0].p[3] = 7;
	//����
	F[1].p[0] = 0;
	F[1].p[1] = 3;
	F[1].p[2] = 2;
	F[1].p[3] = 1;
	//����
	F[2].p[0] = 0;
	F[2].p[1] = 4;
	F[2].p[2] = 7;
	F[2].p[3] = 3;
	//����
	F[3].p[0] = 1;
	F[3].p[1] = 2;
	F[3].p[2] = 6;
	F[3].p[3] = 5;
	//����
	F[4].p[0] = 2;
	F[4].p[1] = 3;
	F[4].p[2] = 7;
	F[4].p[3] = 6;
	//����
	F[5].p[0] = 0;
	F[5].p[1] = 1;
	F[5].p[2] = 5;
	F[5].p[3] = 4;
}

void CExperiment7_1View::InitParameter() {  //͸�ӱ任������ʼ��
	k[1] = sin(PI * Theta / 180);
	k[2] = sin(PI * Phi / 180);
	k[3] = cos(PI * Theta / 180);
	k[4] = cos(PI * Phi / 180);
	k[5] = k[3] * k[2];
	k[6] = k[1] * k[2];
	k[7] = k[3] * k[4];
	k[8] = k[1] * k[4];
	ViewPoint.x = R * k[5];  //�û�����ϵ���ӵ�������
	ViewPoint.y = R * k[6];
	ViewPoint.z = R * k[4];
}

void CExperiment7_1View::PerProject(CP3 P) {  //͸�ӱ任
	CP3 ViewP;
	ViewP.x = -k[1] * P.x + k[3] * P.y;  //�۲�����ϵ��ά����
	ViewP.y = -k[7] * P.x - k[8] * P.y + k[2] * P.z;
	ViewP.z = -k[5] * P.x - k[6] * P.y - k[4] * P.z + R;
	ScreenP.x = ROUND(d * ViewP.x / ViewP.z);  //��Ļ����ϵ��ά����
	ScreenP.y = ROUND(d * ViewP.y / ViewP.z);
}

void CExperiment7_1View::DoubleBuffer() {  //˫����
	CRect Rect;
	GetClientRect(&Rect);
	CDC *pDC = GetDC();
   	pDC->SetMapMode(MM_ANISOTROPIC);  //�Զ�������ϵ
	pDC->SetWindowExt(Rect.Width(), Rect.Height());  //���ô��ڱ���
	pDC->SetViewportExt(Rect.Width(), -Rect.Height());   //����������������x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(Rect.Width() / 2, Rect.Height() / 2);  //���ÿͻ�������Ϊ����ϵԭ��
	Rect.OffsetRect(-Rect.Width() / 2, -Rect.Height() / 2);  //������ͻ����غ�	
	
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
	
	//DrawObject(pDC);
}

void CExperiment7_1View::DrawObject(CDC* pDC) {  //��������
	for(int nFace = 0; nFace < 6; nFace++) {
		CVector VS(P[F[nFace].p[1]], ViewPoint);  //�����ʸ��
		CVector V01(P[F[nFace].p[0]], P[F[nFace].p[1]]);  //���һ����ʸ��
		CVector V12(P[F[nFace].p[1]], P[F[nFace].p[2]]);  //�����һ����ʸ��	
		CVector VN = V01 * V12;  //��ķ�ʸ��
		if(Dot(VS,VN) >= 0) {  //͹����������
			DrawFace(pDC, nFace);  //�����������㣬���滭��
		}
	}
}

void CExperiment7_1View::DrawFace(CDC* pDC, int nface) {  //���Ʊ���
	CP2 t;
	CLine line;
	for(int nEdge = 0; nEdge < F[nface].En; nEdge++) {  //��ѭ��
		PerProject(P[F[nface].p[nEdge]]);  //͸��ͶӰ
		if(nEdge == 0) {
			line.MoveTo(pDC, ScreenP);
			t = ScreenP;
		}
		else {
			line.LineTo(pDC, ScreenP);
		}
	}
	line.LineTo(pDC, t.x, t.y);  //�պ϶����
}
