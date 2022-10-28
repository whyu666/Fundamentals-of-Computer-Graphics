// experiment6_1View.cpp : implementation of the CExperiment6_1View class
//

#include "stdafx.h"
#include "experiment6_1.h"

#include "experiment6_1Doc.h"
#include "experiment6_1View.h"

#define ROUND(a) int(a + 0.5)
#define PI 3.1415926
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1View

IMPLEMENT_DYNCREATE(CExperiment6_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment6_1View, CView)
	//{{AFX_MSG_MAP(CExperiment6_1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1View construction/destruction

CExperiment6_1View::CExperiment6_1View()
{
	// TODO: add construction code here

}

CExperiment6_1View::~CExperiment6_1View()
{
}

BOOL CExperiment6_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1View drawing

void CExperiment6_1View::OnDraw(CDC* pDC) {  //��������ϵ
	CExperiment6_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	GetClientRect(&Rect);  //��ÿͻ�����С
	CPen MyPen, *OldPen;
	MyPen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	OldPen = pDC->SelectObject(&MyPen);
	pDC->MoveTo(Rect.Width() / 2, Rect.Height() / 2);  //����y��
	pDC->LineTo(Rect.Width(), Rect.Height() / 2);
	pDC->TextOut(Rect.Width() - 20, Rect.Height() / 2 - 30, "x");
	pDC->MoveTo(Rect.Width() / 2, Rect.Height() / 2);  //����z��
	pDC->LineTo(Rect.Width() / 2, 0);
	pDC->TextOut(Rect.Width() / 2 - 20, 10, "y");
	pDC->MoveTo(Rect.Width() / 2, Rect.Height() / 2);  //����x��
	pDC->LineTo(Rect.Width() / 2 - Rect.Height() / 2, Rect.Height());  //�н�Ϊ135��
	pDC->TextOut(Rect.Width() / 2 - Rect.Height() / 2 - 20, Rect.Height() - 30, "z");
	pDC->TextOut(Rect.Width() / 2 - 20, Rect.Height() / 2 - 20, "o");
	pDC->SelectObject(OldPen);
	MyPen.DeleteObject();
	
	AfxGetMainWnd()->SetWindowText("б�Ȳ�ͼ");
	alpha = 45; beta = 45;
	DrawCube();

	//AfxGetMainWnd()->SetWindowText("б����ͼ");
	//alpha = 63.4; beta = 45;
	//DrawCube();
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1View printing

BOOL CExperiment6_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment6_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment6_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1View diagnostics

#ifdef _DEBUG
void CExperiment6_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment6_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment6_1Doc* CExperiment6_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment6_1Doc)));
	return (CExperiment6_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1View message handlers

void CExperiment6_1View::ReadPoint() {  //�����
	int a = 200;  //������߳�
	//�������ά����
	P3[0].x = 0; P3[0].y = 0; P3[0].z = 0;  //A��
	P3[1].x = 0; P3[1].y = a; P3[1].z = 0;  //B��
	P3[2].x = 0; P3[2].y = a; P3[2].z = a;  //C��
	P3[3].x = 0; P3[3].y = 0; P3[3].z = a;  //D��
	//ǰ�����ά����
	P3[4].x = a; P3[4].y = 0; P3[4].z = 0;  //E��
	P3[5].x = a; P3[5].y = a; P3[5].z = 0;  //F��
	P3[6].x = a; P3[6].y = a; P3[6].z = a;  //G��
	P3[7].x = a; P3[7].y = 0; P3[7].z = a;  //H��
}

void CExperiment6_1View::ReadFace() {  //���
	//��ı�������Ķ�����
	F[0].En = 4; F[0].p[0] = 0; F[0].p[1] = 3; F[0].p[2] = 2; F[0].p[3] = 1;  //����ADCB
	F[1].En = 4; F[1].p[0] = 4; F[1].p[1] = 5; F[1].p[2] = 6; F[1].p[3] = 7;  //ǰ��EFGH
	F[2].En = 4; F[2].p[0] = 0; F[2].p[1] = 4; F[2].p[2] = 7; F[2].p[3] = 3;  //����AEHD
	F[3].En = 4; F[3].p[0] = 1; F[3].p[1] = 2; F[3].p[2] = 6; F[3].p[3] = 5;  //����BCGF
	F[4].En = 4; F[4].p[0] = 3; F[4].p[1] = 7; F[4].p[2] = 6; F[4].p[3] = 2;  //����DHGC
	F[5].En = 4; F[5].p[0] = 0; F[5].p[1] = 1; F[5].p[2] = 5; F[5].p[3] = 4;  //����ABFE
}

void CExperiment6_1View::DrawCube() {  //����������
	GetClientRect(&Rect);  //��ÿͻ�����С
	CDC *pDC=GetDC();  //�ͻ���DC
	pDC->SetMapMode(MM_ANISOTROPIC);  //�Զ�������ϵ
	pDC->SetWindowExt(Rect.Width(), Rect.Height());
	pDC->SetViewportExt(Rect.Width(), -Rect.Height());  //x�����ң�y������ 
	pDC->SetViewportOrg(Rect.Width() / 2, Rect.Height() / 2);  //��Ļ����Ϊԭ��	
	CP2 Point[4];  //���������涥������
	ReadPoint();
	ReadFace();
	for(int nFace = 0; nFace < 6; nFace++) {  //��ѭ��	
		for(int nEdge = 0; nEdge < F[nFace].En; nEdge++) {  //��ѭ��
			Point[nEdge] = Project(P3[F[nFace].p[nEdge]]);  //бƽ��ͶӰ	
        }	
		Line(pDC, nFace, Point);
	}
	ReleaseDC(pDC);
}

void CExperiment6_1View::Line(CDC *pDC, int nface, CP2 p[]) {  //����������
	for(int i = 0; i < F[nface].En; i++) {
		if(i == 0) {
            pDC->MoveTo(ROUND(p[0].x), ROUND(p[0].y));
        }
		else {
            pDC->LineTo(ROUND(p[i].x), ROUND(p[i].y));
        }
	}
	pDC->LineTo(ROUND(p[0].x), ROUND(p[0].y));
}


CP2 CExperiment6_1View::Project(CP3 P0) {  //бƽ��ͶӰ
	CP2 Pt;
	Pt.x = P0.y - P0.x * cos(beta * PI / 180) / tan(alpha * PI / 180);
	Pt.y = P0.z - P0.x * sin(beta * PI / 180) / tan(alpha * PI / 180);
	return Pt;
}