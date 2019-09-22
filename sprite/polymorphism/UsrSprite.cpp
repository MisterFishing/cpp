#include "UsrSprite.h"

CUsrSprite::CUsrSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1)
	:SpriteBase(x,y,width,height,dx,dy,img,r1)
{

}
CUsrSprite::CUsrSprite(CUsrSprite &sprite):SpriteBase(sprite)
{

}
CUsrSprite::~CUsrSprite(){}

/*
void CUsrSprite::move(int xx, int yy)
{
	x = xx;
	y = yy;
	if (x < r.x)x = r.x;
	if (x >(r.x + r.width - width))x = (r.x + r.width - width);
	if (y < r.y)y = r.y;
	if (y >(r.y + r.height - height))y = (r.y + r.height - height);

}
*/

void CUsrSprite::move(rect r1)
{
	x = r1.x;
	y = r1.y;
	if (x < r.x)x = r.x;
	if (x >(r.x + r.width - width))x = (r.x + r.width - width);
	if (y < r.y)y = r.y;
	if (y >(r.y + r.height - height))y = (r.y + r.height - height);

}

void CUsrSprite::move(int key)
{
	switch (key)
	{
	case VK_UP:
		y -= dx;
		if (y < 0) y = 0;
		break;
	case VK_DOWN:
		y += dy;
		if (y >(r.height - height)) y = (r.height - height);

		break;
	case VK_LEFT:
		x -= dx;
		if (x < r.x)x = r.x;
		break;
	case VK_RIGHT:
		x += dx;
		if (x >(r.width - width)) x = (r.width - width);

		break;
	}
}

int CUsrSprite::collision(rect r2)
{
	rect r1 = { x,y, width, height };
	int c = 1;
	if (r1.x < r2.x && r1.x + r1.width >r2.x) {
		if (r1.y > r2.y && r1.y<r2.y + r2.height)return c;
		if (r1.y <r2.y && r1.y + r1.height >r2.y)return c;
	}
	else {
		if (r1.x > r2.x && r2.x + r2.width > r1.x)
		{
			if (r1.y > r2.y && r1.y<r2.y + r2.height)return c;
			if (r1.y <r2.y && r1.y + r1.height >r2.y)return c;
		}
	}
	c = 0;
	return c;
}
int CUsrSprite::getScore()
{
	return score;
}
void CUsrSprite::setScore(int s)
{
	score = s;
}
void CUsrSprite::addScore(int m)
{
	score += m;
}
