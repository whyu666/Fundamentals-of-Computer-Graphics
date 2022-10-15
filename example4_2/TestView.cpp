// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"

#include "TestDoc.h"
#include "TestView.h"
#define   ROUND(a) int(a+0.5) //����
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
	ON_COMMAND(ID_MENUEdgeFill, OnMENUEdgeFill)
	ON_COMMAND(ID_MENUFillColor, OnMENUFillColor)
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
	FillColor=RGB(0,0,0);
	Point[0]=CPoint(550,400);
	Point[1]=CPoint(350,600);
	Point[2]=CPoint(250,350);
	Point[3]=CPoint(350,50);
	Point[4]=CPoint(500,250);
	Point[5]=CPoint(600,50);
	Point[6]=CPoint(800,450);	
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
	DrawPolygon();//���ƶ����	
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
void CTestView::GetMaxX()//����Ļ���xֵ
{
	CRect rect;
	GetClientRect(rect);
    MaxX=rect.right;
}
void CTestView::GetMaxY()//����Ļ���yֵ
{
	CRect rect;
	GetClientRect(rect);
    MaxY=rect.bottom;
}
void CTestView::Draw()//�������
{
	COLORREF CBackColor=RGB(255,255,255);//��ɫ
	CClientDC dc(this);
	int m,n,ymin,ymax;	
	double x,y,k;
	for(int i=0;i<=6;i++)//���ڶ�������б�ѭ��
	{
		m=i,n=i+1;//�Ե��ѭ��
		if(7==n) n=0;
		k=(double(Point[m].x-Point[n].x))/(Point[m].y-Point[n].y);//����1/k	
		if(Point[m].y<Point[n].y)//�õ�ÿ���ߵ�y����y��Сֵ
		{
			ymin=Point[m].y;
			ymax=Point[n].y;
			x=Point[m].x;//�õ�x|ymin
		}
		else
		{
			ymin=Point[n].y;
			ymax=Point[m].y;
			x=Point[n].x;
		}
		for(y=ymin;y<ymax;y++)//��ÿһ����ѭ��
		{			
			for(int j=ROUND(x);j<MaxX;j++)//��ÿһ��ɨ������ߵĽ�����Ҳ�����ѭ��
			{
				if(dc.GetPixel(j,ROUND(y))==FillColor)//������ص���ɫ�����ɫ
				{
					dc.SetPixel(j,ROUND(y),CBackColor);//��Ϊ����ɫ
				}
				else
				{
					dc.SetPixel(j,ROUND(y),FillColor);//ʹ�����ɫ���
				}		
			}
			x+=k;//������һ��x���ֵ
		}		
	}	
}
void CTestView::DrawPolygon()//���ƶ���κ���
{
	CClientDC dc(this);
	int m,n;
	for(int j=0;j<=6;j++)
	{
		m=j,n=j+1;
		if(7==n) n=0;
		dc.MoveTo(Point[m]);
		dc.LineTo(Point[n]);
	}
}

void CTestView::OnMENUFillColor()//ѡ�����ɫ
{
	// TODO: Add your command handler code here
	CColorDialog ccd(FillColor);
	if(ccd.DoModal()==IDOK)
	{
		FillColor=ccd.GetColor();
	}	
}

void CTestView::OnMENUEdgeFill()//�˵�����
{
	// TODO: Add your command handler code here
	RedrawWindow();
	AfxGetMainWnd()->SetWindowText("����7������α�Ե����㷨");//��ʾ����
	GetMaxX();GetMaxY();
	Draw();
}


