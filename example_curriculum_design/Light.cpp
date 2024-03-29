// Light.cpp: implementation of the CLight class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Test.h"
#include "Light.h"

#include "cmath"
#define PI 3.14159265

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLight::CLight()
{
	L_Diffuse=CRGB(1.0,1.0,1.0);//光源的漫反射颜色	
	L_Specular=CRGB(1.0,1.0,1.0);//光源镜面高光颜色
	L_Position.x=1000.0,L_Position.y=1000.0,L_Position.z=1000;//光源位置直角坐标
	L_R=1000,L_Phi=0,L_Theta=0;//光源位置球坐标
	L_C0=1.0;//常数衰减系数
	L_C1=1.0;//线性衰减系数
	L_C2=1.0;//二次衰减系数
	L_OnOff=TRUE;//光是否开启
}

CLight::~CLight()
{

}

void CLight::SetDiffuse(CRGB dif)
{
	this->L_Diffuse=dif;
}

void CLight::SetSpecular(CRGB spe)
{
	this->L_Specular=spe;
}
void CLight::SetPosition(double x,double y,double z)
{
	this->L_Position.x=x;
	this->L_Position.y=y;
	this->L_Position.z=z;
}

void CLight::SetGlobal(double r,double phi,double theta)
{
	this->L_R=r;
	this->L_Phi=phi;
	this->L_Theta=theta;
}

void CLight::SetOnOff(BOOL onoff)
{
	this->L_OnOff=onoff;
}

void CLight::SetCoef(double c0,double c1,double c2)
{
	this->L_C0=c0;
	this->L_C1=c1;
	this->L_C2=c2;
}

void CLight::GlobalToXYZ()
{
	this->L_Position.x=L_R*sin(L_Phi*PI/180)*cos(L_Theta*PI/180);
	this->L_Position.y=L_R*sin(L_Phi*PI/180)*sin(L_Theta*PI/180);
	this->L_Position.z=L_R*cos(L_Phi*PI/180);
}