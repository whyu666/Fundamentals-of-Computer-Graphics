//有效边表填充算法

void CTestView::ReadPoint() {  //点表
	//(-200,-50)(-100,-50)(-100,50)  (-200,50)(-200,-50)(-100,50)
	//(100,-50)(200,-50)(100,50)  (100,50)(200,50)(200,-50)
	P[0].x = -200;
	P[0].y = -50;
	P[1].x= -100;
	P[1].y = -50;
	P[2].x = -100;
	P[2].y = 50;
	P[3].x = -200;
	P[3].y = 50;
	P[4].x = -200;
	P[4].y = -50;
	P[5].x = -100;
	P[5].y = 50;
	P[6].x = 100;
	P[6].y = -50;
	P[7].x = 200;
	P[7].y = -50;
	P[8].x = 100;
	P[8].y = 50;
	P[9].x = 100;
	P[9].y = 50;
	P[10].x = 200;
	P[10].y = 50;
	P[11].x = 200;
	P[11].y = -50;
}

void CTestView::DrawGraph(CDC *pDC) {  //绘制图形
	CRect rect;  //定义客户区
	GetClientRect(&rect);  //获得客户区的大小
   	pDC->SetMapMode(MM_ANISOTROPIC);  //自定义坐标系
	pDC->SetWindowExt(rect.Width(), rect.Height());  //设置窗口比例
	pDC->SetViewportExt(rect.Width(), -rect.Height());   //设置视区比例，且x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);  //设置客户区中心为坐标系原点
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);  //矩形与客户区重合
	DrawPolygon(pDC);  //绘制多边形
	FillPolygon(pDC);  //填充多边形
}

void CTestView::DrawPolygon(CDC *pDC) {  //绘制多边形边界
	CLine *line = new CLine;
	CP2 t;
	int i;
	for(i = 0; i < 3; i++) {  //绘制多边形
		if(i == 0) {
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}		
	}
	line->LineTo(pDC,t);  //闭合多边形
	for(i = 3; i < 6; i++) {
		if(i == 3) {
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}		
	}
	line->LineTo(pDC,t);
	for(i = 6; i < 9; i++) {
		if(i == 6) {
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}		
	}
	line->LineTo(pDC,t);
	for(i = 9; i < 12; i++) {
		if(i == 9) {
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}		
	}
	line->LineTo(pDC,t);
	delete line;
}

void CTestView::FillPolygon(CDC *pDC) {  //填充多边形
	int i;
	for(i = 0; i < 3; i++) {  //转储顶点坐标，y坐标取为整数
		P1[i].x = P[i].x;
		P1[i].y = Round(P[i].y);
	}
	CFill *fill1 = new CFill;  //动态分配内存
	fill1->SetPoint(P1, 3);  //初始化Fill对象
	fill1->CreateBucket();  //建立桶表
	fill1->CreateEdge();  //建立边表
    fill1->Gouraud(pDC);  //填充多边形
	delete fill1;  //撤销内存
	Sleep(500);
	for(i = 0; i < 3; i++) {
		P1[i].x = P[i + 3].x;
		P1[i].y = Round(P[i + 3].y);
	}
	CFill *fill2 = new CFill;
	fill2->SetPoint(P1, 3);
	fill2->CreateBucket();
	fill2->CreateEdge();
    fill2->Gouraud(pDC);
	delete fill2;
	Sleep(500);
	for(i = 0; i < 3; i++) {
		P1[i].x = P[i + 6].x;
		P1[i].y = Round(P[i + 6].y);
	} 
	CFill *fill3 = new CFill;
	fill3->SetPoint(P1, 3);
	fill3->CreateBucket();
	fill3->CreateEdge();
    fill3->Gouraud(pDC);
	delete fill3;
	Sleep(500);
	for(i = 0; i < 3; i++) {
		P1[i].x = P[i + 9].x;
		P1[i].y = Round(P[i + 9].y);
	}
	CFill *fill4 = new CFill;
	fill4->SetPoint(P1, 3);
	fill4->CreateBucket();
	fill4->CreateEdge();
    fill4->Gouraud(pDC);
	delete fill4;
}

class CAET {
public:
	CAET();
	virtual ~CAET();
public:
	double x;  //当前扫描线与有效边交点的x坐标
	int yMax;  //边的最大y值
	double k;  //斜率的倒数
	CP2 ps;  //边的起点
	CP2 pe;  //边的终点
	CAET *pNext;
};

class CBucket {
public:
	CBucket();
	virtual ~CBucket();
public:
	int ScanLine;  //扫描线
	CAET *pET;  //桶上的边表指针
	CBucket *pNext;
};

class CFill {
public:
	CFill();
	virtual ~CFill();
	void SetPoint(CP2 *p, int);  //初始化
	void CreateBucket();  //创建桶
	void CreateEdge();  //边表
	void AddET(CAET *);  //合并ET表
	void ETOrder();  //ET表排序
	void Gouraud(CDC *);  //填充多边形
 	void ClearMemory();  //清理内存
	void DeleteAETChain(CAET* pAET);  //删除边表
protected:
	int PNum;  //顶点个数
	CP2 *P;  //顶点坐标动态数组
	CAET *pHeadE, *pCurrentE, *pEdge;  //有效边表结点指针
	CBucket *pHeadB, *pCurrentB;  //桶表结点指针
};

CFill::CFill() {
	PNum = 0;
	P = NULL;
	pEdge = NULL;
	pHeadB = NULL;
	pHeadE = NULL;
}
CFill::~CFill() {
	if(P != NULL) {
		delete[] P;
		P = NULL;
	}
	ClearMemory();
}
void CFill::SetPoint(CP2 *p, int m) {
	P = new CP2[m];  //创建一维动态数组
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
		if(yMin == y) {  //如果是扫描线的最小值
			pHeadB = new CBucket;  //建立桶的头结点
			pCurrentB = pHeadB;  //pCurrentB为CBucket当前结点指针
			pCurrentB->ScanLine = yMin;
			pCurrentB->pET = NULL;  //没有链接边表
			pCurrentB->pNext = NULL;
		}
		else {  //其他扫描线
			pCurrentB->pNext = new CBucket;  //建立桶的其他结点
			pCurrentB = pCurrentB->pNext;
			pCurrentB->ScanLine = y;
			pCurrentB->pET = NULL;
			pCurrentB->pNext = NULL;
		}
	}
}
void CFill::CreateEdge() {  //创建边表,链接到初使桶表
	for(int i = 0; i < PNum; i++) {
		pCurrentB = pHeadB;
		int j = (i + 1) % PNum;  //边的另一个顶点，P[i]和P[j]点对构成边
		if(P[i].y < P[j].y) {  //边的终点比起点高
			pEdge = new CAET;
			pEdge->x = P[i].x;  //计算ET表的值
			pEdge->yMax = P[j].y;
			pEdge->k = (P[j].x - P[i].x) / (P[j].y - P[i].y);  //代表1/k
			pEdge->ps = P[i];  //绑定顶点和颜色
			pEdge->pe = P[j];
			pEdge->pNext = NULL;
			while(pCurrentB->ScanLine!=P[i].y) {  //在桶内寻找当前边的yMin
				pCurrentB = pCurrentB->pNext;  //移到yMin所在的桶结点
			}	
		}
		if(P[j].y < P[i].y) {  //边的终点比起点低
			pEdge = new CAET;
			pEdge->x = P[j].x;
			pEdge->yMax = P[i].y;
			pEdge->k = (P[i].x - P[j].x) / (P[i].y - P[j].y);
			pEdge->ps = P[i];
			pEdge->pe = P[j];
			pEdge->pNext = NULL;
			while(pCurrentB->ScanLine!=P[j].y) {
				pCurrentB = pCurrentB->pNext;
			}
		}
		if(P[i].y!=P[j].y) {
			pCurrentE = pCurrentB->pET;
			if(pCurrentE == NULL) {
				pCurrentE = pEdge;
				pCurrentB->pET = pCurrentE;
			}
			else {
				while(pCurrentE->pNext != NULL) {
					pCurrentE = pCurrentE->pNext;
				}
				pCurrentE->pNext = pEdge;
			}
		}
	}
}
void CFill::Gouraud(CDC *pDC) {  //填充多边形
	CAET *pT1 = NULL, *pT2 = NULL;
	pHeadE = NULL;
	for(pCurrentB = pHeadB; pCurrentB != NULL; pCurrentB = pCurrentB->pNext) {
		for(pCurrentE = pCurrentB->pET; pCurrentE != NULL; pCurrentE = pCurrentE->pNext) {
			pEdge = new CAET;
			pEdge->x = pCurrentE->x;
			pEdge->yMax = pCurrentE->yMax;
			pEdge->k = pCurrentE->k;
			pEdge->ps = pCurrentE->ps;
			pEdge->pe = pCurrentE->pe;
			pEdge->pNext = NULL;
			AddET(pEdge);
		}
		ETOrder();
		pT1 = pHeadE;
		if(pT1 == NULL) {
            return;
        }
		while(pCurrentB->ScanLine >= pT1->yMax) {  //下闭上开
			CAET * pAETTEmp = pT1;		
			pT1 = pT1->pNext;
			delete pAETTEmp;
			pHeadE = pT1;
			if(pHeadE == NULL) {
                return;
            }
		}
		if(pT1->pNext != NULL) {
			pT2 = pT1;
			pT1 = pT2->pNext;
		}
		while(pT1 != NULL) {
			if(pCurrentB->ScanLine >= pT1->yMax) {  //下闭上开
				CAET *pAETTemp = pT1;
				pT2->pNext = pT1->pNext;
				pT1 = pT2->pNext;
				delete pAETTemp;
			}
			else {
				pT2 = pT1;
				pT1 = pT2->pNext;
			}
		}
		BOOL bInFlag = FALSE;  //区间内外测试标志，初始值为假表示区间外部
		double xb,xe;  //扫描线与有效边相交区间的起点和终点坐标
		for(pT1 = pHeadE; pT1 != NULL; pT1 = pT1->pNext) {
			if(FALSE == bInFlag) {
				xb = pT1->x;
				bInFlag = TRUE;
			}
			else {
				xe = pT1->x;
				for(double x = xb; x < xe; x++) {  //左闭右开
					pDC->SetPixelV(Round(x), pCurrentB->ScanLine, RGB(255,0,0));  //使用红色填充
				}
				bInFlag = FALSE;
			}
		}
		for(pT1 = pHeadE; pT1 != NULL; pT1 = pT1->pNext) {  //边的连续性
			pT1->x = pT1->x + pT1->k;
		}
	}
}
void CFill::AddET(CAET *pNewEdge) {  //合并ET表
	CAET *pCE = pHeadE;
	if(pCE == NULL) {
		pHeadE = pNewEdge;
		pCE = pHeadE;
	}
	else {
		while(pCE->pNext != NULL) {
			pCE = pCE->pNext;
		}
		pCE->pNext = pNewEdge;
	}
}
void CFill::ETOrder() {  //边表的冒泡排序算法
	CAET *pT1, *pT2;
	int Count = 1;
	pT1 = pHeadE;
	if(pT1 == NULL) {
		return;
	}
	if(pT1->pNext==NULL) {  //如果该ET表没有再连ET表
		return;  //桶结点只有一条边，不需要排序
	}
	while(pT1->pNext != NULL) {  //统计边结点的个数
		Count++;
		pT1 = pT1->pNext;
	}
	for(int i = 0;i < Count - 1; i++) {  //冒泡排序
		CAET **pPre = &pHeadE;
		pT1 = pHeadE;
		for(int j = 0; j < Count - 1 - i; j++) {
			pT2 = pT1->pNext;
			if((pT1->x > pT2->x) || ((pT1->x == pT2->x) && (pT1->k > pT2->k))) {
				pT1->pNext = pT2->pNext;
				pT2->pNext = pT1;
				*pPre = pT2;
				pPre = &(pT2->pNext);  //调整位置为下次遍历准备
			}
			else {
				pPre = &(pT1->pNext);
				pT1 = pT1->pNext;
			}
		}
	}
}
void CFill::ClearMemory() {  //安全删除所有桶与桶上连接的边
	DeleteAETChain(pHeadE);
	CBucket *pBucket = pHeadB;
	while(pBucket!=NULL) {  //针对每一个桶
		CBucket *pBucketTemp = pBucket->pNext;
		DeleteAETChain(pBucket->pET);
		delete pBucket;
		pBucket = pBucketTemp;
	}
	pHeadB = NULL;
	pHeadE = NULL;
}
void CFill::DeleteAETChain(CAET *pAET) {
	while(pAET != NULL) {
		CAET *pAETTemp = pAET->pNext;
		delete pAET;
		pAET = pAETTemp;
	}
}


//边缘填充算法

void CTestView::ReadPoint() {  //点表
	P[0].x = 50;
	P[0].y = 100;
	P[1].x = -150;
	P[1].y = 300;
	P[2].x = -250;
	P[2].y = 50;
	P[3].x = -150;
	P[3].y = -250;
	P[4].x = 0;
	P[4].y = -50;
	P[5].x = 100;
	P[5].y = -250;
	P[6].x = 300;
	P[6].y = 150;
}

void CTestView::DrawPolygon(CDC *pDC) {
	for(int i = 0; i < 7; i++) {  //计算多边形边界
		if(P[i].x > MaxX) {
            MaxX = P[i].x;
        }
		if(P[i].x < MinX) {
            MinX = P[i].x;
        }
		if(P[i].y > MaxY) {
            MaxY = P[i].y;
        }
		if(P[i].y < MinY) {
            MinY = P[i].y;
        }
	}
	CLine *line = new CLine;
	CP2 t;
	for(i = 0; i < 7; i++) {  //绘制多边形
		if(i == 0) {
			line->MoveTo(pDC, P[i]);
			t =P[i];
		}
		else {
			line->LineTo(pDC, P[i]);
		}
	}
	line->LineTo(pDC,t);  //闭合多边形
	line->MoveTo(pDC,CP2(MinX, MinY));  //绘制包围盒
	line->LineTo(pDC,CP2(MinX, MaxY));
	line->LineTo(pDC,CP2(MaxX, MaxY));
	line->LineTo(pDC,CP2(MaxX, MinY));
	line->LineTo(pDC,CP2(MinX, MinY));	
	delete line;
}

void CTestView::FillPolygon(CDC *pDC) {
	COLORREF BClr = RGB(255, 255, 255);  //背景色
	COLORREF FClr = RGB(255, 0, 0);  //填充色
	int ymin, ymax;  //边的最小y值与最大y值
	double x, y, k;  //x,y当前点，k斜率的倒数
	for(int i = 0; i < 7; i++) {  //循环多边形所有边
		int j = (i + 1) % 7;
		k = (P[i].x - P[j].x) / (P[i].y - P[j].y);  //计算1/k
		if(P[i].y < P[j].y) {  //得到每条边y的最大值与最小值
			ymin = Round(P[i].y);
			ymax = Round(P[j].y);
			x = P[i].x;  //得到x|ymin
		}
		else {
			ymin = Round(P[j].y);
			ymax = Round(P[i].y);
			x = P[j].x;
		}
		for(y = ymin; y < ymax; y++) {  //沿每一条边循环扫描线
			for(int m = Round(x); m < MaxX; m++) {  //对每一条扫描线与边的交点的右侧像素循环
				if(FClr == pDC->GetPixel(m, Round(y))) {  //如果是填充色
					pDC->SetPixelV(m, Round(y), BClr);  //置为背景色
                }
				else {
                    pDC->SetPixelV(m, Round(y), FClr);  //置为填充色
                }	
			}
			x+=k;  //计算下一条扫描线的x起点坐标
		}
	}
}


//八邻接点

void CTestView::ReadPoint() {  //点表
	P[0].x = 0;
	P[0].y = -200;
	P[1].x = -200;
	P[1].y = -200;
	P[2].x = -200;
	P[2].y = 0;
	P[3].x = -1;
	P[3].y = 0;
	P[4].x = -1;
	P[4].y = 199;
	P[5].x = 199;
	P[5].y = 199;
	P[6].x = 199;
	P[6].y = -1;
	P[7].x = 0;
	P[7].y = -1;
}

void CTestView::FillPolygon(CDC *pDC) {  //填充多边形
	COLORREF BoundaryClr = RGB(0,0,0);  //边界色
	COLORREF PixelClr;  //当前像素点的颜色
	pHead = new CStackNode;  //建立头结点
	pHead->pNext = NULL;  //栈头结点的指针域总为空
	Push(Seed);	
	int x, y, x0 = Round(Seed.x), y0 = Round(Seed.y);  //x，y用于判断种子与图形的位置关系
	x = x0 - 1;
	while(BoundaryClr != pDC->GetPixel(x, y0) && SeedClr != pDC->GetPixel(x, y0)) {  //左方判断
		x--;
		if(x <= -rect.Width() / 2) {  //到达客户区最左端
			return;
		}
	}
	y = y0 + 1;
	while(BoundaryClr != pDC->GetPixel(x0, y) && SeedClr != pDC->GetPixel(x0, y)) {  //上方判断
		y++;
		if(y >= rect.Height() / 2) {  //到达客户区最上端
			return;
		}
	}
	x = x0 + 1;
	while(BoundaryClr != pDC->GetPixel(x, y0) && SeedClr != pDC->GetPixel(x, y0)) {  //右方判断
		x++;
		if(x >= rect.Width() / 2) {  //到达客户区最右端	
			return;
		}
	}
	y = y0 - 1;
	while(BoundaryClr != pDC->GetPixel(x0, y) && SeedClr != pDC->GetPixel(x0, y)) {  //下方判断
		y--;
		if(y <= -rect.Height() / 2) {  //到达客户区最下端
			return;
		}
	}
	while(pHead->pNext != NULL) {  //如果栈不为空
		CP2 PopPoint;
		Pop(PopPoint);
		if(SeedClr == pDC->GetPixel(Round(PopPoint.x), Round(PopPoint.y))) {
            continue;
        }
		pDC->SetPixelV(Round(PopPoint.x), Round(PopPoint.y), SeedClr);
		Left.x = PopPoint.x - 1;  //搜索出栈结点的左方像素
		Left.y = PopPoint.y;
		PixelClr = pDC->GetPixel(Round(Left.x), Round(Left.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {  //不是边界色并且未置成填充色
			Push(Left);  //左方像素入栈
        }
		LeftTop.x = PopPoint.x - 1;
		LeftTop.y = PopPoint.y + 1;  //搜索出栈结点的左上方像素
		PixelClr = pDC->GetPixel(Round(LeftTop.x), Round(LeftTop.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(LeftTop);  //左上方像素入栈
        }	
		Top.x = PopPoint.x;
		Top.y = PopPoint.y + 1;  //搜索出栈结点的上方像素
		PixelClr = pDC->GetPixel(Round(Top.x), Round(Top.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(Top);  //上方像素入栈
        }
		RightTop.x = PopPoint.x + 1;
		RightTop.y = PopPoint.y + 1;  //搜索出栈结点的右上方像素
		PixelClr = pDC->GetPixel(Round(RightTop.x), Round(RightTop.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(RightTop);  //右上方像素入栈
        }
		Right.x = PopPoint.x + 1;  //搜索出栈结点的右方像素
		Right.y = PopPoint.y;
		PixelClr = pDC->GetPixel(Round(Right.x), Round(Right.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(Right);  //右方像素入栈
        }
		RightBottom.x = PopPoint.x + 1;  //搜索出栈结点的右下方像素
		RightBottom.y = PopPoint.y - 1;
		PixelClr = pDC->GetPixel(Round(RightBottom.x), Round(RightBottom.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(RightBottom);  //右下方像素入栈
        }
		Bottom.x = PopPoint.x;
		Bottom.y = PopPoint.y - 1;  //搜索出栈结点的下方像素
		PixelClr = pDC->GetPixel(Round(Bottom.x), Round(Bottom.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(Bottom);  //下方像素入栈
        }
		LeftBottom.x = PopPoint.x - 1;
		LeftBottom.y = PopPoint.y - 1;  //搜索出栈结点的左下方像素
		PixelClr = pDC->GetPixel(Round(LeftBottom.x), Round(LeftBottom.y));
		if(BoundaryClr != PixelClr && SeedClr != PixelClr) {
            Push(LeftBottom);  //左下方像素入栈
        }
	}
	pDC->TextOut(rect.left + 50, rect.bottom - 20, "填充完毕");
	delete pHead;
	pHead = NULL;
}

void CTestView::Push(CP2 point) {  //入栈函数
	pTop = new CStackNode;
	pTop->PixelPoint = point;
	pTop->pNext = pHead->pNext;
	pHead->pNext = pTop;
}

void CTestView::Pop(CP2 &point) {  //出栈函数
	if(pHead->pNext != NULL) {
		pTop = pHead->pNext;
		pHead->pNext = pTop->pNext;
		point = pTop->PixelPoint;
		delete pTop;
	}
}

class CStackNode {  //栈结点  
public:
	CStackNode();
	virtual ~CStackNode();
public:
    CP2 PixelPoint;
	CStackNode *pNext;
};

void CLine::MoveTo(CDC *pDC, CP2 p0) {  //绘制直线起点函数	
	P0 = p0;
}

void CLine::MoveTo(CDC *pDC, double x0, double y0) {  //重载函数	
	P0 = CP2(x0, y0);
}

void CLine::LineTo(CDC *pDC,CP2 p1) {
	P1 = p1;
	CP2 p, t;
	if(fabs(P0.x - P1.x) < 1e-6) {  //绘制垂线
		if(P0.y > P1.y) {  //交换顶点,使得起始点低于终点
			t = P0;
            P0 = P1;
            P1 = t;
		}
		for(p = P0; p.y <= P1.y; p.y++) {
			pDC->SetPixelV(Round(p.x), Round(p.y), RGB(0, 0, 255));
		}
	}
	else {
		double k, d;
		k = (P1.y - P0.y) / (P1.x - P0.x);
		if(k > 1.0) {  //绘制k > 1
			if(P0.y > P1.y) {
				t = P0;
                P0 = P1;
                P1 = t;
			}
			d = 1 - 0.5 * k;
			for(p = P0; p.y < P1.y; p.y++) {
				pDC->SetPixelV(Round(p.x), Round(p.y), RGB(0, 0, 255));
                if(d >= 0) {
					p.x++;
					d += 1 - k;
				}
				else {
                    d += 1;
                }   
			}
		}
		if(0.0 <= k && k <= 1.0) {  //绘制0 <= k <= 1
			if(P0.x > P1.x) {
				t = P0;
                P0 = P1;
                P1 = t;
			}
			d = 0.5 - k; 
			for(p = P0; p.x < P1.x; p.x++) {
				pDC->SetPixelV(Round(p.x), Round(p.y), RGB(0, 0, 255));
                if(d < 0) {
					p.y++;
					d += 1 - k;
				}
				else {
                    d -= k;
                }
			}
		}		
		if(k >= -1.0 && k < 0.0) {  //绘制-1 <= k < 0
			if(P0.x > P1.x) {
				t = P0;
                P0 = P1;
                P1 = t;
			}
			d = -0.5 - k;
            for(p = P0;p.x < P1.x; p.x++) {
				pDC->SetPixelV(Round(p.x), Round(p.y), RGB(0, 0, 255));
                if(d > 0) {
					p.y--;
					d -= 1 + k;
				}
				else {
                    d -= k;
                }		
			}
		}
		if(k < -1.0) {  //绘制k < -1
			if(P0.y < P1.y) {
				t = P0;
                P0 = P1;
                P1 = t;
			}
			d = -1 - 0.5 * k;
			for(p = P0; p.y > P1.y; p.y--) {
				pDC->SetPixelV(Round(p.x), Round(p.y), RGB(0, 0, 255));
                if(d < 0) {
					p.x++;
					d -= 1 + k;
				}
				else {
                    d -= 1;
                }
			}
		}
	}
	P0 = p1;
}
void CLine::LineTo(CDC *pDC, double x1, double y1) {  //重载函数
	LineTo(pDC, CP2(x1, y1));
}