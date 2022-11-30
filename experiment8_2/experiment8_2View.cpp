// experiment8_2View.cpp : implementation of the CExperiment8_2View class
//

#include "stdafx.h"
#include "experiment8_2.h"

#include "experiment8_2Doc.h"
#include "experiment8_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ROUND(a) int(a + 0.5)  //��������
#define PI 3.1415926  //Բ����

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_2View

IMPLEMENT_DYNCREATE(CExperiment8_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment8_2View, CView)
	//{{AFX_MSG_MAP(CExperiment8_2View)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_2View construction/destruction

CExperiment8_2View::CExperiment8_2View()
{
	// TODO: add construction code here
	R = 800.0, d = 1000, Phi = -45, Theta = -50;  //�ӵ�λ��������
	LightNum = 1;  //��Դ����
	pLight = new CLighting(LightNum);  //��Դ��̬����
	pLight->Light[0].SetGlobal(R, Phi, Theta);  //��Դλ��������
	//���ù�Դ����
	for(int i = 0; i < LightNum; i++) {
		pLight->Light[i].L_Diffuse = CRGB(0.8, 0.8, 0.8);  //��Դ����������ɫ	
		pLight->Light[i].L_Specular = CRGB(0.508, 0.508, 0.508);  //��Դ����߹���ɫ
		pLight->Light[i].L_C0 = 1.0;  //����˥��ϵ��
		pLight->Light[i].L_C1 = 0.0000001;  //����˥��ϵ��
		pLight->Light[i].L_C2 = 0.00000001;//����˥��ϵ��
		pLight->Light[i].L_OnOff = TRUE;  //��Դ����
	}
	//���ò��ʲ���
	pMaterial = new CMaterial;  //����ָ��
	pMaterial->M_Ambient = CRGB(0.192, 0.192, 0.192);  //���ʶԻ�����ķ�����
	pMaterial->M_Diffuse = CRGB(0.508, 0.508, 0.508);  //���ʶ��������ķ�����
	pMaterial->M_Specular = CRGB(1.0, 1.0, 1.0);  //���ʶԾ��淴���ķ�����
	pMaterial->M_Exp = 5.0;  //�߹�ָ��
}

CExperiment8_2View::~CExperiment8_2View()
{
	if(pMaterial) {
		delete pMaterial;
	}
}

BOOL CExperiment8_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_2View drawing

void CExperiment8_2View::OnDraw(CDC* pDC)
{
	CExperiment8_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	ReadPoint();
	ReadFace();
	InitParameter();
	DoubleBuffer();
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_2View printing

BOOL CExperiment8_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExperiment8_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExperiment8_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_2View diagnostics

#ifdef _DEBUG
void CExperiment8_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment8_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment8_2Doc* CExperiment8_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment8_2Doc)));
	return (CExperiment8_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_2View message handlers

void CExperiment8_2View::ReadPoint() {  //���
	double a = 200;  //������߳�
	P[0].x = -a / 2;
	P[0].y = -a / 2;
	P[0].z = -a / 2;
	P[1].x = a / 2;
	P[1].y = -a / 2;
	P[1].z = -a / 2;
	P[2].x = a / 2;
	P[2].y = a / 2;
	P[2].z = -a / 2;
	P[3].x = -a / 2;
	P[3].y = a / 2;
	P[3].z = -a / 2;
	P[4].x = -a / 2;
	P[4].y = -a / 2;
	P[4].z = a / 2;
	P[5].x = a / 2;
	P[5].y = -a / 2;
	P[5].z = a / 2;
	P[6].x = a / 2;
	P[6].y = a / 2;
	P[6].z = a / 2;
	P[7].x = -a / 2;
	P[7].y = a / 2;
	P[7].z = a / 2;
}

void CExperiment8_2View::ReadFace() {  //���
	//��ı�������Ķ����ź������ɫ
	//����
	F[0].En = 4;
	F[0].p[0] = 0;
	F[0].p[1] = 3;
	F[0].p[2] = 2;
	F[0].p[3] = 1;
	//ǰ��
	F[1].En = 4;
	F[1].p[0] = 4;
	F[1].p[1] = 5;
	F[1].p[2] = 6;
	F[1].p[3] = 7;
	//����
	F[2].En = 4;
	F[2].p[0] = 0;
	F[2].p[1] = 4;
	F[2].p[2] = 7;
	F[2].p[3] = 3;
	//����
	F[3].En = 4;
	F[3].p[0] = 1;
	F[3].p[1] = 2;
	F[3].p[2] = 6;
	F[3].p[3] = 5;
	//����
	F[4].En = 4;
	F[4].p[0] = 3;
	F[4].p[1] = 7;
	F[4].p[2] = 6;
	F[4].p[3] = 2;
	//����
	F[5].En = 4;
	F[5].p[0] = 0;
	F[5].p[1] = 1;
	F[5].p[2] = 5;
	F[5].p[3] = 4;
}

void CExperiment8_2View::InitParameter() {  //͸�ӱ任������ʼ��
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

void CExperiment8_2View::PerProject(CP3 P) {  //͸�ӱ任
	CP3 ViewP;
	ViewP.x = -k[1] * P.x + k[3] * P.y;  //�۲�����ϵ��ά����
	ViewP.y = ROUND(-k[7] * P.x - k[8] * P.y + k[2] * P.z);
	ViewP.z = -k[5] * P.x - k[6] * P.y - k[4] * P.z + R;
	ViewP.c = P.c;
	ScreenP.x = d * ViewP.x / ViewP.z;  //��Ļ����ϵ��ά����
	ScreenP.y = ROUND(d * ViewP.y / ViewP.z);
	ScreenP.c = ViewP.c;
}

void CExperiment8_2View::DoubleBuffer() {  //˫����
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
	pDC->BitBlt(-Rect.Width() / 2, -Rect.Height() / 2, Rect.Width(), Rect.Height(), &MemDC, -Rect.Width() / 2,-Rect.Height()/2,SRCCOPY);
	ReleaseDC(pDC);
	MemDC.SelectObject(OldBitmap);	
	NewBitmap.DeleteObject();
}

void CExperiment8_2View::DrawObject(CDC* pDC) {  //����������
	CPi2 Point[4];
	for(int nFace = 0; nFace < 6; nFace++) {
		CVector VS(P[F[nFace].p[1]], ViewPoint);  //�����ʸ��
		CVector V01(P[F[nFace].p[0]], P[F[nFace].p[1]]);  //���һ����ʸ��
		CVector V12(P[F[nFace].p[1]], P[F[nFace].p[2]]);  //�����һ����ʸ��		
		CVector VN = V01 * V12;  //��ķ�ʸ��	
		if(Dot(VS,VN) >= 0) {  //͹����������
			for(int nEdge = 0; nEdge < F[nFace].En; nEdge++) {
				PerProject(P[F[nFace].p[nEdge]]);
				Point[nEdge].x = ScreenP.x;
				Point[nEdge].y = ROUND(ScreenP.y);
				Point[nEdge].c = pLight->Lighting(ViewPoint, P[F[nFace].p[nEdge]], VN, pMaterial);
			}
			fill.SetPoint(Point, 4);  //���ö��������������
			fill.CreateBucket();
			fill.CreateEdge();
			fill.Gouraud(pDC);
		}
	}
}


void CExperiment8_2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar) {
	case VK_UP:
		Phi -= 5;
		break;
	case VK_DOWN:
		Phi += 5;
		break;
	case VK_LEFT:
		Theta -= 5;
		break;
	case VK_RIGHT:
		Theta += 5;
		break;
	default:
		break;
	}
	pLight->Light[0].SetGlobal(R, Phi, Theta);
	InitParameter();
	DoubleBuffer();
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CExperiment8_2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	R = R + 100;
	DoubleBuffer();
	DoubleBuffer();
	
	CView::OnLButtonDown(nFlags, point);
}

void CExperiment8_2View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	R = R - 100;
	DoubleBuffer();
	DoubleBuffer();
	
	CView::OnRButtonDown(nFlags, point);
}
