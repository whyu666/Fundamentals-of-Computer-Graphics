// Material.h: interface for the CMaterial class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATERIAL_H__3B8335D9_2E77_447D_8F20_E3E99EEFAF8E__INCLUDED_)
#define AFX_MATERIAL_H__3B8335D9_2E77_447D_8F20_E3E99EEFAF8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RGB.h"

class CMaterial {  //������
public:
	CMaterial();
	virtual ~CMaterial();
	void SetAmbient(CRGB);  //���ò��ʶԻ�����ķ�����
	void SetDiffuse(CRGB);  //���ò��ʶ��������ķ�����
	void SetSpecular(CRGB);  //���ò��ʶԾ��淴���ķ�����
	void SetExp(double);  //���ò��ʵĸ߹�ָ��
public:
	CRGB M_Ambient;  //���ʶԻ�����ķ�����
	CRGB M_Diffuse;  //���ʶ��������ķ�����
	CRGB M_Specular;  //���ʶԾ��淴���ķ�����
	double M_Exp;  //���ʵĸ߹�ָ��
};

#endif // !defined(AFX_MATERIAL_H__3B8335D9_2E77_447D_8F20_E3E99EEFAF8E__INCLUDED_)
