// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"

#include "TestDoc.h"
#include "TestView.h"

#include "cmath"
#define  PI 3.1415926
#define  ROUND(x)  int(x+0.5)
#include "SetDlg.h"

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
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_MENUPlay, OnMENUPlay)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_UPDATE_COMMAND_UI(ID_MENUPlay, OnUpdateMENUPlay)
	ON_COMMAND(IDD_MENUSet, OnMENUSet)
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
	R=1000,d=800,Phi=90.0,Theta=0.0;	
	LightNum=3;//��Դ����
	pLight=new CLighting(LightNum);//һά��Դ��̬����
	pLight->Light[0].SetGlobal(1200,0,0);//���õ�һ����Դ������
	pLight->Light[1].SetGlobal(1200,90,90);
	pLight->Light[2].SetGlobal(1200,90,0);
	pLight->Light[0].L_Specular=CRGB(0,1,0);
	pLight->Light[1].L_Specular=CRGB(1,0,0);
	pLight->Light[2].L_Specular=CRGB(0,0,1);
	for(int i=0;i<LightNum;i++)
	{
		pLight->Light[i].L_Diffuse=CRGB(1.0,1.0,1.0);//��Դ����������ɫ	
		//pLight->Light[i].L_Specular=CRGB(1,1.0,1.0);//��Դ����߹���ɫ
		pLight->Light[i].L_C0=1.1;//����˥��ϵ��
		pLight->Light[i].L_C1=0.0000001;//����˥��ϵ��
		pLight->Light[i].L_C2=0.00000003;//����˥��ϵ��
		pLight->Light[i].L_OnOff=TRUE;//��Դ����
	}
 	pMaterial=new CMaterial;//һά���ʶ�̬����
	pMaterial->M_Ambient=CRGB(0.1,0.1,0.1);//���ʶԻ�����ķ�����
	pMaterial->M_Diffuse=CRGB(0.3,0.3,0.3);//���ʶ��������ķ�����
	pMaterial->M_Specular=CRGB(1.0,1.0,1.0);//���ʶԾ��淴���ķ�����
	pMaterial->M_Exp=15.0;//�߹�ָ��
}

CTestView::~CTestView()
{
	if(pLight)
		delete [] pLight;
	if(pMaterial)
		delete pMaterial;
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
void CTestView::ReadPoint()//���������
{
	afa=beta=4;//��Ƭ�н�
	N1=180/afa,N2=360/beta;//N1Ϊγ������,N2Ϊ��������
	P=new CP3[(N1-1)*N2+2];//γ�ȷ�����ϱ��������С�N1��1�����㣬��2�������ϱ�������
	double afa1,beta1,r=300;//rΪ��뾶
	//���㱱����
	P[0].x=0,P[0].y=0,P[0].z=r;//����������
	//���������ϵĵ�
	for(int i=0;i<=N1-2;i++)
	{
		afa1=(i+1)*afa*PI/180;
		for(int j=0;j<N2;j++)
	    {
			beta1=j*beta*PI/180;		
			P[i*N2+j+1].x=r*sin(afa1)*cos(beta1);
			P[i*N2+j+1].y=r*sin(afa1)*sin(beta1);
			P[i*N2+j+1].z=r*cos(afa1);				
		}
	}
	//�����ϼ���
	P[(N1-1)*N2+1].x=0,P[(N1-1)*N2+1].y=0,P[(N1-1)*N2+1].z=-r;	
}

void CTestView::ReadFace()//����������
{
	//��Ķ�ά��̬����
	F=new CFace *[N1];
	for(int n=0;n<N1;n++)
	{
		F[n]=new CFace[N2];
	}
	//���챱����������Ƭ
	for(int j=0;j<N2;j++)
	{
		int tempj=j+1;
		if(tempj==N2) tempj=0;//��Ƭ����β����
		int NorthIndex[3];//������������Ƭ����������
		NorthIndex[0]=0;
		NorthIndex[1]=j+1;
		NorthIndex[2]=tempj+1;
		F[0][j]=CFace(NorthIndex,3);
		F[0][j].SetNormal(P[NorthIndex[0]],P[NorthIndex[1]],P[NorthIndex[2]]);//����С��Ƭ��ʸ��
	}
	//���������ı�����Ƭ
	for(int i=1;i<N1-1;i++)
	{
		for(int j=0;j<N2;j++)
	    {
			int tempi=i+1;
			int tempj=j+1;
			if(tempj==N2) tempj=0;
			int BodyIndex[4];//�����ı�����Ƭ����������
			BodyIndex[0]=(i-1)*N2+j+1;
			BodyIndex[1]=(tempi-1)*N2+j+1;
			BodyIndex[2]=(tempi-1)*N2+tempj+1;
			BodyIndex[3]=(i-1)*N2+tempj+1;
			F[i][j]=CFace(BodyIndex,4);
			F[i][j].SetNormal(P[BodyIndex[0]],P[BodyIndex[1]],P[BodyIndex[2]]);//����С��Ƭ��ʸ��
		}
	}
	//�����ϼ���������Ƭ
	for(j=0;j<N2;j++)
	{
		int tempj=j+1;
		if(tempj==N2) tempj=0;
		int SouthIndex[3];//�ϼ���������Ƭ����������
		SouthIndex[0]=(N1-2)*N2+j+1;
		SouthIndex[1]=(N1-1)*N2+1;
		SouthIndex[2]=(N1-2)*N2+tempj+1;
		F[N1-1][j]=CFace(SouthIndex,3);	
		F[N1-1][j].SetNormal(P[SouthIndex[0]],P[SouthIndex[1]],P[SouthIndex[2]]);//����С��Ƭ��ʸ��
	}
}

void CTestView::InitParameter()
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

void CTestView::PerProject(CP3 P)
{
	CP3 ViewP;
	ViewP.x=-k[1]*P.x+k[3]*P.y;//�۲�����ϵ��ά����
	ViewP.y=-k[7]*P.x-k[8]*P.y+k[2]*P.z;
	ViewP.z=-k[5]*P.x-k[6]*P.y-k[4]*P.z+R;
	ViewP.c=P.c;
	ScreenP.x=d*ViewP.x/ViewP.z;//��Ļ����ϵ��ά����
	ScreenP.y=d*ViewP.y/ViewP.z;
	ScreenP.z=d*(d-ViewP.z)/ViewP.z;
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

void CTestView::DrawObject(CDC *pDC)//��������
{
	CPi3 Point3[3];//�ϱ�����������
	CVector Normal3[3];
	CPi3 Point4[4];//���嶥������
	CVector Normal4[4];
	for(int i=0;i<N1;i++)
	{
		for(int j=0;j<N2;j++)
		{
			CVector VS(P[F[i][j].pIndex[1]],ViewPoint);//�����ʸ��
			if(Dot(VS,F[i][j].Normal)>=0)
			{
				if(F[i][j].En==3)
				{
					for(int m=0;m<F[i][j].En;m++)
					{
						PerProject(P[F[i][j].pIndex[m]]);
						Point3[m].x=ScreenP.x;
						Point3[m].y=ROUND(ScreenP.y);
						Point3[m].z=ScreenP.z;
						Normal3[m]=CVector(P[F[i][j].pIndex[m]]);
					}			
					zbuf.SetPoint(Point3,Normal3,3);//��ʼ���ϱ�����CZBuffer����
					zbuf.CreateBucket();//����Ͱ��
					zbuf.CreateEdge();//�����߱�
					zbuf.Phong(pDC,ViewPoint,pLight,pMaterial);//��ɫ�������������
				}
				else
				{
					for(int m=0;m<F[i][j].En;m++)
					{
						PerProject(P[F[i][j].pIndex[m]]);
						Point4[m].x=ScreenP.x;
						Point4[m].y=ROUND(ScreenP.y);
						Point4[m].z=ScreenP.z;
						Normal4[m]=CVector(P[F[i][j].pIndex[m]]);
					}
					zbuf.SetPoint(Point4,Normal4,4);//��ʼ��CZBuffer����
					zbuf.CreateBucket();//����Ͱ��
					zbuf.CreateEdge();//�����߱�
					zbuf.Phong(pDC,ViewPoint,pLight,pMaterial);//��ɫ��������ı���
				}
			} 	
		}	
	}		
}
	
void CTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(!Play)
	{
		switch(nChar)
		{
		case VK_UP:
			Phi-=5;//�趨����
			break;
		case VK_DOWN:
			Phi+=5;
			break;
		case VK_LEFT:
			Theta-=5;
			break;
		case VK_RIGHT:
		    Theta+=5;
			break;
		default:
			break;			
		}
		InitParameter();
		DoubleBuffer();		
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CTestView::OnMENUPlay() 
{
	// TODO: Add your command handler code here
	Play=Play?FALSE:TRUE;
	if (Play)//���ö�����ʱ�䲽
		SetTimer(1,50,NULL);	
	else
		KillTimer(1);
}

void CTestView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//Phi-=5;//�趨����
	//Theta-=5;
	InitParameter();
	DoubleBuffer();	
	pLight->Step();
	CView::OnTimer(nIDEvent);
}


BOOL CTestView::OnEraseBkgnd(CDC* pDC)//���ñ������� 
{
	// TODO: Add your message handler code here and/or call default
	CRect Rect;   
	GetClientRect(&Rect);   
	pDC->FillSolidRect(Rect,RGB(0,0,0));
	return true;
}

void CTestView::OnUpdateMENUPlay(CCmdUI* pCmdUI)//������ť״̬����  
{
	// TODO: Add your command update UI handler code here
	if(Play)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

void CTestView::OnMENUSet() 
{
	// TODO: Add your command handler code here
	CSetDlg dlg;
	int res = dlg.DoModal();
	if (res == IDCANCEL ) return;

	if(dlg.reset==1)
	{
		pLight->Light[0].SetGlobal(1200,0,0);
		pLight->Light[1].SetGlobal(1200,90,90);
		pLight->Light[2].SetGlobal(1200,90,0);
		pLight->Light[0].L_Specular=CRGB(0,1,0);
		pLight->Light[1].L_Specular=CRGB(1,0,0);
		pLight->Light[2].L_Specular=CRGB(0,0,1);
		pMaterial->M_Ambient=CRGB(0.1,0.1,0.1);//���ʶԻ�����ķ�����
		pMaterial->M_Diffuse=CRGB(0.3,0.3,0.3);//���ʶ��������ķ�����
		pMaterial->M_Specular=CRGB(1.0,1.0,1.0);//���ʶԾ��淴���ķ�����
		pMaterial->M_Exp=15.0;//�߹�ָ��
	}

	if(dlg.light==-1&&dlg.m_position1.GetLength()!=0&&dlg.m_position2.GetLength()!=0&&dlg.m_position3.GetLength()!=0&&dlg.m_color1.GetLength()!=0&&dlg.m_color2.GetLength()!=0&&dlg.m_color3.GetLength()!=0)
	{
		MessageBox("��ѡ���Դ��");
	}

	if(dlg.m_position1.GetLength()!=0&&dlg.m_position2.GetLength()!=0&&dlg.m_position3.GetLength()!=0)
	{
		double pos1=atof(dlg.m_position1),pos2=atof(dlg.m_position2),pos3=atof(dlg.m_position3);
		if(pos1<0||pos2<0||pos2>90||pos3<0||pos3>360)
		{
			MessageBox("λ����������");
		}
		else
		{
			pLight->Light[dlg.light].SetGlobal(pos1,pos2,pos3);
		}
	}

	if(dlg.m_color1.GetLength()!=0&&dlg.m_color2.GetLength()!=0&&dlg.m_color3.GetLength()!=0)
	{
		double color1=atof(dlg.m_color1),color2=atof(dlg.m_color2),color3=atof(dlg.m_color3);
		if(color1<0||color1>255||color2<0||color2>255||color3<0||color3>255)
		{
			MessageBox("��ɫ��������");
		}
		else
		{
			if(color1!=0||color2!=0||color3!=0){
				pLight->Light[dlg.light].L_Specular=CRGB(color1/255,color2/255,color3/255);
				pLight->Light[dlg.light].L_OnOff = TRUE;
			}
			else{
				pLight->Light[dlg.light].L_OnOff = FALSE;
			}
			
		}
	}

	pLight->Light[dlg.light].dStepPhi = dlg.m_move_phi;
	pLight->Light[dlg.light].dStepTheta = dlg.m_move_theta;
	pLight->Light[dlg.light].dStepX = dlg.m_move_dx;
	pLight->Light[dlg.light].dStepY = dlg.m_move_dy;
	pLight->Light[dlg.light].dStepZ = dlg.m_move_dz;




	//�챦ʯ
	if(dlg.material==0)
	{
		pMaterial->M_Ambient=CRGB(0.175,0.012,0.012);
		pMaterial->M_Diffuse=CRGB(0.614,0.041,0.041);
		pMaterial->M_Specular=CRGB(0.728,0.527,0.527);
	}

	//�̱�ʯ
	if(dlg.material==1)
	{
		pMaterial->M_Ambient=CRGB(0.022,0.175,0.023);
		pMaterial->M_Diffuse=CRGB(0.076,0.614,0.075);
		pMaterial->M_Specular=CRGB(0.633,0.728,0.633);
	}

	//��
	if(dlg.material==2)
	{
		pMaterial->M_Ambient=CRGB(0.247,0.2,0.075);
		pMaterial->M_Diffuse=CRGB(0.752,0.606,0.226);
		pMaterial->M_Specular=CRGB(0.628,0.556,0.366);
	}

	//��
	if(dlg.material==3)
	{
		pMaterial->M_Ambient=CRGB(0.192,0.192,0.192);
		pMaterial->M_Diffuse=CRGB(0.508,0.508,0.508);
		pMaterial->M_Specular=CRGB(0.508,0.508,0.508);
	}

	DoubleBuffer();
}
