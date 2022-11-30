//8-1

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

void CTestView::ReadPointFlat() {  //恒定颜色正六边形点表
	int a = 200;  //正六边形外接圆半径
	for(int i = 0; i < 6; i++) {
		Pf[i].x = MaxX / 4 + ROUND(a * cos(i * PI / 3));
		Pf[i].y = MaxY / 2 + ROUND(a * sin(i * PI / 3));
	}
	Pf[6].x = MaxX / 4;
	Pf[6].y = MaxY / 2;  //中心点
	//品红
	Pf[0].c.red = 1.0;
	Pf[0].c.green = 0.0;
	Pf[0].c.blue = 1.0;
	//蓝色
	Pf[1].c.red = 0.0;
	Pf[1].c.green = 0.0;
	Pf[1].c.blue = 1.0;
	//青色
	Pf[2].c.red = 0.0;
	Pf[2].c.green = 1.0;
	Pf[2].c.blue = 1.0;
	//绿色
	Pf[3].c.red = 0.0;
	Pf[3].c.green = 1.0;
	Pf[3].c.blue = 0.0;
	//黄色
	Pf[4].c.red = 1.0;
	Pf[4].c.green = 1.0;
	Pf[4].c.blue = 0.0;
	//红色
	Pf[5].c.red = 1.0;
	Pf[5].c.green = 0.0;
	Pf[5].c.blue = 0.0;
	Flag = true;
}

void CTestView::ReadPointSmooth() {  //渐变颜色正六边形点表
	int a = 200;  //半径
	for(int i = 0; i < 6; i++) {
		Ps[i].x = 3 * MaxX / 4 + ROUND(a * cos(i * PI / 3));
		Ps[i].y = MaxY / 2 + ROUND(a * sin(i * PI / 3));
	}
	Ps[6].x = 3 * MaxX / 4;
	Ps[6].y = MaxY / 2;  //中心点
	//品红
	Ps[0].c.red = 1.0;
	Ps[0].c.green = 0.0;
	Ps[0].c.blue = 1.0;
	//蓝色
	Ps[1].c.red = 0.0;
	Ps[1].c.green = 0.0;
	Ps[1].c.blue = 1.0;
	//青色
	Ps[2].c.red = 0.0;
	Ps[2].c.green = 1.0;
	Ps[2].c.blue = 1.0;
	//绿色
	Ps[3].c.red = 0.0;
	Ps[3].c.green = 1.0;
	Ps[3].c.blue = 0.0;
	//黄色
	Ps[4].c.red = 1.0;
	Ps[4].c.green = 1.0;
	Ps[4].c.blue = 0.0;
	//红色
	Ps[5].c.red = 1.0;
	Ps[5].c.green = 0.0;
	Ps[5].c.blue = 0.0;
	//白色
	Ps[6].c.red = 1.0;
	Ps[6].c.green = 1.0;
	Ps[6].c.blue = 1.0;
	Flag = false;
}

void CTestView::ReadFace() {  //正六边形面表
	//恒定颜色模型以多边形第一个顶点的单一颜色填充
	//右下
	F[0].En = 3;
	F[0].p[0] = 0;
	F[0].p[1] = 1;
	F[0].p[2] = 6;
	//下面
	F[1].En = 3;
	F[1].p[0] = 1;
	F[1].p[1] = 2;
	F[1].p[2] = 6;
	//左下
	F[2].En = 3;
	F[2].p[0] = 2;
	F[2].p[1] = 3;
	F[2].p[2] = 6;
	//左上
	F[3].En = 3;
	F[3].p[0] = 3;
	F[3].p[1] = 4;
	F[3].p[2] = 6;
	//上面
	F[4].En = 3;
	F[4].p[0] = 4;
	F[4].p[1] = 5;
	F[4].p[2] = 6;
	//右上
	F[5].En = 3;
	F[5].p[0] = 5;
	F[5].p[1] = 0;
	F[5].p[2] = 6;
}

void CTestView::DrawHexagon(CP2 *P) {  //绘制正六边形
	CDC *pDC = GetDC();
	CPi2 Point[3];  //面的二维顶点数组
	for(int nFace = 0; nFace < 6; nFace++) {
		int TotalEdge = F[nFace].En;  //计算每个面的总边数
		for(int nEdge = 0; nEdge < TotalEdge; nEdge++) {  //边循环
			int PointNumber = F[nFace].p[nEdge];  //面的顶点号
			Point[nEdge].x = P[PointNumber].x;
			Point[nEdge].y = ROUND(P[PointNumber].y);
			if(Flag) {
				Point[nEdge].c = P[F[nFace].p[0]].c;
			}
			else {
				Point[nEdge].c = P[PointNumber].c;
			}
		}
		fill.SetPoint(Point, 3);  //初始化Fill对象
		fill.CreateBucket();  //建立桶表
		fill.CreateEdge();  //建立边表
		fill.Gouraud(pDC);  //填充三角形	
	}
}

class CFill {  //填充类
public:
	CFill();
	virtual ~CFill();
	void SetPoint(CPi2 *p, int);  //类的初始化
	void CreateBucket();  //创建桶
	void CreateEdge();  //边表
	void AddEt(CAET *);  //合并ET表
	void EtOrder();  //ET表排序
	void Gouraud(CDC *);  //填充多边形
    CRGB Interpolation(double, double, double, CRGB, CRGB);  //线性插值
	protected:
	int     PNum;  //顶点个数
	CPi2    *P;  //顶点坐标动态数组
	CAET    *HeadE, *CurrentE, *Edge;  //有效边表结点指针
	CBucket *HeadB, *CurrentB;  //桶表结点指针
};

void CFill::SetPoint(CPi2 *p, int m) {
	P = new CPi2[m];
	for(int i = 0; i < m; i++) {
		P[i] = p[i];	
	}
	PNum = m;
}

void CFill::CreateBucket() {  //创建桶表
	int yMin, yMax;
	yMin = P[0].y;
	yMax = P[0].y;
	for(int i = 0; i < PNum; i++) {  //查找多边形所覆盖的最小和最大扫描线
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

void CFill::CreateEdge() {  //创建边表
	for(int i = 0; i < PNum; i++) {
		CurrentB = HeadB;
		int j = (i + 1) % PNum;  //边的第二个顶点，P[i]和P[j]点对构成边
		if(P[i].y<P[j].y) {  //边的终点比起点高
			Edge = new CAET;
			Edge->x = P[i].x;  //计算ET表的值
			Edge->yMax = P[j].y;
			Edge->k = (P[j].x - P[i].x) / (P[j].y - P[i].y);  //代表1/k
			Edge->pb = P[i];  //绑定顶点和颜色
			Edge->pe = P[j];
			Edge->next = NULL;
			while(CurrentB->ScanLine != P[i].y) {  //在桶内寻找当前边的yMin
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
		if(P[j].y != P[i].y) {
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

void CFill::Gouraud(CDC *pDC) {  //填充多边形
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
				Flag = TRUE;
			}
			else {
				xe = T1->x;
				for(double x=xb;x<xe;x++) {  //左闭右开
					Cf = Interpolation(x, xb, xe, Ca, Cb);
					pDC->SetPixel(ROUND(x), CurrentB->ScanLine, RGB(Cf.red * 255, Cf.green * 255, Cf.blue * 255));
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

void CFill::AddEt(CAET *NewEdge) {  //合并ET表
	CAET *CE;  //当前边表指针
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

void CFill::EtOrder() {  //边表的冒泡排序算法
	CAET *T1, *T2;
	int Count = 1;
	T1 = HeadE;
	if(T1 == NULL) {
		return;
	}
	if(T1->next == NULL) {  //如果该ET表没有再连ET表
		return;  //桶结点只有一条边，不需要排序
	}
	while(T1->next!=NULL) {  //统计结点的个数
		Count++;
		T1 = T1->next;
	}
	for(int i=1;i<Count;i++) {  //冒泡排序
		T1 = HeadE;
		if(T1->x > T1->next->x) {  //按x由小到大排序
			T2 = T1->next;
			T1->next = T2->next;
			T2->next = T1;
			HeadE = T2;
		}
		else {
			if(T1->x == T1->next->x) {
				if(T1->k > T1->next->k) {  //按斜率倒数由小到大排序
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

CRGB CFill::Interpolation(double t, double t1, double t2, CRGB c1, CRGB c2) {  //线性插值
	CRGB c;
	c = (t - t2) / (t1 - t2) * c1 + (t - t1) / (t2 - t1) * c2;
	return c;
}

//8-2

CTestView::CTestView() {
	// TODO: add construction code here
	R = 800.0, d = 1000, Phi = -45, Theta = -50;  //视点位置球坐标
	LightNum = 1;  //光源数量
	pLight = new CLighting(LightNum);  //光源动态数组
	pLight->Light[0].SetGlobal(R, Phi, Theta);  //光源位置球坐标
	//设置光源参数
	for(int i = 0; i < LightNum; i++) {
		pLight->Light[i].L_Diffuse = CRGB(0.8, 0.8, 0.8);  //光源的漫反射颜色	
		pLight->Light[i].L_Specular = CRGB(0.508, 0.508, 0.508);  //光源镜面高光颜色
		pLight->Light[i].L_C0 = 1.0;  //常数衰减系数
		pLight->Light[i].L_C1 = 0.0000001;  //线性衰减系数
		pLight->Light[i].L_C2 = 0.00000001;//二次衰减系数
		pLight->Light[i].L_OnOff = TRUE;  //光源开启
	}
	//设置材质参数
	pMaterial = new CMaterial;  //材质指针
	pMaterial->M_Ambient = CRGB(0.192, 0.192, 0.192);  //材质对环境光的反射率
	pMaterial->M_Diffuse = CRGB(0.508, 0.508, 0.508);  //材质对漫反射光的反射率
	pMaterial->M_Specular = CRGB(1.0, 1.0, 1.0);  //材质对镜面反射光的反射率
	pMaterial->M_Exp = 5.0;  //高光指数
}

CTestView::~CTestView() {
	if(pMaterial) {
		delete pMaterial;
	}
}

void CTestView::ReadPoint() {  //点表
	double a = 200;  //正方体边长
	P[0].x = -a / 2;
	P[0].y = -a / 2;
	P[0].z = -a / 2;
	P[1].x = a / 2;
	P[1].y = -a / 2;
	P[1].z = -a / 2;
	P[2].x = a / 2;
	P[2].y = a / 2;
	P[2].z = -a / 2;
	P[3].x = -a / 2;
	P[3].y = a / 2;
	P[3].z = -a / 2;
	P[4].x = -a / 2;
	P[4].y = -a / 2;
	P[4].z = a / 2;
	P[5].x = a / 2;
	P[5].y = -a / 2;
	P[5].z = a / 2;
	P[6].x = a / 2;
	P[6].y = a / 2;
	P[6].z = a / 2;
	P[7].x = -a / 2;
	P[7].y = a / 2;
	P[7].z = a / 2;
}

void CTestView::ReadFace() {  //面表
	//面的边数、面的顶点编号和面的颜色
	//后面
	F[0].En = 4;
	F[0].p[0] = 0;
	F[0].p[1] = 3;
	F[0].p[2] = 2;
	F[0].p[3] = 1;
	//前面
	F[1].En = 4;
	F[1].p[0] = 4;
	F[1].p[1] = 5;
	F[1].p[2] = 6;
	F[1].p[3] = 7;
	//左面
	F[2].En = 4;
	F[2].p[0] = 0;
	F[2].p[1] = 4;
	F[2].p[2] = 7;
	F[2].p[3] = 3;
	//右面
	F[3].En = 4;
	F[3].p[0] = 1;
	F[3].p[1] = 2;
	F[3].p[2] = 6;
	F[3].p[3] = 5;
	//顶面
	F[4].En = 4;
	F[4].p[0] = 3;
	F[4].p[1] = 7;
	F[4].p[2] = 6;
	F[4].p[3] = 2;
	//底面
	F[5].En = 4;
	F[5].p[0] = 0;
	F[5].p[1] = 1;
	F[5].p[2] = 5;
	F[5].p[3] = 4;
}

void CTestView::InitParameter() {  //透视变换参数初始化
	k[1] = sin(PI * Theta / 180);
	k[2] = sin(PI * Phi / 180);
	k[3] = cos(PI * Theta / 180);
	k[4] = cos(PI * Phi / 180);
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
	ViewP.y = ROUND(-k[7] * P.x - k[8] * P.y + k[2] * P.z);
	ViewP.z = -k[5] * P.x - k[6] * P.y - k[4] * P.z + R;
	ViewP.c = P.c;
	ScreenP.x = d * ViewP.x / ViewP.z;  //屏幕坐标系二维坐标
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
	pDC->BitBlt(-Rect.Width() / 2, -Rect.Height() / 2, Rect.Width(), Rect.Height(), &MemDC, -Rect.Width() / 2,-Rect.Height()/2,SRCCOPY);
	ReleaseDC(pDC);
	MemDC.SelectObject(OldBitmap);	
	NewBitmap.DeleteObject();
}

void CTestView::DrawObject(CDC* pDC) {  //绘制正方体
	CPi2 Point[4];
	for(int nFace = 0; nFace < 6; nFace++) {
		CVector VS(P[F[nFace].p[1]], ViewPoint);  //面的视矢量
		CVector V01(P[F[nFace].p[0]], P[F[nFace].p[1]]);  //面的一个边矢量
		CVector V12(P[F[nFace].p[1]], P[F[nFace].p[2]]);  //面的另一个边矢量		
		CVector VN = V01 * V12;  //面的法矢量	
		if(Dot(VS,VN) >= 0) {  //凸多面体消隐
			for(int nEdge = 0; nEdge < F[nFace].En; nEdge++) {
				PerProject(P[F[nFace].p[nEdge]]);
				Point[nEdge].x = ScreenP.x;
				Point[nEdge].y = ROUND(ScreenP.y);
				Point[nEdge].c = pLight->Lighting(ViewPoint, P[F[nFace].p[nEdge]], VN, pMaterial);
			}
			fill.SetPoint(Point, 4);  //利用多边形填充类来填充
			fill.CreateBucket();
			fill.CreateEdge();
			fill.Gouraud(pDC);
		}
	}
}

void CTestView::OnLButtonDown(UINT nFlags, CPoint point) {  //鼠标左键函数
	// TODO: Add your message handler code here and/or call default
	R = R + 100;
	DoubleBuffer();
	DoubleBuffer();
	CView::OnLButtonDown(nFlags, point);
}

void CTestView::OnRButtonDown(UINT nFlags, CPoint point) {  //鼠标右键函数 
	// TODO: Add your message handler code here and/or call default
	R = R - 100;
	DoubleBuffer();
	DoubleBuffer();
	CView::OnRButtonDown(nFlags, point);
}

void CTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)  {
	// TODO: Add your message handler code here and/or call default
	switch(nChar) {
	case VK_UP:
		Phi -= 5;
		break;
	case VK_DOWN:
		Phi += 5;
		break;
	case VK_LEFT:
		Theta -= 5;
		break;
	case VK_RIGHT:
		Theta += 5;
		break;
	default:
		break;
	}
	pLight->Light[0].SetGlobal(R, Phi, Theta);
	InitParameter();
	DoubleBuffer();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

class CAET {  //有效边表类
public:
	CAET();
	virtual ~CAET();
public:
	double x;  //当前x
	int    yMax;  //边的最大y值
	double k;  //斜率的倒数(x的增量)
	CPi2    pb;  //起点
	CPi2    pe;  //终点
	CAET    *next;
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

class CFill {  //填充类
public:
	CFill();
	virtual ~CFill();
	void SetPoint(CPi2 *p, int);  //类的初始化
	void CreateBucket();  //创建桶
	void CreateEdge();  //边表
	void AddEt(CAET *);  //合并ET表
	void EtOrder();  //ET表排序
	void Gouraud(CDC *);  //填充多边形
    CRGB Interpolation(double, double, double, CRGB, CRGB);  //线性插值
	protected:
	int     PNum;  //顶点个数
	CPi2    *P;  //顶点坐标动态数组
	CAET    *HeadE, *CurrentE, *Edge;  //有效边表结点指针
	CBucket *HeadB, *CurrentB;  //桶表结点指针
};

CFill::CFill()
{

}

CFill::~CFill()
{

}

void CFill::SetPoint(CPi2 *p, int m) {
	P = new CPi2[m];
	for(int i = 0; i < m; i++) {
		P[i] = p[i];	
	}
	PNum = m;
}

void CFill::CreateBucket() {  //创建桶表
	int yMin, yMax;
	yMin = P[0].y;
	yMax = P[0].y;
	for(int i = 0; i < PNum; i++) {  //查找多边形所覆盖的最小和最大扫描线
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

void CFill::CreateEdge() {  //创建边表
	for(int i = 0; i < PNum; i++) {
		CurrentB = HeadB;
		int j = (i + 1) % PNum;  //边的第二个顶点，P[i]和P[j]点对构成边
		if(P[i].y < P[j].y) {  //边的终点比起点高
			Edge = new CAET;
			Edge->x = P[i].x;  //计算ET表的值
			Edge->yMax = P[j].y;
			Edge->k = (P[j].x - P[i].x) / (P[j].y - P[i].y);  //代表1/k
			Edge->pb = P[i];  //绑定顶点和颜色
			Edge->pe = P[j];
			Edge->next = NULL;
			while(CurrentB->ScanLine != P[i].y) {  //在桶内寻找当前边的yMin
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
		if(P[j].y != P[i].y) {
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

void CFill::Gouraud(CDC *pDC) {  //填充多边形
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
		Cb = Interpolation(CurrentB->ScanLine ,HeadE->next->pb.y, HeadE->next->pe.y, HeadE->next->pb.c, HeadE->next->pe.c);
		BOOL Flag = FALSE;
		double xb, xe;  //扫描线的起点和终点坐标
		for(T1 = HeadE; T1 != NULL; T1 = T1->next) {
			if(Flag == FALSE) {
				xb = T1->x;
				Flag = TRUE;
			}
			else {
				xe = T1->x;
				for(double x = xb; x < xe; x++) {  //左闭右开
					Cf = Interpolation(x, xb, xe, Ca, Cb);
					pDC->SetPixel(ROUND(x), CurrentB->ScanLine, RGB(Cf.red * 255, Cf.green * 255, Cf.blue * 255));
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

void CFill::AddEt(CAET *NewEdge) {  //合并ET表
	CAET *CE;  //当前边表指针
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

void CFill::EtOrder() {  //边表的冒泡排序算法
	CAET *T1, *T2;
	int Count = 1;
	T1 = HeadE;
	if(T1 == NULL) {
		return;
	}
	if(T1->next == NULL) {  //如果该ET表没有再连ET表
		return;  //桶结点只有一条边，不需要排序
	}
	while(T1->next != NULL) {  //统计结点的个数
		Count++;
		T1 = T1->next;
	}
	for(int i = 1; i < Count; i++) {  //冒泡排序
		T1 = HeadE;
		if(T1->x > T1->next->x) {  //按x由小到大排序
			T2 = T1->next;
			T1->next = T2->next;
			T2->next = T1;
			HeadE = T2;
		}
		else {
			if(T1->x == T1->next->x) {
				if(T1->k > T1->next->k) {  //按斜率倒数由小到大排序
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

CRGB CFill::Interpolation(double t, double t1, double t2, CRGB c1, CRGB c2) {  //线性插值
	CRGB c;
	c = (t - t2) / (t1 - t2) * c1 + (t - t1) / (t2 - t1) * c2;
	return c;
}

class CLight {  //光源类
public:
	CLight();
	virtual ~CLight();
	void SetDiffuse(CRGB);  //设置光源的漫反射光
	void SetSpecular(CRGB);  //设置光源的镜面反射光
	void SetPosition(double, double, double);  //设置光源的直角坐标位置
	void SetGlobal(double, double, double);  //设置光源的球坐标位置
	void SetCoef(double, double, double);  //设置光强的衰减系数
	void SetOnOff(BOOL);  //设置光源开关状态	
	void GlobalToXYZ();  //球坐标转换为直角坐标	
public:
	CRGB L_Diffuse;  //光的漫反射颜色
	CRGB L_Specular;  //光的镜面高光颜色
	CP3  L_Position;  //光源的位置
	double L_R,L_Phi,L_Theta;  //光源球坐标
	double L_C0;  //常数衰减系数
	double L_C1;  //线性衰减系数
	double L_C2;  //二次衰减系数
	BOOL L_OnOff;  //光源开关
};

CLight::CLight() {
	L_Diffuse = CRGB(1.0, 1.0, 1.0);  //光源的漫反射颜色	
	L_Specular = CRGB(1.0, 1.0, 1.0);  //光源镜面高光颜色
	L_Position.x = 1000.0, L_Position.y = 1000.0, L_Position.z = 1000;  //光源位置直角坐标
	L_R = 1000, L_Phi = 0, L_Theta = 0;  //光源位置球坐标
	L_C0 = 1.0;  //常数衰减系数
	L_C1 = 1.0;  //线性衰减系数
	L_C2 = 1.0;  //二次衰减系数
	L_OnOff = TRUE;  //光是否开启
}

CLight::~CLight() {

}

void CLight::SetDiffuse(CRGB dif) {
	L_Diffuse = dif;
}

void CLight::SetSpecular(CRGB spe) {
	L_Specular = spe;
}

void CLight::SetPosition(double x, double y, double z) {
	L_Position.x = x;
	L_Position.y = y;
	L_Position.z = z;
}

void CLight::SetGlobal(double r, double phi, double theta) {
	L_R = r;
	L_Phi = phi;
	L_Theta = theta;
}

void CLight::SetOnOff(BOOL onoff) {
	L_OnOff = onoff;
}

void CLight::SetCoef(double c0, double c1, double c2) {
	L_C0 = c0;
	L_C1 = c1;
	L_C2 = c2;
}

void CLight::GlobalToXYZ() {
	L_Position.x = L_R * sin(L_Phi * PI / 180) * cos(L_Theta * PI / 180);
	L_Position.y = L_R * sin(L_Phi * PI / 180) * sin(L_Theta * PI / 180);
	L_Position.z = L_R * cos(L_Phi * PI / 180);
}

class CLighting {  //光照类
public:
	CLighting();
	virtual ~CLighting();
	CLighting(int);		
	CRGB Lighting(CP3, CP3, CVector, CMaterial *);  //光照	
public:
	int LightNum;  //光源数量
	CLight *Light;  //光源数组
	CRGB Ambient;  //环境光
};

CLighting::CLighting() {
	LightNum = 1;
	Light = new CLight[LightNum];
	Ambient = CRGB(0.3, 0.3, 0.3);  //环境光恒定不变
}

CLighting::~CLighting() {
	if(Light) {
		delete []Light;
		Light = NULL;
	}
}

CLighting::CLighting(int lightnum) {
	LightNum = lightnum;
	Light = new CLight[lightnum];
	Ambient = CRGB(0.3, 0.3, 0.3);
}

CRGB CLighting::Lighting(CP3 ViewPoint, CP3 Point, CVector Normal, CMaterial *pMaterial) {	
	double LastR = 0.0, LastG = 0.0, LastB = 0.0;
	for(int i = 0; i < LightNum; i++) {  //来自光源
		Light[i].GlobalToXYZ();
		if(Light[i].L_OnOff) {		
			double IRed = 0, IGreen = 0, IBlue = 0;
			//第一步，计算衰减因子
			double c0 = Light[i].L_C0;
			double c1 = Light[i].L_C1;
			double c2 = Light[i].L_C2;
			CVector VL(Point, Light[i].L_Position);  //指向光源的矢量
			double d = VL.Mold();  //光传播的距离，等于向量VL的模
			double a = (1.0 / (c0 + c1 * d + c2 * d * d));  //二次衰减函数
			a = MIN(1.0, a);
			//第二步，加入漫反射光
			VL = VL.Unit();  //光矢量单位化
			CVector VN = Normal;
			VN = VN.Unit();  //法矢量单位化			
			double CosTheta = Dot(VL, VN);
			CosTheta = MAX(0.0, CosTheta);  //theta大于PI/2照射不到
			IRed += Light[i].L_Diffuse.red * pMaterial->M_Diffuse.red * CosTheta * a;
			IGreen += Light[i].L_Diffuse.green * pMaterial->M_Diffuse.green * CosTheta * a;
			IBlue += Light[i].L_Diffuse.blue * pMaterial->M_Diffuse.blue * CosTheta * a;
			//第三步，加入镜面反射光
			if(CosTheta > 0 && CosTheta < PI / 2) {  //光线可以照射到物体
				CVector VS(Point, ViewPoint);  //VS视矢量
				VS = VS.Unit();
				CVector VH = (VL + VS) / (VL + VS).Mold();  //平分矢量	
				double n = pow(Dot(VH, VN), pMaterial->M_Exp);
				IRed += Light[i].L_Specular.red * pMaterial->M_Specular.red * n * a;
				IGreen += Light[i].L_Specular.green * pMaterial->M_Specular.green * n * a;
				IBlue += Light[i].L_Specular.blue * pMaterial->M_Specular.blue * n * a;
			}
			//累加到最后的颜色
			LastR += IRed;
			LastG += IGreen;
			LastB += IBlue;
		}
	}
	LastR += Ambient.red * pMaterial->M_Ambient.red;  //加入环境光
	LastG += Ambient.green * pMaterial->M_Ambient.green;
	LastB += Ambient.blue * pMaterial->M_Ambient.blue;
	LastR = (LastR < 0.0) ? 0.0 : ((LastR > 1.0) ? 1.0 : LastR);  //颜色归一到[0,1]区间
	LastG = (LastG < 0.0) ? 0.0 : ((LastG > 1.0) ? 1.0 : LastG);
	LastB = (LastB < 0.0) ? 0.0 : ((LastB > 1.0) ? 1.0 : LastB);
	return CRGB(LastR, LastG, LastB);  //颜色赋值
}

class CMaterial {  //材质类
public:
	CMaterial();
	virtual ~CMaterial();
	void SetAmbient(CRGB);  //设置材质对环境光的反射率
	void SetDiffuse(CRGB);  //设置材质对漫反射光的反射率
	void SetSpecular(CRGB);  //设置材质对镜面反射光的反射率
	void SetExp(double);  //设置材质的高光指数
public:
	CRGB M_Ambient;  //材质对环境光的反射率
	CRGB M_Diffuse;  //材质对漫反射光的反射率
	CRGB M_Specular;  //材质对镜面反射光的反射率
	double M_Exp;  //材质的高光指数
};

CMaterial::CMaterial() {
	M_Ambient = CRGB(1.0, 1.0, 1.0);  //材质对环境光的反射率
	M_Diffuse = CRGB(1.0, 1.0, 1.0);  //材质对漫反射光的反射率
	M_Specular = CRGB(1.0, 1.0, 1.0);  //材质对镜面反射光的反射率
	M_Exp = 1.0;  //高光指数
}

CMaterial::~CMaterial() {

}

void CMaterial::SetAmbient(CRGB c) {
	M_Ambient = c;
}

void CMaterial::SetDiffuse(CRGB c) {
	M_Diffuse = c;
}

void CMaterial::SetSpecular(CRGB c) {
	M_Specular = c;
}

void CMaterial::SetExp(double Exp) {
	M_Exp = Exp;
}

class CP2 {  //二维点类
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

class CP3:public CP2 {  //三维点类
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

class CPi2 {  //二维点类，y坐标取整数
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

class CRGB {  //颜色类
public:
	CRGB();
	CRGB(double, double, double);
	friend CRGB operator+(CRGB &, CRGB &);
	friend CRGB operator*(double, CRGB &);
	virtual ~CRGB();
public:
	double red; //红色分量
	double green; //绿色分量
	double blue; //蓝色分量
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

CRGB operator +(CRGB &c1, CRGB &c2) {  //+运算符重载
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
	CVector(CP3);
	CVector(CP3, CP3);
	virtual ~CVector();
	CVector Unit();  //单位矢量
	double X();  //矢量的x坐标
	double Y();  //矢量的y坐标
	double Z();  //矢量的z坐标
	double Mold();  //矢量的模
	friend CVector operator +(CVector &, CVector &);  //矢量和
	friend CVector operator -(CVector &, CVector &);  //矢量差
	friend CVector operator *(CVector &, double); //矢量数乘
	friend CVector operator /(CVector &, double); //矢量数除
	friend double Dot(CVector &, CVector &);  //矢量点积
	friend CVector operator *(CVector &, CVector &);  //矢量叉积
public:
	double x, y, z;
};

CVector::CVector() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
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

//8-3

int CTestView::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;	
	// TODO: Add your specialized creation code here

	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),    //pfd大小
			1,                            //版本号
			PFD_DRAW_TO_WINDOW|           //支持Windows
			PFD_SUPPORT_OPENGL            //支持OpenGL
			|PFD_DOUBLEBUFFER,            //使用双缓冲
			PFD_TYPE_RGBA,                //RGBA类型		
			24,                           //24位颜色深度 
			0,0,0,0,0,0,                  //忽略的颜色位
			0,                            //无alpha缓存
			0,                            //忽略移位 
			0,                            //无累积缓冲
			0,0,0,0,                      //忽略的累积位 
			32,                           //32位z缓存
			0,                            //无模版缓存 
			0,                            //无辅助缓存 
			PFD_MAIN_PLANE,               //主绘制层 
			0,                            //保留位 
			0,0,0,                        //忽略的层掩模
	};
	m_pDC = new CClientDC(this);
	int pixelformat;
	if ((pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0) {  //选择像素格式，返回索引号
		MessageBox("ChoosePixelFormat failed");
		return FALSE;
	}
	if (SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat,&pfd) == FALSE) {  //设置像素格式
		MessageBox("SetPixelFormat failed");
		return FALSE;
	}
	rc = wglCreateContext(m_pDC->GetSafeHdc());  //创建渲染上下文
	wglMakeCurrent(m_pDC->GetSafeHdc(), rc);  //DC和RC关联使RC成为现行rc
	return 0;
}

void CTestView::OnSize(UINT nType, int cx, int cy) {
	CView::OnSize(nType, cx, cy);
	// TODO: Add your message handler code here
	if(cy > 0) {
		glViewport(0, 0, cx, cy);
		glEnable(GL_DEPTH_TEST);
		glMatrixMode(GL_PROJECTION);  //投影变换矩阵
		glLoadIdentity();  //投影变换矩阵要求
		gluPerspective(55.0f, (GLdouble)cx / cy, 2.0f, 7.0f);  //定义透视投影取景器
		glMatrixMode(GL_MODELVIEW);
	}
    Texture();
	glEnable(GL_TEXTURE_2D);
}

void CTestView::OnDestroy()  {
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	if(wglGetCurrentContext() != NULL) {  //如果有现行的RC
		wglMakeCurrent(NULL, NULL);  //断开RC与线程的联系
	}
	if(rc != NULL) {
		wglDeleteContext(rc);
		rc = NULL;
	}
}

void CTestView::OnDrawScene() {  //绘制场景
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  //设置清屏颜色为黑色
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //清除颜色缓存区和深度缓存区
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -4.5);  //平移变换
	glRotatef(wAngleX, 1.0f, 0.0f, 0.0f);  //x方向旋转变换
	glRotatef(wAngleY, 0.0f, 1.0f, 0.0f);  //y方向旋转变换
	glRotatef(wAngleZ, 0.0f, 0.0f, 1.0f);  //z方向旋转变换
	wAngleX += 1.0f;
	wAngleY += 1.0f;
	wAngleZ += 1.0f;
	//设置立方体前面纹理坐标和三维顶点坐标
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);  //glBegin()和glEnd()函数对	  
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-a, -a,  a);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(a, -a,  a);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(a,  a,  a);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-a,  a,  a);
	glEnd();
	//设置立方体后面纹理坐标和三维顶点坐标 	   
    glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-a, -a, -a);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-a,  a, -a);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(a,  a, -a);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(a, -a, -a);
	glEnd();
	//设置立方体顶面纹理坐标和三维顶点坐标    
    glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-a,  a, -a);
    glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-a,  a,  a);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(a, a,  a);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(a,  a, -a);
	glEnd(); 
	//设置立方体底面纹理坐标和三维顶点坐标
    glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-a, -a, -a);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(a, -a, -a);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(a, -a,  a);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-a, -a,  a);
	glEnd();
	//设置立方体右面纹理坐标和三维顶点坐标
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(a, -a, -a);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(a,  a, -a);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(a,  a,  a);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(a, -a,  a);
	glEnd();
	//设置立方体左面纹理坐标和三维顶点坐标	   
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-a, -a, -a);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-a, -a,  a);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-a,  a,  a);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-a,  a, -a);
	glEnd();
	glPopMatrix();
    glFlush();
	SwapBuffers(wglGetCurrentDC());  //利用双缓存的机制，实现动画 
}

void CTestView::Texture() {  //图片纹理函数
	HBITMAP hBMP;  //定义BMP头
	BITMAP	BMP;  //BMP结构体
	byte	Texture[] = {IDB_BITMAP1, IDB_BITMAP2, IDB_BITMAP3, IDB_BITMAP4, IDB_BITMAP5, IDB_BITMAP6};
	glGenTextures(sizeof(Texture), &texture[0]);
	for(int loop=0;loop<sizeof(Texture); loop++) {
		hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(Texture[loop]), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		if (hBMP) {
			GetObject(hBMP, sizeof(BMP), &BMP);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
			glBindTexture(GL_TEXTURE_2D, texture[loop]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			gluBuild2DMipmaps(GL_TEXTURE_2D, 3, BMP.bmWidth, BMP.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
			DeleteObject(hBMP);
		}
	}
}

void CTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	// TODO: Add your message handler code here and/or call default
	switch(nChar) {
	case VK_UP:
		wAngleX -= 1.0f;
		break;
	case VK_LEFT:		
		wAngleY -= 1.0f;
		break;
	case VK_RIGHT:
		wAngleZ -= 1.0f;
		break;
	case VK_DOWN:
		wAngleX = 1.0f;
		wAngleY = 1.0f;
		wAngleZ = 1.0f;
		break;
	case VK_ESCAPE:
		AfxGetMainWnd()->SendMessage(WM_CLOSE); 
        break;
	default:
		break;
	}	
	OnDrawScene();
}
