// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"
#include "TestDoc.h"
#include "TestView.h"
#define PI 3.1415926//Բ����
#include "math.h"//��ѧͷ�ļ�
#define ROUND(a) int(a+0.5)//��������
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here
}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here	
	ReadPoint();
	ReadFace();
	DoubleBuffer();	
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers

void CTestView::ReadPoint()//���
{
	int i;	
	//��ɫ�������������ά����(x,y,z)
	P[0][0].x=-150;P[0][0].y=-200;P[0][0].z=0;
	P[0][1].x=-150;P[0][1].y=-200;P[0][1].z=0;
	P[0][2].x=-125;P[0][2].y=-200;P[0][2].z=0;
	P[0][3].x=-125;P[0][3].y=-200;P[0][3].z=0;
	P[0][4].x=25;P[0][4].y=200;P[0][4].z=-100;
	P[0][5].x=25;P[0][5].y=200;P[0][5].z=-100;
	P[0][6].x=50;P[0][6].y=200;P[0][6].z=-100;
	P[0][7].x=50;P[0][7].y=200;P[0][7].z=-100;
	for(i=0;i<8;i++)//������ɫ��ֵ
	{
		P[0][i].c=CRGB(1.0,0.0,0.0);
	}	
	//��ɫ�������������ά����(x,y,z)
	P[1][0].x=150;P[1][0].y=-200;P[1][0].z=50;
	P[1][1].x=150;P[1][1].y=-200;P[1][1].z=50;
	P[1][2].x=125;P[1][2].y=-200;P[1][2].z=50;
	P[1][3].x=125;P[1][3].y=-200;P[1][3].z=50;
	P[1][4].x=-25;P[1][4].y=200;P[1][4].z=100;
	P[1][5].x=-25;P[1][5].y=200;P[1][5].z=100;
	P[1][6].x=-50;P[1][6].y=200;P[1][6].z=100;
	P[1][7].x=-50;P[1][7].y=200;P[1][7].z=100;
	for(i=0;i<8;i++)
	{
		P[1][i].c=CRGB(0.0,0.0,1.0);
	}
	//��ɫ�������������ά����(x,y,z)
	P[2][0].x=-200;P[2][0].y=-150;P[2][0].z=-100;
	P[2][1].x=-200;P[2][1].y=-150;P[2][1].z=-100;
	P[2][2].x=-200;P[2][2].y=-125;P[2][2].z=-100;
	P[2][3].x=-200;P[2][3].y=-125;P[2][3].z=-100;
	P[2][4].x=200;P[2][4].y=-150;P[2][4].z=120;
	P[2][5].x=200;P[2][5].y=-150;P[2][5].z=120;
	P[2][6].x=200;P[2][6].y=-125;P[2][6].z=120;
	P[2][7].x=200;P[2][7].y=-125;P[2][7].z=120;
	for(i=0;i<8;i++)
	{
		P[2][i].c=CRGB(0.0,1.0,0.0);
	}
}
void CTestView::ReadFace()//���
{
	//��ı�������Ķ����ź������ɫ
	F[0].En=4;F[0].p[0]=0;F[0].p[1]=3;F[0].p[2]=2;F[0].p[3]=1;//ÿ�����ĺ���
	F[1].En=4;F[1].p[0]=4;F[1].p[1]=5;F[1].p[2]=6;F[1].p[3]=7;//ÿ������ǰ��
	F[2].En=4;F[2].p[0]=0;F[2].p[1]=4;F[2].p[2]=7;F[2].p[3]=3;//ÿ����������
	F[3].En=4;F[3].p[0]=1;F[3].p[1]=2;F[3].p[2]=6;F[3].p[3]=5;//ÿ����������
	F[4].En=4;F[4].p[0]=3;F[4].p[1]=7;F[4].p[2]=6;F[4].p[3]=2;//ÿ�����Ķ���
	F[5].En=4;F[5].p[0]=0;F[5].p[1]=1;F[5].p[2]=5;F[5].p[3]=4;//ÿ�����ĵ���
}

void CTestView::DoubleBuffer()//˫����
{	
	CRect Rect;
	GetClientRect(&Rect);
	CDC *pDC=GetDC();
	pDC->SetMapMode(MM_ANISOTROPIC);//�Զ�������ϵ
	pDC->SetWindowExt(Rect.Width(),Rect.Height());
	pDC->SetViewportExt(Rect.Width(),-Rect.Height());//x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(Rect.Width()/2,Rect.Height()/2);//��Ļ����Ϊԭ��	
	CDC	MemDC,Picture;
	MemDC.CreateCompatibleDC(pDC);
	MemDC.SetMapMode(MM_ANISOTROPIC);
	MemDC.SetWindowExt(Rect.Width(),Rect.Height());
	MemDC.SetViewportExt(Rect.Width(),-Rect.Height());
	MemDC.SetViewportOrg(Rect.Width()/2,Rect.Height()/2);
	CBitmap NewBitmap,*OldBitmap;
	NewBitmap.LoadBitmap(IDB_BITMAP2);
	OldBitmap=MemDC.SelectObject(&NewBitmap);
	MemDC.BitBlt(-Rect.Width()/2,-Rect.Height()/2,Rect.Width(),Rect.Height(),&Picture,-Rect.Width()/2,-Rect.Height()/2,SRCCOPY);
	DrawObject(&MemDC);
	pDC->BitBlt(-Rect.Width()/2,-Rect.Height()/2,Rect.Width(),Rect.Height(),&MemDC,-Rect.Width()/2,-Rect.Height()/2,SRCCOPY);
	ReleaseDC(pDC);
	MemDC.SelectObject(OldBitmap);	
	NewBitmap.DeleteObject();	
}

void CTestView::DrawObject(CDC *pDC)//���ƽ�����
{
	CPi3 Point[4];	
	zbuf.InitDeepBuffer(800,800,-1000);//��ȳ�ʼ��
	for(int nBar=0;nBar<3;nBar++)
	{		
		for(int nFace=0;nFace<6;nFace++)
		{
			for(int nEdge=0;nEdge<F[nFace].En;nEdge++)//��ѭ��
			{
				Point[nEdge].x=P[nBar][F[nFace].p[nEdge]].x;
				Point[nEdge].y=ROUND(P[nBar][F[nFace].p[nEdge]].y);
				Point[nEdge].z=P[nBar][F[nFace].p[nEdge]].z;
				Point[nEdge].c=P[nBar][F[nFace].p[nEdge]].c;
			}
			zbuf.SetPoint(Point,4);			
			zbuf.CreateBucket();//����Ͱ��
			zbuf.CreateEdge();//�����߱�
			zbuf.Gouraud(pDC);//��ɫ��������ı���
		}
	}
}

BOOL CTestView::OnEraseBkgnd(CDC* pDC)//���ñ���ɫ���� 
{
	// TODO: Add your message handler code here and/or call default
	CRect Rect;   
	GetClientRect(&Rect);   
	pDC->FillSolidRect(Rect,RGB(0,0,0));
	return true;
}
