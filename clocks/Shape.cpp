#include "Shape.h"

CShape::CShape(int x,int y,int w,int h)
{
	this->x=x;
	this->y=y;
	this->width=w;
	this->height=h;
}

CShape::~CShape(void)
{
}
void CShape::GetShapeData(int &x,int &y,int &width,int &height)
{
	x=this->x;
	y=this->y;
	width=this->width;
	height=this->height;
}
