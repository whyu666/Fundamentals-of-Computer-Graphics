// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"

#include "TestDoc.h"
#include "TestView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define ROUND(a) int(a+0.5)//��������
#define LEFT 1//����0001
#define RIGHT 2//����0010
#define BOTTOM 4//����0100
#define TOP 8//����1000
/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_COMMAND(ID_MENUcohen, OnMENUCohen)
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
	 wxl=100;wxr=400;wyb=200;wyt=500;
	 vxl=550;vxr=950;vyb=250;vyt=450;
	 a=(vxr-vxl)/(wxr-wxl);b=vxl-wxl*a;
	 c=(vyt-vyb)/(wyt-wyb);d=vyb-wyb*c;
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
	CPen Pen1,Pen2,Pen3,*pOldPen;//����3�����صĻ���
	Pen1.CreatePen(PS_SOLID,3,RGB(0,0,255));
	pOldPen=pDC->SelectObject(&Pen1);
	//���ƴ���
	pDC->MoveTo(ROUND(wxl),ROUND(wyt));pDC->LineTo(ROUND(wxr),ROUND(wyt));
	pDC->LineTo(ROUND(wxr),ROUND(wyb));pDC->LineTo(ROUND(wxl),ROUND(wyb));
	pDC->LineTo(ROUND(wxl),ROUND(wyt));
	pDC->TextOut((ROUND(wxl)+ROUND(wxr))/2,ROUND(wyb)-20,"����");//���ڱ���
	pDC->SelectObject(pOldPen);
	Pen1.DeleteObject();	
	Pen2.CreatePen(PS_SOLID,3,RGB(255,0,0));
	pOldPen=pDC->SelectObject(&Pen2);
	//��������
	pDC->MoveTo(ROUND(vxl),ROUND(vyt));pDC->LineTo(ROUND(vxr),ROUND(vyt));
	pDC->LineTo(ROUND(vxr),ROUND(vyb));pDC->LineTo(ROUND(vxl),ROUND(vyb));
	pDC->LineTo(ROUND(vxl),ROUND(vyt));
	pDC->TextOut((ROUND(vxl)+ROUND(vxr))/2,ROUND(vyb)-20,"����");//��������
	pDC->SelectObject(pOldPen);
	Pen2.DeleteObject();
	//���ƴ����������ķָ���
	GetClientRect(&Rect);//��ÿͻ����Ĵ�С
	Pen3.CreatePen(PS_SOLID,3,RGB(128,128,128));
	pOldPen=pDC->SelectObject(&Pen3);
	pDC->MoveTo(Rect.Width()/2,0);
	pDC->LineTo(Rect.Width()/2,Rect.Height());	
	pDC->SelectObject(pOldPen);
	Pen3.DeleteObject();	
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

void CTestView::OnMENUCohen()//�˵��������� 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	double xw1,yw1,xw2,yw2;
	CInputDlg dlg;	
	if(dlg.DoModal()==IDOK)
	{
		xw1=dlg.m_x1;xw2=dlg.m_x2;yw1=dlg.m_y1;yw2=dlg.m_y2;		
	}
	RedrawWindow();//ˢ����Ļ	
	//���ڻ���ֱ��
	dc.MoveTo(ROUND(xw1),ROUND(yw1));
	dc.LineTo(ROUND(xw2),ROUND(yw2));	
	clip(xw1,yw1,xw2,yw2);
	
}
void CTestView::clip(double xw1,double yw1,double xw2,double yw2)//�ü�����
{
	double xv1,yv1,xv2,yv2;
	double x,y;
	BOOL Change;
	CClientDC dc(this);
	RC1=EnCode(xw1,yw1);RC2=EnCode(xw2,yw2);
	while(TRUE)
	{
		Change=FALSE;	
		if( (RC1 | RC2)==0)
		{//��ȡ֮
			xv1=a*xw1+b;yv1=c*yw1+d;xv2=a*xw2+b;yv2=c*yw2+d;//������������	
			dc.MoveTo(ROUND(xv1),ROUND(yv1));
			dc.LineTo(ROUND(xv2),ROUND(yv2));
			return;
		}
		else if((RC1 & RC2)!=0)
		{//����֮
			return;
		}
		else
		{
			if(RC1==0)//���P1���ڴ����ڣ�����P1��P2,��֤p1���ڴ�����
			{
				//�����������ֵ
				double tx,ty;
				tx=xw1;ty=yw1;
				xw1=xw2;yw1=yw2;
				xw2=tx;yw2=ty;
				//������ı���ֵ
				unsigned int RC;
				RC=RC1;RC1=RC2;RC2=RC;
				}
			if(RC1 & LEFT )//P1��λ�ڴ��ڵ����
			{
				x=wxl;y=yw1+(yw2-yw1)*(x-xw1)/(xw2-xw1);
				xw1=x;yw1=y;
				Change=TRUE;
				RC1=EnCode(xw1,yw1);RC2=EnCode(xw2,yw2);
			}			
			if(RC1 & RIGHT )//P1��λ�ڴ��ڵ��Ҳ�
			{
				x=wxr;y=yw1+(yw2-yw1)*(x-xw1)/(xw2-xw1);
				xw1=x;yw1=y;
				Change=TRUE;
				RC1=EnCode(xw1,yw1);RC2=EnCode(xw2,yw2);
			}				
			if(RC1 & BOTTOM )//P1��λ�ڴ��ڵ��²�
			{
				y=wyb;x=xw1+(xw2-xw1)*(y-yw1)/(yw2-yw1);
				xw1=x;yw1=y;
				Change=TRUE;
				RC1=EnCode(xw1,yw1);RC2=EnCode(xw2,yw2);
			}			
			if(RC1 & TOP )//P1��λ�ڴ��ڵ��ϲ�
			{
				y=wyt;x=xw1+(xw2-xw1)*(y-yw1)/(yw2-yw1);
				xw1=x;yw1=y;
				Change=TRUE;
				RC1=EnCode(xw1,yw1);RC2=EnCode(xw2,yw2);
			}
			if(Change==FALSE)
			{
				return;
			}			
		}
	}
}
unsigned int CTestView::EnCode(double x,double y)//���뺯��
{//˳����������
	unsigned int RC=0;	
	if(x<wxl)
	{
		RC=RC | LEFT;
	}
	if(x>wxr)
	{
		RC=RC | RIGHT;
	}
	if(y<wyb)
	{
		RC=RC | BOTTOM;
	}
	if(y>wyt)
	{
		RC=RC | TOP;
	}
	return RC;
}
