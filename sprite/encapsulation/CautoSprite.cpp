#include "CautoSprite.h"

CautoSprite::~CautoSprite(void)
{
}
CautoSprite::CautoSprite(CautoSprite & a)
{
	img=a.img;
	x=a.x;
	y=a.y;
	dx=a.dx;
	dy=a.dy;
	width=a.width;
	height=a.height;
	winWidth=a.winWidth;
	winHeight=a.winHeight;
}
CautoSprite::CautoSprite(char const *name,int x,int y,int dx,int dy,int w,int h,int wWidth,int wHeight)
{
	loadImage(name,&img);
	width=w;
	height=h;
	this->x=x;
	this->y=y;
	this->dx=dx;
	this->dy=dy;
	winWidth=wWidth;
	winHeight=wHeight;
}
struct rect CautoSprite::getRect()
{
	struct rect r;
	r.x=x;
	r.y=y;
	r.width=width;
	r.height=height;
	return r;
}
void CautoSprite::move()
{
	x+=dx;
	y+=dy;
	if(x<0 || x> winWidth-width) dx*=-1;
	if(y<0 || y>winHeight-height) dy*=-1;
}
void CautoSprite::drawScale(int w,int h)
{
	putImageScale(&img,x,y,w,h);
}