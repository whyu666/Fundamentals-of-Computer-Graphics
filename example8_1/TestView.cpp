// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"
#include "TestDoc.h"
#include "TestView.h"
#define ROUND(a) int(a+0.5)//��������
#define PI 3.1415926//Բ����
#include "cmath"//��ѧͷ�ļ�

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
	ON_COMMAND(ID_MENUDraw, OnMENUDraw)
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
void CTestView::GetMaxX()//�����Ļ���
{
	CRect Rect;
	GetClientRect(&Rect);
	MaxX=Rect.right;
}
void CTestView::GetMaxY()//�����Ļ�߶�
{
	CRect Rect;
	GetClientRect(&Rect);
	MaxY=Rect.bottom;
}
void CTestView::ReadPointFlat()//�㶨��ɫ�������ε��
{
	int a=200;//�����������Բ�뾶
	for(int i=0;i<6;i++)
	{
		Pf[i].x=MaxX/4+ROUND(a*cos(i*PI/3));
		Pf[i].y=MaxY/2+ROUND(a*sin(i*PI/3));
	}
	Pf[6].x=MaxX/4;Pf[6].y=MaxY/2;//���ĵ�
	Pf[0].c.red=0.0;Pf[0].c.green=0.0;Pf[0].c.blue=1.0;//��ɫ
	Pf[1].c.red=0.0;Pf[1].c.green=1.0;Pf[1].c.blue=0.0;//��ɫ
	Pf[2].c.red=0.0;Pf[2].c.green=1.0;Pf[2].c.blue=1.0;//��ɫ
	Pf[3].c.red=1.0;Pf[3].c.green=0.0;Pf[3].c.blue=0.0;//��ɫ
	Pf[4].c.red=1.0;Pf[4].c.green=0.0;Pf[4].c.blue=1.0;//Ʒ��
	Pf[5].c.red=1.0;Pf[5].c.green=1.0;Pf[5].c.blue=0.0;//��ɫ
	Flag=true;
}

void CTestView::ReadPointSmooth()//������ɫ�������ε��
{
	int a=200;//�뾶
	for(int i=0;i<6;i++)
	{
		Ps[i].x=3*MaxX/4+ROUND(a*cos(i*PI/3));
		Ps[i].y=MaxY/2+ROUND(a*sin(i*PI/3));
	}
	Ps[6].x=3*MaxX/4;Ps[6].y=MaxY/2;//���ĵ�
	Ps[0].c.red=0.0;Ps[0].c.green=0.0;Ps[0].c.blue=1.0;//��ɫ
	Ps[1].c.red=0.0;Ps[1].c.green=1.0;Ps[1].c.blue=0.0;//��ɫ
	Ps[2].c.red=0.0;Ps[2].c.green=1.0;Ps[2].c.blue=1.0;//��ɫ
	Ps[3].c.red=1.0;Ps[3].c.green=0.0;Ps[3].c.blue=0.0;//��ɫ
	Ps[4].c.red=1.0;Ps[4].c.green=0.0;Ps[4].c.blue=1.0;//Ʒ��
	Ps[5].c.red=1.0;Ps[5].c.green=1.0;Ps[5].c.blue=0.0;//��ɫ
	Ps[6].c.red=1.0;Ps[6].c.green=1.0;Ps[6].c.blue=1.0;//��ɫ
	Flag=false;
}

void CTestView::ReadFace()//�����������
{
	//�㶨��ɫģ���Զ���ε�һ������ĵ�һ��ɫ���
	F[0].En=3;F[0].p[0]=0;F[0].p[1]=1;F[0].p[2]=6;//����
	F[1].En=3;F[1].p[0]=1;F[1].p[1]=2;F[1].p[2]=6;//����
	F[2].En=3;F[2].p[0]=2;F[2].p[1]=3;F[2].p[2]=6;//����
	F[3].En=3;F[3].p[0]=3;F[3].p[1]=4;F[3].p[2]=6;//����
	F[4].En=3;F[4].p[0]=4;F[4].p[1]=5;F[4].p[2]=6;//����
	F[5].En=3;F[5].p[0]=5;F[5].p[1]=0;F[5].p[2]=6;//����	
}

void CTestView::DrawHexagon(CP2 *P)//������������
{
	CDC *pDC=GetDC();
	CPi2 Point[3];//��Ķ�ά��������
	for(int nFace=0;nFace<6;nFace++)
	{
		int TotalEdge=F[nFace].En;//����ÿ������ܱ���
		for(int nEdge=0;nEdge<TotalEdge;nEdge++)//��ѭ��
		{
			int PointNumber=F[nFace].p[nEdge];//��Ķ����
			Point[nEdge].x=P[PointNumber].x;
			Point[nEdge].y=ROUND(P[PointNumber].y);
			if(Flag)
				Point[nEdge].c=P[F[nFace].p[0]].c;
			else
				Point[nEdge].c=P[PointNumber].c;
		}
		fill.SetPoint(Point,3);//��ʼ��Fill����
		fill.CreateBucket();//����Ͱ��
		fill.CreateEdge();//�����߱�
		fill.Gouraud(pDC);//���������	
	}
}

void CTestView::OnMENUDraw()//�˵��������� 
{
	// TODO: Add your command handler code here
	GetMaxX();GetMaxY();
	ReadPointFlat();
	ReadFace();
	DrawHexagon(Pf);
	ReadPointSmooth();
	DrawHexagon(Ps);
}
