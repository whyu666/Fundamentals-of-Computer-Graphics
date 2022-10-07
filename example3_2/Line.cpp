// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Line.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{

}
double Round(double val)
{
    return (val> 0.0) ? floor(val+ 0.5) : ceil(val- 0.5);
}
CLine::~CLine()
{

}
void CLine::MoveTo(CDC *pDC,CP2 p0)
{
	P0 = p0;
}
void CLine::MoveTo(CDC *pDC,double x0,double y0)
{
	this->P0 = CP2(x0,y0);
}
void CLine::LineTo(CDC *pDC,CP2 p1)
{
	this->P1 = p1;
	CP2 p,t,Pu,Pd;
	double k,d,e=0.0,u;
	COLORREF clr=RGB(255,255,255);

	if(fabs(P0.x-P1.x)==0){		//´¹Ïß
		if(P0.y > P1.y)
		{
			t=P0;
			P0=P1;
			P1=t;
		}
		for(p=P0;p.y < P1.y;p.y++)
		{
			u=fabs(p.y-P0.y)/fabs(P1.y-P0.y);
			pDC->SetPixelV(Round(p.x),Round(p.y),RGB((1-u)*(1-e)*255,0,u*255));
		}
	} 
	else
	{
		
		k = (P1.y-P0.y)/(P1.x-P0.x);
		if(k>1.0)
		{
			if(P0.y>P1.y)
			{
				t=P0;
				P0=P1;
				P1=t;
			}
			for(p=P0;p.y<P1.y;p.y++)
			{
				Pu.x=p.x+1;
				Pu.y=p.y;

				u=fabs(p.y-P0.y)/fabs(P1.y-P0.y);

				Pd.x=p.x;
				Pd.y=p.y;
				
				pDC->SetPixelV(Round(Pu.x),Round(Pu.y),RGB((1-u)*(1-e)*255,0,u*255));
				pDC->SetPixelV(Round(Pd.x),Round(Pd.y),RGB((1-u)*e*255,0,u*255));
				e=e+1/k;
				if(e>=1.0)
				{
					p.x=p.x+1;
					e=e-1;
				}
			}
		}
	
		if(0.0<=k&&k<=1.0)
		{
			if(P0.x>P1.x)
			{
				t=P0;
				P0=P1;
				P1=t;
			}
			
			for(p=P0;p.x<P1.x;p.x++)
			{
				
				Pu.x=p.x;
				Pu.y=p.y+1;

				u=fabs(p.x-P0.x)/fabs(P1.x-P0.x);

				Pd.x=p.x;
				Pd.y=p.y;

				pDC->SetPixelV(Round(Pu.x),Round(Pu.y),RGB((1-u)*(1-e)*255,0,u*255));
				pDC->SetPixelV(Round(Pd.x),Round(Pd.y),RGB((1-u)*e*255,0,u*255));
				e=e+k;
				if(e>=1.0)
				{
					p.y=p.y+1;
					e=e-1;
				}
				
				
			}
		}
		if(k>=-1.0&&k<0.0)//Î´Ã÷°×
		{
			if(P0.x>P1.x)
			{
				t=P0;
				P0=P1;
				P1=t;
			}
			u=(p.x-P0.x)/(P1.x-P0.x);
			for(p=P0;p.x<P1.x;p.x++)
			{
				Pu.x=p.x;
				Pu.y=p.y+1;

				u=fabs(p.x-P0.x)/fabs(P1.x-P0.x);

				Pd.x=p.x;
				Pd.y=p.y;

				pDC->SetPixelV(Round(Pd.x),Round(Pd.y),RGB((1-u)*(1-e)*255,0,u*255));
				pDC->SetPixelV(Round(Pu.x),Round(Pu.y),RGB((1-u)*e*255,0,u*255));
				e=e-k;
				if(e>=1.0)
				{
					p.y=p.y-1;
					e=e-1;
				}
				
			}
		}
		if(k<-1.0)
		{
			if(P0.y<P1.y)
			{
				t=P0;
				P0=P1;
				P1=t;
			}
			
			for(p=P0;p.y>P1.y;p.y--)
			{
				Pu.x=p.x+1;
				Pu.y=p.y;

				u=fabs(p.y-P0.y)/fabs(P1.y-P0.y);

				Pd.x=p.x;
				Pd.y=p.y;

				pDC->SetPixelV(Round(Pu.x),Round(Pu.y),RGB((1-u)*(1-e)*255,0,u*255));
				pDC->SetPixelV(Round(Pd.x),Round(Pd.y),RGB((1-u)*e*255,0,u*255));
				e=e-1/k;
				if(e>=1.0)
				{
					p.x=p.x+1;
					e=e-1;
				}
			}
		}
	}
	P0=p1;
}
void CLine::LineTo(CDC *pDC,double x1,double y1)
{
	LineTo(pDC,CP2(x1,y1));
}