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
#pragma comment(lib, "openGL32.lib")//���ӿ�
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")
/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_UPDATE_COMMAND_UI(ID_MenuDraw, OnUpdateMenuDraw)
	ON_WM_TIMER()
	ON_COMMAND(ID_MenuPlay, OnMenuPlay)
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
	GLfloat  wAngleX=1.0f;
	GLfloat  wAngleY=40.0f;    
    GLfloat  wAngleZ=5.0f;
	a=1.0f;
	m_pDC=NULL;
	Play=FALSE;	
}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style=WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS;
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	OnDrawScene();//���Ƴ���	
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

int CTestView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;	
	// TODO: Add your specialized creation code here
	PIXELFORMATDESCRIPTOR pfd=
	{
		sizeof(PIXELFORMATDESCRIPTOR),    //pfd��С
			1,                            //�汾��
			PFD_DRAW_TO_WINDOW|           // ֧��Windows
			PFD_SUPPORT_OPENGL            // ֧��OpenGL
			|PFD_DOUBLEBUFFER,            //ʹ��˫����
			PFD_TYPE_RGBA,                //RGBA ����		
			24,                           // 24λ��ɫ��� 
			0,0,0,0,0,0,                  // ���Ե���ɫλ
			0,                            // ��alpha����
			0,                            // ������λ 
			0,                            // ���ۻ�����
			0,0,0,0,                      // ���Ե��ۻ�λ 
			32,                           // 32λz����
			0,                            // ��ģ�滺�� 
			0,                            // �޸������� 
			PFD_MAIN_PLANE,               // �����Ʋ� 
			0,                            // ����λ 
			0,0,0,                        // ���ԵĲ���ģ
	};
	m_pDC=new CClientDC(this);
	int pixelformat;
	if ((pixelformat=ChoosePixelFormat(m_pDC->GetSafeHdc(),&pfd))==0)//ѡ�����ظ�ʽ������������
	{
		MessageBox("ChoosePixelFormat failed");
		return FALSE;
	}
	if (SetPixelFormat(m_pDC->GetSafeHdc(),pixelformat,&pfd)==FALSE)//�������ظ�ʽ
	{
		MessageBox("SetPixelFormat failed");
		return FALSE;
	}
	rc=wglCreateContext(m_pDC->GetSafeHdc());//������Ⱦ������
	wglMakeCurrent(m_pDC->GetSafeHdc(),rc);//DC��RC����ʹRC��Ϊ����rc
	return 0;	
}

void CTestView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	// TODO: Add your message handler code here
	if(cy>0)
	{
		glViewport(0, 0, cx, cy);
		glEnable(GL_DEPTH_TEST);
		glMatrixMode(GL_PROJECTION);//ͶӰ�任����
		glLoadIdentity();//ͶӰ�任����Ҫ��
		gluPerspective(55.0f,(GLdouble)cx/cy,2.0f,7.0f);//����͸��ͶӰȡ����
		glMatrixMode(GL_MODELVIEW);
	}
    Texture();
	glEnable(GL_TEXTURE_2D);	
}

void CTestView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	if(wglGetCurrentContext()!=NULL)//��������е�RC
		wglMakeCurrent(NULL,NULL);//�Ͽ�RC���̵߳���ϵ
	if(rc!=NULL)
	{
		wglDeleteContext(rc);
		rc=NULL;
	}	
}
void CTestView::OnDrawScene() //���Ƴ���
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);//����������ɫΪ��ɫ
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//�����ɫ����������Ȼ�����
	glPushMatrix();
	glTranslatef(0.0f,0.0f,-4.5);//ƽ�Ʊ任
	glRotatef(wAngleX,1.0f,0.0f,0.0f);//x������ת�任
	glRotatef(wAngleY,0.0f,1.0f,0.0f);//y������ת�任
	glRotatef(wAngleZ,0.0f,0.0f,1.0f);//z������ת�任
	wAngleX+=1.0f;
	wAngleY+=1.0f;
	wAngleZ+=1.0f;
	//����������ǰ�������������ά��������
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);//glBegin()��glEnd()������	  
	glTexCoord2f(0.0f, 0.0f);glVertex3f(-a, -a,  a);
	glTexCoord2f(1.0f, 0.0f);glVertex3f( a, -a,  a);
	glTexCoord2f(1.0f, 1.0f);glVertex3f( a,  a,  a);
	glTexCoord2f(0.0f, 1.0f);glVertex3f(-a,  a,  a);
	glEnd();
	//������������������������ά�������� 	   
    glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-a, -a, -a);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-a,  a, -a);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( a,  a, -a);
	glTexCoord2f(0.0f, 1.0f); glVertex3f( a, -a, -a);
	glEnd();
	//���������嶥�������������ά��������    
    glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-a,  a, -a);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-a,  a,  a);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( a, a,  a);
	glTexCoord2f(0.0f, 1.0f); glVertex3f( a,  a, -a);
	glEnd(); 
	//������������������������ά��������
    glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-a, -a, -a);
	glTexCoord2f(1.0f, 0.0f); glVertex3f( a, -a, -a);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( a, -a,  a);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-a, -a,  a);
	glEnd();
	//�������������������������ά��������
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f( a, -a, -a);
	glTexCoord2f(1.0f, 0.0f); glVertex3f( a,  a, -a);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( a,  a,  a);
	glTexCoord2f(0.0f, 1.0f); glVertex3f( a, -a,  a);
	glEnd();
	//�������������������������ά��������	   
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-a, -a, -a);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-a, -a,  a);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-a,  a,  a);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-a,  a, -a);
	glEnd();
	glPopMatrix();
    glFlush();
	SwapBuffers(wglGetCurrentDC());//����˫����Ļ��ƣ�ʵ�ֶ��� 
}
void CTestView::Texture()//ͼƬ������
{
	HBITMAP hBMP;//����BMPͷ
	BITMAP	BMP;//BMP�ṹ��
	byte	Texture[]={IDB_BITMAP1,IDB_BITMAP2,IDB_BITMAP3,IDB_BITMAP4,IDB_BITMAP5,IDB_BITMAP6};
	glGenTextures(sizeof(Texture), &texture[0]);// Generate 6 Textures (sizeof(Texture)=6 ID's)
	for(int loop=0;loop<sizeof(Texture); loop++)// Loop Through All The ID's (Bitmap Images)
	{
		hBMP=(HBITMAP)LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(Texture[loop]),IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
		if (hBMP)												// Does The Bitmap Exist?
		{														// If So...
			GetObject(hBMP,sizeof(BMP), &BMP);					// Get The Object
			// hBMP: Handle To Graphics Object
			// sizeof(BMP): Size Of Buffer For Object Information
			// Buffer For Object Information
			glPixelStorei(GL_UNPACK_ALIGNMENT,4);				// Pixel Storage Mode (Word Alignment / 4 Bytes)
			glBindTexture(GL_TEXTURE_2D, texture[loop]);		// Bind Our Texture
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	// Linear Filtering
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR); // Mipmap Linear Filtering
			// Generate Mipmapped Texture (3 Bytes, Width, Height And Data From The BMP)
			gluBuild2DMipmaps(GL_TEXTURE_2D,3,BMP.bmWidth,BMP.bmHeight,GL_BGR_EXT,GL_UNSIGNED_BYTE,BMP.bmBits);
			DeleteObject(hBMP);	// Delete The Bitmap Object
		}
	}
}
void CTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
	case VK_UP:
		wAngleX-=1.0f;
		break;
	case VK_LEFT:		
		wAngleY-=1.0f;
		break;
	case VK_RIGHT:
		wAngleZ-=1.0f;
		break;
	case VK_DOWN:
		wAngleX=1.0f;
		wAngleY=1.0f;
		wAngleZ=1.0f;
		break;
	case VK_ESCAPE:
		AfxGetMainWnd()->SendMessage(WM_CLOSE); 
        break;
	default:
		break;
	}	
	OnDrawScene();
}

void CTestView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	wAngleX=GLfloat(point.x);
	wAngleY=GLfloat(point.y);
	UpdateWindow();
	OnDrawScene();
	CView::OnMouseMove(nFlags, point);
}

void CTestView::OnUpdateMenuDraw(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(Play)
		pCmdUI ->SetCheck(TRUE);
	else
		pCmdUI ->SetCheck(FALSE);
}

void CTestView::OnTimer(UINT nIDEvent)//��ʱ��Ĳ��� 
{
	// TODO: Add your message handler code here and/or call default
	OnDrawScene();
	CView::OnTimer(nIDEvent);
}

void CTestView::OnMenuPlay() 
{
	// TODO: Add your command handler code here
	Play=Play?FALSE:TRUE;
	if (Play)
		//���ö�����ʱ�䲽
		SetTimer(1,15,NULL);
	else
		KillTimer(1);
}
