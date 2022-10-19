// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"
#define ROUND(a) int(a+0.5)//��������
#include "math.h"//������ѧͷ�ļ�
#define PI 3.1415926//Բ����
#include "TestDoc.h"
#include "TestView.h"

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
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUPlay, OnMENUPlay)
	ON_UPDATE_COMMAND_UI(ID_MENUPlay, OnUpdateMENUPlay)
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
	Play=FALSE;
	beta=0;
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
void CTestView::GetMaxX()//����Ļ���xֵ
{
	CRect rect;
	GetClientRect(&rect);
    MaxX=rect.right;
}
void CTestView::GetMaxY()//����Ļ���yֵ
{
	CRect rect;
	GetClientRect(&rect);
    MaxY=rect.bottom;
}
void CTestView::ReadPoint()
{
	a=100,b=200;
	POld[0][0]=-a/2;POld[0][1]=-(b-a/2);POld[0][2]=1;//�����ζ����������
	POld[1][0]=-a/2;POld[1][1]=-(b+a/2);POld[1][2]=1;
	POld[2][0]=a/2;POld[2][1]=-(b+a/2);POld[2][2]=1;
	POld[3][0]=a/2;POld[3][1]=-(b-a/2);POld[3][2]=1;	
}
void CTestView::DrawPolygon(CDC *pDC,double p[][3])//���ƶ���κ���
{
	double Tempx,Tempy;
	for(int i=0;i<4;i++)
	{
		if(i==0)
		{
			pDC->MoveTo(ROUND(p[i][0]),ROUND(p[i][1]));
			Tempx=p[i][0];Tempy=p[i][1];
		}
		else
			pDC->LineTo(ROUND(p[i][0]),ROUND(p[i][1]));
	}
	pDC->LineTo(ROUND(Tempx),ROUND(Tempy));
}


void CTestView::DoubleBuffer()//˫���庯��
{
	double Tx=0,Ty=b;
	//ƽ�Ʊ任����
	T1[0][0]=1;T1[0][1]=0;T1[0][2]=0;
	T1[1][0]=0;T1[1][1]=1;T1[1][2]=0;
	T1[2][0]=-Tx;T1[2][1]=Ty;T1[2][2]=1;
	//��ʱ����ת�任����
	T2[0][0]=cos(beta*PI/180);T2[0][1]=sin(beta*PI/180);T2[0][2]=0;
	T2[1][0]=-sin(beta*PI/180);T2[1][1]=cos(beta*PI/180);T2[1][2]=0;
	T2[2][0]=0;T2[2][1]=0;T2[2][2]=1;
	//��ƽ�Ʊ任����
	T3[0][0]=1;T3[0][1]=0;T3[0][2]=0;
	T3[1][0]=0;T3[1][1]=1;T3[1][2]=0;
	T3[2][0]=Tx;T3[2][1]=-Ty;T3[2][2]=1;
	MultiMatrix(POld,T1);
	MultiMatrix(POld,T2);
	MultiMatrix(POld,T3);
	CDC *pDC=GetDC();//�ͻ���DC	
	GetMaxX();GetMaxY();
	pDC->SetMapMode(MM_ANISOTROPIC);//�Զ�������ϵ
	pDC->SetWindowExt(MaxX,MaxY);
	pDC->SetViewportExt(MaxX,-MaxY);//x��ˮƽ���ң�y�ᴹֱ���� 
	pDC->SetViewportOrg(MaxX/2,MaxY/2);//��Ļ����Ϊԭ��
	CDC	MemDC,Picture;
	MemDC.CreateCompatibleDC(pDC);
	MemDC.SetMapMode(MM_ANISOTROPIC);
	MemDC.SetWindowExt(MaxX,MaxY);
	MemDC.SetViewportExt(MaxX,-MaxY);
	MemDC.SetViewportOrg(MaxX/2,MaxY/2);
	CBitmap NewBitmap,*OldBitmap;
	NewBitmap.LoadBitmap(IDB_BITMAP2);
	OldBitmap=MemDC.SelectObject(&NewBitmap);
	MemDC.BitBlt(-MaxX/2,-MaxY/2,MaxX,MaxY,&Picture,-MaxX/2,-MaxY/2,SRCCOPY);
	DrawCoor(&MemDC);
	DrawPolygon(&MemDC,POld);
	pDC->BitBlt(-MaxX/2,-MaxY/2,MaxX,MaxY,&MemDC,-MaxX/2,-MaxY/2,SRCCOPY);
	ReleaseDC(pDC);
	MemDC.SelectObject(OldBitmap);	
	NewBitmap.DeleteObject();	
}

void CTestView::MultiMatrix(double P0[][3],double T[3][3])//�������
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
			PNew[i][j]=P0[i][0]*T[0][j]+P0[i][1]*T[1][j]+P0[i][2]*T[2][j];
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
			POld[i][j]=PNew[i][j];
	}
}

void CTestView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	beta=10;
	DoubleBuffer();	
	CView::OnTimer(nIDEvent);
}

void CTestView::DrawCoor(CDC *pDC)//��������ϵ����
{
	CPen NewPen,*OldPen;
	NewPen.CreatePen(PS_SOLID,3,RGB(128,0,128));
	OldPen=pDC->SelectObject(&NewPen);
	pDC->MoveTo(-100,0);
	pDC->LineTo(100,0);
	pDC->MoveTo(0,0);
	pDC->LineTo(0,-b);
	pDC->SelectObject(OldPen);
	NewPen.DeleteObject();	
}

void CTestView::OnMENUPlay()//�˵��������� 
{
	// TODO: Add your command handler code here
	Play=Play?FALSE:TRUE;
	if (Play)//���ö�����ʱ�䲽
		SetTimer(1,15,NULL);		
	else
		KillTimer(1);
}

void CTestView::OnUpdateMENUPlay(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(Play)
	{
		pCmdUI->SetCheck(TRUE);
	    pCmdUI->SetText("ֹͣ����");
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
		pCmdUI->SetText("���Ŷ���");
	}
}
