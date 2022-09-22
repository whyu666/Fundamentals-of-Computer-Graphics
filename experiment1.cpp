/*
    2-7
    从起点p0(-100, -50)到终点p1(100, 50)绘制一条1像素宽的蓝色直线段。
*/
void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    CRect rect;
    GetClientRect(&rect);
    pDC->SetMapMode(MM_ANISOTROPIC);
    pDC->SetWindowExt(rect.Width(), rect.Height());
    pDC->SetViewportExt(rect.Width(), -rect.Height());
    pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);

    CPoint p0(-100, -50), p1(100, 50);
    CPen NewPen, *pOldPen;
    NewPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
    pOldPen = pDC->SelectObject(&NewPen);
    pDC->MoveTo(p0);
    pDC->LineTo(p1);
    pDC->SelectObject(pOldPen);
}

/*
    2-8
    将客户区矩形左右边界各收缩100个像素绘制重叠的矩形和圆角矩形。
    矩形边框为1像素宽的蓝色边界线，矩形内部填充红色，圆角取(50, 50)。
*/
void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    CRect rect;
    GetClientRect(&rect);
    pDC->SetMapMode(MM_ANISOTROPIC);
    pDC->SetWindowExt(rect.Width(), rect.Height());
    pDC->SetViewportExt(rect.Width(), -rect.Height());
    pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);

    rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
    rect.DeflateRect(100, 100);

    CPen NewPen, *pOldPen;
    NewPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
    pOldPen = pDC->SelectObject(&NewPen);
    CBrush NewBrush, *pOldBrush;
    NewBrush.CreateSolidBrush(RGB(255, 0, 0));
    pOldBrush = pDC->SelectObject(&NewBrush);
    pDC->Rectangle(rect);
    pDC->RoundRect(rect, CPoint(50, 50));
    pDC->SelectObject(pOldPen);
    pDC->SelectObject(pOldBrush);
}

/*
    2-9
    以(-250, 50)为左下角点，以(250, 150)为右上角点绘制矩形，使用红色HS_BDIANGONAL阴影模式填充。
    以(-250, -150)为左下角点，以(250, -50)为右上角点绘制矩形，使用红色填充。
*/
void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    CRect rect;
    GetClientRect(&rect);
    pDC->SetMapMode(MM_ANISOTROPIC);
    pDC->SetWindowExt(rect.Width(), rect.Height());
    pDC->SetViewportExt(rect.Width(), -rect.Height());
    pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);

    rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);

    CRect rect1(CPoint(-250, 50), CPoint(250, 150));
    CRect rect2(CPoint(-250, -150), CPoint(250, -50));
    CBrush Brush(HS_BDIAGONAL, RGB(255, 0, 0));     //定义红色阴影画刷
    CBrush *pOldBrush = pDC->SelectObject(&Brush);  //选取画刷
    pDC->FillRect(&rect1, &Brush);                  //阴影填充矩形
    pDC->FillSolidRect(&rect2, RGB(255, 0, 0));     //红色填充矩形
    pDC->SelectObject(pOldBrush);                   //恢复画刷
}

/*
    2-10
    将客户区矩形左右边界各收缩100个像素，分别绘制矩形、矩形内切圆和矩形内切椭圆。
    绘制过程按圆、椭圆和矩形的顺序完成。
    设定圆、椭圆和矩形的边界线为1像素宽黑色实线，内部全部使用透明画刷填充
*/
void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    CRect rect;
    GetClientRect(&rect);
    pDC->SetMapMode(MM_ANISOTROPIC);
    pDC->SetWindowExt(rect.Width(), rect.Height());
    pDC->SetViewportExt(rect.Width(), -rect.Height());
    pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);

    rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
    rect.DeflateRect(100, 100);

    CBrush NewBrush, *pOldBrush;
    pOldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);   //选择透明画刷
    int r = rect.Height() / 2;                                  //定义圆的半径
    CRect rect1(CPoint(-r, -r), CPoint(r, r));                  //定义圆的外接矩形
    pDC->Ellipse(rect1);                                        //绘制圆
    pDC->Ellipse(rect);                                         //绘制椭圆
    pDC->Rectangle(rect);                                       //绘制外接矩形
    pDC->SelectObject(pOldBrush);
}
