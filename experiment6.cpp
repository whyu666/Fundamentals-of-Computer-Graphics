//6-1

class CFace {
public:
	CFace();
	virtual ~CFace();
	int En;  //面的边数
	int p[4];  //面的顶点号
};

class CP2 {  //二维点类
public:
	CP2();
	virtual ~CP2();
	double x;
	double y;
};

class CP3 : public CP2 {  //三维点类
public:
	CP3();
	virtual ~CP3();
	double z;
};

void CTestView::OnDraw(CDC* pDC) {  //绘制坐标系
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	GetClientRect(&Rect);  //获得客户区大小
	CPen MyPen, *OldPen;
	MyPen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	OldPen = pDC->SelectObject(&MyPen);
	pDC->MoveTo(Rect.Width() / 2, Rect.Height() / 2);  //绘制y轴
	pDC->LineTo(Rect.Width(), Rect.Height() / 2);
	pDC->TextOut(Rect.Width() - 20, Rect.Height() / 2 - 30, "x");
	pDC->MoveTo(Rect.Width() / 2, Rect.Height() / 2);  //绘制z轴
	pDC->LineTo(Rect.Width() / 2, 0);
	pDC->TextOut(Rect.Width() / 2 - 20, 10, "y");
	pDC->MoveTo(Rect.Width() / 2, Rect.Height() / 2);  //绘制x轴
	pDC->LineTo(Rect.Width() / 2 - Rect.Height() / 2, Rect.Height());  //夹角为135°
	pDC->TextOut(Rect.Width() / 2 - Rect.Height() / 2 - 20, Rect.Height() - 30, "z");
	pDC->TextOut(Rect.Width() / 2 - 20, Rect.Height() / 2 - 20, "o");
	pDC->SelectObject(OldPen);
	MyPen.DeleteObject();

    RedrawWindow();
	AfxGetMainWnd()->SetWindowText("斜等侧图");
	alpha = 45; beta = 45;
	DrawCube();

    // RedrawWindow();
	// AfxGetMainWnd()->SetWindowText("斜二侧图");
	// alpha = 63.4; beta = 45;
	// DrawCube();
}

void CTestView::ReadPoint() {  //顶点表
	int a = 200;  //立方体边长
	//后面的三维坐标
	P3[0].x = 0; P3[0].y = 0; P3[0].z = 0;  //A点
	P3[1].x = 0; P3[1].y = a; P3[1].z = 0;  //B点
	P3[2].x = 0; P3[2].y = a; P3[2].z = a;  //C点
	P3[3].x = 0; P3[3].y = 0; P3[3].z = a;  //D点
	//前面的三维坐标
	P3[4].x = a; P3[4].y = 0; P3[4].z = 0;  //E点
	P3[5].x = a; P3[5].y = a; P3[5].z = 0;  //F点
	P3[6].x = a; P3[6].y = a; P3[6].z = a;  //G点
	P3[7].x = a; P3[7].y = 0; P3[7].z = a;  //H点
}

void CTestView::ReadFace() {  //面表
	//面的边数、面的顶点编号
	F[0].En = 4; F[0].p[0] = 0; F[0].p[1] = 3; F[0].p[2] = 2; F[0].p[3] = 1;  //后面ADCB
	F[1].En = 4; F[1].p[0] = 4; F[1].p[1] = 5; F[1].p[2] = 6; F[1].p[3] = 7;  //前面EFGH
	F[2].En = 4; F[2].p[0] = 0; F[2].p[1] = 4; F[2].p[2] = 7; F[2].p[3] = 3;  //左面AEHD
	F[3].En = 4; F[3].p[0] = 1; F[3].p[1] = 2; F[3].p[2] = 6; F[3].p[3] = 5;  //右面BCGF
	F[4].En = 4; F[4].p[0] = 3; F[4].p[1] = 7; F[4].p[2] = 6; F[4].p[3] = 2;  //顶面DHGC
	F[5].En = 4; F[5].p[0] = 0; F[5].p[1] = 1; F[5].p[2] = 5; F[5].p[3] = 4;  //底面ABFE
}

void CTestView::DrawCube() {  //绘制立方体
	GetClientRect(&Rect);  //获得客户区大小
	CDC *pDC=GetDC();  //客户区DC
	pDC->SetMapMode(MM_ANISOTROPIC);  //自定义坐标系
	pDC->SetWindowExt(Rect.Width(), Rect.Height());
	pDC->SetViewportExt(Rect.Width(), -Rect.Height());  //x轴向右，y轴向上 
	pDC->SetViewportOrg(Rect.Width() / 2, Rect.Height() / 2);  //屏幕中心为原点	
	CP2 Point[4];  //定义多边形面顶点数组
	ReadPoint();
	ReadFace();
	for(int nFace = 0; nFace < 6; nFace++) {  //面循环	
		for(int nEdge = 0; nEdge < F[nFace].En; nEdge++) {  //边循环
			Point[nEdge] = Project(P3[F[nFace].p[nEdge]]);  //斜平行投影	
        }	
		Line(pDC, nFace, Point);
	}
	ReleaseDC(pDC);
}

void CTestView::Line(CDC *pDC, int nface, CP2 p[]) {  //绘制正方形
	for(int i = 0; i < F[nface].En; i++) {
		if(i == 0) {
            pDC->MoveTo(ROUND(p[0].x), ROUND(p[0].y));
        }
		else {
            pDC->LineTo(ROUND(p[i].x), ROUND(p[i].y));
        }
	}
	pDC->LineTo(ROUND(p[0].x), ROUND(p[0].y));
}


CP2 CTestView::Project(CP3 P0) {  //斜平行投影
	CP2 Pt;
	Pt.x = P0.y - P0.x * cos(beta * PI / 180) / tan(alpha * PI / 180);
	Pt.y = P0.z - P0.x * sin(beta * PI / 180) / tan(alpha * PI / 180);
	return Pt;
}


//6-2

void CTestView::OnDraw(CDC* pDC) {  //绘制坐标轴
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	GetMaxX();
    GetMaxY();
	CPen NewPen3d ,NewPen2d, NewPen, *OldPen;
	NewPen3d.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	OldPen = pDC->SelectObject(&NewPen3d);
	pDC->MoveTo(MaxX / 4, MaxY / 2);  //绘制x轴
	pDC->LineTo(MaxX / 2 - 25 , MaxY / 2);
	pDC->TextOut(MaxX / 2 - 50, MaxY / 2 - 20, "x");
	pDC->MoveTo(MaxX / 4, MaxY / 2);  //绘制y轴
	pDC->LineTo(MaxX / 4, 0);
	pDC->TextOut(MaxX / 4 - 20, 10, "y");
	pDC->MoveTo(MaxX / 4, MaxY / 2);  //绘制z轴
	pDC->LineTo(MaxX / 4 - MaxY / 2, MaxY);  //夹角为135°
	pDC->TextOut(MaxX / 4 - MaxY / 2 + 70, MaxY - 30,"z");
	pDC->TextOut(MaxX / 4 - 20, MaxY / 2 - 10, "o");
	pDC->TextOut(20, 20, "立体图");
	pDC->SelectObject(OldPen);
	NewPen3d.DeleteObject();
	NewPen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	OldPen = pDC->SelectObject(&NewPen);
	pDC->MoveTo(MaxX / 2 - 25, 0);  //绘制分割线
	pDC->LineTo(MaxX / 2 - 25, MaxY);
	pDC->SelectObject(OldPen);
	NewPen.DeleteObject();
	NewPen2d.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	OldPen = pDC->SelectObject(&NewPen2d);
	pDC->MoveTo(MaxX / 2 - 25, MaxY / 2);  //绘制z轴
	pDC->LineTo(3 * MaxX / 4, MaxY / 2);
	pDC->TextOut(MaxX / 2 - 15, MaxY / 2 - 20, "z");
	pDC->MoveTo(3 * MaxX / 4, MaxY / 2);  //绘制y轴
	pDC->LineTo(3 * MaxX / 4, 0);
	pDC->TextOut(3 * MaxX / 4 - 20, 10, "y");
	pDC->MoveTo(3 * MaxX / 4, MaxY / 2);  //绘制右x轴
	pDC->LineTo(MaxX, MaxY / 2);
	pDC->TextOut(MaxX - 20, MaxY / 2 - 20, "x");
	pDC->MoveTo(3 * MaxX / 4, MaxY / 2);  //绘制下x轴
	pDC->LineTo(3 * MaxX / 4, MaxY);
	pDC->TextOut(3 * MaxX / 4 - 20, MaxY - 20, "x");
	pDC->TextOut(MaxX / 2 + 10, 20, "三视图");
	pDC->SelectObject(OldPen);
	NewPen2d.DeleteObject();

    DrawPolygon();
    DrawVView();  //主视图
	DrawHView();  //俯视图
	DrawWView();  //侧视图
}

void CTestView::GetMaxX() {  //获得屏幕宽度
	CRect Rect;
	GetClientRect(&Rect);
	MaxX = Rect.right;
}

void CTestView::GetMaxY() {  //获得屏幕高度
	CRect Rect;
	GetClientRect(&Rect);
	MaxY = Rect.bottom;
}

void CTestView::ReadPoint() {  //点表
	P3[0][0] = 0;   P3[0][1] = 0;   P3[0][2] = 0;   P3[0][3] = 1;  //A点
	P3[1][0] = 0;   P3[1][1] = 200; P3[1][2] = 0;   P3[1][3] = 1;  //B点
	P3[2][0] = 0;   P3[2][1] = 200; P3[2][2] = 100; P3[2][3] = 1;  //C点
	P3[3][0] = 0;   P3[3][1] = 0;   P3[3][2] = 100; P3[3][3] = 1;  //D点
	P3[4][0] = 100; P3[4][1] = 0;   P3[4][2] = 0;   P3[4][3] = 1;  //E点
	P3[5][0] = 100; P3[5][1] = 200; P3[5][2] = 0;   P3[5][3] = 1;  //F点
	P3[6][0] = 100; P3[6][1] = 200; P3[6][2] = 100; P3[6][3] = 1;  //G点
	P3[7][0] = 100; P3[7][1] = 0;   P3[7][2] = 100; P3[7][3] = 1;  //H点
	P3[8][0] = 50;  P3[8][1] = 0;   P3[8][2] = 150; P3[8][3] = 1;  //I点
	P3[9][0] = 50;  P3[9][1] = 200; P3[9][2] = 150; P3[9][3] = 1;  //J点
}

void CTestView::ReadFace() {  //面表
    //面的边数、面的顶点编号
	F[0].En = 4; F[0].p[0] = 0; F[0].p[1] = 3; F[0].p[2] = 2; F[0].p[3] = 1;  //后面ADEB
	F[1].En = 4; F[1].p[0] = 4; F[1].p[1] = 5; F[1].p[2] = 6; F[1].p[3] = 7;  //前面EFGH
	F[2].En = 5; F[2].p[0] = 4; F[2].p[1] = 7; F[2].p[2] = 8; F[2].p[3] = 3; F[2].p[4] = 0;  //左面EHIDA
	F[3].En = 5; F[3].p[0] = 1; F[3].p[1] = 2; F[3].p[2] = 9; F[3].p[3] = 6; F[3].p[4] = 5;  //右面BCJGF
	F[4].En = 4; F[4].p[0] = 3; F[4].p[1] = 8; F[4].p[2] = 9; F[4].p[3] = 2;  //后顶面DIJC
	F[5].En = 4; F[5].p[0] = 7; F[5].p[1] = 6; F[5].p[2] = 9; F[5].p[3] = 8;  //前顶面HGJI
	F[6].En = 4; F[6].p[0] = 0; F[6].p[1] = 1; F[6].p[2] = 5; F[6].p[3] = 4;  //底面HBFE
}

void CTestView::DrawPolygon() {  //绘制多面体斜等测投影图函数
	ReadPoint();
	ReadFace();
	Project(P3, P2, 10);  //斜等侧投影变换
	CRect Rect;
	GetClientRect(&Rect);  //获得客户区大小
	CDC *pDC = GetDC();  //客户区DC
	pDC->SetMapMode(MM_ANISOTROPIC);  //自定义坐标系
	pDC->SetWindowExt(Rect.Width(), Rect.Height());
	pDC->SetViewportExt(Rect.Width(), -Rect.Height());  //x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(Rect.Width() / 2, Rect.Height() / 2);  //屏幕中心为原点
	CPoint p[5];  //定义多边形顶点数组
	int TotalEdge, PointNumber;
	for(int nFace = 0; nFace < 7; nFace++) {
		TotalEdge = F[nFace].En;  //每个面的总边数
		for(int nEdge = 0; nEdge < F[nFace].En; nEdge++) {  //边循环
			PointNumber = F[nFace].p[nEdge];  //面的顶点号
			p[nEdge] = CPoint(-MaxX / 4 + ROUND(P2[PointNumber][0]), ROUND(P2[PointNumber][1]));
		}
		Line(pDC, p, TotalEdge);  //绘制斜投影图
	}	
}

void CTestView::Line(CDC *pDC, CPoint p[], int num) {  //绘制多边形函数
	for(int i = 0; i < num; i++) {
        if(i == 0) {
            pDC->MoveTo(p[i]);
        }
		else {
            pDC->LineTo(p[i]);
        }
    }
    pDC->LineTo(p[0]);
}

void CTestView::Project(const double P3[][4],double P2[][3],const int n) {  //三维坐标变换为二维坐标函数
	for(int i = 0; i < n; i++) {
		P2[i][0] = P3[i][1] - P3[i][0] / sqrt(2);
		P2[i][1] = P3[i][2] - P3[i][0] / sqrt(2);
	}
}

void CTestView::DrawVView() {  //主视图变换矩阵
	ClearMatrix(TV);
	TV[0][0] = 1;
	TV[2][2] = 1;
	TV[3][3] = 1;
	MultiMatrix(P3, TV);
	DrawTriView();
}

void CTestView::DrawHView() {  //俯视图变换矩阵
	ClearMatrix(TH);
	TH[0][0] = 1;
	TH[1][2] = -1;
	TH[3][2] = -30;
	TH[3][3] = 1;
	MultiMatrix(P3, TH);
	DrawTriView();
}

void CTestView::DrawWView() {  //侧视图变换矩阵
	ClearMatrix(TW);
	TW[1][0] = 1;
	TW[2][2] = 1;
	TW[3][0] = -30;
	TW[3][3] = 1;
	MultiMatrix(P3, TW);
	DrawTriView();
}

void CTestView::ClearMatrix(int A[][4]) {  //清除变换矩阵
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
            A[i][j] = 0;
        }		
	}
}

void CTestView::MultiMatrix(double P[][4], int T[][4]) {  //两个矩阵相乘
	for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 4; j++) {
			Tri[i][j] = P3[i][0] * T[0][j] + P3[i][1] * T[1][j] + P3[i][2] * T[2][j] + P3[i][3] * T[3][j];
		}
    }
		
}

void CTestView::DrawTriView() {  //绘制三视图
	CRect Rect;
	GetClientRect(&Rect);   //获得客户区大小
	CDC *pDC = GetDC();  //客户区DC
	pDC->SetMapMode(MM_ANISOTROPIC);  //自定义坐标系
	pDC->SetWindowExt(Rect.Width(), Rect.Height());
	pDC->SetViewportExt(Rect.Width(), -Rect.Height());  //x轴向右，y轴向上 
	pDC->SetViewportOrg(Rect.Width() / 2, Rect.Height() / 2);  //屏幕中心为原点
	CPoint p[5];
	int TotalEdge, PointNumber;
	for(int nFace = 0; nFace < 7; nFace++) {
		TotalEdge = F[nFace].En;  //每个面的总边数
		for(int nEdge = 0; nEdge < F[nFace].En; nEdge++) {  //边循环
			PointNumber = F[nFace].p[nEdge];  //面的顶点号
			p[nEdge] = CPoint(MaxX / 4 - ROUND(Tri[PointNumber][0]), ROUND(Tri[PointNumber][2]));
		}
		Line(pDC, p, TotalEdge);
	}
}