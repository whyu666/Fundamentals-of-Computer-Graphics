// P3.cpp: implementation of the CP3 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Test.h"
#include "P3.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CP3::CP3()
{
	this->z=0.0;
}

CP3::~CP3()
{

}
CP3::CP3(double x0,double y0,double z0):CP2(x0,y0)
{
	this->z=z0;
}

//double CP3::Dist(CP3 to)
//{
//	return sqrt((x-to.x)*(x-to.x)+(y-to.y)*(y-to.y)+(z-to.x)*(x-to.z));
//}