#include "CusrSprite.h"

CusrSprite::CusrSprite(CusrSprite & a)
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
CusrSprite::CusrSprite(char const *name,int x,int y,int dx,int dy,int w,int h,int wWidth,int wHeight)
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


CusrSprite::~CusrSprite(void)
{
}
void CusrSprite::keyMove(int key)
{
	switch(key)
	{
	case VK_UP:y-=dy;
		if(y<0)y=0;
		break;
	case VK_DOWN:
		y+=dy;
		if(y>=winHeight-height)y = winHeight-height;
		break;
	case VK_LEFT:
		x -=dx;
		if(x<=0)x=0;
		break;
	case VK_RIGHT:
		x+=dx;
		if(x>=winWidth-width)x = winWidth-width;
		break;
	}
}
int CusrSprite::collision(CautoSprite &a){int c = 1;struct rect r2=a.getRect();if (x < r2.x && x+width >r2.x ){if (y > r2.y && y<r2.y + r2.height  )return c;if (y <r2.y && y + height >r2.y)return c;}else{if (x > r2.x && r2.x + r2.width > x){if (y > r2.y && y<r2.y + r2.height)return c;if (y <r2.y && y + height >r2.y)return c;}}c = 0;return c;}void CusrSprite::drawScale(int w,int h){	putImageScale(&img,x,y,w,h);}
