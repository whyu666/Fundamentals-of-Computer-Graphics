//2-4

BigCircle = atoi(dlg.m_R.GetBuffer(0));  //从对话框中获取R和r的值，用atoi函数将string转换为int
SmallCircle = atoi(dlg.m_r.GetBuffer(0));

CRect rect;
GetClientRect(&rect);
pDC->SetMapMode(MM_ANISOTROPIC);
pDC->SetWindowExt(rect.Width(),rect.Height());
pDC->SetViewportExt(rect.Width(),-rect.Height());
pDC->SetViewportOrg(rect.Width() / 2,rect.Height() / 2);
rect.OffsetRect(-rect.Width() / 2,-rect.Height() / 2);

CBrush *pOldBrush;
pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);  //设置画刷

double a = 0;
for(; a < 2 * PI; ) //设置圆的参数
{
    CRect rect2(
        CPoint(BigCircle * cos(a) - SmallCircle, BigCircle * sin(a) - SmallCircle), 
        CPoint(BigCircle * cos(a) + SmallCircle, BigCircle * sin(a) + SmallCircle));
    pDC->Ellipse(rect2);
    a = a + (2 * PI / 40);
}
pDC->SelectObject(pOldBrush);

//2-5

CRect rect;
GetClientRect(&rect);
//将坐标轴及原点移至中央
pDC->SetMapMode(MM_ANISOTROPIC);
pDC->SetWindowExt(rect.Width(), rect.Height());
pDC->SetViewportExt(rect.Width(), -rect.Height());
pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);

int r = 200, n = 5, k = 0, j; //r为初始最大的分割圆半径
j = atoi(dlg.m_input.GetBuffer(0)); //j为交互传入的递归次数
double PI = 3.1415926;
CPoint P[5]; //5等分圆得到五个顶点
double Theta = 2 * PI / n;
double Alta = PI / 10;
double Ethta = PI / 5;
double lr = 1 / (cos(Ethta) * cos(Ethta) * 4); //每次递归分割圆的缩小比例
CPen blackPen, bluePen, * pOldPen;
blackPen.CreatePen(0, 1, RGB(0, 0, 0));
bluePen.CreatePen(0, 1, RGB(0, 0, 255));
int i;
while (k < j)
{ 
    for (i = 0; i < n; i++) { 
        P[i].x = round(r  * cos(i * Theta + Alta * (1 + k * 2)));
        P[i].y = round(r  * sin(i * Theta + Alta * (1 + k * 2)));
    }
    pOldPen = pDC->SelectObject(&bluePen);
    for (i = 0; i < n; i++)
    { 
        pDC->MoveTo(P[i]);
        pDC->LineTo(P[(i + 2) % 5]); //隔点绘制五角星
    }
    pDC->SelectObject(pOldPen);
    pOldPen = pDC->SelectObject(&blackPen);
    for (i = 0; i < n; i++)
    { 
        pDC->MoveTo(P[i]);
        pDC->LineTo(P[(i + 1) % 5]); //连续点绘制正五边形
    }
    pDC->SelectObject(pOldPen);
    r = r * lr;
    k++;
}