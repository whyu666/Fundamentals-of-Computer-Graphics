// experiment8_1View.cpp : implementation of the CExperiment8_1View class
//

#include "stdafx.h"
#include "experiment8_1.h"

#include "experiment8_1Doc.h"
#include "experiment8_1View.h"

#define ROUND(a) int(a + 0.5)  //��������
#define PI 3.1415926  //Բ����
#include "cmath"  //��ѧͷ�ļ�

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1View

IMPLEMENT_DYNCREATE(CExperiment8_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment8_1View, CView)
	//{{AFX_MSG_MAP(CExperiment8_1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1View construction/destruction

CExperiment8_1View::CExperiment8_1View()
{
	// TODO: add construction code here

}

CExperiment8_1View::~CExperiment8_1View()
{
}

BOOL CExperiment8_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1View drawing

void CExperiment8_1View::OnDraw(CDC* pDC)
{
	CExperiment8_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	GetMaxX();
	GetMaxY();
	ReadPointFlat();
	ReadFace();
	DrawHexagon(Pf);
	ReadPointSmooth();
	DrawHexagon(Ps);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1View printing

BOOL CExperiment8_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment8_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment8_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1View diagnostics

#ifdef _DEBUG
void CExperiment8_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment8_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment8_1Doc* CExperiment8_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment8_1Doc)));
	return (CExperiment8_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1View message handlers

void CExperiment8_1View::GetMaxX() {  //�����Ļ���
	CRect Rect;
	GetClientRect(&Rect);
	MaxX = Rect.right;
}

void CExperiment8_1View::GetMaxY() {  //�����Ļ�߶�
	CRect Rect;
	GetClientRect(&Rect);
	MaxY = Rect.bottom;
}

void CExperiment8_1View::ReadPointFlat() {  //�㶨��ɫ�������ε��
	int a = 200;  //�����������Բ�뾶
	for(int i = 0; i < 6; i++) {
		Pf[i].x = MaxX / 4 + ROUND(a * cos(i * PI / 3));
		Pf[i].y = MaxY / 2 + ROUND(a * sin(i * PI / 3));
	}
	Pf[6].x = MaxX / 4;
	Pf[6].y = MaxY / 2;  //���ĵ�
	//Ʒ��
	Pf[0].c.red = 1.0;
	Pf[0].c.green = 0.0;
	Pf[0].c.blue = 1.0;
	//��ɫ
	Pf[1].c.red = 0.0;
	Pf[1].c.green = 0.0;
	Pf[1].c.blue = 1.0;
	//��ɫ
	Pf[2].c.red = 0.0;
	Pf[2].c.green = 1.0;
	Pf[2].c.blue = 1.0;
	//��ɫ
	Pf[3].c.red = 0.0;
	Pf[3].c.green = 1.0;
	Pf[3].c.blue = 0.0;
	//��ɫ
	Pf[4].c.red = 1.0;
	Pf[4].c.green = 1.0;
	Pf[4].c.blue = 0.0;
	//��ɫ
	Pf[5].c.red = 1.0;
	Pf[5].c.green = 0.0;
	Pf[5].c.blue = 0.0;
	Flag = true;
}

void CExperiment8_1View::ReadPointSmooth() {  //������ɫ�������ε��
	int a = 200;  //�뾶
	for(int i = 0; i < 6; i++) {
		Ps[i].x = 3 * MaxX / 4 + ROUND(a * cos(i * PI / 3));
		Ps[i].y = MaxY / 2 + ROUND(a * sin(i * PI / 3));
	}
	Ps[6].x = 3 * MaxX / 4;
	Ps[6].y = MaxY / 2;  //���ĵ�
	//Ʒ��
	Ps[0].c.red = 1.0;
	Ps[0].c.green = 0.0;
	Ps[0].c.blue = 1.0;
	//��ɫ
	Ps[1].c.red = 0.0;
	Ps[1].c.green = 0.0;
	Ps[1].c.blue = 1.0;
	//��ɫ
	Ps[2].c.red = 0.0;
	Ps[2].c.green = 1.0;
	Ps[2].c.blue = 1.0;
	//��ɫ
	Ps[3].c.red = 0.0;
	Ps[3].c.green = 1.0;
	Ps[3].c.blue = 0.0;
	//��ɫ
	Ps[4].c.red = 1.0;
	Ps[4].c.green = 1.0;
	Ps[4].c.blue = 0.0;
	//��ɫ
	Ps[5].c.red = 1.0;
	Ps[5].c.green = 0.0;
	Ps[5].c.blue = 0.0;
	//��ɫ
	Ps[6].c.red = 1.0;
	Ps[6].c.green = 1.0;
	Ps[6].c.blue = 1.0;
	Flag = false;
}

void CExperiment8_1View::ReadFace() {  //�����������
	//�㶨��ɫģ���Զ���ε�һ������ĵ�һ��ɫ���
	//����
	F[0].En = 3;
	F[0].p[0] = 0;
	F[0].p[1] = 1;
	F[0].p[2] = 6;
	//����
	F[1].En = 3;
	F[1].p[0] = 1;
	F[1].p[1] = 2;
	F[1].p[2] = 6;
	//����
	F[2].En = 3;
	F[2].p[0] = 2;
	F[2].p[1] = 3;
	F[2].p[2] = 6;
	//����
	F[3].En = 3;
	F[3].p[0] = 3;
	F[3].p[1] = 4;
	F[3].p[2] = 6;
	//����
	F[4].En = 3;
	F[4].p[0] = 4;
	F[4].p[1] = 5;
	F[4].p[2] = 6;
	//����
	F[5].En = 3;
	F[5].p[0] = 5;
	F[5].p[1] = 0;
	F[5].p[2] = 6;
}

void CExperiment8_1View::DrawHexagon(CP2 *P) {  //������������
	CDC *pDC = GetDC();
	CPi2 Point[3];  //��Ķ�ά��������
	for(int nFace = 0; nFace < 6; nFace++) {
		int TotalEdge = F[nFace].En;  //����ÿ������ܱ���
		for(int nEdge = 0; nEdge < TotalEdge; nEdge++) {  //��ѭ��
			int PointNumber = F[nFace].p[nEdge];  //��Ķ����
			Point[nEdge].x = P[PointNumber].x;
			Point[nEdge].y = ROUND(P[PointNumber].y);
			if(Flag) {
				Point[nEdge].c = P[F[nFace].p[0]].c;
			}
			else {
				Point[nEdge].c = P[PointNumber].c;
			}
		}
		fill.SetPoint(Point, 3);  //��ʼ��Fill����
		fill.CreateBucket();  //����Ͱ��
		fill.CreateEdge();  //�����߱�
		fill.Gouraud(pDC);  //���������	
	}
}