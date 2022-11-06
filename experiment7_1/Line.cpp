// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "experiment7_1.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine() { 

}

CLine::~CLine() {
	
}

void CLine::MoveTo(CDC *pDC, CP2 p1) {  //����ֱ����㺯��
	P1 = p1;
}

void CLine::MoveTo(CDC *pDC, int x1, int y1) {  //���غ���
	P1.x = x1;
	P1.y = y1;
}

void CLine::LineTo(CDC *pDC, CP2 p2) {  //ͨ��ֱ�ߵ�����Bresenham�㷨
	P2 = p2;
	CP2 delta, p;
	bool InterChange = false;
	delta.x = abs(P2.x - P1.x);  //��x
	delta.y = abs(P2.y - P1.y);  //��y
	int e, s1, s2, temp;  //eΪ�����	
	s1 = Sign(P2.x - P1.x);
    s2 = Sign(P2.y - P1.y);
	if(delta.x < delta.y) {
		temp = delta.x;
		delta.x = delta.y;
		delta.y = temp;
        InterChange = true;  //y����Ϊ��λ�Ʒ���
	}
	e = 2 * delta.y - delta.x;
	p = P1;  //e=k-1/2��kΪֱ�ߵ�б�ʣ���e=2��x��e�任ʵ�������㷨
	for(int i = 0; i<delta.x; i++) {  //ֱ�߲������յ�����
		pDC->SetPixel(p.x, p.y, RGB(0, 0, 0));
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

void CLine::LineTo(CDC *pDC, int x2, int y2) {  //���غ���
	LineTo(pDC, CP2(x2, y2));
}

int CLine::Sign(int m) {  //����-1,0,1���Ա���Ϊ<0,=0,>0
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
