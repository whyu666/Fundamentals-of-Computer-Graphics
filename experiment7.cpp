//7-1

void CTestView::ReadPoint() {  //点表
	int a = 100;  //边长
	P[0].x = -a;
	P[0].y = -a;
	P[0].z = -a;
	P[1].x = a;
	P[1].y = -a;
	P[1].z = -a;
	P[2].x = a;
	P[2].y = a;
	P[2].z = -a;
	P[3].x = -a;
	P[3].y = a;
	P[3].z = -a;
	P[4].x = -a;
	P[4].y = -a;
	P[4].z = a;
	P[5].x = a;
	P[5].y = -a;
	P[5].z = a;
	P[6].x = a;
	P[6].y = a;
	P[6].z = a;
	P[7].x = -a;
	P[7].y = a;
	P[7].z = a;
}

void CTestView::ReadFace() {  //面表
	//面的边数、面的顶点编号
	F[0].En = 4;
	F[1].En = 4;
	F[2].En = 4;
	F[3].En = 4;
	F[4].En = 4;
	F[5].En = 4;
	//前面
	F[0].p[0] = 4;
	F[0].p[1] = 5;
	F[0].p[2] = 6;
	F[0].p[3] = 7;
	//后面
	F[1].p[0] = 0;
	F[1].p[1] = 3;
	F[1].p[2] = 2;
	F[1].p[3] = 1;
	//左面
	F[2].p[0] = 0;
	F[2].p[1] = 4;
	F[2].p[2] = 7;
	F[2].p[3] = 3;
	//右面
	F[3].p[0] = 1;
	F[3].p[1] = 2;
	F[3].p[2] = 6;
	F[3].p[3] = 5;
	//顶面
	F[4].p[0] = 2;
	F[4].p[1] = 3;
	F[4].p[2] = 7;
	F[4].p[3] = 6;
	//底面
	F[5].p[0] = 0;
	F[5].p[1] = 1;
	F[5].p[2] = 5;
	F[5].p[3] = 4;
}

void CTestView::InitParameter() {  //透视变换参数初始化
	k[1] = sin(PI * Theta / 180);
	k[2] = sin(PI * Phi / 180);
	k[3] = cos(PI * Theta / 180);
	k[4] = cos(PI*Phi/180);
	k[5] = k[3] * k[2];
	k[6] = k[1] * k[2];
	k[7] = k[3] * k[4];
	k[8] = k[1] * k[4];
	ViewPoint.x = R * k[5];  //用户坐标系的视点球坐标
	ViewPoint.y = R * k[6];
	ViewPoint.z = R * k[4];
}

void CTestView::PerProject(CP3 P) {  //透视变换
	CP3 ViewP;
	ViewP.x = -k[1] * P.x + k[3] * P.y;  //观察坐标系三维坐标
	ViewP.y = -k[7] * P.x - k[8] * P.y + k[2] * P.z;
	ViewP.z = -k[5] * P.x - k[6] * P.y - k[4] * P.z + R;
	ViewP.c = P.c;
	ScreenP.x = ROUND(d * ViewP.x / ViewP.z);  //屏幕坐标系二维坐标
	ScreenP.y = ROUND(d * ViewP.y / ViewP.z);
	ScreenP.c = ViewP.c;
}

void CTestView::DoubleBuffer() {  //双缓冲
	CRect Rect;
	GetClientRect(&Rect);
	CDC *pDC = GetDC();
	pDC->SetMapMode(MM_ANISOTROPIC);  //自定义坐标系
	pDC->SetWindowExt(Rect.Width(), Rect.Height());
	pDC->SetViewportExt(Rect.Width(), -Rect.Height());  //x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(Rect.Width() / 2, Rect.Height() / 2);  //屏幕中心为原点	
	CDC	MemDC, Picture;
	MemDC.CreateCompatibleDC(pDC);
	MemDC.SetMapMode(MM_ANISOTROPIC);
	MemDC.SetWindowExt(Rect.Width(), Rect.Height());
	MemDC.SetViewportExt(Rect.Width(), -Rect.Height());
	MemDC.SetViewportOrg(Rect.Width() / 2, Rect.Height() / 2);
	CBitmap NewBitmap, *OldBitmap;
	NewBitmap.LoadBitmap(IDB_BITMAP2);
	OldBitmap = MemDC.SelectObject(&NewBitmap);
	MemDC.BitBlt(-Rect.Width() / 2, -Rect.Height() / 2, Rect.Width(), Rect.Height(), &Picture, -Rect.Width() / 2, -Rect.Height() / 2, SRCCOPY);
	DrawObject(&MemDC);	
	pDC->BitBlt(-Rect.Width() / 2, -Rect.Height() / 2, Rect.Width(), Rect.Height(), &MemDC, -Rect.Width() / 2, -Rect.Height() / 2, SRCCOPY);
	ReleaseDC(pDC);
	MemDC.SelectObject(OldBitmap);
	NewBitmap.DeleteObject();
}

void CTestView::DrawObject(CDC* pDC) {  //绘制物体
	for(int nFace = 0; nFace < 6; nFace++) {
		CVector VS(P[F[nFace].p[1]], ViewPoint);  //面的视矢量
		CVector V01(P[F[nFace].p[0]], P[F[nFace].p[1]]);  //面的一个边矢量
		CVector V12(P[F[nFace].p[1]], P[F[nFace].p[2]]);  //面的另一个边矢量	
		CVector VN = V01 * V12;  //面的法矢量
		if(Dot(VS,VN) >= 0) {  //凸多面体消隐
			DrawFace(pDC, nFace);  //数量积大于零，表面画出
		}
	}
}

void CTestView::DrawFace(CDC* pDC, int nface) {  //绘制表面
	CP2 t;
	CLine line;
	for(int nEdge = 0; nEdge < F[nface].En; nEdge++) {  //边循环
		PerProject(P[F[nface].p[nEdge]]);  //透视投影
		if(nEdge == 0) {
			line.MoveTo(pDC,ScreenP);
			t = ScreenP;
		}
		else {
			line.LineTo(pDC, ScreenP);
		}		
	}
	line.LineTo(pDC, t.x, t.y);  //闭合多边形
}

void CTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	// TODO: Add your message handler code here and/or call default
	switch(nChar) {
	case VK_UP:
		Phi -= 10;  //设定步长
		break;
	case VK_DOWN:
		Phi += 10;
		break;
	case VK_LEFT:
		Theta -= 10;
		break;
	case VK_RIGHT:
		Theta += 10;
		break;
	default:
		break;
	}
	InitParameter();
	DoubleBuffer();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

class CP2 {  //二维点类
public:
	CP2();
	virtual ~CP2();
	CP2(int, int);
public:
	int x;
	int y;
};

CP2::CP2() {
	this->x = 0;
	this->y = 0;
}

CP2::~CP2() {

}

CP2::CP2(int x0, int y0) {
	this->x = x0;
	this->y = y0;
}

class CP3 {  //三维点类
public:
	CP3();
	virtual ~CP3();
	CP3(double, double, double);
public:
	double x;
	double y;
	double z;
};

CP3::CP3() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

CP3::~CP3() {

}

CP3::CP3(double x0, double y0, double z0) {
	this->x = x0;
	this->y = y0;
	this->z = z0;
}

class CVector {  //矢量类
public:
	CVector();	
	virtual ~CVector();
	CVector(CP3);
	CVector(CP3, CP3);	
	double X();  //矢量的x坐标
	double Y();  //矢量的y坐标
	double Z();  //矢量的z坐标
	double Mold();  //矢量的模
	CVector Unit();  //单位矢量
	friend CVector operator +(CVector &, CVector &);  //矢量和
	friend CVector operator -(CVector &, CVector &);  //矢量差
	friend CVector operator *(CVector &, double);  //矢量数乘
	friend CVector operator /(CVector &, double);  //矢量数除
	friend double Dot(CVector &, CVector &);  //矢量点积
	friend CVector operator *(CVector &, CVector &);  //矢量叉积
public:
	double x, y, z;
};

CVector::CVector() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

CVector::~CVector() {

}

CVector::CVector(CP3 p) {
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;	
}

CVector::CVector(CP3 p1, CP3 p2) {
	this->x = p2.x - p1.x;
	this->y = p2.y - p1.y;
	this->z = p2.z - p1.z;
}

double CVector::X() {
	return this->x;
}

double CVector::Y() {
	return this->y;
}

double CVector::Z() {
	return this->z;
}

CVector CVector::Unit() {  //单位矢量
	CVector vector;
	double product = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	if(product < 1e-5) {
		product = 1.0;
	}
	vector.x = this->x / product;
	vector.y = this->y / product;
	vector.z = this->z / product;
	return vector;
}

double CVector::Mold() { //矢量的模
	double product = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	return product;
}

double Dot(CVector &v1, CVector &v2) {  //矢量的点积
	return(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

CVector operator +(CVector &v1, CVector &v2) {  //矢量的和
	CVector vector;
	vector.x = v1.x + v2.x;
	vector.y = v1.y + v2.y;
	vector.z = v1.z + v2.z;
	return vector;
}

CVector operator -(CVector &v1, CVector &v2) {  //矢量的差
	CVector vector;
	vector.x = v1.x - v2.x;
	vector.y = v1.y - v2.y;
	vector.z = v1.z - v2.z;
	return vector;
}

CVector operator *(CVector &v, double k) {  //矢量和常量的积	
	CVector vector;
	vector.x = v.x * k;
	vector.y = v.y * k;
	vector.z = v.z * k;
	return vector;
}

CVector operator /(CVector &v, double k) {  //矢量数除
	CVector vector;
	vector.x = v.x / k;
	vector.y = v.y / k;
	vector.z = v.z / k;
	return vector;
}

CVector operator *(CVector &v1, CVector &v2) {  //矢量的叉积
	CVector vector;
	vector.x = v1.y * v2.z - v1.z * v2.y;
	vector.y = v1.z * v2.x - v1.x * v2.z;
	vector.z = v1.x * v2.y - v1.y * v2.x;
	return vector;
}

class CLine {  //直线类
public:
	CLine();
	virtual ~CLine();
    void MoveTo(CDC *, CP2);  //移动到指定位置
	void MoveTo(CDC *, int, int);  //重载函数
	void LineTo(CDC *, CP2);  //通用直线的整数Bresenham算法,不包含终点坐标
	void LineTo(CDC *, int, int);  //重载函数
	int Sign(int);  //返回-1,0,1当自变量为<0,=0,>0
public:
	CP2 P1;  //直线起点坐标
	CP2 P2;  //直线终点坐标
};

CLine::CLine() { 

}

CLine::~CLine() {
	
}

void CLine::MoveTo(CDC *pDC, CP2 p1) {  //绘制直线起点函数
	P1 = p1;
}

void CLine::MoveTo(CDC *pDC, int x1, int y1) {  //重载函数
	P1.x = x1;
	P1.y = y1;
}

void CLine::LineTo(CDC *pDC, CP2 p2) {  //通用直线的整数Bresenham算法
	P2 = p2;
	CP2 delta, p;
	bool InterChange = false;
	delta.x = abs(P2.x - P1.x);  //Δx
	delta.y = abs(P2.y - P1.y);  //Δy
	int e, s1, s2, temp;  //e为误差项	
	s1 = Sign(P2.x - P1.x);
    s2 = Sign(P2.y - P1.y);
	if(delta.x < delta.y) {
		temp = delta.x;
		delta.x = delta.y;
		delta.y = temp;
        InterChange = true;  //y方向为主位移方向
	}
	e = 2 * delta.y - delta.x;
	p = P1;  //e=k-1/2，k为直线的斜率，做e=2Δx×e变换实现整数算法
	for(int i = 0; i<delta.x; i++) {  //直线不包含终点坐标
		pDC->SetPixel(p.x, p.y, RGB(255, 255, 255));
		if(e > 0) {
			if(InterChange) {
				p.x += s1;
			}		
			else {
				p.y += s2;
			}
             e -= 2 * delta.x;  //e=e-1
		}
		if(InterChange) {
			p.y += s2;
		}
		else {
			p.x += s1;
		}
		e += 2 * delta.y;  //e=e+k		
	}
	P1 = p2;
}

void CLine::LineTo(CDC *pDC, int x2, int y2) {  //重载函数
	LineTo(pDC, CP2(x2, y2));
}

int CLine::Sign(int m) {  //返回-1,0,1当自变量为<0,=0,>0
   if(m < 0) {
		return -1;
   }
   else if(m == 0) {
		return 0;
   }
   else {
		return 1;
   }
}

class CFace {  //面类
public:
	CFace();
	virtual ~CFace();
public:
	int En;  //面的边数
	int p[10];  //面的顶点号
};


//7-2

void CTestView::ReadPoint() {  //点表
	int i;	
	//红色长方条顶点的三维坐标(x,y,z)
	P[0][0].x = -150;
	P[0][0].y = -200;
	P[0][0].z = 0;
	P[0][1].x = -150;
	P[0][1].y = -200;
	P[0][1].z = 0;
	P[0][2].x = -125;
	P[0][2].y = -200
	;P[0][2].z = 0;
	P[0][3].x = -125;
	P[0][3].y = -200;
	P[0][3].z = 0;
	P[0][4].x = 25;
	P[0][4].y = 200;
	P[0][4].z = -100;
	P[0][5].x = 25;
	P[0][5].y = 200;
	P[0][5].z = -100;
	P[0][6].x = 50;
	P[0][6].y = 200;
	P[0][6].z = -100;
	P[0][7].x = 50;
	P[0][7].y = 200;
	P[0][7].z = -100;
	for(i = 0; i < 8; i++) {  //顶点颜色赋值
		P[0][i].c = CRGB(1.0, 0.0, 0.0);
	}	
	//蓝色长方条顶点的三维坐标(x,y,z)
	P[1][0].x = 150;
	P[1][0].y = -200;
	P[1][0].z = 50;
	P[1][1].x = 150;
	P[1][1].y = -200;
	P[1][1].z = 50;
	P[1][2].x = 125;
	P[1][2].y = -200;
	P[1][2].z = 50;
	P[1][3].x = 125;
	P[1][3].y = -200;
	P[1][3].z = 50;
	P[1][4].x = -25;
	P[1][4].y = 200;
	P[1][4].z = 100;
	P[1][5].x = -25;
	P[1][5].y = 200;
	P[1][5].z = 100;
	P[1][6].x = -50;
	P[1][6].y = 200;
	P[1][6].z = 100;
	P[1][7].x = -50;
	P[1][7].y = 200;
	P[1][7].z = 100;
	for(i = 0; i < 8; i++) {
		P[1][i].c = CRGB(0.0, 0.0, 1.0);
	}
	//绿色长方条顶点的三维坐标(x,y,z)
	P[2][0].x = -200;
	P[2][0].y = -150;
	P[2][0].z = -100;
	P[2][1].x = -200;
	P[2][1].y = -150;
	P[2][1].z = -100;
	P[2][2].x = -200;
	P[2][2].y = -125;
	P[2][2].z = -100;
	P[2][3].x = -200;
	P[2][3].y = -125;
	P[2][3].z = -100;
	P[2][4].x = 200;
	P[2][4].y = -150;
	P[2][4].z = 120;
	P[2][5].x = 200;
	P[2][5].y = -150;
	P[2][5].z = 120;
	P[2][6].x = 200;
	P[2][6].y = -125;
	P[2][6].z = 120;
	P[2][7].x = 200;
	P[2][7].y = -125;
	P[2][7].z = 120;
	for(i = 0; i < 8; i++) {
		P[2][i].c = CRGB(0.0, 1.0, 0.0);
	}
}

void CTestView::ReadFace() {  //面表
	//面的边数、面的顶点编号和面的颜色
	F[0].En = 4;
	F[0].p[0] = 0;  //每个条的后面
	F[0].p[1] = 3;
	F[0].p[2] = 2;
	F[0].p[3] = 1;
	F[1].En = 4;
	F[1].p[0] = 4;  //每个条的前面
	F[1].p[1] = 5;
	F[1].p[2] = 6;
	F[1].p[3] = 7;
	F[2].En = 4;
	F[2].p[0] = 0;  //每个条的左面
	F[2].p[1] = 4;
	F[2].p[2] = 7;
	F[2].p[3] = 3;
	F[3].En = 4;
	F[3].p[0] = 1;  //每个条的右面
	F[3].p[1] = 2;
	F[3].p[2] = 6;
	F[3].p[3] = 5;
	F[4].En = 4;
	F[4].p[0] = 3;  //每个条的顶面
	F[4].p[1] = 7;
	F[4].p[2] = 6;
	F[4].p[3] = 2;
	F[5].En = 4;
	F[5].p[0] = 0;  //每个条的底面
	F[5].p[1] = 1;
	F[5].p[2] = 5;
	F[5].p[3] = 4;
}

void CTestView::DoubleBuffer() {  //双缓冲
	CRect Rect;
	GetClientRect(&Rect);
	CDC *pDC = GetDC();
	pDC->SetMapMode(MM_ANISOTROPIC);  //自定义坐标系
	pDC->SetWindowExt(Rect.Width(), Rect.Height());
	pDC->SetViewportExt(Rect.Width(), -Rect.Height());  //x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(Rect.Width() / 2, Rect.Height() / 2);  //屏幕中心为原点	
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
	pDC->BitBlt(-Rect.Width() / 2, -Rect.Height() / 2, Rect.Width(), Rect.Height(), &MemDC, -Rect.Width() / 2, -Rect.Height() / 2, SRCCOPY);
	ReleaseDC(pDC);
	MemDC.SelectObject(OldBitmap);	
	NewBitmap.DeleteObject();	
}

void CTestView::DrawObject(CDC *pDC) {  //绘制交叉面
	CPi3 Point[4];	
	zbuf.InitDeepBuffer(800, 800, -1000);  //深度初始化
	for(int nBar = 0; nBar < 3; nBar++) {
		for(int nFace = 0; nFace < 6; nFace++) {
			for(int nEdge=0;nEdge<F[nFace].En;nEdge++) {  //边循环
				Point[nEdge].x = P[nBar][F[nFace].p[nEdge]].x;
				Point[nEdge].y = ROUND(P[nBar][F[nFace].p[nEdge]].y);
				Point[nEdge].z = P[nBar][F[nFace].p[nEdge]].z;
				Point[nEdge].c = P[nBar][F[nFace].p[nEdge]].c;
			}
			zbuf.SetPoint(Point,4);			
			zbuf.CreateBucket();  //建立桶表
			zbuf.CreateEdge();  //建立边表
			zbuf.Gouraud(pDC);  //颜色渐变填充四边形
		}
	}
}

class CAET {  //有效边表类
public:
	CAET();
	virtual ~CAET();
public:
	double x;  //当前x
	int    yMax;  //边的最大y值
	double k;  //斜率的倒数(x的增量)
	CPi3    pb;  //起点
	CPi3    pe;  //终点
	CAET   *next;
};

class CBucket {  //桶类
public:
	CBucket();
	virtual ~CBucket();
public:
	int     ScanLine;
	CAET    *pET;
	CBucket *next;
};

class CFace {  //面类
public:
	CFace();
	virtual ~CFace();
public:
	int En;  //面的边数
	int p[4];  //面的顶点号
};

class CP2 {  //二维顶点类
public:
	CP2();
	virtual ~CP2();
	CP2(double, double);
	double x;
	double y;
	CRGB   c;
};

CP2::CP2() {
	this->x = 0.0;
	this->y = 0.0;
	this->c = CRGB(1.0, 1.0, 1.0);
}

CP2::~CP2() {

}

CP2::CP2(double x0, double y0) {
	this->x = x0;
	this->y = y0;
}

class CP3:public CP2 {  //三维顶点类
public:
	CP3();
	virtual ~CP3();
	CP3(double, double, double);
public:
	double z;
};

CP3::CP3() {
	this->z = 0.0;
}

CP3::~CP3() {

}

CP3::CP3(double x0, double y0, double z0):CP2(x0, y0) {
	this->z = z0;
}

class CPi2 {  //二维顶点，y为整数值
public:
	CPi2();
	virtual ~CPi2();
	CPi2(double, int);
	double x;
	int    y;
	CRGB   c;
};

CPi2::CPi2() {
	this->x = 0.0;
	this->y = 0;
	this->c = CRGB(1.0, 1.0, 1.0);
}

CPi2::~CPi2() {

}

CPi2::CPi2(double x0, int y0) {
	this->x = x0;
	this->y = y0;
}

class CPi3:public CPi2 {  //三维顶点，y为整数值
public:
	CPi3();
	virtual ~CPi3();
	CPi3(double, int, double);
	double z;
};

CPi3::CPi3() {
	this->z = 0.0;
}

CPi3::~CPi3() {

}

CPi3::CPi3(double x0, int y0, double z0):CPi2(x0, y0) {
	this->z = z0;
}

class CRGB {  //颜色类
public:
	CRGB();
	CRGB(double, double, double);
	friend CRGB operator+(CRGB &, CRGB &);
	friend CRGB operator*(double, CRGB &);
	virtual ~CRGB();
public:
	double red;  //红色分量
	double green;  //绿色分量
	double blue;  //蓝色分量
};

CRGB::CRGB() {
	this->red = 1.0;
	this->green = 1.0;
	this->blue = 1.0;
}

CRGB::CRGB(double r, double g, double b) {  //重载构造函数
	this->red = r;
	this->green = g;
	this->blue = b;
}

CRGB::~CRGB() {

}

CRGB operator +(CRGB &c1,CRGB &c2) {  //+运算符重载
	CRGB c;
	c.red = c1.red + c2.red;
	c.green = c1.green + c2.green;
	c.blue = c1.blue + c2.blue;
	return c;
}

CRGB operator *(double k,CRGB &c1) {  //*运算符重载
   CRGB c;
   c.red = k * c1.red;
   c.green = k * c1.green;
   c.blue = k * c1.blue;
   return c;
}

class CVector {  //矢量类
public:
	CVector();	
	CVector(CP3 &);
	CVector(CPi3 &);
	CVector(CP3 p1, CP3 p2);
	CVector(CPi3 p1, CPi3 p2);
	virtual ~CVector();
	CVector Unit();  //单位矢量
	double X();  //矢量的x坐标
	double Y();  //矢量的y坐标
	double Z();  //矢量的z坐标
	double Mold();  //矢量的模
	friend CVector operator +(CVector &, CVector &);  //矢量和
	friend CVector operator -(CVector &, CVector &);  //矢量差
	friend CVector operator *(CVector &, double);  //矢量积
	friend double Dot(CVector &, CVector &);  //矢量点积
	friend CVector operator /(CVector &, double);  //矢量数除
	friend CVector operator *(CVector &, CVector &);  //矢量叉积
private:
	double x, y, z;
};

CVector::CVector() {

}

CVector::~CVector() {

}

CVector::CVector(CP3 &p) {
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;	
}

CVector::CVector(CPi3 &p) {
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;	
}

CVector::CVector(CP3 p1, CP3 p2) {
	this->x = p2.x - p1.x;
	this->y = p2.y - p1.y;
	this->z = p2.z - p1.z;
}

CVector::CVector(CPi3 p1, CPi3 p2) {
	this->x = p2.x - p1.x;
	this->y = p2.y - p1.y;
	this->z = p2.z - p1.z;
}

double CVector::X() {
	return this->x;
}

double CVector::Y() {
	return this->y;
}

double CVector::Z() {
	return this->z;
}

CVector CVector::Unit() {  //单位矢量
	CVector vector;
	double product = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	if(product < 1e-5) {
		product = 1.0;
	}
	vector.x = this->x / product;
	vector.y = this->y / product;
	vector.z = this->z / product;
	return vector;
}

double CVector::Mold() {  //矢量的模
	double product = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	return product;
}

double Dot(CVector &v1, CVector &v2) {  //矢量的点积
	return(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

CVector operator +(CVector &v1, CVector &v2) {  //矢量的和	
	CVector vector;
	vector.x = v1.x + v2.x;
	vector.y = v1.y + v2.y;
	vector.z = v1.z + v2.z;
	return vector;
}

CVector operator -(CVector &v1, CVector &v2) {  //矢量的差
	CVector vector;
	vector.x = v1.x - v2.x;
	vector.y = v1.y - v2.y;
	vector.z = v1.z - v2.z;
	return vector;
}

CVector operator *(CVector &v, double k) {  //矢量和常量的积
	CVector vector;
	vector.x = v.x * k;
	vector.y = v.y * k;
	vector.z = v.z * k;
	return vector;
}

CVector operator /(CVector &v, double k) {  //矢量数除
	CVector vector;
	vector.x = v.x / k;
	vector.y = v.y / k;
	vector.z = v.z / k;
	return vector;
}

CVector operator * (CVector &v1,CVector &v2) {  //矢量的叉积
	CVector vector;
	vector.x = v1.y * v2.z - v1.z * v2.y;
	vector.y = v1.z * v2.x - v1.x * v2.z;
	vector.z = v1.x * v2.y - v1.y * v2.x;
	return vector;
}

class CZBuffer {  //深度缓冲类
public:
	CZBuffer();
    virtual ~CZBuffer();
	void CreateBucket();  //创建桶
	void CreateEdge();  //边表
	void AddEt(CAET *);  //合并ET表
	void EtOrder();  //ET表排序
	void Gouraud(CDC *);  //填充
	void InitDeepBuffer(int, int, double);  //初始化深度缓存
    CRGB Interpolation(double, double, double, CRGB, CRGB);  //线性插值
	void SetPoint(CPi3 *, int);
protected:
	int PNum;  //顶点个数
	CPi3 *P;  //顶点数组
	CAET *CurrentE, *HeadE, *Edge;
	CBucket *CurrentB, *HeadB;
	double **ZB;
	int Width, Height;  //深度缓冲大小参数
};

CZBuffer::CZBuffer() {

}

CZBuffer::~CZBuffer() {
	delete []P;
}

void CZBuffer::SetPoint(CPi3 p[], int m) {
	P = new CPi3[m];
    for(int i = 0; i < m; i++) {
		P[i] = p[i];
	}
	PNum = m;
}

void CZBuffer::CreateBucket() {  //创建桶表
	int yMin, yMax;
	yMin = P[0].y;
	yMax = P[0].y;
	for(int i = 0;i < PNum; i++) {  //查找多边形所覆盖的最小和最大扫描线
		if(P[i].y < yMin) {
			yMin = P[i].y;  //扫描线的最小值
		}
		if(P[i].y > yMax) {
			yMax = P[i].y;  //扫描线的最大值
		}
	}
	for(int y = yMin; y <= yMax; y++) {
		if(yMin == y) {  //建立桶头结点
			HeadB = new CBucket;  //建立桶的头结点
			CurrentB = HeadB;  //CurrentB为CBucket当前结点指针
			CurrentB->ScanLine = yMin;
			CurrentB->pET = NULL;  //没有连接边链表
			CurrentB->next = NULL;
		}
		else {  //建立桶的其它结点
			CurrentB->next = new CBucket;
			CurrentB = CurrentB->next;
			CurrentB->ScanLine = y;
			CurrentB->pET = NULL;
			CurrentB->next = NULL;
		}
	}
}

void CZBuffer::CreateEdge() {  //创建边表
	for(int i = 0; i < PNum; i++) {
		CurrentB = HeadB;
		int j = (i + 1) % PNum;  //边的第二个顶点，P[i]和P[j]构成边
		if(P[i].y < P[j].y) {  //边的终点比起点高
			Edge = new CAET;
			Edge->x = P[i].x;  //计算ET表的值
			Edge->yMax = P[j].y;
			Edge->k = (P[j].x - P[i].x) / (P[j].y - P[i].y);  //代表1/k
			Edge->pb = P[i];  //绑定顶点和颜色
			Edge->pe = P[j];
			Edge->next = NULL;
			while(CurrentB->ScanLine != P[i].y) {  //在桶内寻找该边的yMin
				CurrentB = CurrentB->next;  //移到yMin所在的桶结点
			}		
		}
		if(P[j].y < P[i].y) {  //边的终点比起点低
			Edge = new CAET;
			Edge->x = P[j].x;
			Edge->yMax = P[i].y;
			Edge->k = (P[i].x - P[j].x) / (P[i].y - P[j].y);
			Edge->pb = P[i];
			Edge->pe = P[j];
			Edge->next = NULL;
			while(CurrentB->ScanLine != P[j].y) {
				CurrentB = CurrentB->next;
			}
		}
		if(int(P[j].y) != P[i].y) {
			CurrentE = CurrentB->pET;
			if(CurrentE == NULL) {
				CurrentE = Edge;
				CurrentB->pET = CurrentE;
			}
			else {
				while(CurrentE->next != NULL) {
					CurrentE = CurrentE->next;
				}
				CurrentE->next = Edge;
			}
		}
	}
}

void CZBuffer::Gouraud(CDC *pDC) {  //填充多边形
	double	CurDeep = 0.0;  //当前扫描线的深度
	double	DeepStep = 0.0;  //当前扫描线随着x增长的深度步长
	double	A, B, C, D;  //平面方程Ax+By+Cz＋D=0的系数
	CVector V21(P[1], P[2]), V10(P[0], P[1]);
	CVector VN = V21 * V10;
	A = VN.X();
	B = VN.Y();
	C = VN.Z();
	D = -A * P[1].x - B * P[1].y - C * P[1].z;
	DeepStep = -A / C;  //计算直线deep增量步长
	CAET *T1, *T2;
	HeadE = NULL;	
	for(CurrentB = HeadB; CurrentB != NULL; CurrentB = CurrentB->next) {
		for(CurrentE = CurrentB->pET; CurrentE != NULL; CurrentE = CurrentE->next) {
			Edge = new CAET;
			Edge->x = CurrentE->x;
			Edge->yMax = CurrentE->yMax;
			Edge->k = CurrentE->k;
			Edge->pb = CurrentE->pb;
			Edge->pe = CurrentE->pe;
			Edge->next = NULL;
			AddEt(Edge);
		}
		EtOrder();	
		T1 = HeadE;
		if(T1 == NULL) {
			return;
		}
		while(CurrentB->ScanLine >= T1->yMax) {  //下闭上开
			T1 = T1->next;
			HeadE = T1;
			if(HeadE == NULL) {
				return;
			}
		}
		if(T1->next != NULL) {
			T2 = T1;
			T1 = T2->next;
		}
		while(T1 != NULL) {
			if(CurrentB->ScanLine >= T1->yMax) {  //下闭上开
				T2->next = T1->next;
				T1 = T2->next;
			}
			else {
				T2 = T1;
				T1 = T2->next;
			}
		}
		CRGB Ca, Cb, Cf;  //Ca、Cb代边上任意点的颜色，Cf代表面上任意点的颜色
		Ca = Interpolation(CurrentB->ScanLine, HeadE->pb.y, HeadE->pe.y, HeadE->pb.c, HeadE->pe.c);
		Cb = Interpolation(CurrentB->ScanLine, HeadE->next->pb.y, HeadE->next->pe.y, HeadE->next->pb.c, HeadE->next->pe.c);
		BOOL Flag = FALSE;
		double xb, xe;  //扫描线的起点和终点坐标
		for(T1 = HeadE; T1 != NULL; T1 = T1->next) {
			if(Flag == FALSE) {
				xb = T1->x;
				CurDeep = -(xb * A + CurrentB->ScanLine * B + D) / C;  //z=-(Ax+By-D)/C
				Flag = TRUE;
			}
			else {
				xe = T1->x;
				for(double x = xb; x < xe; x++) {  //左闭右开
					Cf = Interpolation(x, xb, xe, Ca, Cb);
					if(CurDeep >= ZB[ROUND(x) + Width / 2][CurrentB->ScanLine + Height / 2]) {  //如果新采样点的深度大于原采样点的深度
						ZB[ROUND(x) + Width / 2][CurrentB->ScanLine + Height / 2] = CurDeep;  //xy坐标与数组下标保持一致
						pDC->SetPixel(ROUND(x), CurrentB->ScanLine, RGB(Cf.red * 255, Cf.green * 255, Cf.blue * 255));
					}
					CurDeep += DeepStep;					
				}
				Flag = FALSE;
			}
		}
		for(T1 = HeadE; T1 != NULL; T1 = T1->next) {  //边的连续性
			T1->x = T1->x + T1->k;
		}		
	}
	delete HeadB;
	delete HeadE;
	delete CurrentE;
	delete CurrentB;
	delete Edge;	
}

void CZBuffer::AddEt(CAET *NewEdge) {  //合并ET表
	CAET *CE;
	CE = HeadE;
	if(CE == NULL) {
		HeadE = NewEdge;
		CE = HeadE;
	}
	else {
		while(CE->next != NULL) {
			CE = CE->next;
		}
		CE->next = NewEdge;
	}
}

void CZBuffer::EtOrder() {  //边表的冒泡排序算法
	CAET *T1, *T2;
	int Count = 1;
	T1 = HeadE;
	if(T1 == NULL) {
		return;
	}
	if(T1->next==NULL) {  //如果该ET表没有再连ET表
		return;  //桶结点只有一条边，不需要排序
	}
	while(T1->next != NULL) {  //统计结点的个数
		Count++;
		T1 = T1->next;
	}
	for(int i=1;i<Count;i++) {  //冒泡排序
		T1 = HeadE;
		if(T1->x > T1->next->x) {  //按x由小到大排序
			T2 = T1->next;
			T1->next = T1->next->next;
			T2->next = T1;
			HeadE = T2;
		}
		else {
			if(T1->x == T1->next->x) {
				if(T1->k>T1->next->k) {  //按斜率由小到大排序
					T2 = T1->next;
					T1->next = T1->next->next;
					T2->next = T1;
					HeadE = T2;
				}
			}
		}
		T1 = HeadE;
		while(T1->next->next != NULL) {
			T2 = T1;
			T1 = T1->next;
			if(T1->x > T1->next->x) {  //按x由小到大排序
				T2->next = T1->next;
				T1->next = T1->next->next;
				T2->next->next = T1;
				T1 = T2->next;
			}
			else {
				if(T1->x == T1->next->x) {
					if(T1->k > T1->next->k) {  //按斜率由小到大排序
						T2->next = T1->next;
						T1->next = T1->next->next;
						T2->next->next = T1;
						T1 = T2->next;
					}
				}
			}
		}
	}
}

CRGB CZBuffer::Interpolation(double t, double t1, double t2, CRGB c1, CRGB c2) {  //线性插值
	CRGB c;
	c = (t - t2) / (t1 - t2) * c1 + (t - t1) / (t2 - t1) * c2;
	return c;
}

void CZBuffer::InitDeepBuffer(int width, int height, double depth) {  //初始化深度缓冲
	Width = width, Height = height;
	ZB = new double *[Width];
	for(int i = 0; i < Width; i++) {
		ZB[i] = new double[Height];
	}
	for(i = 0; i < Width; i++) {  //初始化深度缓冲
		for(int j = 0; j < Height; j++) {
			ZB[i][j] = double(depth);
		}
	}
}
