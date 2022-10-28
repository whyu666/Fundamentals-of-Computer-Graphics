//5-1

void CTestView::GetMaxX() {  //求屏幕最大x值
	CRect rect;
	GetClientRect(&rect);
    MaxX = rect.right;
}

void CTestView::GetMaxY() {  //求屏幕最大y值
	CRect rect;
	GetClientRect(&rect);
    MaxY = rect.bottom;
}

void CTestView::ReadPoint() {
	a = 100, b = 200;
	POld[0][0] = -a / 2;  //正方形顶点齐次坐标
    POld[0][1 ]= -(b - a / 2);
    POld[0][2] = 1;
	POld[1][0] = -a / 2;
    POld[1][1] = -(b + a / 2);
    POld[1][2] = 1;
	POld[2][0] = a/2;
    POld[2][1] = -(b + a / 2);
    POld[2][2] = 1;
	POld[3][0] = a / 2;
    POld[3][1] = -(b - a / 2);
    POld[3][2] = 1;	
}

void CTestView::DrawPolygon(CDC *pDC, double p[][3]) {  //绘制多边形函数
	double x,y;
	for(int i = 0; i < 4; i++) {
		if(i == 0) {
			pDC->MoveTo(ROUND(p[i][0]), ROUND(p[i][1]));
			x = p[i][0];
            y = p[i][1];
		}
		else {
            pDC->LineTo(ROUND(p[i][0]), ROUND(p[i][1]));
        }
	}
	pDC->LineTo(ROUND(x), ROUND(y));
}


void CTestView::DoubleBuffer() {  //双缓冲函数
	double Tx = 0, Ty = b;
	//平移变换矩阵
	T1[0][0] = 1;
    T1[0][1] = 0;
    T1[0][2] = 0;
	T1[1][0] = 0;
    T1[1][1] = 1;
    T1[1][2] = 0;
	T1[2][0] = -Tx;
    T1[2][1] = Ty;
    T1[2][2] = 1;
	//逆时针自转变换矩阵
	T2[0][0] = cos(beta * PI / 180);
    T2[0][1] = sin(beta * PI / 180);
    T2[0][2] = 0;
	T2[1][0] = -sin(beta * PI / 180);
    T2[1][1] = cos(beta * PI / 180);
    T2[1][2] = 0;
	T2[2][0] = 0;
    T2[2][1] = 0;
    T2[2][2] = 1;
	//反平移变换矩阵
	T3[0][0] = 1;
    T3[0][1] = 0;
    T3[0][2] = 0;
	T3[1][0] = 0;
    T3[1][1] = 1;
    T3[1][2] = 0;
	T3[2][0] = Tx;
    T3[2][1] =-Ty;
    T3[2][2] = 1;
	MultiMatrix(POld, T1);
	MultiMatrix(POld, T2);
	MultiMatrix(POld, T3);
	CDC *pDC = GetDC();  //客户区DC	
	GetMaxX();
    GetMaxY();
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(MaxX, MaxY);
	pDC->SetViewportExt(MaxX, -MaxY);
	pDC->SetViewportOrg(MaxX / 2, MaxY / 2);
	CDC	MemDC, Picture;
	MemDC.CreateCompatibleDC(pDC);
	MemDC.SetMapMode(MM_ANISOTROPIC);
	MemDC.SetWindowExt(MaxX, MaxY);
	MemDC.SetViewportExt(MaxX, -MaxY);
	MemDC.SetViewportOrg(MaxX / 2, MaxY / 2);
	CBitmap NewBitmap, *OldBitmap;
	NewBitmap.LoadBitmap(IDB_BITMAP2);
	OldBitmap = MemDC.SelectObject(&NewBitmap);
	MemDC.BitBlt(-MaxX / 2, -MaxY / 2, MaxX, MaxY, &Picture, -MaxX / 2, -MaxY / 2, SRCCOPY);
	DrawCoor(&MemDC);
	DrawPolygon(&MemDC, POld);
	pDC->BitBlt(-MaxX / 2, -MaxY / 2, MaxX, MaxY, &MemDC, -MaxX / 2, -MaxY / 2, SRCCOPY);
	ReleaseDC(pDC);
	MemDC.SelectObject(OldBitmap);	
	NewBitmap.DeleteObject();	
}

void CTestView::MultiMatrix(double P0[][3], double T[3][3]) {  //矩阵相乘
	int i, j;
	for(i = 0; i < 4; i++) {
        for(j = 0; j < 3; j++) {
            PNew[i][j] = P0[i][0] * T[0][j] + P0[i][1] * T[1][j] + P0[i][2] * T[2][j];
        }
    }
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 3; j++) {
            POld[i][j] = PNew[i][j];
        }
	}
}

void CTestView::OnTimer(UINT nIDEvent) {
	// TODO: Add your message handler code here and/or call default
	beta = 10;
	DoubleBuffer();	
	CView::OnTimer(nIDEvent);
}

void CTestView::DrawCoor(CDC *pDC) {  //绘制坐标系函数
	CPen NewPen, *OldPen;
	NewPen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	OldPen = pDC->SelectObject(&NewPen);
	pDC->MoveTo(-100, 0);
	pDC->LineTo(100, 0);
	pDC->MoveTo(0, 0);
	pDC->LineTo(0, -b);
	pDC->SelectObject(OldPen);
	NewPen.DeleteObject();	
}


//5-2

class CP2  {
public:
	CP2();
	virtual ~CP2();
public:
	double x;  //直线段端点x坐标
	double y;  //直线段端点y坐标
	UINT  rc;  //直线段端点编码
};

void CTestView::DoubleBuffer(CDC* pDC) {  //双缓冲
	CRect rect;  //定义客户区
	GetClientRect(&rect);  //获得客户区的大小
	pDC->SetMapMode(MM_ANISOTROPIC);  //pDC自定义坐标系
	pDC->SetWindowExt(rect.Width(), rect.Height());  //设置窗口范围
	pDC->SetViewportExt(rect.Width(), -rect.Height());  //设置视区范围,x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);  //客户区中心为原点
	CDC memDC;  //内存DC
	memDC.CreateCompatibleDC(pDC);  //创建一个与显示pDC兼容的内存memDC
	CBitmap NewBitmap, *pOldBitmap;  //内存中承载的临时位图 
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());  //创建兼容位图 
	pOldBitmap=memDC.SelectObject(&NewBitmap);  //将兼容位图选入memDC 
	memDC.FillSolidRect(rect, pDC->GetBkColor());  //按原来背景填充客户区，否则是黑色
	memDC.SetMapMode(MM_ANISOTROPIC);  //memDC自定义坐标系
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	DrawWindowRect(&memDC);  //绘制窗口
	if(PtCount >= 1) {
		memDC.MoveTo(Round(P[0].x), Round(P[0].y));
		memDC.LineTo(Round(P[1].x), Round(P[1].y));
	}
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);  //将内存memDC中的位图拷贝到显示pDC中
	memDC.SelectObject(pOldBitmap);  //恢复位图
	NewBitmap.DeleteObject();  //删除位图
}

void CTestView::DrawWindowRect(CDC* pDC) {  //绘制裁剪窗口
	pDC->SetTextColor(RGB(0, 255, 0));
	pDC->TextOut(-10, Wyt + 20, "窗口");
	CPen NewPen3, *pOldPen3;  //定义3个像素宽度的画笔
	NewPen3.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	pOldPen3 = pDC->SelectObject(&NewPen3);
    pDC->Rectangle(Wxl, Wyt, Wxr, Wyb);
	pDC->SelectObject(pOldPen3);
	NewPen3.DeleteObject();
}

void CTestView::Cohen() {  //Cohen-Sutherland算法
	CP2 p;  //交点坐标
	EnCode(P[0]);  //起点编码
	EnCode(P[1]);  //终点编码
	while(P[0].rc != 0 || P[1].rc != 0) {  //处理至少一个顶点在窗口之外的情况
		if((P[0].rc & P[1].rc)!=0) {  //简弃之
			PtCount = 0;
			return;
		}
		if(0 == P[0].rc) {  //确保P[0]位于窗口之外
			CP2 temp;
			temp = P[0];
			P[0] = P[1];
			P[1] = temp;
		}
		UINT RC = P[0].rc;
		double k = (P[1].y - P[0].y) / (P[1].x - P[0].x);  //直线段的斜率
		//窗口边界按左、右、下、上的顺序裁剪直线段
		if(RC & LEFT) {  //P[0]点位于窗口的左侧
			p.x = Wxl;  //计算交点y坐标
			p.y = k * (p.x - P[0].x) + P[0].y;
		}
		else if(RC & RIGHT) {  //P[0]点位于窗口的右侧
			p.x = Wxr;  //计算交点y坐标
			p.y = k * (p.x - P[0].x) + P[0].y;
		}
		else if(RC & BOTTOM) {  //P[0]点位于窗口的下侧
			p.y = Wyb;  //计算交点x坐标
			p.x = (p.y - P[0].y) / k + P[0].x;
		}			
		else if(RC & TOP) {  //P[0]点位于窗口的上侧
			p.y = Wyt;  //计算交点x坐标
			p.x = (p.y - P[0].y) / k + P[0].x;
		}
		EnCode(p);
		P[0] = p;
	}
}

void CTestView::EnCode(CP2 &pt) {  //端点编码函数
	pt.rc = 0;
	if(pt.x < Wxl) {
		pt.rc = pt.rc | LEFT;
	}
	else if(pt.x > Wxr) {
		pt.rc = pt.rc | RIGHT;
	}
	if(pt.y < Wyb) {
		pt.rc = pt.rc | BOTTOM;
	}
	else if(pt.y > Wyt) {
		pt.rc = pt.rc | TOP;
	}
}