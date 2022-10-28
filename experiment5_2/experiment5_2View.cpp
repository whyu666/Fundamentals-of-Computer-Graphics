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

#define LEFT   1   //����:0001
#define RIGHT  2   //����:0010
#define BOTTOM 4   //����:0100
#define TOP    8   //����:1000

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

void CExperiment5_2View::DoubleBuffer(CDC* pDC) {  //˫����
	CRect rect;  //����ͻ���
	GetClientRect(&rect);  //��ÿͻ����Ĵ�С
	pDC->SetMapMode(MM_ANISOTROPIC);  //pDC�Զ�������ϵ
	pDC->SetWindowExt(rect.Width(), rect.Height());  //���ô��ڷ�Χ
	pDC->SetViewportExt(rect.Width(), -rect.Height());  //����������Χ,x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);  //�ͻ�������Ϊԭ��
	CDC memDC;  //�ڴ�DC
	memDC.CreateCompatibleDC(pDC);  //����һ������ʾpDC���ݵ��ڴ�memDC
	CBitmap NewBitmap, *pOldBitmap;  //�ڴ��г��ص���ʱλͼ 
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());  //��������λͼ 
	pOldBitmap=memDC.SelectObject(&NewBitmap);  //������λͼѡ��memDC 
	memDC.FillSolidRect(rect, pDC->GetBkColor());  //��ԭ���������ͻ����������Ǻ�ɫ
	memDC.SetMapMode(MM_ANISOTROPIC);  //memDC�Զ�������ϵ
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	DrawWindowRect(&memDC);  //���ƴ���
	if(PtCount >= 1) {
		memDC.MoveTo(Round(P[0].x), Round(P[0].y));
		memDC.LineTo(Round(P[1].x), Round(P[1].y));
	}
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);  //���ڴ�memDC�е�λͼ��������ʾpDC��
	memDC.SelectObject(pOldBitmap);  //�ָ�λͼ
	NewBitmap.DeleteObject();  //ɾ��λͼ

	Cohen();
}

void CExperiment5_2View::DrawWindowRect(CDC* pDC) {  //���Ʋü�����
	pDC->SetTextColor(RGB(0, 255, 0));
	CPen NewPen3, *pOldPen3;  //����3�����ؿ�ȵĻ���
	NewPen3.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	pOldPen3 = pDC->SelectObject(&NewPen3);
    pDC->Rectangle(Wxl, Wyt, Wxr, Wyb);
	pDC->SelectObject(pOldPen3);
	NewPen3.DeleteObject();
}

void CExperiment5_2View::Cohen() {  //Cohen-Sutherland�㷨
	CP2 p;  //��������
	EnCode(P[0]);  //������
	EnCode(P[1]);  //�յ����
	while(P[0].rc != 0 || P[1].rc != 0) {  //��������һ�������ڴ���֮������
		if((P[0].rc & P[1].rc)!=0) {  //����֮
			PtCount = 0;
			return;
		}
		if(0 == P[0].rc) {  //ȷ��P[0]λ�ڴ���֮��
			CP2 temp;
			temp = P[0];
			P[0] = P[1];
			P[1] = temp;
		}
		UINT RC = P[0].rc;
		double k = (P[1].y - P[0].y) / (P[1].x - P[0].x);  //ֱ�߶ε�б��
		//���ڱ߽簴���ҡ��¡��ϵ�˳��ü�ֱ�߶�
		if(RC & LEFT) {  //P[0]��λ�ڴ��ڵ����
			p.x = Wxl;  //���㽻��y����
			p.y = k * (p.x - P[0].x) + P[0].y;
		}
		else if(RC & RIGHT) {  //P[0]��λ�ڴ��ڵ��Ҳ�
			p.x = Wxr;  //���㽻��y����
			p.y = k * (p.x - P[0].x) + P[0].y;
		}
		else if(RC & BOTTOM) {  //P[0]��λ�ڴ��ڵ��²�
			p.y = Wyb;  //���㽻��x����
			p.x = (p.y - P[0].y) / k + P[0].x;
		}			
		else if(RC & TOP) {  //P[0]��λ�ڴ��ڵ��ϲ�
			p.y = Wyt;  //���㽻��x����
			p.x = (p.y - P[0].y) / k + P[0].x;
		}
		EnCode(p);
		P[0] = p;
	}
}

void CExperiment5_2View::EnCode(CP2 &pt) {  //�˵���뺯��
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