// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"
#include "TestDoc.h"
#include "TestView.h"
#define ROUND(a) int(a+0.5)//��������
#define PI 3.1415926//Բ����
#include "math.h"//��ѧͷ�ļ�

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
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_COMMAND(ID_MENUPlay, OnMENUPlay)
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_MENUPlay, OnUpdateMENUPlay)
	ON_WM_KEYDOWN()
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
	R=800.0;d=1000;Phi=0;Theta=-90;	
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
	InitParameter();
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
	int a=300;//�ⳤ
	P[0].x=0;P[0].y=0;P[0].z=2*sqrt(6)*a/9;   
	P[1].x=a/2;P[1].y=-sqrt(3)*a/6;P[1].z=-sqrt(6)*a/9;
	P[2].x=0;P[2].y=sqrt(3)*a/3;P[2].z=-sqrt(6)*a/9; 
	P[3].x=-a/2;P[3].y=-sqrt(3)*a/6;P[3].z=-sqrt(6)*a/9;  
}

void CTestView::ReadFace()//���
{
	//��ı�������Ķ�����
	F[0].En=3;F[0].p[0]=0;F[0].p[1]=1;F[0].p[2]=2;
	F[1].En=3;F[1].p[0]=0;F[1].p[1]=2;F[1].p[2]=3;
	F[2].En=3;F[2].p[0]=0;F[2].p[1]=3;F[2].p[2]=1;
	F[3].En=3;F[3].p[0]=1;F[3].p[1]=3;F[3].p[2]=2;
}

void CTestView::InitParameter()//͸�ӱ任������ʼ��
{	
	k[1]=sin(PI*Theta/180);
	k[2]=sin(PI*Phi/180);
	k[3]=cos(PI*Theta/180);
	k[4]=cos(PI*Phi/180);
	k[5]=k[3]*k[2];
	k[6]=k[1]*k[2];
	k[7]=k[3]*k[4];
	k[8]=k[1]*k[4];
	ViewPoint.x=R*k[5];//�û�����ϵ���ӵ�������
	ViewPoint.y=R*k[6];
	ViewPoint.z=R*k[4];
}

void CTestView::PerProject(CP3 P)//͸�ӱ任
{
	CP3 ViewP;
	ViewP.x=-k[1]*P.x+k[3]*P.y;//�۲�����ϵ��ά����
	ViewP.y=-k[7]*P.x-k[8]*P.y+k[2]*P.z;
	ViewP.z=-k[5]*P.x-k[6]*P.y-k[4]*P.z+R;
	ViewP.c=P.c;
	ScreenP.x=ROUND(d*ViewP.x/ViewP.z);//��Ļ����ϵ��ά����
	ScreenP.y=ROUND(d*ViewP.y/ViewP.z);
	ScreenP.c=ViewP.c;
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

void CTestView::DrawObject(CDC* pDC)//��������
{
	for(int nFace=0;nFace<4;nFace++)
	{
		CVector VS(P[F[nFace].p[1]],ViewPoint);//�����ʸ��
		CVector V01(P[F[nFace].p[0]],P[F[nFace].p[1]]);//���һ����ʸ��
		CVector V12(P[F[nFace].p[1]],P[F[nFace].p[2]]);//�����һ����ʸ��		
		CVector VN=V01*V12;//��ķ�ʸ��	
		if(Dot(VS,VN)>=0)//͹����������
			DrawFace(pDC,nFace);//�����������㣬���滭��
	}	
}

void CTestView::DrawFace(CDC* pDC,int nface)//���Ʊ���
{
	CP2 t;
	CLine line;
	for(int nEdge=0;nEdge<F[nface].En;nEdge++)//��ѭ��
	{
		PerProject(P[F[nface].p[nEdge]]);//͸��ͶӰ
		if(nEdge==0)
		{
			line.MoveTo(pDC,ScreenP);
			t=ScreenP;
		}
		else
		{
			line.LineTo(pDC,ScreenP);
		}		
	}
	line.LineTo(pDC,t.x,t.y,t.c);//�պ϶����
}

void CTestView::OnLButtonDown(UINT nFlags, CPoint point)//����������
{
	// TODO: Add your message handler code here and/or call default
	R=R+100;
	DoubleBuffer();
	CView::OnLButtonDown(nFlags, point);
}

void CTestView::OnRButtonDblClk(UINT nFlags, CPoint point)//����Ҽ����� 
{
	// TODO: Add your message handler code here and/or call default
	R=R-100;
	DoubleBuffer();
	CView::OnRButtonDblClk(nFlags, point);
}

void CTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(!Play)
	{
		switch(nChar)
		{
		case VK_UP:
			Phi-=1;//�趨����
			break;
		case VK_DOWN:
			Phi+=1;
			break;
		case VK_LEFT:
			Theta-=1;
			break;
		case VK_RIGHT:
		    Theta+=1;
			break;
		default:
			break;			
		}
		InitParameter();
		DoubleBuffer();		
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CTestView::OnMENUPlay()//������ť���� 
{
	// TODO: Add your command handler code here
	Play=Play?FALSE:TRUE;
	if (Play)//���ö�����ʱ�䲽
		SetTimer(1,15,NULL);	
	else
		KillTimer(1);
}

void CTestView::OnTimer(UINT nIDEvent)//����ʱ�亯�� 
{
	// TODO: Add your message handler code here and/or call default
	Phi-=1;//�趨����
	Theta-=1;
	InitParameter();
	DoubleBuffer();	
	CView::OnTimer(nIDEvent);
}

void CTestView::OnUpdateMENUPlay(CCmdUI* pCmdUI) //������ť״̬���� 
{
	// TODO: Add your command update UI handler code here
	if(Play)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);	
}


