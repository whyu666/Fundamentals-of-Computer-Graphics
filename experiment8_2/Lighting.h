// Lighting.h: interface for the CLighting class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIGHTING_H__F1B58C3F_ECCB_4F90_907C_CB043209757F__INCLUDED_)
#define AFX_LIGHTING_H__F1B58C3F_ECCB_4F90_907C_CB043209757F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Light.h"
#include "Material.h"
#include "Vector.h"

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

#endif // !defined(AFX_LIGHTING_H__F1B58C3F_ECCB_4F90_907C_CB043209757F__INCLUDED_)
